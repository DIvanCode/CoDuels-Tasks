#include<bits/stdc++.h>

using namespace std;

int sum(int x) {
    int res = 0;
    while (x) {
        res += x % 10, x /= 10;
    }
    return res;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, x, k;
    cin >> t;
    while (t--) {
        cin >> x >> k;
        while (sum(x) % k != 0) x++;
        cout << x << '\n';
    }
    return 0;
}
