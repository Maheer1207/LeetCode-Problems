// Question: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <iostream>
#include <iterator>
#include <list>

using namespace std;
 
 
class ListNode {
public:
    int val;
    ListNode* next;
};

void push(ListNode** head_ref, int new_data)
{
    /* allocate node */
    ListNode* new_node = new ListNode();
  
    /* put in the val */
    new_node->val = new_data;
  
    /* link the old list of the new node */
    new_node->next = (*head_ref);
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = head;
        ListNode *nTH_Node = new ListNode();

        int cnt = 1;
        while (start->next != NULL) {
            start = start->next;
            cnt++;
        }

        start = head;
        cnt -= n;
        if (cnt == 0) {
            head = head->next;
            start->next = NULL;
            return head;
        }
        
        while (cnt > 1) {
            start = start->next;
            cnt--;
        }

        if (n == 1) { start->next = NULL;}
        else {
            nTH_Node = start->next;
            start->next = nTH_Node->next;
        }
        return head;
    }
};
 
 
int main()
{
    Solution sol;

    ListNode* list1 = NULL;
    /* Use push() to construct below list
    1->2->4 */
    push(&list1, 1);
    push(&list1, 2);
    push(&list1, 3);
    push(&list1, 4);
    push(&list1, 5);
    
    int n = 2;
    
    ListNode* result = sol.removeNthFromEnd(list1, n);
    while (result->next != NULL) {
       cout << result->val << "->";
       result = result->next;
    }
    
    cout << result->val << endl;
   
    return 0;
}
