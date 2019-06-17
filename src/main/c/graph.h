#include "std.h"
#include "list.h"

struct Graph {
  i32 edges_size;
  i32* edges;
};

typedef struct Graph* Graph;

Graph graph_new(i32);

void graph_free(Graph);

void graph_add_edge(Graph, i32, i32, i32);

i32 graph_get_weight(Graph, i32, i32);

List graph_shortest_path(Graph, i32, i32);