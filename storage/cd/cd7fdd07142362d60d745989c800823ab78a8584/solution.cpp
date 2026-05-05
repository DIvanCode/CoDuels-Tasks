#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> day = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int a, b, ans;
    string s;
    cin >> a >> s >> b;
    for (int i = 0; i < 7; i++)
        if (s == day[i])
            ans = i;
    ans = (ans + (b - a))%7;
    if (ans < 0)
        ans += 7;
    cout << day[ans] << '\n';
    return 0;
}
