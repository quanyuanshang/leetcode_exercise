#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 前序遍历
class Solution
{
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
// 中序遍历
class Solution
{
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;

        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
// 后序
class Solution
{
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;

        traversal(cur->left, vec);

        traversal(cur->right, vec);
        vec.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
// 非递归遍历
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *node;
        while (!st.empty())
        {
            node = st.top();
            st.pop();
            if (node != nullptr)
            {
                result.push_back(node->val); // 中
            }
            else
            {
                continue;
            }
            st.push(node->right); // 右
            st.push(node->left);  // 左
        }
        return result;
    }
};
class Solution // 后续遍历
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *node;
        while (!st.empty())
        {
            node = st.top();
            st.pop();
            if (node != nullptr)
            {
                result.push_back(node->val); // 中
            }
            else
            {
                continue;
            }

            st.push(node->left);  // 左
            st.push(node->right); // 右
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
class Solution // 后续中序
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};

// 层序遍历
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        queue<TreeNode *> que;
        TreeNode *node;
        int layer = 0;
        int min_layer = INT_MAX;
        if (root != NULL)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size(); // 不记录的话容易和下一层的元素一起弹出来，这是控制弹出数目
            vector<int> vec;
            layer++;
            while (size--) // 在循环里que的size是不断变化的
            {
                node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                if (!node->right && !node->left)
                {
                    if (min_layer >= layer)
                        min_layer = layer;
                }
            }
        }
        return min_layer == INT_MAX ? 0 : min_layer;
    }
};
// 翻转二叉树
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr) // root是指操作的变量
            return root;
        swap(root->left, root->right); // 中
        invertTree(root->left);        // 左
        invertTree(root->right);       // 右

        return root;
    }
};

// 对称二叉树
class Solution
{
public:
    bool compare(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left == nullptr && right == nullptr) // 第二层就是两个都为空就可以直接返回。
            // 剩下的内部节点由bool inside = compare(left->right, right->left)检查
            // 到最终两个节点都是空就直接返回true。
            return true;
        else if (left->val != right->val)
            return false;
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool result = outside & inside;
        return result;
    };

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return compare(root->left, root->right);
    }
};