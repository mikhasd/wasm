#include <stdio.h>
#include "graph.h"
#include "data.h"

void calculate_path(Graph graph, i32 from, i32 to){
  List path = graph_shortest_path(graph, from, to);
  list_free(path);
}

int main(int argc, char **argv){
  Graph graph = graph_new(EDGES_COUNT);
  for(i32 i = 0; i < EDGES_COUNT * 2; i += 2){
    i32 from = edges_data[i];
    i32 to = edges_data[i+1];    
    graph_add_edge(graph, from, to, 1);
  }
  
  calculate_path(graph, 0, 6);
  calculate_path(graph, 4, 7);
  calculate_path(graph, 7, 0);
  calculate_path(graph, 16232, 15536);

  calculate_path(graph, 15047, 15389);

  calculate_path(graph, 15047, 17972);

  calculate_path(graph, 10631, 10630);
  calculate_path(graph, 956, 1092);
  
  
  graph_free(graph);
  return 0;
}
