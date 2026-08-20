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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyNode = NULL;
        while( head )
        {
            ListNode* temp = head->next;
            head->next = dummyNode;
            dummyNode = head;
            head = temp;
        }
        return dummyNode;
    }
};

/*
Given Linked List: 
0|200  -> 1|300   -> 2|400   -> 3 
 100      200         300       400   

Reversed Linked List:
3|300  -> 2|200   -> 1|100   -> 0|NUll
 400      300         200       100   




dummy Node

 NULL  ->  0|N  -> 1|100   -> 2|200   -> 3|300
           100      200         300       400 
                                           d           h
while( dum->next != NULL )
temp = head->next;
head->next = dummy;
dummy = head;
head = head->next;


Reversed Linked List:
3|300  -> 2|200   -> 1|100   -> 0|NUll
 400      300         200       100
*/    
