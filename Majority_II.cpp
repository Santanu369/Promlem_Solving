#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// elems appears > n/3 times
// max elem can be 2
// they cant be beated by other as they are more that n/3 and other simply not
// at last check if they are really appearing > n/3 times or no

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans1=INT_MIN, ans2=INT_MIN;
        int cnt1=0, cnt2=0;
        int target = n/3;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && nums[i] != ans2) {
                ans1 = nums[i];
                cnt1++;
            }
            else if (cnt2 == 0 && nums[i] != ans1) {
                ans2 = nums[i];
                cnt2++;
            }
            else if (nums[i] == ans1) cnt1++;
            else if (nums[i] == ans2) cnt2++;
            else {
                cnt1--;cnt2--;
            }

        }
        cnt1=0;cnt2=0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ans1) cnt1++;
            else if(nums[i] == ans2) cnt2++;
        }

        if (cnt1 > target) v.push_back(ans1);
        if (cnt2 > target) v.push_back(ans2);
        

        return v;

    }
};
                                                     
int main() {
    int n = 6;
    int cnt=n-1;
    int value = 1;

    cout << 1 << " ";
    for (int i = 0; i < n-2; i++)
    {
        value *= (cnt);
        value /= (n-cnt);
    }
    

    

    return 0;
}