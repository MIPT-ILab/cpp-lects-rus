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
options.verbose = 1

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

leftmost = random_int(0, options.lenall / 4)
rightmost = random_int(3 * options.lenall / 4, options.lenall)

nintv = random_int(0, options.maxintv) + 1
intvs = (0..nintv).map do
  istart = random_int(0, options.lenall)  
  ilen = random_int(1, options.maxlen)
  [istart, istart + ilen]
end

# check that coverage possible and add intervals if not
(leftmost..rightmost).each do |n|
  if not intvs.find{|i| (i[0] <= n) && (i[1] >= n) }
    intvs << [n, n + random_int(1, options.maxlen)]
  end
end

puts "intv from #{leftmost} to #{rightmost}"
sintvs = intvs.sort_by{|i| i[0]}
sintvs.each { |i| puts "next #{i[0]} -- #{i[1]}" } if options.verbose != 0

# looking for first covering leftmost
idx = sintvs.find_index { |i| (i[0] <= leftmost) && (i[1] >= leftmost) }
curright = sintvs[idx][1]
puts "starting from #{sintvs[idx][0]} -- #{curright}"

res = sintvs.inject([leftmost, curright, 0]) do |acc, newintv|
  if acc[0] > rightmost
    [acc[0], acc[1], acc[2]]
  elsif newintv[0] <= acc[0] 
    newright = [acc[1], newintv[1]].max
    accinc = (newintv == sintvs.last) ? 1 : 0
    puts "peek last ends in #{newright}" if newintv == sintvs.last && options.verbose != 0
    [acc[0], newright, acc[2] + accinc]
  else
    needlast = acc[1] + 1 <= rightmost && newintv == sintvs.last
    puts "peek for point #{acc[0]} interval ending in #{acc[1]}" if options.verbose != 0
    puts "peek last ends in #{newintv[1]}" if needlast && options.verbose != 0
    accinc = needlast ? 2 : 1
    [acc[1] + 1, newintv[1], acc[2] + accinc]
  end
end


# --- file dumps ---

File.open("#{options.findex}.dat", "w") do |f|
  f << leftmost << " " << rightmost << " " << intvs.size << "\n"
  intvs.each do |i|
    f << i[0] << " " << i[1] << "\n"
  end
end

File.open("#{options.findex}.ans", "w") do |f|
  f << res[2] << "\n"
end

