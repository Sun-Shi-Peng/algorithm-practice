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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1, * cur2 = l2;
        ListNode* newhead = new ListNode(0);  //创建一个虚拟头节点，记录最终结果
        ListNode* prev = newhead; //尾指针
        int t = 0;    //记录进位

        while (cur1 || cur2 || t)
        {
            //先加上第一个链表
            if (cur1)
            {
                t += cur1->val;
                cur1 = cur1->next;
            }
            //加上第二个链表
            if (cur2)
            {
                t += cur2->val;
                cur2 = cur2->next;
            }
            prev->next = new ListNode(t % 10);
            prev = prev->next;
            t /= 10;
        }

        prev = newhead->next;
        delete newhead;
        return prev;
    }
};