/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/

//Solution 1:

class Solution {
public:
    int search(vector<int>& A,int l,int r,int k){
        if(l>r) return -1;
        int mid=(r-l)/2 + l;
        
        if(A[mid]==k) return mid;
        if(A[mid]>k) return search(A,l,mid-1,k);
        return search(A,mid+1,r,k);
    }
    
    int find(vector<int>& A,int l,int r){
        if(l>r) return -1;
        
        if(l==r) return r;
        
        int mid= (r-l)/2+l;
        
        if(mid<r && A[mid]>A[mid +1]) return mid;
        
        if(mid>l && A[mid]<A[mid-1]) return mid-1;
        
        if(A[l]>=A[mid]) return find(A,l,mid-1);
         
        return find(A,mid+1,r);
    }
    
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        int pivot=find(nums,0,n-1);
       
        if(pivot==-1) return search(nums,0,n-1,target);
        
        if(nums[pivot]==target) return pivot;
        
        if(nums[0]>target) return search(nums,pivot+1,n-1,target);
        else return search(nums,0,pivot,target);
    }
};

