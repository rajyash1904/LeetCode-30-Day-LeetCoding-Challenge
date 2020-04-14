/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

1. All inputs will be in lowercase.
2. The order of your output does not matter.
*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> sol;
        unordered_map<string,vector<string>> hash;
        
        for(int i=0;i<strs.size();i++){
            
            string key=strs[i];
            
            sort(key.begin(),key.end());
            
            hash[key].push_back(strs[i]);
            
            
        }
        
        for(auto i : hash){
            
            sol.push_back(i.second);
        }
        return sol;
        
    }
};
