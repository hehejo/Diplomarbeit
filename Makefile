.PHONY: fast full doppel

export TEXINPUTS=:_sty

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
	
	
copy: full
	scp master.pdf hehejo.de:html/de.hehejo/Diplomarbeit.pdf 2>/dev/null & 
	scp doppelmaster.pdf hehejo.de:html/de.hehejo/Diplomarbeit2.pdf 2>/dev/null & 
