/*LC-1376 Time needed to inform all Employee*/

class Solution {
public:
    int dfs(int employee, vector<vector<int>>& arr, vector<int>& informTime) {
        int time=0;
        for(int i : arr[employee]) {
            time=max(time,dfs(i,arr,informTime));
        }
        return informTime[employee]+time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>arr(n);
        for(int i=0;i<n;i++) {
            if(manager[i]!=-1) {
                arr[manager[i]].push_back(i);
            }
        }
        return dfs(headID,arr,informTime);
    }
};
