#include "graph.hpp"
#include <list>
#include <iostream>

Graph::Graph(int vertex_count) {
  vertices = vertex_count;
  edge_nodes = new std::list<int>[vertices];
  directed = false;
  finished = false;
  time_counter = 0;
  entry_time.assign(vertices, 0);
  exit_time.assign(vertices, 0);
  parent.assign(vertices, -1);
  discovered.assign(vertices, false);
  processed.assign(vertices, false);
}

void Graph::add_edge(int start_vertex, int end_vertex, bool directed) {
  edge_nodes[start_vertex].push_back(end_vertex);
  if (!directed) {
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
    edge_nodes[start_vertex].pop_front();

    if (!discovered[next_vertex]) {
      parent[next_vertex] = start_vertex;
      process_edge(start_vertex, next_vertex);
      dfs(next_vertex);
    }
    else if (!processed[next_vertex] || directed) {
      process_edge(start_vertex, next_vertex);
    }
    if (finished) return;
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
  if (parent[start_vertex] != end_vertex && parent[start_vertex] != -1 && parent[end_vertex] != start_vertex) {
    std::cout << "Cycle from " << end_vertex << " to " << start_vertex << std::endl;
    std::cout << std::endl;
    finished = true;
  }
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
