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


pair<ListNode*,ListNode*> recReverseList( ListNode* head )
{
    if( head == NULL || head->next == NULL ) return { head , head } ;

    pair<ListNode*,ListNode*> new_node = recReverseList( head->next );
    ListNode* new_head = new_node.first;
    ListNode* new_tail = new_node.second;
    head->next = NULL;
    new_tail->next = head;
    return { new_head , new_tail->next };
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        pair<ListNode*,ListNode*> new_h_t = recReverseList(head);
        return new_h_t.first;
    }
};
