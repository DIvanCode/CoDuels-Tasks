#include <bits/stdc++.h>

using ll = long long;

const int MOD = 998244353;

int pow(int to) {
	int res = 1;
	for (int i = 0; i < to; i++) {
		res = (int)(res * 2ll % MOD);
	}
	return (int)res;
}

int main() {
	int n;
	std::cin >> n;
	int c0 = 0, c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		if (a == 0) {
			c0++;
		} else if (a == 1) {
			c1++;
		} else if (a == 2) {
			c2++;
		}
	}
	int ans = 0;
	ans = (ans + pow(c0) - 1) % MOD;
	ans = (ans + pow(c1) - 1) % MOD;
	ans = (ans + (pow(c0) - 1ll) * (pow(c2) - 1ll) % MOD) % MOD;
	std::cout << ans << '\n';
	return 0;
}
