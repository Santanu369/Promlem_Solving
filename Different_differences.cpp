#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// if n i even then reptet the arr a
// if odd then fist add b and then treat as even

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[8] = {2,1,1,2,1,2,2,1};
        int b[12] = {1,1,2,1,2,3,1,3,2,2,3,3};

        int ans[n*4];
        int index=0;

        if (n%2 == 0) {
            for (int i = 1; i <= n; i+=2)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (a[j] == 1) {
                        ans[index++] = i;
                    }
                    else {
                        ans[index++] = i+1;
                    }
                }
                
            }
            
        }
        else {
            for (int i = 0; i < 12; i++)
            {
                ans[index++] = b[i];
            }
            
            for (int i = 4; i <= n; i+=2)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (a[j] == 1) {
                        ans[index++] = i;
                    }
                    else {
                        ans[index++] = i+1;
                    }
                }
                
            }
        }

        for (int i = 0; i < n*4; i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
        
        
 
    }

    return 0;  
}