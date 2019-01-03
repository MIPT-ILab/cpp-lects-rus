#!/usr/bin/ruby

# test generator to check deep copy. Simplest possible one

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
  h[:num] = random_int(0, 1000000)  
  h[:name] = (0..15).map { (65 + rand(26)).chr }.join
  h
end

File.open("#{options.findex}.dat", "w") {|f|
  f << seq.length
  f << "\n"
  seq.each { |x| f << x[:name] << " " << x[:num] << "\n" }
}

File.open("#{options.findex}.ans", "w") {|f|
  seq.each { |x| f << x[:name] << " " << x[:num] << "\n" }
}