// PROBLEM -> https://leetcode.com/problems/design-circular-queue/
// time complexity  -> O(1)
// space complexity -> O(1)

// we initially set the first to 0 and last to -1
// queue's underflow and overflow is tracked by the memeber size
// for adding value, increement the last and add it
// for poping value, pop the value and then increment the first

typedef struct {
  int *val;
  int first, last;
  int size;            // no of elements in queue
  int capacity;        // size of the queue
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
  MyCircularQueue *cq = malloc(sizeof(MyCircularQueue));
  if (!cq) return NULL;

  cq->val = malloc(sizeof(int) * k);
  if (!cq->val) {
    free(cq);
    return NULL;
  }

  cq->first = 0;
  cq->last = -1;
  cq->size = 0;
  cq->capacity = k;
  return cq;    
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return obj->size == obj->capacity; 
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  if (!obj || myCircularQueueIsFull(obj)) return false;

  // update the last position and then insert the value
  obj->last = (obj->last + 1) % obj->capacity;
  obj->val[obj->last] = value;
  obj->size++;
  return true;     
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  if (!obj || myCircularQueueIsEmpty(obj)) return false;

  // pop the element and then increment the first's value
  obj->first = (obj->first + 1) % obj->capacity;
  obj->size--;
  return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
  if (!obj || myCircularQueueIsEmpty(obj)) return -1;

  return obj->val[obj->first];    
}

int myCircularQueueRear(MyCircularQueue* obj) {
  if (!obj || myCircularQueueIsEmpty(obj)) return -1;

  return obj->val[obj->last];  
}

void myCircularQueueFree(MyCircularQueue* obj) {
  free(obj->val);
  free(obj);   
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
