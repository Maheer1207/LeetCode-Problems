// Question: https://leetcode.com/problems/reverse-linked-list/description/

#include <iostream>
#include <iterator>
#include <list>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {return head;}
        stack<ListNode*> stackLN;
        ListNode* node = head;
        while (node != NULL) {
            stackLN.push(node);
            node = node->next;
        }

        head = stackLN.top();
        node = head;

        while (!stackLN.empty()) {
            node->next = stackLN.top();
            stackLN.pop();
            node = node->next;
        }

        node->next = NULL;

        return head;
    }
};

int main()
{
    Solution sol;

    ListNode* list1 = NULL;
    push(&list1, 4);
    push(&list1, 1);
    push(&list1, 8);
    push(&list1, 4);
    push(&list1, 5);
    
    ListNode* result = sol.reverseList(list1);
    while (result->next != NULL) {
       cout << result->val << "->";
       result = result->next;
    }
    
    cout << result->val << endl;
    return 0;
}

