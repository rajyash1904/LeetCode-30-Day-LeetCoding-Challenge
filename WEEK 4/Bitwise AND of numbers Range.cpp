/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0

*/
//For Explanation of Solution: https://www.geeksforgeeks.org/bitwise-and-or-of-a-range/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(m<n){
            
            n-=n &-n;
        }
        return n;
    }
};
auto gucciGang = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
