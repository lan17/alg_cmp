#!/bin/bash

if [ "$1" = "clean" ] 
then
	rm *.aux
	rm *.out
	rm *.dvi
	rm *.log
	rm *.bbl
	rm *.blg
	rm *.pdf
	exit 0
fi

latex $1.tex
bibtex $1.aux
latex $1.tex
latex $1.tex
dvipdf $1.dvi $1.pdf

