#include <stdio.h>
#include "graph.h"
#include "data.h"
#include <sys/timeb.h>

void calculate_path(Graph graph, i32 from, i32 to){
  List path = graph_shortest_path(graph, from, to);
  list_free(path);
}

i64 now(){
  struct timeb time_buffer;
  if(!ftime(&time_buffer)){
    return time_buffer.time * 1000 + time_buffer.millitm;
  } else {
    printf("Unable to get current time\n");
    return -1;
  }
}

void iterateTest(i32 iteration){
  printf("iteration:\t%d\n", iteration);

  i64 start = now();

  Graph graph = graph_new(EDGES_COUNT);
  for(i32 i = 0; i < EDGES_COUNT * 2; i += 2){
    i32 from = edges_data[i];
    i32 to = edges_data[i+1];    
    graph_add_edge(graph, from, to, 1);
  }

  i64 loaded = now();

  calculate_path(graph, 0, 6);
  calculate_path(graph, 4, 7);
  calculate_path(graph, 7, 0);
  calculate_path(graph, 16232, 15536);
  calculate_path(graph, 15047, 15389);
  calculate_path(graph, 15047, 17972);
  calculate_path(graph, 10631, 10630);
  calculate_path(graph, 956, 1092);
  calculate_path(graph, 10631, 10630);
  calculate_path(graph, 797, 816);
  calculate_path(graph, 29, 1175);

  graph_free(graph);

  i64 end = now();

  i64 timeToLoad = loaded - start;
  i64 timeToSearch = end - loaded;        
  i64 total = end - start;

  printf("load:\t%ld\n", timeToLoad);
  printf("search:\t%ld\n", timeToSearch);
  printf("total:\t%ld\n", total); 
}

i32 parseInt(char* argt){
  i32 i;
  sscanf(argt, "%d", &i);
  return i; 
}

int main(int argc, char **argv){  
  if(argc < 2)
    return 1;

  i32 iterations = parseInt(argv[1]);
  for(i32 i = 0; i < iterations; i++)
    iterateTest(i);
  return 0;
}
