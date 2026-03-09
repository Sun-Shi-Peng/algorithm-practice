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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return;

        //1.找到链表的中间节点 --- 快慢双指针(一定画图考虑 slow 的落点)
        ListNode* slow = head;    //慢指针
        ListNode* fast = head;    //快指针
        while (fast && fast->next) //最终slow指向中间节点
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //2.把后面的部分逆序 --- 头插法、多指针
        ListNode* head2 = new ListNode(0);
        ListNode* cur = slow->next;
        slow->next = nullptr; //注意把两个链表断开
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = head2->next;
            head2->next = cur;

            cur = next;
        }

        //3.合并两个链表 --- 双指针
        ListNode* ret = new ListNode(0);
        ListNode* prev = ret;
        ListNode* cur1 = head, * cur2 = head2->next;
        while (cur1)
        {
            //先放第一个链表
            prev->next = cur1;
            cur1 = cur1->next;
            prev = prev->next;

            //再放第二个链表
            if (cur2)
            {
                prev->next = cur2;
                cur2 = cur2->next;
                prev = prev->next;
            }
        }
        delete head2;
        delete ret;
    }
};