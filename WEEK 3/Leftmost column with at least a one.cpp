/*

(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in
non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. 
If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

1. BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
2. BinaryMatrix.dimensions() returns a list of 2 elements [m, n], which means the matrix is m * n.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions 
that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples.
You will not have access the binary matrix directly.

 

Example 1:

https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-5.jpg

Input: mat = [[0,0],[1,1]]
Output: 0
Example 2:
https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-4.jpg


Input: mat = [[0,0],[0,1]]
Output: 1
Example 3:
https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-3.jpg


Input: mat = [[0,0],[0,0]]
Output: -1
Example 4:
https://assets.leetcode.com/uploads/2019/10/25/untitled-diagram-6.jpg


Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.
   Hide Hint #1  
1. (Binary Search) For each row do a binary search to find the leftmost one on that row and update the answer.
   Hide Hint #2  
2. (Optimal Approach) Imagine there is a pointer p(x, y) starting from top right corner. p can only move left or down. 
   If the value at p is 0, move down. If the value at p is 1, move left. Try to figure out the correctness and time complexity 
   of this algorithm.
*/


/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int srch (BinaryMatrix &binaryMatrix,int i,int low,int high){
        if(low>high) return -1;
        
        int mid=(high-low)/2 +low;
        int k=binaryMatrix.get(i,mid);
        int prev=0;
        if(mid>=1)
            prev=binaryMatrix.get(i,mid-1);
        
        if(k==1 && prev==0){
            return mid;
        }else if(prev==1){
            return srch(binaryMatrix,i,low,mid-1);
        }
            return srch(binaryMatrix,i,mid+1,high);
        
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int> dim=binaryMatrix.dimensions();
        int sol=dim[1];
        int curr=dim[1]-1;
        for(int i=0;i<dim[0];i++){
            int val=binaryMatrix.get(i,curr);
            if(val==0){
                continue;
            }else{
                curr=srch(binaryMatrix,i,0,curr);
                sol=min(sol,curr);
                curr--;
                if(sol==0) return 0;
            }
            
        }
        if(sol==dim[1]) return -1;
        return sol;
    }
};
   
