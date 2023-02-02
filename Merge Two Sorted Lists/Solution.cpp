// Question: https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL) {return NULL;}
        else if (list1 == NULL) {return list2;}
        else if (list2 == NULL) {return list1;}

        ListNode *result = new ListNode();
        if(list1->val < list2->val) { 
            result->val = list1->val;
            result->next = mergeTwoLists(list1->next, list2);
        }
        else {
            result->val = list2->val;
            result->next = mergeTwoLists(list1, list2->next);
        }
        
        return result;
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
    push(&list1, 4);
   
    ListNode* list2 = NULL;
    /* Use push() to construct below list
    1->3->4 */
    push(&list2, 1);
    push(&list2, 3);
    push(&list2, 4);
   
    ListNode* result = sol.mergeTwoLists(list1, list2);
    while (result->next != NULL) {
       cout << result->val << "->";
       result = result->next;
    }
    
    cout << result->val << endl;
   
    return 0;
}
