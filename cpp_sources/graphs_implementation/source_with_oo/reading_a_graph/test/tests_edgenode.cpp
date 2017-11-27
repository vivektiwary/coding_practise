#include "catch.hpp"
#include "reading_a_graph/edge_node.hpp"

SCENARIO( "Manipulating EdgeNode", "[edgenode]") {
  GIVEN( "An empty EdgeNode" ) {
    EdgeNode edge;

    WHEN( "the y value gets set" ) {
      edge.set_y_node(4);

      THEN( "the y value of edgenode changes to 4" ) {
        REQUIRE(edge.get_y_node() == 4);
      }
    }

    WHEN( "a new edgenode gets added to the next of existing edge" ) {
      EdgeNode edge1;
      edge.set_next_node(&edge1);

      THEN( "the next value of edgenode changes to edge1" ) {
        REQUIRE(edge.get_next_node() == &edge1);
      }
    }
  }
}
