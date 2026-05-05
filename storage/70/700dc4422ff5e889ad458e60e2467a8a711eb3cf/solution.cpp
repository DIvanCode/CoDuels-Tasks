#include <bits/stdc++.h>
using namespace std;

int n;
long long sum, x;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        sum += x;
    }
    cout << sum;
    return 0;
}
