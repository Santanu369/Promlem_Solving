#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Prefix sum
// if a sum exist in the past where its sum-k then we can exclue that part and form a sum array
// there can be multiple sub arrays with same last index so wen need map
// when sum == k then we need 0 in the past to we have to add that manually at first

                                                     
int main() {
    int n = 10;
    int arr[] = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    int sum = 0;


    int sub_arr_cnt = 0;
    set <int> s;
    map<int, int> mp;
    mp.insert({0,1});
    for (int i = 0; i < n; i++)
    {
        sum +=  arr[i];

        sub_arr_cnt+= mp[sum-k];

        mp[sum]++;
    }

    cout << sub_arr_cnt;
    

    

    return 0;
}