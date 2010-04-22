#!/usr/bin/ruby -w

labels = []
refs = []

`grep -ho '\\Fref{.*}' main/*.tex`.each_line do |l|
	refs << l.split('{')[1].split('}')[0]
end


`grep -ho '\\label{.*}' main/*.tex`.each_line do |l|
	labels << l.split('{')[1].split('}')[0]
end

labels.sort!
refs.uniq!.sort! 


puts "not used:"
puts labels - refs
puts
puts "not defined:"
puts refs-labels

