#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithLessK(nums, k) - subarrayWithLessK(nums, k-1);
    }

    int subarrayWithLessK(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<int, int> mpp;
        while (l <= r && r < n)
        {
            mpp[nums[r]]++;
            if (mpp.size() <= k) {
                ans += r - l + 1;
            }
            else {
                while (mpp.size() > k)
                {
                    mpp[nums[l]]--;
                    if (mpp[nums[l]] == 0) {
                        mpp.erase(nums[l]);
                    }
                    l++;
                }
                mpp.erase(nums[r]);
                r--;
                
            }

            r++;
        }
        return ans;
    }
};