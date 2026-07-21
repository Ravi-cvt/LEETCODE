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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; 
            curr->next = prev;               
            prev = curr;                    
            curr = nextTemp;                
        }
        
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* firstHalfHead = head;
        ListNode* secondHalfHead = reverseList(slow->next);

        ListNode* p1 = firstHalfHead;
        ListNode* p2 = secondHalfHead;
        bool isPalin = true;

        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                isPalin = false;
                break; 
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        slow->next = reverseList(secondHalfHead);

        return isPalin;
    }
};