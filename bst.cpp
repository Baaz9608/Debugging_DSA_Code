#include <iostream>
using namespace std;
int numTrees(int n)
{
    if (n == 0 or n == 1)
        return 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += numTrees(i - 1) * numTrees(n - i);
    }
    return ans;
}

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr){};
    TreeNode():left(nullptr), right(nullptr){};
};

TreeNode *pre = nullptr, *first = nullptr, *sec = nullptr;
void inorder(TreeNode *cur)
{
    if (!cur)
    {
        return;
    }
    inorder(cur->left);
    if (pre) // this condition was missing
    {
        if (cur->val < pre->val)
        {
            if (!first)
            {
                first = pre;
            }
            sec = cur;
        }
    }
    pre = cur;
    inorder(cur->right);
}
void recoverTree(TreeNode *root)
{
    inorder(root);
    int temp = first->val;
    first->val = sec->val;
    sec->val = temp;

    // solved -> debugged
}

bool hasPathSum(TreeNode *root, int &targetSum)
{
    if (!root)
        return false;

    targetSum -= root->val;
    if (targetSum == 0 && !root->left && !root->right)
        return true;

    bool leftPath = hasPathSum(root->left, targetSum);
    bool rightPath = hasPathSum(root->right, targetSum);
    // backtracking
    targetSum += root->val;

    return leftPath || rightPath;

    // Nothing was missing 

    // debugged
}

#include <vector>

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.size() == 0)
        return NULL;
    if (nums.size() == 1) // this condition was missing
        return new TreeNode(nums[0]);
    int middle = nums.size() / 2;
    TreeNode *root = new TreeNode(nums[middle]);
    vector<int> leftsub(nums.begin(), nums.begin() + middle);
    vector<int> rightsub(nums.begin() + middle + 1, nums.end()); //middle+1 was missing in this line
    root->left = sortedArrayToBST(leftsub);
    root->right = sortedArrayToBST(rightsub);
    return root;

    // done
}

TreeNode *ans = new TreeNode();
TreeNode *solve(vector<int> &node, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e)>>1;
    TreeNode *p = new TreeNode(node[mid]);

    p->left = solve(node, s, mid-1); //mid -> mid -1 changes
    p->right = solve(node, mid+1, e); // mid -> mid+1 changes
    return p;
}

class ListNode{
    public:
    int val;
    ListNode*next;
    ListNode(int data):val(data), next(nullptr){};
};

TreeNode *sortedListToBST(ListNode *head)
{
    vector<int> v;
    ListNode *temp = head;
    while (temp != NULL)
    {
        v.push_back(temp->val);
        temp = temp->next;
    }
    TreeNode *tmp = new TreeNode(0);

    return solve(v, 0, v.size() - 1);

    //debugged
}

int main()
{
    // cout<<numTrees(5)<<endl;
    return 0;
}