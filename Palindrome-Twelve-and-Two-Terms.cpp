#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// n = b + a
// n = 12*k + 0-11 (total 12)
// if we remove 0-11 from n one is must divisable by 12
// its 10 then do + 12 and - from k if k = 0 mean b < 0 means doesnt exist


int main() {
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a=0; ll b=n;

        while (b % 12 != 0) {
            a++;
            b--;
        }

        if (a==10) {
            a+= 12;
            b-=12;
            if (b >= 0) {
                cout << a << " " << b << endl;
            } 
            else {
                cout << -1 << endl;
            }
        }
        else {
                cout << a << " " << b << endl;
            }
        
 
    }

    return 0;  
}