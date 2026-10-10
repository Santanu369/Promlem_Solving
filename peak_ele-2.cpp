#include<bits/stdc++.h>
using namespace std;

// like the peak element 1
// lets say in a col the pos peak will def be the largest one
// now just need to check the righ and left
// if right is grater move right and same for left

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m-1;
        vector<int> ans;

        while (low <= high)
        {
            int mid = (low + high)/2;

            int max_r = 0;
            int max_value = -1;

            for (int i = 0; i < n; i++)
            {
                if (mat[i][mid] > max_value) {
                    max_r = i;
                    max_value = mat[i][mid];
                }
            }
            
            if (mid > 0 && mid < m-1) {
                if (mat[max_r][mid] > mat[max_r][mid+1] && mat[max_r][mid] > mat[max_r][mid-1]) {
                    ans.push_back(max_r);
                    ans.push_back(mid);
                    return ans; 
                }
                else {
                    if (mat[max_r][mid] < mat[max_r][mid+1]) {
                        low = mid + 1;
                    }
                    else {
                        high = mid - 1;
                    }
                }
            }
            else if (mid == 0 && mid != m-1) {
                if (mat[max_r][mid] > mat[max_r][mid+1]) {
                    ans.push_back(max_r);
                    ans.push_back(mid);
                    return ans; 
                }
                else {
                    if (mat[max_r][mid] < mat[max_r][mid+1]) {
                        low = mid + 1;
                    }
                }
            }
            else if (mid != 0 && mid == m-1) {
                if (mat[max_r][mid] > mat[max_r][mid-1]) {
                    ans.push_back(max_r);
                    ans.push_back(mid);
                    return ans; 
                }
                else {
                    if (mat[max_r][mid] < mat[max_r][mid-1]) {
                        high = mid - 1;
                    }
                }
            }
            else {
                ans.push_back(max_r);
                ans.push_back(mid);
                return ans; 
            }
        }
        return ans;
    }
};


int mian() {

    Solution s = Solution();
    cout << s.minRotations(4, "4219");
    return

}