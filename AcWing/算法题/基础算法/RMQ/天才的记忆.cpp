#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
	int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<vector<int>> st(n + 2, vector<int>(20));
    for(int i = 1; i <= n; i ++ ) {
        st[i][0] = a[i];
    } 
    int p = log2(n);
    for(int j = 1; j <= p; j ++ ) {
        for(int i = 1; i + (1 << j) <= n + 1; i ++ ) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
        }
    }
    auto query = [&](int l, int r)->int{
        int len = r - l + 1;
        int p = log2(len);
        return max(st[l][p], st[r - (1 << p) + 1][p]); 
    };
    int m;
    cin >> m;
    while(m -- ){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}