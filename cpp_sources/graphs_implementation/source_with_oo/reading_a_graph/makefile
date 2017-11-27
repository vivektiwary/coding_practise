graph_read : driver_file.o edge_node.o graph.o
	g++ -g -Wall -o graph_read driver_file.o edge_node.o graph.o

driver_file.o : driver_file.cpp edge_node.hpp graph.hpp
	g++ -c -g -Wall driver_file.cpp

edge_node.o : edge_node.cpp edge_node.hpp
	g++ -c -g -Wall edge_node.cpp

graph.o : graph.cpp graph.hpp
	g++ -c -g -Wall graph.cpp

clean :
	rm edge_node.o graph.o driver_file.o
