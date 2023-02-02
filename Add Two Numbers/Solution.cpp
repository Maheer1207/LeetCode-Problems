// Question: https://leetcode.com/problems/add-two-numbers/description/

#include <iostream>
#include <iterator>
#include <list>

using namespace std;
 
 
class ListNode {
public:
    int val = 1;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL and l2 == NULL) {return NULL;}
        else if (l1 == NULL) {return l2;}
        else if (l2 == NULL) {return l1;}
        
        int a = l1->val + l2->val;
		ListNode *p = new ListNode();
        p->val = a % 10;
		p->next = addTwoNumbers(l1->next,l2->next);
        if (a >= 10) {p->next = addTwoNumbers(p->next, new ListNode());}
        return p;
    }
};
 
 
int main()
{
    Solution sol;

    ListNode* list1 = NULL;
    
    push(&list1, 2);
    push(&list1, 4);
    push(&list1, 3);
   
    ListNode* list2 = NULL;
    
    push(&list2, 5);
    push(&list2, 6);
    push(&list2, 4);
    
    ListNode* result = sol.addTwoNumbers(list1, list2);
    while (result->next != NULL) {
       cout << result->val << "->";
       result = result->next;
    }
    
    cout << result->val << endl;
   
    return 0;
}
