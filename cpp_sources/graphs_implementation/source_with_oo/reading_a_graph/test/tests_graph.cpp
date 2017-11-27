#include "catch.hpp"
#include "reading_a_graph/graph.hpp"

SCENARIO( "Manipulating a Graph" ) {
  GIVEN( "A graph with no of vertex, edges and directed" ) {
    int vertex = 2;
    int edges = 1;
    bool directed = true;
    Graph g(vertex, edges, directed);

    WHEN( "Calling get_nedges method" ) {
      THEN( "the result should be 1" ) {
        REQUIRE(g.get_nedges() == 1);
      }
    }
  }
}
