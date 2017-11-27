graph_read: driver.o graph.o
	g++ -g -Wall -o graph_read driver.o graph.o 

driver.o: driver.cpp graph.hpp
	g++ -c -g -Wall driver.cpp

graph.o: graph.cpp graph.hpp
	g++ -c -g -Wall graph.cpp

clean:
	rm graph.o driver.o
