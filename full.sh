#!/bin/sh
pdflatex master
makeindex -g -l -s index.ist master &
bibtex master 
pdflatex master
pdflatex master


pdflatex doppelmaster
