/*
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1.  1 <= prices.length <= 3 * 10 ^ 4
2.  0 <= prices[i] <= 10 ^ 4

complete function only.
*/

//solution 1.

int maxProfit(vector<int>& prices) {
        
        int profit=0,x=INT_MAX;
    
    for(int i=0;i<prices.size();++i){
        if(prices[i]<=x){
            x=prices[i];
        }
        else{
            profit+=prices[i]-x;
            x=prices[i];
        }
    }
    
    return profit;
        }
        

//solution 2 DP

int maxProfit(vector<int>& prices) {
  
    if(prices.size()<=1) return 0;
     vector<int> sol;
     int maxdif=0-prices[0];
     sol.push_back(0);
     sol.push_back(0);
     for(int i=2;i<prices.size()+1;i++){
         
         int k=max(sol[i-1],maxdif+prices[i-1]);
         sol.push_back(k);
         maxdif=max(maxdif,sol[i]-prices[i-1]);
     }
     return sol.back();
     }
