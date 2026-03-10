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
    class Less {
    public:
        bool operator()(ListNode* l1, ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, Less> heap;  //Ð¡¸ù¶Ñ

        for (auto l : lists)
        {
            if (l)
                heap.push(l);
        }

        ListNode* head = new ListNode(0);
        ListNode* prev = head;
        while (!heap.empty())
        {
            ListNode* tmp = heap.top();
            heap.pop();
            if (tmp->next)
                heap.push(tmp->next);
            prev->next = tmp;
            prev = tmp;
        }
        prev = head->next;
        delete head;
        return prev;
    }
};