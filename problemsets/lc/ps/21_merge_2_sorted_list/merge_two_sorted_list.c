// PROBLEM ->  https://leetcode.com/problems/merge-two-sorted-lists/
// TIME COMPLEXITY  -> O(M + N)    ; M - size of list1, N - size of list2
// SPACE COMPLEXITY -> O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  // create a dummy node to act as the head node
  struct ListNode *merged = malloc( sizeof(struct ListNode) );
  merged->next = NULL;

  struct ListNode *lptr = merged;

  // when elements are present in both the lists
  while (list1 && list2) {
    if (list1->val < list2->val) {
      lptr->next = list1;
      list1 = list1->next;   // update the list1
    } else {
      lptr->next = list2;
      list2 = list2->next;   // update the list2
    }

    lptr = lptr->next;      // update the merged list
  }

  // if there were any left over elements in list1 or list2
  // then update that with the merged list
  lptr->next = list1 != NULL ? list1 : list2;

  return merged->next;    
}
