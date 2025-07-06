struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Ritorno true se due alberi sono uguali, false altrimenti
class Solution
{
public:
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (p != nullptr)
    {
      if (q == nullptr || p->val != q->val)
      {
        return false;
      }
      if (!isSameTree(p->left, q->left))
      {
        return false;
      }
      if (!isSameTree(p->right, q->right))
      {
        return false;
      }
    }
    else if (q != nullptr)
    {
      return false;
    }
    return true;
  }
};