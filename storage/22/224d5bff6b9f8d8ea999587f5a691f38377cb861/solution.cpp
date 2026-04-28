#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve();

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

const int MOD = 998244353;

int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}

int mul(int x, int y) {
    return 1ll * x * y % MOD;
}

const int MAX_N = 1e5 + 5;
const int MAX_Q = 1e5 + 5;

struct Query {
    int type, L, R, x, A, B;

    Query() = default;
};

int n;
int a[MAX_N], b[MAX_N];
int q;
Query queries[MAX_Q];

void read() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        Query query{};
        cin >> query.type >> query.L >> query.R >> query.x >> query.A >> query.B;
        queries[i] = query;
    }
}

int T[4 * MAX_N], A[4 * MAX_N], B[4 * MAX_N];
int A_[4 * MAX_N], B_[4 * MAX_N];

void comb(int v) {
    T[v] = add(T[v * 2 + 1], T[v * 2 + 2]);
    A[v] = add(A[v * 2 + 1], A[v * 2 + 2]);
    B[v] = add(B[v * 2 + 1], B[v * 2 + 2]);
}

void build(int v, int tl, int tr) {
    if (tl + 1 == tr) {
        T[v] = mul(a[tl], b[tl]);
        A[v] = a[tl];
        B[v] = b[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm, tr);
    comb(v);
}

void updA(int v, int tl, int tr, int value) {
    T[v] = add(T[v], mul(value, B[v]));
    A[v] = add(A[v], mul(value, tr - tl));
    A_[v] = add(A_[v], value);
}

void updB(int v, int tl, int tr, int value) {
    T[v] = add(T[v], mul(value, A[v]));
    B[v] = add(B[v], mul(value, tr - tl));
    B_[v] = add(B_[v], value);
}

void push(int v, int tl, int tr) {
    int tm = (tl + tr) / 2;
    if (A_[v]) {
        updA(v * 2 + 1, tl, tm, A_[v]);
        updA(v * 2 + 2, tm, tr, A_[v]);
        A_[v] = 0;
    }
    if (B_[v]) {
        updB(v * 2 + 1, tl, tm, B_[v]);
        updB(v * 2 + 2, tm, tr, B_[v]);
        B_[v] = 0;
    }
}

void updateA(int v, int tl, int tr, int L, int R, int value) {
    if (tl >= R || L >= tr) return;
    if (L <= tl && tr <= R) {
        updA(v, tl, tr, value);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    updateA(v * 2 + 1, tl, tm, L, R, value);
    updateA(v * 2 + 2, tm, tr, L, R, value);
    comb(v);
}

void updateB(int v, int tl, int tr, int L, int R, int value) {
    if (tl >= R || L >= tr) return;
    if (L <= tl && tr <= R) {
        updB(v, tl, tr, value);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    updateB(v * 2 + 1, tl, tm, L, R, value);
    updateB(v * 2 + 2, tm, tr, L, R, value);
    comb(v);
}

int get(int v, int tl, int tr, int L, int R) {
    if (tl >= R || L >= tr) return 0;
    if (L <= tl && tr <= R) return T[v];
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return add(get(v * 2 + 1, tl, tm, L, R), get(v * 2 + 2, tm, tr, L, R));
}

vector<int> fast() {
    build(0, 1, n + 1);
    vector<int> answer;
    for (int i = 1; i <= q; ++i) {
        Query query = queries[i];
        if (query.type == 1) {
            updateA(0, 1, n + 1, query.L, query.R + 1, query.x);
        } else if (query.type == 2) {
            updateB(0, 1, n + 1, query.L, query.R + 1, query.x);
        }
        answer.emplace_back(get(0, 1, n + 1, query.A, query.B + 1));
    }
    return answer;
}

void solve() {
    read();
    vector<int> answer = fast();
    for (int ans : answer) {
        cout << ans << "\n";
    }
}
