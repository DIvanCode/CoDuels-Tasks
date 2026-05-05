#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_CONSTANTS
#include <bits/stdc++.h>
#define forall(i, x) for(auto& i: x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

mt19937 rnd(228);
void solve() {
    int x;
    cin >> x;
    if(x%3==0){
        cout << 1ll*x*(x/3*4);
    }
    else{
        cout << 1ll*x*(x/5*12);
    }
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setprecision(15) << fixed;
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
    return 0;
}//agv9
