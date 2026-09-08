#include <bits/stdc++.h>
 
using namespace std;

// fine peak
// consicutives are stricly different
// so graph is eighter sorted of zic zac
// so we are either on a peak or slop of bottom
// if we are on slop then if - 
//                 we are on incr slop mean peak is right
//                 we are on dec slop means peak is at left
// if we are on bottom then go any of theose sides we can find a peak

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n-1;
        int ans;

        if (n==1) return 0;

        while (l <= r)
        {
            int mid = (l+r)/2;

            if (mid > 0 && mid < n-1) {
                if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                    ans = mid;
                    break;                    
                }

                else if (nums[mid] > nums[mid-1]) {
                    l = mid + 1;
                }
                else if (nums[mid] > nums[mid+1]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }

            else if (mid == 0) {
                if (nums[0] > nums[1]) {
                    ans = 0;
                    break;
                }
                else {
                    l = mid + 1;
                }
            }

            else if (mid == n-1) {
                if (nums[n-1] > nums[n-2]) {
                    ans = n-1;break;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return ans;
    }
};
 
int main() {
    
    return 0;
}