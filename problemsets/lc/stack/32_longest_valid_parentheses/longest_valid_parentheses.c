#define STACK_SIZE 300000

typedef struct {
  int top;
  int val[STACK_SIZE];
} stack_t;

stack_t* init() {
  stack_t *s = malloc(sizeof(stack_t));
  if (!s) return NULL;

  s->top = -1;
  return s;
}

bool stack_empty(stack_t *s) {
  return s->top == -1;
}

void push(stack_t *s, int val) {
  s->val[++s->top] = val;
}

int pop(stack_t *s) {
  return s->val[s->top--];
}

int peek(stack_t *s) {
  return s->val[s->top];
}
////////////////////////////////////////////////////////////

// PROBLEM -> https://leetcode.com/problems/longest-valid-parentheses/
// time complexity  -> O(N) 
// space complexity -> O(N)

int longestValidParentheses(char* s) {
  // keep track of max valid parenthesis seen so far
  int max_len = 0;

  // initialize with -1, to handle initial case
  stack_t *stack = init();
  push(stack, -1);

  for (int i = 0; s[i] != '\0'; i++) {
    // if opening bracket, push the index to stack
    if (s[i] == '(')
      push(stack, i);
    else {
      pop(stack);

      // in case the stack is empty, then we got a unmatched closing
      // bracket. so add the index of closing bracket which will be
      // used to find the length if we have a valid parenthesis
      if (stack_empty(stack)) 
        push(stack, i);
      else {
        // if stack not empty, then we got a valid parenthesis match
        // calculate the len so far, by using the index in the top
        // of stack and the current index. This will give the length
        // of valid parenthesis seen so for
        int valid_len = i - peek(stack);

        // if the current valid length is higher than the max recorded
        // then update the max lenght
        max_len = valid_len > max_len ? valid_len : max_len;
      }
    }
  }
  return max_len;
}
