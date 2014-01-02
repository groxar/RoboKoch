CC = gcc
CXX = g++
OBJDIR = obj/
OPTION = -Wall

phony: test

RoboKoch: main.cpp Point.cpp PointRelation.cpp
	$(CXX) -std=c++0x -lpthread -o $@ $+

test: main.cpp Point.cpp PointRelation.cpp TimeFrame.cpp
	$(CXX) $(Wall) -std=c++0x -lpthread -o $@ $+
	
