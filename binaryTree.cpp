#include <iostream>
#include <stack>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr){};
    TreeNode() : left(nullptr), right(nullptr){};
};

void flatten(TreeNode *root)
{
    if (!root)
        return;
    stack<TreeNode *> s;
    s.push(root); // this line was missing
    while (!s.empty())
    {
        TreeNode *cur = s.top();
        s.pop();

        if (cur->right)
            s.push(cur->right);
        if (cur->left)
            s.push(cur->left);
        if (!s.empty())
            cur->right = s.top();
        cur->left = nullptr;
    }

    // solved
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(!root) return nullptr;
    if (root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    return left ? right : right ? left
                                : root;
}

int main()
{
    return 0;
}