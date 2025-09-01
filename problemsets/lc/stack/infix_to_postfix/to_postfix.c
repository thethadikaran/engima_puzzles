#define ST_SIZE 300

typedef struct {
  int top;
  char oper[ST_SIZE];
} stack_t;

stack_t* stack_init() {
  stack_t *s = malloc(sizeof(stack_t));
  if (!s) return NULL;
  
  s->top = -1;
  return s;
}

bool stack_empty(stack_t *s) {
  return (s->top == -1);
}

bool stack_push(stack_t *s, char val) {
  if (!s) return false;
  
  s->oper[++s->top] = val;
  return true;
}

char stack_peek(stack_t *s) {
  return s->oper[s->top];
}

char stack_pop(stack_t *s) {
  if (!s || stack_empty(s)) return '\0';
  
  return s->oper[s->top--];
}

/////////////////////////////////////////////////////////

bool is_operator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')');
}

int priority(char oper) {
  switch (oper) {
    case '(': return 0;
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    case '^': return 3;

    default: return 0;   // invalid operator
  }
}










/* CONVERT INFIX TO POSTFIX NOTATION */
char* to_reverse_polish_notation(char *infix) {
  char *postfix = malloc(strlen(infix) * sizeof(char) + 1);   // +1 for NULL character
  if (!postfix) return NULL;
  
  stack_t *oper_stk = stack_init();     // stack to hold the operators
  int p_idx = 0;                         // keep track of index in postfix string
  
  for (int i = 0; infix[i] != '\0'; i++) {
    char curr = infix[i];
    
    // I. if curr is operand, than update the postfix string
    if (!is_operator(curr)) {
      postfix[p_idx++] = curr;
      continue;
    }
    
    // II. if curr is operator
    if (curr == '(') {
      // if it's opening bracket, then update it to the stack
      stack_push(oper_stk, curr);
    }
    else if (curr == ')') {
      // if it's a closing bracket, then pop all the operators till opening bracket '('
      // and update those in postfix string
      while (!stack_empty(oper_stk) && stack_peek(oper_stk) != '(')
        postfix[p_idx++] = stack_pop(oper_stk);
      
      // finally pop the opening bracket;
      stack_pop(oper_stk);
    }
    else {
      // operators -> other than brackets
      // pop operators that are having higher priority & equal priority than curr
      // oprator and update the postfix string
      while (!stack_empty(oper_stk) && priority(stack_peek(oper_stk)) >= priority(curr))
        postfix[p_idx++] = stack_pop(oper_stk);
        
      // lastly add the curr operator into the stack
      stack_push(oper_stk, curr);
    }
  }
  
  // update the postfix string with leftover operators in stack
  while (!stack_empty(oper_stk)) 
    postfix[p_idx++] = stack_pop(oper_stk);
    
  // finally update the string termination character
  postfix[p_idx] = '\0';
  
  return postfix;
}

