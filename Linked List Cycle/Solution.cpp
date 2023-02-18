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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
    }
};
 
 
int main()
{
    Solution sol;

    ListNode* list1 = NULL;
    
    push(&list1, 2);
    push(&list1, 4);
    push(&list1, 3);
    
    list1->next->next->next = list1->next;
    
    cout << sol.hasCycle(list1) << endl;
    
    return 0;
}
