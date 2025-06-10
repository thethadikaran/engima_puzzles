// PROBLEM -> https://leetcode.com/problems/add-two-numbers-ii/
// TIME COMPLEXITY  -> O(M + N)   ; M & N - size of lists1 and lists2
// SPACE COMPLEXITY -> O(M + N)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define SIZE 101    // stack size limit

 struct stack {
  int ele[SIZE];
  int top;
 };


 bool is_s_full(struct stack *s) {
  return (s->top >= SIZE);
 }

 bool is_s_empty(struct stack *s) {
  return (s->top <= 0);
 }

 void spush(struct stack *s, int val) {
  if (is_s_full(s)) return;

  s->top++;
  s->ele[s->top] = val;
 }

 int spop(struct stack *s) {
  if (is_s_empty(s)) return -1;

  int val = s->ele[s->top];
  s->top--;

  return val;
 }



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct stack s1; s1.top = 0;
  struct stack s2; s2.top = 0;
  struct stack res; res.top = 0;

  struct ListNode *tot = malloc(sizeof(struct ListNode));
  struct ListNode *tptr = tot;

  // add the elements form the list to stack
  while (l1 || l2) {
    if (l1) {
      spush(&s1, l1->val);
      l1 = l1->next;
    }
  
    if (l2) {
      spush(&s2, l2->val);
      l2 = l2->next;
    }
  }

  int sum, carry = 0;

  // pop elements from the stacks, add and push sum to res stack
  while (!is_s_empty(&s1) || !is_s_empty(&s2) || carry) {
    sum = 0;
    if (!is_s_empty(&s1)) {
      sum += spop(&s1);
    }

    if (!is_s_empty(&s2)) {
      sum += spop(&s2);
    }

    sum += carry;
    carry = sum / 10;
    spush(&res, sum % 10);
  }

  // pop the res stack and populate it into a linkedlist
  while (!is_s_empty(&res)) {
    struct ListNode *tmp = malloc(sizeof(struct ListNode));
    tmp->val = spop(&res);

    tot->next = tmp;
    tot = tmp;
  }

  // marking the last nodes next reference
  tot->next = NULL;

  // ignoring the dummy node, total starts from the next node
  return stptr->next;    
}
