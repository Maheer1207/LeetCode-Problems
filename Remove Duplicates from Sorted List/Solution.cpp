//Question: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        int isHead = true;
        ListNode *first = new ListNode();
        ListNode *second = new ListNode();
        
        first = head;
        
        if (head) { second = head->next; }
        
        while (second && head) {
            if (first->val != second->val) {
                first->next = second;
                first = second;
                if (isHead) {
                    head->next = second;
                    isHead = false;
                }
                
            }
            
            second = second->next;
            first->next = NULL;
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
    push(&list1, 2);
    push(&list1, 4);
   
    ListNode* list2 = NULL;
    /* Use push() to construct below list
    1->3->4 */
    push(&list2, 1);
    push(&list2, 3);
    push(&list2, 4);
    
    ListNode* list3 = NULL;
    /* Use push() to construct below list
    1->3->4 */
    push(&list3, 3);
    push(&list3, 3);
    push(&list3, 2);
    push(&list3, 1);
    push(&list3, 1);
   
    ListNode* result = sol.deleteDuplicates(list3);
    while (result->next != NULL) {
       cout << result->val << "->";
       result = result->next;
    }
    
    cout << result->val << endl;
   
    return 0;
}
