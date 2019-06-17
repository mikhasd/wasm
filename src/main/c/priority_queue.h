#include "std.h"

struct PriorityQueueNode {
  i32 data;
  i32 priority;
  struct PriorityQueueNode* next;
};

struct PriorityQueue {
  i32 size;
  struct PriorityQueueNode* head;
};

typedef struct PriorityQueue* PriorityQueue;

PriorityQueue priority_queue_new();

void priority_queue_free(PriorityQueue);

i32 priority_queue_pop(PriorityQueue);

void priority_queue_push(PriorityQueue, i32, i32);

bool priority_is_empty(PriorityQueue);