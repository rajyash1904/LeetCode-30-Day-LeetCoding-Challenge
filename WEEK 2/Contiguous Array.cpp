/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        vector<int> leftsum(n,-1);
        leftsum[0]=((nums[0]==0)? -1 :1);
        
        for(int i=1;i<n;i++){
          leftsum[i]=leftsum[i-1] + ((nums[i]==0)? -1:1);
        }
       
        unordered_map<int,int> hash;
        int sol=0;
        for(int i=0;i<n;i++){
            
            if(leftsum[i]==0) sol=i+1;
            
            else { if(hash.find(leftsum[i])==hash.end()){
                hash[leftsum[i]]=i;
            }else{
                sol=max(sol,i-hash[leftsum[i]]);
                }
            }
        }
        return sol;
    }
};
auto gucciGang = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
