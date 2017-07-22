test:test.o dict.o
	g++ -o test test.o dict.o

test.o:test.cc
	g++ -std=c++11 -c test.cc
dict.o:dict.cc
	g++ -std=c++11 -c dict.cc

clean:
	rm *.o
	rm test
