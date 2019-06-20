#include "graph.h"
#include "priority_queue.h"

Graph graph_new(i32 edges){
  Graph graph = malloc(sizeof(struct Graph));
  graph->edges_size = edges;
  graph->edges = calloc(edges * edges, sizeof(i32));
  return graph;
}

void graph_free(Graph this){
  free(this->edges);
  free(this);
}

size_t calc_offset(Graph graph, i32 x, i32 y){
  return x + graph->edges_size * y;
}

void graph_add_edge(Graph graph, i32 from, i32 to, i32 weight){
  graph->edges[calc_offset(graph, from, to)] = weight;
  graph->edges[calc_offset(graph, to, from)] = weight;
}

i32 graph_get_weight(Graph graph, i32 from, i32 to){
  return graph->edges[calc_offset(graph, from, to)];
}

List get_neighbors(Graph this, i32 vertex){
  List neighbors = list_new(this->edges_size / 2);
  for(i32 i = 0; i< this->edges_size; i ++){
    if(vertex != i){
      i32 weight = graph_get_weight(this, i, vertex);
      if(weight > 0){
        list_add(neighbors, i);
      }
    }
  }
  return neighbors;
}

i32* calculate_cost_table(Graph this, i32 from){
  i32* costs = malloc(this->edges_size * sizeof(i32));
  i32* source = calloc(this->edges_size, sizeof(i32));
  for(i32 i = 0; i < this->edges_size;i++){
    costs[i] = source[i] = -1;    
  }

  costs[from] = 0;
  source[from] = from;  

  PriorityQueue queue = priority_queue_new();

  priority_queue_push(queue, from, 0);

  while(!priority_is_empty(queue)){
    i32 current = priority_queue_pop(queue);
    i32 currentCost = costs[current];

    List neighbors = get_neighbors(this, current);
    for(i32 i = 0; i < neighbors->size; i++){
      i32 neighbor = list_get(neighbors, i);
      i32 cost = currentCost + graph_get_weight(this, neighbor, current);
      i32 neighbor_cost = costs[neighbor];

      if(neighbor_cost == -1 || neighbor_cost > cost){
        costs[neighbor] = cost;
        source[neighbor] = current;
        priority_queue_push(queue, neighbor, cost);
      }
    }
    list_free(neighbors);
  }

  priority_queue_free(queue);

  free(costs);

  return source;
}

List graph_shortest_path(Graph this, i32 from, i32 to){
  List path = list_new(10);
  list_add(path, to);

  i32* sources = calculate_cost_table(this, from);

  i32 previous = sources[to];

  while(previous != -1 && previous != from){
    list_add(path, previous);
    previous = sources[previous];
  }

  free(sources);

  if(previous == -1){
    return list_new(0);
  } else {
    list_add(path, previous);
    return path;
  } 
}