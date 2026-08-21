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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dum = new ListNode( -1 , head );
        ListNode* slow = dum;
        ListNode* fast = dum;
        for( int i = 0 ; i < n ; i++ )
        {
            fast = fast->next;
        }
        while( fast->next != NULL )
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dum->next;
    }
};


/*
Question:
1|200  2|300  3|400  4|NULL
 100    200    300.  400
         s             f   
  
n = 2

Output:
1|200  2|400    4|NULL
 100    200     400

dum -1|100
      500

1|200  2|300  3|400  4|NULL
 100    200    300.  400
*/

 

