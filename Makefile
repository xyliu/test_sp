all:
	g++ -g3 -O0 RefBase.cpp main.cpp -o testsp
clean:
	rm -f testsp *.o
