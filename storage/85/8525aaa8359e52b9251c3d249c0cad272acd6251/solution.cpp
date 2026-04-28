#include<iostream>
#include<map>

using namespace std;

const int INF = 1e9 + 1;

map<int, int> amountOfLines;

int getCrossWithOy(int k, int b) {
    return b;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int k, b;
        cin >> k >> b;

        int y = getCrossWithOy(k, b);

        amountOfLines[y]++;
    }

    int maxAmount = 0, minYcoord = INF;
    for (auto &item : amountOfLines) {
        int y = item.first, amount = item.second;
        if (maxAmount < amount) {
            maxAmount = amount;
            minYcoord = y;
        } else if (maxAmount == amount) {
            minYcoord = min(minYcoord, y);
        }
    }

    cout << minYcoord << "\n";

    return 0;
}
