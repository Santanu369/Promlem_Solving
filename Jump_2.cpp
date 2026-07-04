#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// first we are at 0th index, test say 1st ele is 2
// then we will check all the elem we can reach(next two) and jump of that index which can take us most further
// if the elem we are jumping of is taking us most further will take us fastest poss
// this is a greegy approch 

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int max_reach = -1;
        int jump_index;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == n-1) break;
            if (nums[i]+i >= n-1) {
                ans++;
                break;
            }
            int max_reach = -1;
            for (int j = i+1; j < i+nums[i]+1; j++)
            {
                if (j > n-1) continue;
                int reach = j + nums[j];
                if (reach > max_reach) {
                    max_reach = reach;
                    jump_index = j;
                }
            }

            i = jump_index - 1;
            ans++;
        }
        return ans;
    }
};