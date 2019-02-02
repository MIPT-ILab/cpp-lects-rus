#!/usr/bin/ruby

# test generator 
# idea of generation: generate triangles, sum up squares

ARGV << '-h' if ARGV.empty?

require 'optparse'
require 'ostruct'
require 'pp'

def random_num(min, max)
    rand(max - min) + min
end

def random_scale(min, max, scal)
    (rand(max * scal - min * scal) + min * scal) / scal
end

# --- options parser ---

options = OpenStruct.new
options.findex = "001"
options.maxtriang = 10
options.minx = 1.0
options.miny = 1.0
options.maxx = 10.0
options.maxy = 10.0
options.prognum = 0
options.verbose = 0

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> -m <maxtriang> -p <0|1>"
  opts.on("-f", "--file-index f", "") { |v| options.findex = v }
  opts.on("-m", "--max-triang m", Integer, "") { |v| options.maxtriang = v }
  opts.on("-p", "--prog-num p", Integer, "") { |v| options.prognum = v }
  opts.on("-x", "--max-x x", Float, "") { |v| options.maxx = v }
  opts.on("-y", "--max-y y", Float, "") { |v| options.maxy = v }
  opts.on("-v", "--verbose", "") { |v| options.verbose = 1 }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

# --- main logic here ---

ntriangles = random_num(options.maxtriang / 2, options.maxtriang)

maxsq = 0
totalsq = 0

triangles = (0..ntriangles).map do
  xs = (0..2).map { random_scale(options.minx, options.maxx, 1.0) }
  ys = (0..2).map { random_scale(options.miny, options.maxy, 1.0) }
  [xs, ys]
end

if options.verbose == 1
  puts "Triangles:"
  pp triangles
end

squares = triangles.map do |v| 
  xs = v[0]
  ys = v[1]
  (xs[0] * ys[1] - xs[1] * ys[0] + 
   xs[1] * ys[2] - xs[2] * ys[1] +
   xs[2] * ys[0] - xs[0] * ys[2]).abs / 2  
end

if options.verbose == 1
puts "Squares:"
pp squares
end

# --- file dumps ---

File.open("#{options.findex}.dat", "w") do |f|
  f << triangles.size << "\n"
  triangles.each do |v|
    xs = v[0]
    ys = v[1]
    (0..2).each {|i| f << xs[i] << " " << ys[i] << "\n"}
  end
end

File.open("#{options.findex}.ans", "w") do |f|
  if options.prognum == 0
    f << squares.max << "\n"
  else
    f << squares.reduce(0, :+) << "\n"
  end
end

