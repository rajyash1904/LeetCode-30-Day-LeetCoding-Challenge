/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose 
sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
1. The length of the array is in range [1, 20,000].
2. The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
   
   Hide Hint #1  
Will Brute force work here? Try to optimize it.
   
   Hide Hint #2  
Can we optimize it by using some extra space?
   
   Hide Hint #3  
What about storing sum frequencies in a hash table? Will it be useful?
   
   Hide Hint #4  
sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1.
Can we use this property to optimize it.

*/

//solution 1  Accepted but Time: O(N^2)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sol=0;
        int n=nums.size();
        
        int sum[n+1];
        
        
        //if(sum[0]==k) sol++;
        sum[0]=0;
        for(int i=1;i<n+1;i++){
            
            sum[i]=sum[i-1]+nums[i-1];
            if(sum[i]==k) sol++;
        }
        for(int i=1;i<n+1;i++){
            for(int j=i+1;j<n+1;j++){
                int curr=sum[j]-sum[i];
                if(curr==k) sol++;
                    
            }
        }
        
        
        return sol;
    }
};
