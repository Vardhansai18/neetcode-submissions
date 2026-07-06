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
    int LinkedListSize( ListNode* head )
    {
        int size = 0;
        while( head )
        {
            size++;
            head = head->next;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = LinkedListSize( head );
        int removedNodeIdx = size - n ;
        ListNode* node = head;
        if( removedNodeIdx == 0 ) return head->next;  
        while( --removedNodeIdx > 0 )
        {
            node = node->next;
        }
        if( node != NULL && node->next != NULL )
        {
            node->next = node->next->next;
        }
        return head;
        
    }
};
