#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

	int n, k;
	std::cin >> n >> k;
	std::set<int> free;
	std::queue<std::vector<int>> q;
	for (int i = n; i > 0; i--) free.insert(i);

	while (k--) {
		std::string ord;
		std::cin >> ord;
		if (ord[0] == 'O') {
			std::string name;
			int cnt;
			std::cin >> name >> cnt;
			q.emplace();
			while (cnt--) {
				std::cout << *free.begin() << ' ';
				q.back().push_back(*free.begin());
				free.erase(free.begin());
			}
			std::cout << '\n';
		} else {
			std::string name;
			std::cin >> name;
			// in fact delete first, not by name
			auto tmp = q.front();
			q.pop();
			for (auto &i : tmp) { free.insert(i); }
		}
	}

	for (auto &i : free) std::cout << i << ' ';
	std::cout << '\n';
}
