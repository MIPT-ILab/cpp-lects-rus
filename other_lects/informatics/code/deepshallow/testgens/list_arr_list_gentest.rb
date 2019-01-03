#!/usr/bin/ruby

# test generator to check refs
# idea of generation: generate arrays then merge

ARGV << '-h' if ARGV.empty?

require 'optparse'
require 'ostruct'
require 'pp'

def random_int(min, max)
    rand(max - min) + min
end

options = OpenStruct.new
options.findex = "001"
options.len = 10
options.nlsts = 5
options.prob = 0.3
options.verbose = false

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> -l <len> [-v]"
  opts.on("-v", "--[no-]verbose", "Run verbosely") { |v| options.verbose = v }
  opts.on("-f", "--file-index f", "Specify file index for .dat and .ans, default is 001") { |v| options.findex = v }
  opts.on("-l", "--length-of l", Integer, "Specify maximum list len, default is 10") { |v| options.len = v }
  opts.on("-n", "--number-of n", Integer, "Specify length of array of lists, default is 5") { |v| options.nlsts = v }
  opts.on("-p", "--probability-of n", Float, "Specify probability to have list, default is 0.3") { |v| options.prob = v }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

lsts = Array.new(options.nlsts) do |i|
  if (rand(0.0..1.0) < options.prob)
    Array.new(random_int(1, options.len + 1)) { rand(options.len) }.sort
  else
    Array.new
  end
end

File.open("#{options.findex}.dat", "w") do |f|
  f << options.nlsts
  f << "\n"
  lsts.each do |v|
    f << v.length
    v.each { |nxt| f << " " << nxt }
    f << "\n"
  end
end

lsts.flatten!
lsts.sort!

File.open("#{options.findex}.ans", "w") do |f|
  lsts.each { |x| f << x << "\n" }
end

