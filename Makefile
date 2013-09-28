all:
	g++ -g3 -O0 RefBase.cpp main.cpp -o testsp
clean:
	rm -f testsp test2  *.o
test2:
	g++ -g3 -O0 RefBase.cpp test2.cpp -o test2 
