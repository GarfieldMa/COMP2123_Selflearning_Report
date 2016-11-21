CPPFLAGS=-std=c++11 -O3

test_graph: test_graph.cpp Graph.h
	g++ $(CPPFLAGS) $< -o $@

run_test_graph: test_graph input.txt
	./$< < input.txt

.PHONY: run_test_graph
