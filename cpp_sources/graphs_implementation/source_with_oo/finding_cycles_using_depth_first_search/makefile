cycle : driver.o graph.o
	g++ -Wall -g -o cycle driver.o graph.o

driver.o : driver.cpp graph.hpp
	g++ -c -Wall -g driver.cpp

graph.o : graph.cpp graph.hpp
	g++ -c -Wall -g graph.cpp

clean:
	rm driver.o graph.o
