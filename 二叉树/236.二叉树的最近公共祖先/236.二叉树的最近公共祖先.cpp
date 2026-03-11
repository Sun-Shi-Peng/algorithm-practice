#define _CRT_SECURE_NO_WARNINGS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool Find(TreeNode* root, stack<TreeNode*>& st, TreeNode* key)
    {
        if (root == nullptr)
            return false;

        st.push(root);
        if (root == key)
        {
            return true;
        }

        if (Find(root->left, st, key) || Find(root->right, st, key))
        {
            return true;
        }
        else
        {
            st.pop();   //这条路径下没有对应值
            return false;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //使用两个栈记录查找的路径
        stack<TreeNode*> pst;
        stack<TreeNode*> qst;

        if (Find(root, pst, p) && Find(root, qst, q))
        {
            while (pst.size() != qst.size())
            {
                if (pst.size() > qst.size())
                {
                    pst.pop();
                }
                if (pst.size() < qst.size())
                {
                    qst.pop();
                }
            }
            //现在两个栈里面的数量相同
            while (!pst.empty())
            {
                if (pst.top() != qst.top())
                {
                    pst.pop();
                    qst.pop();
                }
                else
                {
                    return pst.top();
                }
            }
        }

        return nullptr;
    }
};