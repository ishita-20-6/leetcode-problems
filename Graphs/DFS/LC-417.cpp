/*LC-417 Pacific Atlantic Water Flow*/

class Solution {
public:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited) {
        visited[r][c]=true;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && heights[nr][nc]>=heights[r][c] && !visited[nr][nc]) {
                dfs(heights,nr,nc,visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>>visitPacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>>visitAtlantic(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>> result;
        for(int i=0;i<heights.size();i++) {
            dfs(heights,i,0,visitPacific);
        }
        for(int j=0;j<heights[0].size();j++) {
            dfs(heights,0,j,visitPacific);
        }
        for(int i=0;i<heights.size();i++) {
            dfs(heights,i,heights[0].size()-1,visitAtlantic);
        }
        for(int j=0;j<heights[0].size();j++) {
            dfs(heights,heights.size()-1,j,visitAtlantic);
        }
        for(int i=0;i<heights.size();i++) {
            for(int j=0;j<heights[0].size();j++) {
                if(visitPacific[i][j] && visitAtlantic[i][j]) {
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};  q
