.PHONY: fast full doppel

fast:
	pdflatex master
	pdflatex doppelmaster
	
full:
	pdflatex master
	makeindex -g -l -s index.ist master &
	bibtex master 
	pdflatex master
	bibtex master 
	pdflatex master
	pdflatex doppelmaster
	
crop: 
	cd grafics; ./cropem.rb
	
copy: full
	scp master.pdf hehejo.de:html/de.hehejo/Diplomarbeit.pdf 2>/dev/null & 
	scp doppelmaster.pdf hehejo.de:html/de.hehejo/Diplomarbeit2.pdf 2>/dev/null & 
