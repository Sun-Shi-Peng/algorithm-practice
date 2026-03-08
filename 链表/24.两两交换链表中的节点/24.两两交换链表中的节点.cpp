#define _CRT_SECURE_NO_WARNINGS
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)   return head;

        ListNode* newhead = new ListNode(0);
        newhead->next = head;

        ListNode* prev = newhead, * cur = prev->next, * next = cur->next, * nnext = next->next;
        while (cur && next)
        {
            //交换结点
            prev->next = next;
            next->next = cur;
            cur->next = nnext;

            //修改指针
            prev = cur;
            cur = nnext;
            if (cur) next = cur->next;
            if (next) nnext = next->next;
        }
        cur = newhead->next;
        delete newhead;
        return cur;
    }
};