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
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        
        //middle
        ListNode* slow = head; ListNode* fast = head;
        while(fast -> next && fast -> next -> next){ 
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        //Reverse
        ListNode *prev = nullptr, *curr = slow -> next;
        slow -> next = nullptr;
        while(curr){
            ListNode* nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }

        ListNode *a = head, *b = prev;
        while(b){
            ListNode* na = a -> next;
            ListNode* nb = b -> next;
            a -> next = b;
            b -> next = na;
            a = na;
            b = nb;
        }
    }
};
