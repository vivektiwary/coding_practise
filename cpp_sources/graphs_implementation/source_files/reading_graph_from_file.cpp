#include <iostream>

#define MAXV 1000  /* maximum number of vertices */

using namespace std;

struct edgenode {
  int y;                  /* adjacency info */
  int weight;             /* edge weight, if any */
  edgenode *next;         /* next edge in the list */
};

struct graph {
  edgenode *edges[MAXV + 1];    /* adjacency info */
  int degree[MAXV + 1];         /* outdegree of each vertex */
  int nvertices;                /* number of vertices in the graph */
  int nedges;                   /* number of edges in the graph */
  bool directed;                /* is the graph directed?     */
};

void initialize_graph(graph *g, bool directed) {
  int i;                          /* counter */
  g -> nvertices = 0;
  g -> nedges = 0;
  g -> directed = directed;
  for (i = 1; i <= MAXV; ++i) g -> edges[i] = NULL;
  for (i = 1; i <= MAXV; ++i) g -> degree[i] = 0;
}

void insert_edge(graph *g, int x, int y, bool directed) {
  edgenode *p;

  p = (edgenode *) malloc(sizeof(edgenode));

  p->weight = 0;
  p->y = y;
  p->next = g->edges[x];          /* front insertion logic, here head ptr is edges[x] */

  g->edges[x] = p;

  g->degree[x] ++;

  if (directed == false) {
    insert_edge(g, y, x, true);
  }
  else {
    g->nedges ++;
  }
}

void read_graph(graph *g, bool directed) {
  int m;                /* number of edges */
  int x, y;             /* vertex in edge (x, y) */

  initialize_graph(g, directed);
  cout << "Enter the number of vertex and edges" << endl;
  cin >> g->nvertices >> m;
  for (int i = 1; i <= m; ++i) {
    cout << "Enter the vertext x and y coordinates" << endl;
    cin >> x >> y;
    insert_edge(g, x, y, directed);
  }
}

void print_graph(graph *g) {
  edgenode *p;          /* temporary pointer */

  for (int i = 1; i <= g->nvertices; i++) {
    cout << i << ":";
    p = g->edges[i];
    while(p != nullptr) {
      cout << " " << p->y;
      p = p->next;
    }
    cout << endl;
  }
}

int main()
{
  graph *g;
  g = (graph *) malloc(sizeof(graph));
  read_graph(g, true);
  print_graph(g);
  return 0;
}

