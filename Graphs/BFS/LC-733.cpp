/* LC-733 Flood Fill*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original=image[sr][sc];
        if(original==color) return image;
        queue<pair<int, int>>q;
        q.push({sr, sc});
        image[sr][sc]=color;
        vector<vector<int>>ans;
        while(!q.empty()) {
            int size=q.size();
            vector<int>arr;
            for(int i=0;i<size;i++) {
                auto [r, c]=q.front();
                q.pop();
                int dr[]={-1, 1, 0, 0};
                int dc[]={0, 0, -1, 1};
                for(int j=0;j<4;j++) {
                    int nr=r+dr[j];
                    int nc=c+dc[j];
                    if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size() && image[nr][nc]==original) {
                        image[nr][nc]=color;
                        q.push({nr,nc});
                    }
                }
            }
            // return image;
        }
        return image;
    }
};
