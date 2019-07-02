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

void iterateTest(i32 max, i32 iteration){
  printf("iteration:\t%d\n", iteration);

  i64 start = now();

  Graph graph = graph_new(max + 1);
  for(i32 i = 0; i < EDGES_COUNT * 2; i += 2){
    i32 from = edges_data[i];
    i32 to = edges_data[i+1];    
    graph_add_edge(graph, from, to, 1);
  }

  i64 loaded = now();

  for(i32 i = 0; i < 10; i++){
    calculate_path(graph, 0, 6);
    calculate_path(graph, 4, 7);
    calculate_path(graph, 7, 0);
    calculate_path(graph, 10631, 10630);
    calculate_path(graph, 956, 1092);
    calculate_path(graph, 10631, 10630);
    calculate_path(graph, 797, 816);
    calculate_path(graph, 29, 1175);
    calculate_path(graph, 29, 1175);
    calculate_path(graph, 232, 6055);
    calculate_path(graph, 32, 6007);
  }
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

i64 parseLong(char* argt){
  i64 i;
  sscanf(argt, "%ld", &i);
  return i; 
}

i32 biggestVertex(){
  i32 max = edges_data[0];
  for(i32 i = 1; i < EDGES_COUNT * 2; i++){
    i32 current = edges_data[i];
    if(current > max)
      max = current;
  }
  return max;
}

int main(int argc, char **argv){  
  if(argc < 3)
    return 1;

  i64 startup = parseLong(argv[1]);

  printf("Started in %ldms\n", now() - startup);

  i32 iterations = parseInt(argv[2]);
  i32 biggest = biggestVertex();

  for(i32 i = 0; i < iterations; i++)
    iterateTest(biggest, i);
  return 0;
}
