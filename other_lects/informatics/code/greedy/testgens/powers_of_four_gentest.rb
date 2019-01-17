#!/usr/bin/ruby

# test generator to check even powers of 2
# idea of generation: generate proper tuple to highest, next add some highest

ARGV << '-h' if ARGV.empty?

require 'optparse'
require 'ostruct'

def random_int(min, max)
    rand(max - min) + min
end

options = OpenStruct.new
options.findex = "001"
options.maxpower = 12
options.maxval = 100

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> -m <maxpower>"
  opts.on("-f", "--file-index f", "") { |v| options.findex = v }
  opts.on("-p", "--max-power m", Integer, "") { |v| options.maxpower = v }
  opts.on("-m", "--max-value v", Integer, "") { |v| options.maxval = v }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

seq = (0..options.maxpower).map { random_int(0, 3) }
seq[options.maxpower] += random_int(0, options.maxval)
biseq = seq.each_with_index.map {|v, i| v * (4 ** i) }

File.open("#{options.findex}.dat", "w") do |f|
  f << biseq.reduce(:+) << " " << options.maxpower << "\n"
end

File.open("#{options.findex}.ans", "w") do |f|
  f << seq.reduce(:+) << "\n"
end
