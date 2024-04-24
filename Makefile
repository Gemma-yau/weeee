FLAGS = -pedantic-errors -std=c++11

findcoord.o: findcoord.cpp findcoord.h
	g++ $(FLAGS) -c $<

getch.o: getch.cpp getch.h
	g++ $(FLAGS) -c $<

lose.o: lose.cpp lose.h findcoord.h
	g++ $(FLAGS) -c $<

move.o: move.cpp move.h getch.h printcolour.h findcoord.h
	g++ $(FLAGS) -c $<

printbg.o: printbg.cpp printbg.h printcolour.h
	g++ $(FLAGS) -c $<

printcolour.o: printcolour.cpp printcolour.h
	g++ $(FLAGS) -c $<

printresult.o: printresult.cpp printresult.h
	g++ $(FLAGS) -c $<

setBoard.o: setBoard.cpp setBoard.h
	g++ $(FLAGS) -c $<

win.o: win.cpp win.h
	g++ $(FLAGS) -c $<

ctd: main.cpp findcoord.o getch.o lose.o move.o printbg.o printcolour.o printresult.o setBoard.o win.o
	g++ $(FLAGS) $^ -o ctd

clean:
	rm -f ctd findcoord.o getch.o lose.o move.o printbg.o printcolour.o printresult.o setBoard.o win.o ctd.tgz

tar:
	tar -czvf ctd.tgz *.cpp *.h

.PHONY: clean tar
