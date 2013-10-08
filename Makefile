all:
	g++ -g3 -O0 RefBase.cpp main.cpp -o testsp
clean:
	rm -f testsp test2 test3 *.o
test2:
	g++ -g3 -O0 RefBase.cpp test2.cpp -o test2 
test3:
	g++ -g3 -O0 RefBase.cpp test3.cpp -o test3

run_test2:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./test2
