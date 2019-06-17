#include <stdio.h>
#include "graph.h"

void calculate_path(Graph graph, i32 from, i32 to){
  List path = graph_shortest_path(graph, from, to);

  printf("Path calculated from %d to %d\n", from, to);
  for(i32 i = 0; i < path->size; i++){
    printf("Hop %d\n", list_get(path, i));
  }
  printf("\n");

  list_free(path);
}

int main(){
  
  Graph graph = graph_new(8);

  graph_add_edge(graph, 0, 1, 1);
  graph_add_edge(graph, 1, 2, 2);
  graph_add_edge(graph, 1, 3, 6);
  graph_add_edge(graph, 2, 3, 2);
  graph_add_edge(graph, 1, 4, 3);
  graph_add_edge(graph, 3, 5, 1);
  graph_add_edge(graph, 5, 4, 5);
  graph_add_edge(graph, 0, 6, 1);
  graph_add_edge(graph, 6, 7, 1);
  graph_add_edge(graph, 0, 7, 8);
  
  calculate_path(graph, 0, 6);
  calculate_path(graph, 4, 7);
  calculate_path(graph, 7, 0);
  
  graph_free(graph);

  return 0;
}
