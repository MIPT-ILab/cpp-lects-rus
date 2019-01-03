#!/usr/bin/ruby

# test generator to check refs
# idea of generation: generate n < k strings, fill array with random strings and increasing numbers, sort and group by strings

ARGV << '-h' if ARGV.empty?

require 'optparse'
require 'ostruct'

def random_int(min, max)
    rand(max - min) + min
end

options = OpenStruct.new
options.findex = "001"
options.len = 10
options.nstrs = 5
options.verbose = false

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> -l <len> [-v]"
  opts.on("-v", "--[no-]verbose", "Run verbosely") { |v| options.verbose = v }
  opts.on("-f", "--file-index f", "Specify file index for .dat and .ans, default is 001") { |v| options.findex = v }
  opts.on("-l", "--length-of l", Integer, "Specify length of array of structs, default is 10") { |v| options.len = v }
  opts.on("-s", "--number-of s", Integer, "Specify number of different strings, default is 5") { |v| options.nstrs = v }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

strs = Array.new(options.nstrs) do
  (0..15).map { (65 + rand(26)).chr }.join
end

seq = Array.new(options.len) do |i|
  h = Hash.new
  h[:num] = i
  h[:str] = random_int(0, options.nstrs-1)
  h
end

File.open("#{options.findex}.ans", "w") do |f|
  seq.each { |x| f << x[:num] << " " << strs[x[:str]] << "\n" }
end

gseq = seq.group_by{|x| x[:str]}

File.open("#{options.findex}.dat", "w") do |f|
  f << gseq.length << " " << seq.length
  f << "\n"
  gseq.each do |k, v| 
    f << v.length << " " << strs[k]
    v.each { |nxt| f << " " << nxt[:num] }
    f << "\n"
  end
end
