/**
 * Finding shorted path in an unweighted graph
 */

#include <iostream>
#include <queue>

using namespace std;

#define MAXV 1000

struct edgenode {
  int y;
  int weight;
  edgenode *next;
};

struct graph {
  edgenode *edges[MAXV + 1];
  int degree[MAXV + 1];
  int nvertices;
  int nedges;
  bool directed;
};

/*
 * For BFS initialization
 */
int processed[MAXV + 1];
int discovered[MAXV + 1];
int parent[MAXV + 1];

/*
 * For Reading the graph
 */

void initialize_graph(graph *g, bool directed) {
  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;
  for (int i = 1; i <= g->nvertices; i++) g->edges[i] = NULL;
  for (int i = 1; i <= g->nvertices; i++) g->degree[i] = 0;
}

void insert_edge(graph *g, int x, int y, bool directed) {
  edgenode *node = (edgenode *) malloc(sizeof(edgenode));
  node->y = y;
  node->weight = 0;
  node->next = g->edges[x];

  g->edges[x] = node;
  g->degree[x]++;

  if (directed == false) {
    insert_edge(g, y, x, true);
  }
  else {
    g->nedges++;
  }
}

void read_graph(graph *g, bool directed) {
  int edge_count;
  int x, y;
  initialize_graph(g, directed);
  cout << "Enter the number of vertex and edges" << endl;
  cin >> g->nvertices >> edge_count;
  for (int i = 1; i <= edge_count; i++) {
    cout << "Enter the x and y vertex connecting an edge" << endl;
    cin >> x >> y;
    insert_edge(g, x, y, directed);
  }
}

void initialize_search(graph *g) {
  for (int i = 1; i <= g->nvertices; i++) {
    processed[i] = discovered[i] = false;
    parent[i] = -1;
  }
}

void process_vertex_early(int vertex_number) {
  cout << "Processing vertex " << vertex_number << endl;
}

void process_edge(int start_vertex, int end_vertex) {
  cout << "Processing edge " << start_vertex << ", " << end_vertex << endl;
}

// void process_vertex_late(int vertex_number) {
// }
//
void bfs(graph *g, int start) {
  queue<int> q;
  int current_vertex;
  int edge_vertex;
  edgenode *node;

  q.push(start);
  discovered[start] = true;

  while(!q.empty()) {
    current_vertex = q.front();
    q.pop();
    process_vertex_early(current_vertex);

    node = g->edges[current_vertex];
    while (node != nullptr) {
      edge_vertex = node->y;
      if (processed[edge_vertex] == false || g->directed) {
        process_edge(current_vertex, edge_vertex);
      }
      if (discovered[edge_vertex] == false) {
        q.push(edge_vertex);
        discovered[edge_vertex] = true;
        parent[edge_vertex] = current_vertex;
      }
      node = node->next;
    }
    // process_vertex_late(current_vertex);
  }
}

void print_parent_relationship(graph *g) {
  cout << "The nvertices are: " << g->nvertices << endl;
  int size = g->nvertices;
  for (int i = 1; i <= size; i++) {
    cout << "The parent of vertex " << i << " is ==== " << parent[i] << endl;
  }
}

void find_shortest_path(int source, int destination, int parent[]) {
  if (source == destination || destination == -1) {
    cout << "Vertex is: " << source << endl;
    return;
  }
  find_shortest_path(source, parent[destination], parent);
  cout << "Vertex is: " << destination << endl;
}

int main(void)
{
  int source, destination;
  graph *g;
  g = (graph *) malloc(sizeof(graph));
  read_graph(g, true);
  initialize_search(g);
  bfs(g, 1);
  print_parent_relationship(g);
  cout << "Please enter your input for shortest path finder" << endl;
  cout << "Please enter source" << endl;
  cin >> source;
  cout << "Please enter destination" << endl;
  cin >> destination;
  find_shortest_path(source, destination, parent);
  return 0;
}
