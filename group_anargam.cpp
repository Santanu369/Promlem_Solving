#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = (int) 1e18;

// eat tea both have have hash
// then use map {hash_code : [tea, ate]}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string, vector<string>> mpp;
        for (int i = 0; i < n; i++)
        {
            vector<int> v(26, 0);
            for (int j = 0; j < strs[i].size(); j++)
            { 
                v[strs[i][j]-'a'] += 1;
            }
            string s = "";
            for (int k = 0; k < 26; k++)
            {
                s+= to_string(v[k]);
                 s += '#';
            }
            if (mpp[s].size() == 0) {
                vector <string> v1 = {strs[i]};
                mpp[s] = v1;
            }
            else {
                mpp[s].push_back(strs[i]);
            }
        }
        vector<vector<string>> ans;
        for(const auto& [key, value]: mpp) {
            ans.push_back(value);
        }
        return ans;
    }
};
 
int main() {
    Solution sol;
    vector<string> v = {"bdddddddddd","bbbbbbbbbbc"};
    vector<vector<string>> ans = sol.groupAnagrams(v);
    
 
    return 0;
}