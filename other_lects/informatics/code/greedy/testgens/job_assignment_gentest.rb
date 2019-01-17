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
options.maxcnt = 10
options.maxdays = 5
options.maxweight = 100
options.verbose = 0

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> "
  opts.on("-f", "--file-index f", "") { |v| options.findex = v }
  opts.on("-c", "--max-cnt c", Integer, "") { |v| options.maxcnt = v }
  opts.on("-d", "--max-days d", Integer, "") { |v| options.maxdays = v }
  opts.on("-w", "--max-weight w", Integer, "") { |v| options.maxweight = v }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

# --- main logic here ---

ndays = random_int(options.maxdays / 2, options.maxdays)
njobs = random_int(options.maxcnt / 2, options.maxcnt)

jweights = (0..njobs).map{ [random_int(1, options.maxweight), random_int(1, ndays)] }

sjweights = jweights.sort_by{|j| j[0]}.reverse

resset = sjweights.drop(1).inject([[sjweights[0][0], sjweights[0][1]]]) do |acc, jw|
  result = nil
  jw[1].downto(1).each do |t|
    if not acc.find { |j| j[1] == t }
      result = [jw[0], t]
      break
    end
  end
  result.nil? ? acc : acc.insert(-1, result)
end

# --- file dumps ---

puts "days: #{ndays - 1}, jobs: #{njobs + 1}" if (options.verbose != 0)

File.open("#{options.findex}.dat", "w") do |f|
  f << ndays - 1 << " " << njobs + 1 << "\n"
  jweights.each { |j| puts "#{j[0]} #{j[1] - 1}" } if (options.verbose != 0)
  jweights.each { |j| f << j[0] << " " << j[1] - 1 << "\n" }
end

puts "res:" if (options.verbose != 0)

File.open("#{options.findex}.ans", "w") do |f|
  resset.each { |j| puts "#{j[0]} #{j[1] - 1}" } if (options.verbose != 0)
  f << resset.inject(0) { |n, j| n + j[0] } << "\n"
end
