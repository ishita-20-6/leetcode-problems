/*LC-841 Keys and Rooms*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        vector<int>visited(rooms.size(),false);
        q.push(0);
        visited[0]=true;
        while(!q.empty()) {
            int a=q.front();
            q.pop();
            for(int i : rooms[a]) {
                if(!visited[i]) {
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        for(int i=0;i<rooms.size();i++) {
            if(!visited[i]) return false;
        }
        return true;
    }
}; 
