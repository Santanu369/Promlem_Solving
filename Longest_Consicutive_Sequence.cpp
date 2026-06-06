#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int max_count = 1;
        int count = 1;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (s.find(nums[i]-1) == s.end()) {
                count = 1;
                int x = nums[i];
                while (s.find(x+1) != s.end())
                {
                    count ++;
                    x++;
                }
                max_count = max(max_count, count);
            }
        }
        return max_count;
        
        
    }
};

                                                     
int main() {
    vector <int> v  =  {100,4,200,1,3,2};
    Solution sol;
    cout << sol.longestConsecutive(v);
    return 0;
}