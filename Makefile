.PHONY: fast full doppel

fast:
	pdflatex --synctex=1 master
	pdflatex doppelmaster
	
full:
	pdflatex --synctex=1 master
	makeindex -g -l -s index.ist master &
	bibtex master 
	pdflatex --synctex=1 master
	bibtex master 
	pdflatex --synctex=1 master
	pdflatex doppelmaster
	
crop: 
	cd grafics; ./cropem.rb
	
copy: full
	scp master.pdf hehejo.de:html/de.hehejo/Diplomarbeit.pdf 2>/dev/null & 
	scp doppelmaster.pdf hehejo.de:html/de.hehejo/Diplomarbeit2.pdf 2>/dev/null & 
