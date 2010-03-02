#!/usr/bin/ruby

roh = Dir.glob('roh/*.pdf').select do |f|
	base = File.basename(f)
	!File.exists?(base) or
		File.stat(f).ctime >= File.stat(base).ctime
end

roh.each { |f|
	pid = fork do
		base = File.basename(f)
		`pdfcrop #{f} #{base} &`
	end
	Process.detach pid
}
