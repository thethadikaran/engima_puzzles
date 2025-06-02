// PROBLEM -> https://leetcode.com/problems/baseball-game/
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(N)

#define SIZE 1000

struct stack {
  int top;
  int element[SIZE];
};

///// FUNCTION PROTOTYPES /////
struct stack* sinit();
void push(struct stack*, int);
int pop(struct stack*);
bool is_empty(struct stack*);


///// SOLUTION /////
int calPoints(char** operations, int operationsSize) {
  // initialize stack to push in scores
  struct stack *s = sinit();

  for (int operation = 0; operation < operationsSize; operation++) {
    if (operations[operation][0] == '+') {         // check 01
      int latest = pop(s);
      int old = pop(s);
      push(s, old);
      push(s, latest);
      push(s, latest + old);
    }
    else if (operations[operation][0] == 'D') {   // check 02
      int latest = pop(s);
      push(s, latest);
      push(s, latest * 2);
    }
    else if (operations[operation][0] == 'C') {   // check 03
      pop(s);
    }
    else {                                        // finally then it's a score
      push(s, atoi(operations[operation]) );
    }
  }

  // count the score
  int score_total = 0;
  while (!is_empty(s))  score_total += pop(s);

  free(s);      // release the stack
  return score_total;    
}





///// FUNCTION DEFINITIONS /////
struct stack* sinit() {
  struct stack *s = malloc(sizeof(struct stack));
  s->top = -1;  // stack with no elements
  return s;
}

bool is_empty(struct stack *s) {
  return (s->top == -1);
}

void push(struct stack *s, int val) {
  s->top++;
  s->element[s->top] = val;
}

int pop(struct stack *s) {
  int val = s->element[s->top];
  s->top--;
  return val;
}
