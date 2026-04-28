#include <bits/stdc++.h>

#define sz(v) (int)v.size()

using namespace std;

int main() {
  string n;
  cin >> n;

  sort(n.begin(), n.end());

  if (sz(n) % 2 == 1) {
    for (int i = 0; i < sz(n) / 2 + 1; ++i) {
      cout << n[i];
    }
    cout << "\n";
    return 0;
  }

  string ans;
  int i = 0;
  while (i < sz(n)) {
    ans.push_back(n[i + 1]);
    if (n[i] != n[i + 1]) {
      break;
    }
    i += 2;
  }
  for (int j = i + 2; sz(ans) < sz(n) / 2; ++j) {
    ans.push_back(n[j]);
  }

  cout << ans << "\n";

  return 0;
}
