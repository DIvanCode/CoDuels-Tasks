//
//  main.cpp
//  Tour1
//
//  Created by Vano Podvornidze on 02.11.2022.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
#define int long long
signed main() {
  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    vector<pair<int, int>> st;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            if (st.size() == 0) {
                st.push_back({x, x});
            } else {
                st.push_back({x, min(x, st.back().second)});
            }
        } else if (t == 2) {
            cout << st.back().first << '\n';
            st.pop_back();
        } else {
            cout << st.back().second << '\n';
        }
    }
}
