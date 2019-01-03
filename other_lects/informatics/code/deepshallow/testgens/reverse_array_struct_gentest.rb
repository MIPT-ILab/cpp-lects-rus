#!/usr/bin/ruby

# test generator for reverse array of structs
# idea of generation: array of random long long, double, char
# written in .dat file in direct order and in ans in reversed

ARGV << '-h' if ARGV.empty?

require 'optparse'
require 'ostruct'

def random_int(min, max)
    rand(max - min) + min
end

options = OpenStruct.new
options.findex = "001"
options.len = 10
options.verbose = false

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> -l <len> [-v]"
  opts.on("-v", "--[no-]verbose", "Run verbosely") { |v| options.verbose = v }
  opts.on("-f", "--file-index f", "Specify file index for .dat and .ans, default is 001") { |v| options.findex = v }
  opts.on("-l", "--length-of l", Integer, "Specify length of array of structs, default is 10") { |v| options.len = v }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

fidx = options.findex
len = options.len

seq = Array.new(options.len) do
  h = Hash.new
  h[:ll] = random_int(0, 1000000)
  h[:d] = rand(0.0 .. 1.0)
  h[:c] = (65 + rand(26)).chr
  h
end

File.open("#{options.findex}.dat", "w") {|f|
  f << seq.length
  f << "\n"
  seq.each { |x| f << x[:ll] << " " << x[:d].round(6) << " " << x[:c] << "\n" }
}

File.open("#{options.findex}.ans", "w") {|f|
  seq.reverse.each { |x| f << x[:ll] << " " << x[:d].round(6) << " " << x[:c] << "\n" }
}