/* LC-127 Word Ladder*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        set<string>visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        while(!q.empty()) {
            auto [a,b]=q.front();
            q.pop();
            if(a==endWord) return b;
            for(int i=0;i<wordList.size();i++) {
                string temp=wordList[i];
                int count=0;
                for(int j=0;j<a.size();j++) {
                    if(a[j]!=temp[j]) count++;

                }
                if(count==1 && !visited.count(temp)) {
                    visited.insert(temp);
                    q.push({temp, b+1});
                }
            }
        }
        return 0;
    }
};
