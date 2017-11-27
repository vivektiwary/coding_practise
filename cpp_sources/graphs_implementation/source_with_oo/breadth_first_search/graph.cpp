#include "graph.hpp"
#include <iostream>
#include <vector>
#include <queue>

Graph::Graph(int vertex_count) {
  vertices = vertex_count;
  adj = new std::list<int>[vertices];
  directed = false;
  parent.assign(vertices, -1);
  discovered.assign(vertices, false);
  processed.assign(vertices, false);
}

void Graph::add_edge(int vertex, int y_value, bool directed) {
  adj[vertex].push_back(y_value);
  if (!directed) {
    add_edge(y_value, vertex, true);
  }
}

void Graph::BFS(int start_vertex) {
  // initialize the parent array with -1, meaning no parent;

  
  std::queue<int> bfs_queue;
  
  // mark the starting vertex 'discovered'
  discovered[start_vertex] = true;
  bfs_queue.push(start_vertex);

  while(!bfs_queue.empty()) {
    int vertex = bfs_queue.front();
    process_vertex_early(vertex);

    processed[vertex] = true;
    // remove the vertex from the queue
    bfs_queue.pop();
    
    while(!adj[vertex].empty()) {
      int next_vertex = adj[vertex].front();
      // pop from the list
      adj[vertex].pop_front();

      if (!processed[next_vertex] || directed) {
        process_edge(vertex, next_vertex);
      }
      if (!discovered[next_vertex]) {
        bfs_queue.push(next_vertex);
        discovered[next_vertex] = true;
        parent[next_vertex] = vertex;
      }
    }
    process_vertex_late(vertex);
  }
  print_parent();
}

void Graph::print_parent() {
  std::cout << "===============================" << std::endl;
  for (auto p = parent.cbegin(); p != parent.cend(); ++p) {
    std::cout << " : " << *p << std::endl;
  } 
  std::cout << "===============================" << std::endl;
}

void Graph::process_vertex_early(int vertex) {
  std::cout << "Processing early :" << vertex << std::endl;
}

void Graph::process_vertex_late(int vertex) {
  std::cout << "Processing late : " << vertex << std::endl;
}

void Graph::process_edge(int vertex, int next_vertex) {
  std::cout << "We have an edge from : " << vertex << " to " << next_vertex << std::endl;
}

void Graph::find_path(int start, int end) {
  // print_parent();
  if (start == end) {
    std::cout << "The vertex is: " << end << std::endl;
    return;
  }
  find_path(start, parent[end]);
  std::cout << "The vertex is: " << end << std::endl;
}
