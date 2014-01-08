CC = gcc
CXX = g++
OBJDIR = obj/
OPTION = -W -Wall -Wextra -g

phony: test

RoboKoch: main.cpp Point.cpp PointRelation.cpp
	$(CXX) -std=c++0x -lpthread -o $@ $+

test: main.cpp Point.cpp PointRelation.cpp TimeFrame.cpp
	$(CXX) $(OPTION) -std=c++0x -lpthread -pthread -o $@ $+
	
format: 
	astyle -A14 --indent=force-tab -H *.cpp *.hpp
