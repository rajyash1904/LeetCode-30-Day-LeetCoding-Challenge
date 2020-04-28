/*
Maximal Square

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

*/

//standard Dynamic Progamming question.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);  
          
       int m = matrix.size();
    if(m==0) return 0;
    int n = matrix[0].size();
    
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    int ret = 0;
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            if(matrix[i-1][j-1] == '0'){
                dp[i][j] = 0;
            }else{
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
            ret = max(ret, dp[i][j]);
        }
    }
    return ret*ret;
    }
};
