tree : driver.o tree.o node.o
	g++ -std=c++11 -Wall -g -o tree driver.o tree.o node.o

driver.o : driver.cpp tree.hpp node.hpp
	g++ -std=c++11 -c -Wall -g driver.cpp

tree.o : tree.cpp tree.hpp node.hpp
	g++ -std=c++11 -c -Wall -g tree.cpp

node.o : node.cpp node.hpp
	g++ -std=c++11 -c -Wall -g node.cpp

clean:
	rm driver.o tree.o node.o
