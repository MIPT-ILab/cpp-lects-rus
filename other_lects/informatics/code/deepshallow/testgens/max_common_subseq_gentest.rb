#!/usr/bin/ruby

# test generator for max common subsequence
# idea of generation: shuffle array of 1..n numbers, take first k to be common subsequence
# then using part of others to mix into first and part to mix into second
# printing findex.dat and findex.ans files

ARGV << '-h' if ARGV.empty?

require 'optparse'
require 'ostruct'

def random_int(min, max)
    rand(max - min) + min
end

def fixidxs(seq1, seq)
  sidx = -1
  raise if (seq1.count(-1) != seq.length)
  seq1.map.with_index do |x, i|
    unless x == -1
      x
    else
      sidx += 1
      seq[sidx]
    end
  end
end

options = OpenStruct.new
options.findex = "001"
options.len = 3
options.total = 8
options.verbose = false

OptionParser.new do |opts|
  opts.banner = "Usage: #{$0} -f <fname> -l <seq len> -t <total len> [-v]"
  opts.on("-v", "--[no-]verbose", "Run verbosely") { |v| options.verbose = v }
  opts.on("-f", "--file-index f", "Specify file index, like 005.dat, default is 001") { |v| options.findex = v }
  opts.on("-l", "--length-of l", Integer, "Specify length of common part, default is 3") { |v| options.len = v }
  opts.on("-t", "--total-of t", Integer, "Specify length of total string, default is 8") { |v| options.total = v }
  opts.on_tail("-h", "--help", "Show this message") do
    puts opts
    exit
  end
end.parse!

fidx = options.findex
seqlen = options.len
totlen = options.total

if (seqlen > totlen)
  puts "common sequence length #{seqlen} shall be less or equal to total length #{totlen}"
end

arrtotal = Array.new(totlen){ |index| index }.shuffle
seq = arrtotal[0 ... seqlen]
seq1 = (0 ... seqlen).collect{-1}
seq2 = (0 ... seqlen).collect{-1}
if (totlen > seqlen)
  rem = arrtotal[seqlen ... totlen]
  
  #split rem into parts
  r = random_int(0, rem.length - 1)
  rem1 = rem[0 ... r]
  rem2 = rem[r ... rem.length]
  seq1.push(*rem1)
  seq2.push(*rem2)
end

seq1.shuffle!
seq2.shuffle!

# now fix seq1 and seq2 replacing -1 with seq
seq1 = fixidxs(seq1, seq)
seq2 = fixidxs(seq2, seq)

File.open("#{fidx}.dat", "w") {|f|
  f << seq1.length << " " << seq2.length
  f << "\n"
  seq1.each { |x| f << x << " " }
  f << "\n"
  seq2.each { |x| f << x << " " }
}

File.open("#{fidx}.ans", "w") {|f|
  f << seq.length
}