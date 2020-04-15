/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

Complete function only diameterOfBinaryTree().
*/

class Solution
{
public:

  int dia (TreeNode * root, int &height)
  {

    if (root == NULL)
      {
	return 0;
      }

    int ldia = dia (root->left, height);
    int rdia = dia (root->right, height);

    height = max (height, ldia + rdia + 1);

    return max (ldia, rdia) + 1;

  }
  
  
  int diameterOfBinaryTree (TreeNode * root)
  {

    if (root == NULL)
      return 0;
    int height = INT_MIN;

    int hans = dia (root, height);
    return height - 1;
  }
};
