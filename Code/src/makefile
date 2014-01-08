CC = gcc
CXX = g++
OBJDIR = obj/
OPTION = -W -Wall -Wextra 

phony: test

RoboKoch: main.cpp Point.cpp PointRelation.cpp
	$(CXX) -std=c++0x -lpthread -o $@ $+

test: main.cpp Point.cpp PointRelation.cpp TimeFrame.cpp
	$(CXX) $(OPTION) -std=c++0x -lpthread -pthread -o $@ $+
	
