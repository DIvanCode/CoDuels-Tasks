#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, ans = -1; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; ans = max(ans, x);
	}
	cout << ans;
	return 0;
}
