#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//Moore's voting algorith
//ele appears > n/2 times


int main() {
    int n = 5;
    int arr[n] = {4,1,5,4,4};

    int ans;
    int cnt=0;

    for (int i = 0; i < n; i++)
    {
        if (i==0) {ans = arr[i];cnt++;}
        else {
            if (arr[i] == ans) {
                cnt++;
            }
            else {
                cnt --;
            }
        }
        if (cnt < 0) {
            ans = arr[i];
            cnt = 1;
        }
    }
    
    return ans;

    return 0;
}