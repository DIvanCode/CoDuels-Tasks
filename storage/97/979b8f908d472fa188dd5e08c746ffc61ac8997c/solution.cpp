#include <bits/stdc++.h>

using namespace std;

long long n, x, k = 0, a[100100], pr[100100];

char sim;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sim;
        if(sim == '+') {
            cin >> x;
            k++;
            a[k] = x;
            pr[k] = pr[k-1] + x;
        }
        if (sim == '-') {
            cout << a[k] << endl;
            a[k] = 0;
            pr[k] = 0;
            k--;
        }
        if (sim == '?') {
            cin >> x;
            cout << pr[k] - pr[k-x] << endl;
        }
    }
}
