/*LC-547. Number of Provinces*/

class Solution {
public:
    void bfs(int src, vector<bool>& visited, vector<vector<int>>& connected) {
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            for(int i=0;i<connected.size();i++) {
                if(connected[node][i]==1 && !visited[i]) {
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(),0);
        int count=0;
        for(int i=0;i<isConnected.size();i++) {
            if(!visited[i]) {
                count++;
                bfs(i,visited,isConnected);
            }
        }
        return count;
    }
};
