require 'fileutils'
require 'open3'
require 'optparse'
require 'ostruct'

ARGV << '-h' if ARGV.empty?

options = OpenStruct.new
options.filename = "a.exe"
options.topdir = "."

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> -t <testdir>"
  opts.on("-f", "--file-name f", "") { |v| options.filename = v }
  opts.on("-t", "--test-dir d", "") { |v| options.topdir = v }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

dat = Dir["#{options.topdir}/*.dat"]
ans = Dir["#{options.topdir}/*.ans"]

raise "You need equal ans and dat" if (dat.nil? or ans.nil? or ans.size != dat.size)

dat.each do |s| 
  puts "checking #{s}"
  outf = File.basename(s, ".dat")
  system("#{options.filename} < #{s} > #{outf}.out")
  if not FileUtils.compare_file("#{options.topdir}/#{outf}.ans", "#{outf}.out")
    puts "Fail"
  else
    FileUtils.remove_file("#{outf}.out")
  end
end
