FLAGS = -pedantic-errors -std=c++11

findcoord.o: findcoord.cpp findcoord.h
  g++ $(FLAGS) -c $<
