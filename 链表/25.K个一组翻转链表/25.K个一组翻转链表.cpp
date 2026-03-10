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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //1.先求出需要逆序多少组
        int n = 0;
        ListNode* cur = head;
        while (cur)
        {
            cur = cur->next;
            n++;
        }
        n /= k;   //有几组

        //2.重复n次，长度为k的链表逆序即可
        ListNode* newhead = new ListNode(0);
        ListNode* prev = newhead;
        cur = head;
        for (int i = 0; i < n; i++)
        {
            ListNode* tmp = cur;
            for (int j = 0; j < k; j++)
            {
                ListNode* next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
                cur = next;
            }
            prev = tmp;
        }
        //把不需要翻转的接上
        prev->next = cur;
        cur = newhead->next;
        delete newhead;
        return cur;
    }
};