.PHONY: fast full doppel

fast:
	pdflatex master
	
full:
	pdflatex master
	makeindex -g -l -s index.ist master &
	bibtex master 
	pdflatex master
	bibtex master 
	pdflatex master
	
	
doppel: full
	pdflatex doppelmaster

copy: doppel
	scp master.pdf hehejo.de:html/de.hehejo/Diplomarbeit.pdf 2>/dev/null & 
	scp doppelmaster.pdf hehejo.de:html/de.hehejo/Diplomarbeit2.pdf 2>/dev/null & 
