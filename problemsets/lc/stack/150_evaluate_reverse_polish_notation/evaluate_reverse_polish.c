#define SIZE 10000

typedef struct {
  int top;
  int val[SIZE];
} stack_t;

bool is_empty(stack_t *s) {
  return s->top == -1;
}

void push(stack_t *s, int val) {
  s->val[++s->top] = val;
}

int pop(stack_t *s) {
  return s->val[s->top--];
}

stack_t* init() {
  stack_t *s = malloc(sizeof(stack_t));
  if (!s) return NULL;
  
  s->top = -1;
  return s;
}

/////////////////////////////////////////////////////////////////////////////
int str_to_unsigned(char *str) {
  int val = 0;

  while (*str) {
    val = val * 10 + (*str - '0');
    str++;
  }
  return val;
}

int str_to_int(char *str) {
  return *str == '-' ? -str_to_unsigned(str + 1) : str_to_unsigned(str);
}

bool is_operator(char *oper) {
  return (oper[0] == '+' || strcmp(oper, "-") == 0 || oper[0] == '*' || oper[0] == '/');
}

int evaluate(char oper, int opnd1, int opnd2) {
  switch (oper) {
    case '+': return opnd1 + opnd2; 
    case '-': return opnd1 - opnd2;
    case '*': return opnd1 * opnd2;
    case '/': return (opnd1 / opnd2);
  }
  return 0;
}


// PROBLEM -> https://leetcode.com/problems/evaluate-reverse-polish-notation/
// time complexity  -> O(N) 
// space complexity -> O(N)

// for evaluation of polish notation (prefix expression), start the loop from the
// end and move towards start, everything remains the same.
int evalRPN(char** tokens, int tokensSize) {
  stack_t *stack = init();

  for (int idx = 0; idx < tokensSize; idx++) {
    // if operator, then pop two values from the stack and evaluate it
    // push back the result to the stack
    if (is_operator(tokens[idx])) {
      int opnd2 = pop(stack);
      int opnd1 = pop(stack);
      push(stack, evaluate(tokens[idx][0], opnd1, opnd2));
    }
    else {
      // if operand, then convert to int and push it to the stack
      push(stack, str_to_int(tokens[idx]));
    }
  }

  // the final value in the stack, the the result of evaluation
  return pop(stack);  
}
