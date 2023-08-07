#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define PIIII pair<int, PIII>
#define sqrt(x) __builtin_sqrt(x)
#define popcount(x) __builtin_popcount(x)
const int INF = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> B(n), A;
    for (int i = 1; i < n; ++i) {
        cin >> B[i];
    }
    A.emplace_back(0);
    for (int i = 1; i < n; ++i) {
        int last = A.back(), mid = A.back() ^ B[i];
        if (mid < last) {
            cout << -1 << endl;
            return;
        }
        A.emplace_back(mid);
    }
    int l = floor(log2(A.back())) + 1;
    // cout << l << endl;
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] + ((k - 1) << l) << " \n"[i == A.size() - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _; cin >> _; while (_--)
    solve();
    return 0;
}