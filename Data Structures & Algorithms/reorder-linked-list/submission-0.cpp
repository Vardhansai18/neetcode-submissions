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
    ListNode* reverseLinkedList( ListNode* head )
    {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while( temp != NULL )
        {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    pair<ListNode*,ListNode*> middleLinkedList( ListNode* head )
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        while( fast && fast->next )
        {
            temp  = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        // cout << slow->val << endl;
        // cout << temp->val << endl;
        return { slow , temp };

    }

    void print( ListNode* node )
    {
        while( node )
        {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
        return;
    }
    void reorderList(ListNode* head) {
        if( head->next == NULL  ) return;
        pair<ListNode*,ListNode*> middle = middleLinkedList( head );
        middle.second->next = NULL;
        ListNode* firstNode = head;
        ListNode* secondNode = middle.first;
        // cout << "secondNode" << secondNode->val << endl;

        print( firstNode );
        cout << endl;
        print( secondNode ); 

        // ListNode* List1 = reverseLinkedList( firstNode );
        ListNode* List1 = firstNode;
        ListNode* List2 = reverseLinkedList( secondNode );

        print( List1 );
        cout << endl;
        print( List2 ); 

        ListNode* dum = new ListNode(-1);

        ListNode* res = dum;
        ListNode* temp = NULL;
        while( List1 && List2 )
        {
            dum->next = List1;
            temp = List1->next;
            dum = dum->next;
            List1 = List1->next;

            temp = List2->next;
            dum->next = List2;
            dum = dum->next;
            List2 = List2->next;
        }
        head = res->next;
        // return res;
    }
};