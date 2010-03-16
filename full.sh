#!/bin/sh
pdflatex master
makeindex -g -s index.ist master &
bibtex master 
pdflatex master
pdflatex master
