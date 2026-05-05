#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <vector <int> > d(8, vector <int>(8, 0));
    int x, y;
    cin >> y >> x;
    x--;
    y--;
    int start = y - 1;
    d[x][y] = 1;
    for (int i = x + 1; i < 8; i++){
        for (int j = start; j < 8; j+=2){
            if (j > 0 && i > 0 && j <= 7){
                d[i][j] += d[i - 1][j - 1];
            }
            if (j < 7 && i > 0 && j >= 0){
                d[i][j] += d[i - 1][j + 1];
            }
        }
        start--;
    }
    int ans = 0;
    for (auto i: d[7]){
        ans += i;
    }
    cout << ans;
    return 0;
}
