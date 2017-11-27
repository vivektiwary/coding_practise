#include <list>
#include <vector>

class Graph {
 private:
  int vertices;
  std::list<int> *adj;
  void initialize_trackers(std::vector<bool> &);
  void process_vertex_early(int);
  void process_vertex_late(int);
  void process_edge(int, int);
 public:
  Graph(int);
  std::vector<int> parent; //(vertices, -1);
  std::vector<bool> discovered; //(vertices, false);
  std::vector<bool> processed; //(vertices, false);
  bool directed;
  void add_edge(int, int, bool);
  void BFS(int);
  void find_path(int, int);
  void print_parent();
};
