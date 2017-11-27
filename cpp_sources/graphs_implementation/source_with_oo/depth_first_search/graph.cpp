#include <iostream>
#include "graph.hpp"

Graph::Graph(int vertex_count) {
  vertices = vertex_count;
  edge_nodes = new std::list<int>[vertices];
  directed = false;
  time_counter = 0;
  parent.assign(vertices, -1);
  discovered.assign(vertices, false);
  processed.assign(vertices, false);
  entry_time.assign(vertices, 0);
  exit_time.assign(vertices, 0);
}

void Graph::add_edge(int start_vertex, int end_vertex, bool directed) {
  // std::cout << "Inserting an edge " << start_vertex << " : " << end_vertex << std::endl;
  edge_nodes[start_vertex].push_back(end_vertex);
  if (!directed) {
    // if the graph is not directed and the start vertex
    // is 1 and end vertex is 2, we need two entries.
    // 1. adding 2 in edge for 1
    // 2. adding 1 in edge for 2
    add_edge(end_vertex, start_vertex, true);
  }
}

void Graph::dfs(int start_vertex) {
  discovered[start_vertex] = true;
  time_counter += 1;
  entry_time[start_vertex] = time_counter;
  process_vertex_early(start_vertex);

  while(!edge_nodes[start_vertex].empty()) {
    int next_vertex = edge_nodes[start_vertex].front();
    // std::cout << "the next vertex of " << start_vertex << " is: " << next_vertex << std::endl;
    edge_nodes[start_vertex].pop_front();
    if (!discovered[next_vertex]) {
      process_edge(start_vertex, next_vertex);
      parent[next_vertex] = start_vertex;
      dfs(next_vertex);
    }
    else if (!processed[next_vertex] || directed) {
      process_edge(start_vertex, next_vertex);
    }
  }

  process_vertex_late(start_vertex);
  time_counter += 1;
  exit_time[start_vertex] = time_counter;
  processed[start_vertex] = true;
}

void Graph::process_vertex_early(int vertex) {
  std::cout << "Processing vertex early: " << vertex << std::endl;
}

void Graph::process_vertex_late(int vertex) {
  std::cout << "Processing vertex late: " << vertex << std::endl;
}

void Graph::process_edge(int start_vertex, int end_vertex) {
  std::cout << "Processing the edge with vertex : " << start_vertex << " and " << end_vertex << std::endl;
}

void Graph::print_entry_time() {
  for (auto et: entry_time) {
    std::cout << "the entry time is: " << et << ", "; 
  }
  std::cout << std::endl;
}

void Graph::print_exit_time() {
  for (auto exitt: exit_time) {
    std::cout << "the exit time is: " << exitt << ", "; 
  }
  std::cout << std::endl;
}

void Graph::print_parent_info() {
  std::cout << "Parent info " << std::endl;
  for (auto p : parent) {
    std::cout << p << ",";
  }
  std::cout << std::endl;
}
