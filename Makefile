CPPFLAGS=-std=c++11 -O3

test_graph.o: test_graph.cpp Graph.h
	g++ $(CPPFLAGS) $< -o $@

test_prism.o: test_prism.cpp Graph.h
	g++ $(CPPFLAGS) $< -o $@

main.o: main.cpp Graph.h
	g++ $(CPPFLAGS) $< -o $@

run_test_graph: test_graph.o input.txt
	./$< < input.txt

run_test_prism: test_prism.o
	./$<

run_case0: main.o
	./$< < test_cases/case0.txt

run_case1: main.o
	./$< < test_cases/case1.txt

run_case2: main.o
	./$< < test_cases/case2.txt

run_case3: main.o
	./$< < test_cases/case3.txt

run_case4: main.o
	./$< < test_cases/case4.txt

run_case5: main.o
	./$< < test_cases/case5.txt

run_case6: main.o
	./$< < test_cases/case6.txt

run_case7: main.o
	./$< < test_cases/case7.txt

run_case8: main.o
	./$< < test_cases/case8.txt
.PHONY: run_test_graph
