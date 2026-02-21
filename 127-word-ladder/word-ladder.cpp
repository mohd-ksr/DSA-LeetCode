class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<string>q;
        unordered_set<string>st(wordList.begin(), wordList.end());
        q.push(beginWord);
        st.erase(beginWord);
        int ans = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                string curr = q.front(); q.pop();
                int size = curr.size();
                if(curr==endWord)return ans;
                for(int i=0; i<size; i++){
                    for(int j=0; j<26; j++){
                        string temp = curr;
                        temp[i]=('a'+j);
                        if(st.find(temp)!=st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};