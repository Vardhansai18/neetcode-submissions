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

        int sum = 0 , rem = 0;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while( l1 != NULL && l2 != NULL )
        {
            int sum = l1->val + l2->val + rem;
            rem = sum / 10;
            ListNode* newNode = new ListNode(sum%10);
            if( head == NULL && tail == NULL )
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while( l1 != NULL  )
        {
            int sum = l1->val + rem;
            rem = sum / 10;
            ListNode* newNode = new ListNode(sum%10);
            if( head == NULL && tail == NULL )
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            l1 = l1->next;
        }

        while( l2 != NULL  )
        {
            int sum = l2->val + rem;
            rem = sum / 10;
            ListNode* newNode = new ListNode(sum%10);
            if( head == NULL && tail == NULL )
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            l2 = l2->next;
        }

        while( rem != 0 )
        {
            ListNode* newNode = new ListNode( rem % 10 );
            rem = rem / 10;
            tail->next = newNode;
            tail = newNode;
        }
        return head;
    }
};
