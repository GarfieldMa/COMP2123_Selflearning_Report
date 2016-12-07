CPPFLAGS=-std=c++11 -O3

Prim.o: Prim.cpp Prim.h
	g++ -c $< $(CPPFLAGS)

main.o: main.cpp Prim.h Graph.h
	g++ -c $< $(CPPFLAGS)

main: main.o Prim.o
	g++ $^ -o $@ $(CPPFLAGS)

run_case0: main
	./$< < test_cases/case0.txt

run_case1: main
	./$< < test_cases/case1.txt

run_case2: main
	./$< < test_cases/case2.txt

run_case3: main
	./$< < test_cases/case3.txt

run_case4: main
	./$< < test_cases/case4.txt

run_case5: main
	./$< < test_cases/case5.txt

run_case6: main
	./$< < test_cases/case6.txt

run_case7: main
	./$< < test_cases/case7.txt

run_case8: main
	./$< < test_cases/case8.txt

run_case9: main
	./$< < test_cases/case9.txt

clean:
	rm *.o main

.PHONY: clean
