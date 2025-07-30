// PROBLEM -> https://leetcode.com/problems/implement-queue-using-stacks/

/* struct to define struct */
typedef struct {
  int data[100];
  int top;
} stack_t;

stack_t* sinit() {
  stack_t *s = malloc(sizeof(stack_t));
  if (!s) return NULL;

  s->top = -1;
  return s;
}

bool is_empty(stack_t *s) {
  return (s->top == -1);
}

void push(stack_t *s, int val) {
  s->data[++s->top] = val;
}

int pop(stack_t *s) {
  return s->data[s->top--];
}

int peek(stack_t *s) {
  return s->data[s->top];
}

void sfree(stack_t *s) {
  free(s);
}
/* =========================================================*/

/* struct to define queue - using two stack */
typedef struct {
  stack_t *main;
  stack_t *sub;
} MyQueue;

// time complexity - O(1), space complexity - O(1)
MyQueue* myQueueCreate() {
  MyQueue *q = malloc(sizeof(MyQueue));
  if (!q) return NULL;

  q->main = sinit();
  q->sub = sinit();
  return q;    
}

// time complexity - O(N), space complexity - O(N)
void myQueuePush(MyQueue* obj, int x) {
  // if stack is empty, then just push the elements
  if (is_empty(obj->main)) {
    return push(obj->main, x);
  }

  // move all the elements from main to sub stack
  while (!is_empty(obj->main))
    push(obj->sub, pop(obj->main));
  
  // add the new element to main stack
  push(obj->main, x);

  // finally move all the elements from sub to main stack
  while (!is_empty(obj->sub))
    push(obj->main, pop(obj->sub));
}

// time complexity - O(1), space complexity - O(1)
int myQueuePop(MyQueue* obj) {
  return pop(obj->main);    
}

// time complexity - O(1), space complexity - O(1)
int myQueuePeek(MyQueue* obj) {
  return peek(obj->main);    
}

// time complexity - O(1), space complexity - O(1)
bool myQueueEmpty(MyQueue* obj) {
  return is_empty(obj->main);
}

void myQueueFree(MyQueue* obj) {
  sfree(obj->main);
  sfree(obj->sub);
  free(obj); 
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
