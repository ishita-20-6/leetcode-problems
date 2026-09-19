/*LC-827 Making a Large Island*/

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited, int id) {
        visited[r][c]=true;
        grid[r][c]=id;
        int area=1;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1 && !visited[nr][nc]) {
                area+=dfs(grid,nr,nc,visited,id);
            }
        }
        return area;
    }
    int largestIsland(vector<vector<int>>& grid) {
        map<int, int>mp;
        int id=2;
        int result=0;
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    int area=dfs(grid,i,j,visited,id);
                    mp[id]=area;
                    result=max(result,area);
                    id++;
                }
            }
        }
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==0) {
                    set<int>st;
                    int dr[]={-1,1,0,0};
                    int dc[]={0,0,-1,1};
                    for(int k=0;k<4;k++) {
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]!=0) {
                            st.insert(grid[nr][nc]);
                        } 
                    }
                    int res=1;
                    for(int x : st) {
                        res+=mp[x];
                    }
                    result=max(result,res);
                }
            }
        }
        return result;
    }
};
