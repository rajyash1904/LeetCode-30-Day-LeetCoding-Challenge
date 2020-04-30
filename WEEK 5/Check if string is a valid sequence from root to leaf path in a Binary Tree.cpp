/*

Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given 
string is a valid sequence in such binary tree. 

We get the given string from the concatenation of an array of integers arr and the concatenation of all values
of the nodes along a path results in a sequence in the given binary tree.

 
Example 1:

https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_1.png

Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true
Explanation: 
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
Other valid sequences are: 
0 -> 1 -> 1 -> 0 
0 -> 0 -> 0
Example 2:

https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_2.png

Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
Output: false 
Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.
Example 3:

https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_3.png

Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
Output: false
Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.
 

Constraints:

1. 1 <= arr.length <= 5000
2. 0 <= arr[i] <= 9
3. Each node's value is between [0 - 9].
 
   Hide Hint #1  
Depth-first search (DFS) with the parameters: current node in the binary tree and current position in the array of integers.
   
   Hide Hint #2  
When reaching at final position check if it is a leaf node.
*/



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
    bool check(TreeNode* node, vector<int>& arr, int idx) {
        if (node == NULL) return false;
        if (node->val != arr[idx]) return false;
        if (idx + 1 == arr.size())
            return node->left == NULL && node->right == NULL;
        return check(node->left, arr, idx+1) || check(node->right, arr, idx+1);
    }

    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return check(root, arr, 0);
    }
};
