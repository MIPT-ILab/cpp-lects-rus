#!/usr/bin/ruby

# test generator 
# idea of generation: 

ARGV << '-h' if ARGV.empty?

require 'optparse'
require 'ostruct'

def random_int(min, max)
    rand(max - min) + min
end

# --- options parser ---

options = OpenStruct.new
options.findex = "001"
options.maxintv = 10
options.maxspace = 5
options.unitlen = 3
options.verbose = nil
options.prob = 80

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> "
  opts.on("-f", "--file-index f", "") { |v| options.findex = v }
  opts.on("-m", "--max-intv m", Integer, "") { |v| options.maxintv = v }
  opts.on("-s", "--max-space s", Integer, "") { |v| options.maxspace = v }
  opts.on("-u", "--unit-len u", Integer, "") { |v| options.unitlen = v }
  opts.on("-p", "--probability p", Integer, "") { |v| options.prob = v }
  opts.on("-v", "--verbose", "") { options.verbose = 1 }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

# --- main logic here ---

raise "max space shall be at least 1" if options.maxspace < 1

nintvs = random_int(options.maxintv / 2, options.maxintv)
lastright = 0
intvs = (0..nintvs).map do
  dist = [1, random_int(0, options.maxspace)].max
  newleft = lastright + dist 
  newright = newleft + options.unitlen
  puts "peeking intv #{newleft} -- #{newright}" if options.verbose
  lastright = newright
  [newleft, newright]
end

points = intvs.map do |i|
  ret = []
  ret << i[0]
  ret << i[1]
  if (i[0] + 1 < i[1])
    (i[0] + 1 .. i[1] - 1).each do |n|
      if random_int(0, 99) < options.prob
        ret << n
      end      
    end
  end
  puts "peeking #{ret}"
  ret
end.flatten.shuffle

points.sort.each {|p| puts "point: #{p}" } if options.verbose

# --- file dumps ---

File.open("#{options.findex}.dat", "w") do |f|
  f << points.size << " " << options.unitlen << "\n"
  points.each{|p| f << p << " "}
  f << "\n"
end

File.open("#{options.findex}.ans", "w") do |f|
  f << intvs.size << "\n"
end
