#!/usr/bin/ruby

# test generator to check egyptian fractions
# idea of generation: generate proper fractions, add, reduce

ARGV << '-h' if ARGV.empty?

require 'optparse'
require 'ostruct'

def random_int(min, max)
    rand(max - min) + min
end

options = OpenStruct.new
options.findex = "001"
options.maxcnt = 3
options.maxden = 100

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> -c <maxcnt> -d <maxden>"
  opts.on("-f", "--file-index f", "") { |v| options.findex = v }
  opts.on("-c", "--max-cnt c", Integer, "") { |v| options.maxcnt = v }
  opts.on("-d", "--max-denom d", Integer, "") { |v| options.maxden = v }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

cnt = random_int(3, 3 + options.maxcnt)

# seq shall be set manually
seq = [2, 3, 7, 44, 9462, 373029888]

# sum[0]/sum[1] + 1/n = (sum[0]*n + sum[1]) / sum[1]*n
res = seq.inject([0, 1]) { |sum, n| [sum[0]*n + sum[1], sum[1]*n] }
g = res[1].gcd(res[0])

File.open("#{options.findex}.dat", "w") do |f|
  f << res[0] / g << " " << res[1] / g << "\n"
end

File.open("#{options.findex}.ans", "w") do |f|
  seq.each { |s| f << s << " " }
  f << "\n"
end
