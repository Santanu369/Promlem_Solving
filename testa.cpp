#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// if 4 preset then remove it
// now 12 32 combos are poss
// 2 in right is dengerous
// triverse from left, if 2 then twsos++ if 1 or 3 then twos -- and cnt++
// 1 two can cancel one 1 or 3
// the concept is if 2 present in right then it can make 1 or 3 dengerous
//
                                                     
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int cnt = 0;
        int twos=0, one_or_three=0; 
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '4') {s[i] = '0';cnt++;}
        }

        int two_there = 0;
        for (int i = n-1; i >= 0; i--)
        {
            if (s[i] == '2') twos++;
            else if (s[i] == '3' || s[i] == '1') {
                if (twos > 0) {
                    twos--;
                    cnt++;
                }
            }

        }

        cout << cnt << endl;
        
        
 
    }

    return 0;  
}