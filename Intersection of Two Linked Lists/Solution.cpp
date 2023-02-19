// Question: 

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* startA = headA, *startB = headB, *longH, *shortH;
        long cnt, lenA = 0, lenB=0;

        while (startA || startB) {
            if (startA) {
                lenA++;
                startA = startA->next;
            }
            if (startB) {
                lenB++;
                startB = startB->next;
            }
        }

        if (lenA==0 || lenB==0) { return NULL; }

        if (lenA > lenB) {
            cnt = lenA-lenB;
            longH = headA;
            shortH = headB;
        } else if (lenB > lenA) {
            cnt = lenB-lenA;
            longH = headB;
            shortH = headA;
        } else {
            cnt = lenA-lenB;
            longH = headA;
            shortH = headB;
        }

        while (longH && shortH) {
            if (cnt>0) {
                longH = longH->next;
                cnt--;
            } else if (longH == shortH) {
                return longH;
            } else {
                longH = longH->next;
                shortH = shortH->next;
            } 
        }

        return NULL;
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
    
    ListNode* list2 = NULL;
    push(&list2, 5);
    push(&list2, 6);
    push(&list2, 1);
    
    list2->next->next->next = list1->next->next;
    
    cout << (sol.getIntersectionNode(list1, list2))->val << endl;
    
    return 0;
}
