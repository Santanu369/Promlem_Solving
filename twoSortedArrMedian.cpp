#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int total_left = (n+m)/2;
        double ans;

        int l = 0, r = min(n, m);

        while (l <=r )
        {
            int mid_1 = (l+r) / 2;
            int mid_2 = total_left - mid_1;

            int l1 = INT_MIN, r1 = INT_MAX;
            int l2 = INT_MIN, r2 = INT_MAX;

            if (mid_1 > 0) l1 = nums1[mid_1-1];
            if (mid_2 > 0) l2 = nums2[mid_2-1];

            if (mid_1 < n) r1 = nums1[mid_1];
            if (mid_2 < m) r2 = nums2[mid_2];

            //check
            if (l1 <= r2 && l2 <= r1) {
                // correct
                if ((n+m) % 2 == 0) {
                    ans = min(r1, r2)+max(l1, l2);
                    ans /= 2;
                }
                else {
                    ans = min(r1, r2);
                }
            }
            else if (l1 > r2) {
                r = mid_1 - 1;
            }
            else {
                l = mid_1 + 1;
            }
        }
        return ans;

    }
};


int mian() {


}