#include "priority_queue.h"

typedef struct PriorityQueueNode* Node;

PriorityQueue priority_queue_new(){
  PriorityQueue pq = malloc(sizeof(struct PriorityQueue));
  pq->size = 0;
  Node head = malloc(sizeof(struct PriorityQueueNode));
  head->data = 0;
  head->priority = 0;
  head->next = head;
  pq->head = head;
  return pq;
}

void priority_queue_free(PriorityQueue this){
  Node tmp = this->head->next;

  while(tmp != this->head){
    Node next = tmp->next;
    free(tmp);
    tmp = next;
  }

  free(this->head);
  free(this);
}

i32 priority_queue_pop(PriorityQueue this){
  if(this->size == 0){
    return -1;
  }

  Node node = this->head->next;
  i32 val = node->data;
  this->head->next = node->next;
  free(node);
  this->size--;
  return val;
}

void priority_queue_push(PriorityQueue this, i32 data, i32 priority){
  Node head = this->head;

  Node node = malloc(sizeof(struct PriorityQueueNode));
  node->data = data;
  node->priority = priority;
  
  
  Node prev = head;
  Node tmp = head->next;

  while(tmp != head && tmp->priority < priority){
    prev = tmp;
    tmp = tmp->next;
  }

  prev->next = node;
  node->next = tmp;
  this->size++;
}

bool priority_is_empty(PriorityQueue this){
  return this->size == 0;
}