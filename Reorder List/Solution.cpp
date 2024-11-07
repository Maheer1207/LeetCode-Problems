// Question: https://leetcode.com/problems/reorder-list/description/

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
    void reorderList(ListNode* head) {
        stack<ListNode*> ll;
        ListNode *itr = head;

        while (itr != NULL) {
            ll.push(itr);
            itr = itr->next;
        }

        int n = ll.size();
        int cnt=0, stCnt=0;
        itr = head;
        ListNode *temp = itr->next;

        while (cnt<n) {
            if (stCnt <= (n/2)) {
                itr->next = ll.top();
                itr = itr->next;
                itr->next = nullptr;
                ll.pop();
                stCnt++;
                cnt++;
            }

            if (cnt<n) {
                itr->next = temp;
                itr = itr->next;
                cnt++;

                temp = temp->next;
            }
        }
        
        itr->next = NULL;
    }
};
 
int main()
{
    Solution sol;

    ListNode* list1 = NULL;
    
    push(&list1, 1);
    push(&list1, 2);
    push(&list1, 3);
    push(&list1, 4);
    
    cout << sol.reorderList(list1) << endl;
    
    return 0;
}
