/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

*/

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
public:
    bool fill(vector<vector<char>>& grid,int x,int y){
        if(x<0 ||y<0 || x>=grid.size() || y>=grid[x].size()) return false;
        if(grid[x][y]!='1'){
            return false;
        }
        
        grid[x][y]='-';
        
        bool x1=fill(grid,x+1,y);
    
        bool x2=fill(grid,x-1,y);
    
        bool x3=fill(grid,x,y+1);
    
        bool x4=fill(grid,x,y-1);
        
        return true;
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
      
        int sol=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(fill(grid,i,j)) {
                        sol++;
                }
            }
        }
        return sol;
    }
};
