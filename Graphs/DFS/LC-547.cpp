/*LC-547 Number of Provinces*/

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
        queue<int>q;
        visited[node]=true;
        q.push(node);
        while(!q.empty()) {
            int a=q.front();
            q.pop();
            for(int i=0;i<isConnected.size();i++) {
                if(isConnected[a][i]==1 && !visited[i]) {
                    dfs(isConnected,visited,i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        vector<bool>visited(isConnected.size(), false);
        for(int i=0;i<isConnected.size();i++) {
            if(!visited[i]) {
                count++;
                dfs(isConnected,visited,i);
            }
        }
        return count;
    }
};
