all:
	ghc ${T} GCJ.hs -XBangPatterns -threaded -O3 -rtsopts -feager-blackholing

clean:
	echo ". 2016 2017" | perl -pe 's/\s+/\n/g' | xargs -I % sh -c 'cd %; rm -rf *.hi *.o *.in *.out'

