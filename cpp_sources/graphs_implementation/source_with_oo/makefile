edge_node_test : edge_node.o tests_edgenode.o tests_main.o
	g++ -g -Wall -o edge_node_test edge_node.o tests_edgenode.o tests_main.o

edge_node.o : reading_a_graph/edge_node.cpp reading_a_graph/edge_node.hpp
	g++ -c -g -Wall reading_a_graph/edge_node.cpp

tests_main.o : tests_main.cpp catch.hpp
	g++ -c -g -Wall tests_main.cpp

tests_edgenode.o : tests_edgenode.cpp reading_a_graph/edge_node.hpp
	g++ -c -g -Wall tests_edgenode.cpp


# making graph tests

graph_test : graph.o tests_graph.o tests_main.o
	g++ -g -Wall -o graph_test graph.o tests_graph.o tests_main.o

graph.o : reading_a_graph/graph.cpp reading_a_graph/graph.hpp reading_a_graph/edge_node.hpp
	g++ -c -g -Wall reading_a_graph/graph.cpp

tests_graph.o : tests_graph.cpp reading_a_graph/graph.hpp
	g++ -c -g -Wall tests_graph.cpp


# all : edge_node_test graph_test

clean :
	rm edge_node.o tests_edgenode.o graph.o tests_graph.o tests_main.o
