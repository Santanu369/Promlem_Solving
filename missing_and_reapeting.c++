#include <bits/stdc++.h>
using namespace std;

// fron 1 to n on value is missing and 1 is twice
// so the true sum of 1 to n is not == arr sum
// so we can -ve and get one eq
// so their sum or sq is also not equial
// we can get another eq like that and we get the ans

class Solution {
public:
    vector<int> missingAndRep(vector<int>& nums, int n) {
        int true_sum = n*(n+1)/2;
        int real_sum = 0;
    
        for (int i = 0; i < n; i++)
        {
            real_sum += nums[i]; 
        }

        int true_sq_sum = n*(n+1)*(2*n+1)/6;
        int real_sq_sum = 0;

        for (int i = 0; i < n; i++)
        {
            real_sq_sum += nums[i] * nums[i];
        }        
        int m, r;

        r = (real_sq_sum*real_sq_sum - true_sq_sum* true_sq_sum)/(real_sum - true_sum);
        r += real_sum - true_sum;
        r /= 2;

        m = - real_sum + true_sum + r;
        
    }
};

// [1,3,-1,-3,5,3,6,7]
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        int n = nums.size();

        deque<int> dq;

        int l = 0, r = 0;
        
        while (r < n) {

            if (!dq.empty()) {
                if(dq[0] < l) {
                    dq.pop_front();
                }
            }

            if (dq.empty()) {
                dq.push_back(r);
            }

            else if (nums[r] >= nums[dq[0]]) {
                dq.clear();
                dq[0] = r;
            }

            else if (dq.size() > 1) {
                if (nums[r] > nums[dq[1]]) {
                    dq[1] = r;
                }
            }
            
            else {
                dq.push_back(r);
            }

            if (r-l+1 == k) {
                ans.push_back(nums[dq[0]]);
                r++; l++;
            }

            else {
                r++;
            }
        }

        return ans;
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        
        int cnt_a = 0, cnt_b = 0;

        int l = 0, r = m-1;

        for (int i = 0; i < n-1; i++)
        {
            cnt_a += (a[i]-a[i+1] + 1);
        }
        cnt_a += a[n-1];

        for (int i = 0; i < m-1; i++)
        {
            cnt_b += (b[i]-b[i+1] + 1);
        }
        cnt_b += b[m-1];
        

        if (cnt_a < cnt_b) cout << 2 << endl;
        else cout << 1 << endl;
        
    }
    


    return 0;
}