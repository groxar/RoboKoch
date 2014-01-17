CC = gcc
CXX = g++
OBJDIR = obj/
OPTION = -W -Wall -Wextra -g

phony: test

rk: main.cpp Point.cpp Interval.cpp axiomSet.cpp TimeDomain.cpp TimeFrame.cpp
	$(CXX) $(OPTION) -std=c++0x -lpthread -pthread -o $@ $+

test: TimeFrame.cpp TimeDomain.cpp Range.cpp Interval.cpp axiomSet.cpp CSVIterator.cpp Util.cpp main.cpp
	$(CXX) $(OPTION) -std=c++0x -lpthread -pthread -o $@ $+
	
format: 
	astyle -A14 --indent=force-tab -H *.cpp *.hpp

a:
	./test testData/A_002_Ablauf_Bsp.csv testData/A_002_Beziehungen_Bsp.csv testData/A_002_DurchfuerungAC.csv

b:
	./test testData/A_002_Ablauf_Bsp.csv testData/A_002_Beziehungen_Bsp.csv testData/A_002_DurchfuerungBC.csv

c:
	./test testData/A_002_Ablauf_Bsp.csv testData/A_002_Beziehungen_Bsp.csv testData/A_002_DurchfuerungCC.csv
