#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

	std::set<int> s;
	int q;
	std::cin >> q;
	while (q--) {
		int type;
		std::cin >> type;
		if (type == 1) {
			int val;
			std::cin >> val;
			assert(!s.count(val));
			s.insert(val);
		} else if (type == 2) {
			int val;
			std::cin >> val;
			assert(s.count(val));
			s.erase(val);
		} else {
			std::cout << *s.rbegin() / 2 << '\n';
		}
	}
}
