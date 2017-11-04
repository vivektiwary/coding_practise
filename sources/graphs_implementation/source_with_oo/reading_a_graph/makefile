graph_read : edge_node.o graph.o
	g++ -o graph_read edge_node.o graph.o

edge_node.o : edge_node.cpp edge_node.hpp
	g++ -c edge_node.cpp

graph.o : graph.cpp graph.hpp
	g++ -c graph.cpp

clean :
	rm edge_node.o graph.o
