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
options.maxlen = 10
options.lenall = 20
options.verbose = 0

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> -m <maxintv>"
  opts.on("-f", "--file-index f", "") { |v| options.findex = v }
  opts.on("-m", "--max-intv m", Integer, "") { |v| options.maxintv = v }
  opts.on("-a", "--len-all a", Integer, "") { |v| options.lenall = v }
  opts.on("-l", "--max-len l", Integer, "") { |v| options.maxlen = v }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

# --- main logic here ---

nintv = random_int(0, options.maxintv) + 1
intvs = (0..nintv).map do
  istart = random_int(0, options.lenall)
  ilen = random_int(1, options.maxlen)
  [istart, istart + ilen]
end

sintvs = intvs.sort_by{|i| i[1]}

sintvs.each { |i| puts "next #{i[0]} -- #{i[1]}" } if options.verbose != 0

puts "pick #{sintvs[0][0]} -- #{sintvs[0][1]}" if options.verbose != 0
res = sintvs.inject([1, sintvs[0]]) do |acc, newintv| 
  oldintv = acc[1]
  if (newintv[0] > oldintv[1])
    puts "pick #{newintv[0]} -- #{newintv[1]}" if options.verbose != 0
    [acc[0] + 1, newintv]
  else
    [acc[0], oldintv]
  end
end

# --- file dumps ---

File.open("#{options.findex}.dat", "w") do |f|
  intvs.each do |i|
    f << i[0] << " " << i[1] << "\n"
  end
end

File.open("#{options.findex}.ans", "w") do |f|
  f << res[0] << "\n"
end
