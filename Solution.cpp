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
        int carry = 0;
        ListNode* temp = nullptr;
        ListNode* head = new ListNode(l1->val + l2->val + carry);
        head->next = temp;
        temp = head;

        if (head->val >= 10) {
            head->val = head->val % 10;
            carry = 1;
        }
        else {
            carry = 0;
        }

        l1 = l1->next;
        l2 = l2->next;

        while (l1 && l2) {
            temp->next = new ListNode(l1->val + l2->val + carry);
            temp = temp->next;

            if (temp->val >= 10) {
                temp->val = temp->val % 10;
                carry = 1;
            }
            else {
                carry = 0;
            }

            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            temp->next = new ListNode(l1->val + carry);
            temp = temp->next;

            if (temp->val >= 10) {
                temp->val = temp->val % 10;
                carry = 1;
            }
            else {
                carry = 0;
            }

            l1 = l1->next;
        }
        while (l2) {
            temp->next = new ListNode(l2->val + carry);
            temp = temp->next;

            if (temp->val >= 10) {
                temp->val = temp->val % 10;
                carry = 1;
            }
            else {
                carry = 0;
            }

            l2 = l2->next;
        }
        
        if (carry == 1) {
            temp->next = new ListNode(carry);
            temp = temp->next;
        }

        return head;
    }
};