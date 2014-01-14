CC = gcc
CXX = g++
OBJDIR = obj/
OPTION = -W -Wall -Wextra -g

phony: test

rk: main.cpp Point.cpp Interval.cpp axiomSet.cpp TimeDomain.cpp TimeFrame.cpp
	$(CXX) $(OPTION) -std=c++0x -lpthread -pthread -o $@ $+

test: TimeDomain.cpp Range.cpp Interval.cpp axiomSet.cpp CSVIterator.cpp Util.cpp main.cpp
	$(CXX) $(OPTION) -std=c++0x -lpthread -pthread -o $@ $+
	
format: 
	astyle -A14 --indent=force-tab -H *.cpp *.hpp
