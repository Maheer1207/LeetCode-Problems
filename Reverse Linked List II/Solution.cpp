// Question: https://leetcode.com/problems/reverse-linked-list-ii/description/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left==right) return head;

        ListNode *preLeft=head, *res=head, *ll=head, *prev=nullptr, *next=nullptr;
        int cnt=1;

        while (cnt < left) {
            preLeft = head;
            head = head->next;
            cnt++;
        }

        ListNode *end = head;

        while (cnt <= right) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;

            cnt++;
        }
        preLeft->next = prev;
        end->next = head;

        return left==1? prev:res;
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

    int left, right;
    cin >> left >> right >> endl;
    
    ListNode* result = sol.reverseBetween(list1);
    while (result->next != NULL) {
       cout << result->val << "->";
       result = result->next;
    }
    
    cout << result->val << endl;
    return 0;
}
