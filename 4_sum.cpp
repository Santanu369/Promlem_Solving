#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int INF = (int) 1e18;

// 4 sum
//sort bcz if we sort then we know if we move right then sum inc else dec
// now take two pointer n^2 and two pointer for rest sum, which changes to adjast sum
// n^3

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n-3; i++)
        {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n-2; j++)
            {
                if (j != i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = n-1;

                while(k < l) {

                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target) {
                        vector<int> v = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(v);

                        k++; l--;
                        while (k < l && nums[k] == nums[k-1]) k++;
                        while (l > k && nums[l] == nums[l+1]) l--;
                        
                    }
                    else {
                        if (sum > target) l--;
                        else k++;
                    }
                }
            }
            
        }
        return ans;
    }
};
 
int main() {
 
 
    return 0;
}