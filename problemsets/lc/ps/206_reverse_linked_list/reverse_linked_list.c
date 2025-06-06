// PROBLEM -> https://leetcode.com/problems/reverse-linked-list/
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
  struct ListNode *prev = NULL, *curr, *next;
  curr = head;

  while (curr != NULL) {
    // store the next element link for current node
    next = curr->next;

    // update the current element's next value
    curr->next = prev;

    // updating variables to continue the loop
    prev = curr;
    curr = next;
  }

  // finally set the head to the last node
  head = prev;
  return head;   
}
