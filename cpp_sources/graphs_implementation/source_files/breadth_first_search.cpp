#include <iostream>
#include <queue>

#define MAXV 1000

using namespace std;


struct edgenode {
  int y;
  int weight;
  edgenode *next;
};

struct graph {
  edgenode *edges [MAXV + 1];
  int degree[MAXV + 1];
  int nvertices;
  int nedges;
  bool directed;
};

bool processed[MAXV + 1];       /* which vertices have been processed */
bool discovered[MAXV + 1];      /* which vertices have been found */
int parent[MAXV + 1];           /* discovery relation */

void initialize_search(graph *g) {
  for (int i = 1; i <= g->nvertices; i++) {
    processed[i] = discovered[i] = false;
    parent[i] = -1;
  }
}

void process_vertex_late(int v) {
  v = 5;              /* dummy value given to prevent syntastic to raise an error in vim */
}

void process_vertex_early(int v) {
  cout << "Processed vertex " << v << endl;
}

void process_edge(int x, int y) {
  cout << "Processed edge " << x << "," << y << endl;
}

void bfs(graph *g, int start) {
  queue<int> q;       /* queue of vertices to visit */
  int v;              /* current vertex */
  int y;              /* successor vertex */
  edgenode *p;

  q.push(start);
  discovered[start] = true;

  while (!q.empty()) {
    v = q.front();
    q.pop();

    process_vertex_early(v);
    processed[v] = true;
    p = g->edges[v];
    while(p != nullptr) {
      y = p->y;
      if ((processed[y] == false) || g->directed) {
        process_edge(v, y);
      }
      if (discovered[y] == false) {
        q.push(y);
        discovered[y] = true;
        parent[y] = v;
      }
      p = p -> next;
    }
    process_vertex_late(v);
  }
}

void initialize_graph(graph *g, bool directed) {
  g -> nvertices = 0;
  g -> nedges = 0;
  g -> directed = directed;
  for (int i = 1; i <= MAXV; ++i) g->degree[i] = 0;
  for (int i = 1; i <= MAXV; ++i) g->edges[i] = NULL;
}

void insert_edge(graph *g, int x, int y, bool directed) {
  edgenode *p;
  p = (edgenode *) malloc(sizeof(edgenode));
  p->y = y;
  p->weight = 0;
  p->next = g->edges[x];

  g->edges[x] = p;

  g->degree[x] ++;

  if (directed == false) {
    insert_edge(g, y, x, true);
  }
  else {
    g->nedges++;
  }

}

void read_graph(graph *g, bool directed) {
  int edges;        /* no of edges */
  int x, y;         /* vertex in edge (x, y) */

  initialize_graph(g, directed);
  cout << "Enter the number of vertices and edges" << endl;
  cin >> g->nvertices >> edges;
  for (int i = 1; i <= edges; ++i) {
    cout << "Enter the vertex x and y number" << endl;
    cin >> x >> y;
    insert_edge(g, x, y, directed);
  }
}

int main() {
  graph *g;
  g = (graph *) malloc(sizeof(graph));
  read_graph(g, true);
  initialize_search(g);
  bfs(g, 1);
  return 0;
}
