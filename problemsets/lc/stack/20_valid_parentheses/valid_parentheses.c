// PROBLEM: https://leetcode.com/problems/valid-parentheses/
// time complexity  -> O(N)
// space complexity -> O(N)


typedef struct {
  int top;
  char val[10000];
} stack_t;

stack_t* init() {
  stack_t *s = malloc(sizeof(stack_t));
  if (!s) return NULL;

  s->top = -1;
  return s;
}

bool is_empty(stack_t *s) {
  return (s->top == -1);
}

void push(stack_t *s, char ch) {
  s->val[++s->top] = ch;
}

int pop(stack_t *s) {
  return s->val[s->top--];
}

bool isValid(char* s) {
  // 1. total no of left parentheses == total no of right parentheses
  // 2. for every right parentheses should have a equal left parentheses
  
  stack_t *st = init();

  while (*s) {
    // for opening type parentheses, just push it to the stack
    // for closing type parentheses, pop the last element and compare
    if (*s == '{' || *s == '(' || *s == '[') {
      push(st, *s);
    } 
    else {
      if (is_empty(st)) return false;    // more no of right parentheses than left
      char last = pop(st);

      switch (*s) {
        case '}': if (last != '{') return false; break;
        case ']': if (last != '[') return false; break;
        case ')': if (last != '(') return false; break;
      }
    }

    s++;
  }

  return is_empty(st);    
}
