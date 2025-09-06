// PROBLEM -> https://leetcode.com/problems/min-stack/description/
// time complexity  -> O(1)  ; for all the functions
// space complexity -> O(N)  ; N no of elements pushed

/* HINT: Consider each node in the stack having a minimum value */

#define STK_SIZE 300000

typedef struct {
  int val;
  int min;
} node_t;

typedef struct {
  int top;
  node_t data[STK_SIZE];    
} MinStack;


MinStack* minStackCreate() {
  MinStack *s = malloc(sizeof(MinStack));

  s->top = -1;
  return s;    
}

bool stackEmpty(MinStack *obj) {
  return obj->top == -1;
}

void minStackPush(MinStack* obj, int val) {
  // identify the min value
  int min;
  if (stackEmpty(obj)) min = val;
  else min = val < obj->data[obj->top].min ? val : obj->data[obj->top].min;

  // udpate the value
  obj->top++;        // increment the top pointer

  obj->data[obj->top].val = val;
  obj->data[obj->top].min = min;    
}

void minStackPop(MinStack* obj) {
  if (stackEmpty(obj)) return;
  obj->top--;  
}

int minStackTop(MinStack* obj) {
  if (stackEmpty(obj)) return '\0';
  return obj->data[obj->top].val;    
}

int minStackGetMin(MinStack* obj) {
  if (stackEmpty(obj)) return '\0';
  return obj->data[obj->top].min;    
}

void minStackFree(MinStack* obj) {
  free(obj);    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
