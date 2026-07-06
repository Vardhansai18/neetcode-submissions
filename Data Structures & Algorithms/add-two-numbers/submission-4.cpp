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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int sum = 0 , carr = 0;
        ListNode* dum = new ListNode(-1);
        ListNode* curr = dum;
        while( l1 != NULL || l2 != NULL || carr != 0 )
        {
            sum = carr;
            if( l1!= NULL )
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if( l2 != NULL )
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carr = sum / 10;
            dum->next = new ListNode(sum % 10);
            dum = dum->next;
        }
        return curr->next;
    }
};
