#include <bits/stdc++.h>

using namespace std;
// search ele in rotated array
// the critical part is value at l = r = m = 3 means if value at m is not the ans then l and r nither
// so just dec the size of the arr l++, r-- and continue

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n-1;

        while (l <= h) {
            int mid = (l+h)/2;

            if (nums[mid] == target) return true;
            if (nums[l] == nums[mid] && nums[mid] == nums[h]) {
                l++;h--;
                continue;
            }
            else if (nums[mid] > nums[l]) {
                if (nums[mid] >= target && nums[l] <= target) {
                    h = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else (nums[mid] < nums[h]) {
                if (target >= nums[mid] && target <= nums[h]) {
                    l = mid + 1;
                }
                else {
                    h = mid - 1;
                }
            }
        }
        return false;
    }
};
int main() {
    cout << 1;


    return 0;
}