#!/usr/bin/ruby

# test generator 
# idea of generation: generate nchange coins of 2..options.maxnom sort/uniq
#                     build up optimal solution
#                     MAYBE: if it comes up to be greedy, drop, redo?

ARGV << '-h' if ARGV.empty?

require 'optparse'
require 'ostruct'
require 'pp'

def random_num(min, max)
    rand(max - min) + min
end

# --- options parser ---

options = OpenStruct.new
options.findex = "001"
options.nchange = 3
options.sum = 100
options.verbose = 0
options.maxnom = 30

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> -n <nchange> -s <sum>"
  opts.on("-f", "--file-index f", "") { |v| options.findex = v }
  opts.on("-n", "--nchange n", Integer, "") { |v| options.nchange = v }
  opts.on("-m", "--maxnom m", Integer, "") { |v| options.maxnom = v }
  opts.on("-s", "--sum s", Integer, "") { |v| options.sum = v }
  opts.on("-v", "--verbose", "") { |v| options.verbose = 1 }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

# --- main logic here ---

sum = options.sum

change = (0..options.nchange-1).map{ random_num(2, options.maxnom) }
change << 1 # we need 1 to make any change possible
change.sort!
change.uniq!

#sum = 11
#change = [1, 3, 4]

if change[-1] > change[-2] * 2
  change[-1] = change[-2] * 2 - 1
end

if options.verbose == 1
  puts "Sum: #{sum}"
  puts "Change:"
  pp change
end

req = (1..sum).map { 0 }

(1..sum).each do |n|
  cvals = change.map { |x| (x > n) ? sum : x == n ? 1 : (req[n-x-1] + 1) }  
  req[n-1] = cvals.min
end

if options.verbose == 1
  puts "Res:"
  pp req
end

# --- file dumps ---

File.open("#{options.findex}.dat", "w") do |f|
  f << sum << " " << change.size << "\n"
  change.each do |v|
    f << v << " "
  end
  f << "\n"
end

File.open("#{options.findex}.ans", "w") do |f|
  f << req[sum-1] << "\n"
end

