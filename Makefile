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
	./$< < case0.txt


.PHONY: run_test_graph
