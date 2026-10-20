#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int start = 0;
        int cnt = 0;
        int ans = 0;
        int end = 0;
        int temp;
        while (start <= end && end < n)
        {
            if (nums[end] % 2 != 0) {
                cnt++;
                if (cnt > k) {
                    start = temp + 1;
                    cnt --;
                }
            }
            if (cnt == k) {
                ans++;
                temp = start;
                while (nums[temp] % 2 == 0)
                {
                    ans++;
                    temp++;
                }
            }
            end ++;
            // if (start > end) break;
        }

        return ans;
        
    }
};