#include <list>
#include <vector>

class Graph {
  int vertices;
  std::list<int> *edge_nodes;
  void process_vertex_early(int);
  void process_vertex_late(int);
  void process_edge(int, int);
 public:
  bool directed;
  int time_counter;
  std::vector<int> entry_time;
  std::vector<int> exit_time;
  std::vector<int> parent; 
  std::vector<bool> discovered; 
  std::vector<bool> processed; 

  Graph(int);
  void add_edge(int, int, bool);
  void dfs(int);
  void print_entry_time();
  void print_exit_time();
  void print_parent_info();
};
