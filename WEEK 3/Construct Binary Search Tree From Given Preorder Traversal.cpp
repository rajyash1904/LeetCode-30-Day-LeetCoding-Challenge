/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Note: 

1 <= preorder.length <= 100
The values of preorder are distinct.
*/

class Solution {
public:
    TreeNode* cons(TreeNode* root, int k){
        if(root==NULL){
            root=new TreeNode(k);
        }else if(root->val>k){
            root->left=cons(root->left,k);
        }else if(root->val<k){
            root->right=cons(root->right,k);
        }
        return root;
        
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode * root= cons(root,preorder[0]);
        for(int i=1;i<preorder.size();i++){
            cons(root,preorder[i]);
        }
        return root;
    }
};
