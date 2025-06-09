// PROBLEM -> https://leetcode.com/problems/add-two-numbers/
// TIME COMPLEXITY  -> O(M + N)    ; M - no of digits in list1, N - no of digits in list2
// SPACE COMPLEXITY -> O(M + N)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* list1, struct ListNode* list2) {
  int carry = 0, sum = 0;

  struct ListNode *add = malloc(sizeof(struct ListNode));
  struct ListNode *lptr = add;

  while (list1 || list2 || carry) {
    sum = 0;                // reset the sum on every iteration

    if (list1) {
      sum += list1->val;
      list1 = list1->next;
    }

    if (list2) {
      sum += list2->val;
      list2 = list2->next;
    }

    sum += carry;          // calculate total sum, including the carry
    carry = sum / 10;      // update the carry
    add->val = sum % 10;   // update the sum

    if (list1 || list2 || carry) {
      struct ListNode *ls = malloc(sizeof(struct ListNode));
      add->next = ls;
      add = ls;
    }
    else
      add->next = NULL;    // if it's the last node, then update the next to NULL
  }

  return lptr;
}
