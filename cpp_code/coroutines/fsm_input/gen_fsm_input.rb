#!/usr/bin/ruby

ARGV << '-h' if ARGV.empty?

require 'optparse'
require 'ostruct'
require 'pp'

options = OpenStruct.new
options.findex = "001"
options.verbose = false
options.len = 10

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> -l <len> [-v]"
  opts.on("-v", "--[no-]verbose", "Run verbosely") { |v| options.verbose = v }
  opts.on("-f", "--file-index f", "Specify file index for .dat and .ans, default is #{options.findex}") { |v| options.findex = v }
  opts.on("-l", "--length-of l", Integer, "Specify maximum list len, default is #{options.len}") { |v| options.len = v }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!


lst = Array.new(options.len) do |i|
  if (rand(0.0..1.0) < 0.5)
    'a'
  else
    'b'
  end
end

File.open("#{options.findex}.dat", "w") do |f|
  lst.each { |v| f << v }
end
