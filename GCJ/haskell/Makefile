all:
	ghc ${T} GCJ.hs -XBangPatterns -threaded -O3 -rtsopts -feager-blackholing

clean:
	rm -rf *.hi *.o
	cd 2016; rm -rf *.hi *.o

