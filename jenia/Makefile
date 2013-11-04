all:mst shortpath neg_cycle
mst:mst.o GraphAlgorithms.o routines.o
	g++ -o mst mst.o GraphAlgorithms.o routines.o
shortpath:shortpath.o GraphAlgorithms.o routines.o
	g++ -o shortpath shortpath.o GraphAlgorithms.o routines.o
neg_cycle:neg_cycle.o GraphAlgorithms.o routines.o
	g++ -o neg_cycle neg_cycle.o GraphAlgorithms.o routines.o
mst.o:mst.cc GraphAlgorithms.h 
	g++ -c mst.cc
shortpath.o:shortpath.cc GraphAlgorithms.h
	g++ -c shortpath.cc
neg_cycle.o:neg_cycle.cc GraphAlgorithms.h 
	g++ -c neg_cycle.cc
GraphAlgorithms.o:GraphAlgorithms.cc GraphAlgorithms.h
	g++ -c GraphAlgorithms.cc
routines.o:routines.cc
	g++ -c routines.cc
