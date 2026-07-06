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

    pair<ListNode*,ListNode*> solve( ListNode* head )
    {
        if( head == NULL || head->next == NULL )
        {
            return { head , head };
        }
        pair<ListNode*,ListNode*> new_node = solve( head->next );
        head->next = new_node.second->next;
        new_node.second->next = head;
        return { new_node.first , head };
    }
    ListNode* reverseList(ListNode* head) {
        pair<ListNode*,ListNode*> node = solve(head);
        return node.first;
    }
};
