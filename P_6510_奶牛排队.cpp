#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007, P = 131;

typedef pair<int, int> PII;
typedef unsigned long long UII;

void solve(){
	int n;
    cin >> n;
    vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<int> pre(n + 1), suf(n + 1);
    // pre[i]存的是i之前第一个大于等于a[i]
    // suf[i]存的是i之后第一个小于等于a[i]
	stack<int> stk;
	for(int i = 1; i <= n; i ++ ) {
		while(stk.size() && a[i] > a[stk.top()]) stk.pop();
		if(stk.size()) pre[i] = stk.top();
		else pre[i] = 0;
		stk.push(i);
	}
	// while(stk.size()) stk.pop();
	// for(int i = n; i; i -- ) {
	// 	while(stk.size() && a[i] < a[stk.top()]) stk.pop();
	// 	if(stk.size()) suf[i] = stk.top();
	// 	else suf[i] = n + 1;
	// 	stk.push(i);
	// }
	vector<vector<int>> st(n + 10, vector<int>(20)); 
	// init
	for(int i = 1; i <= n; i ++ ) {
		st[i][0] = i;
	}
	// st表找minpos
	int p = log2(n);
	for(int j = 1; j <= p; j ++ ) {
		for(int i = 1; i + (1 << j) <= n + 1; i ++ ) {
			if(a[st[i][j - 1]] < a[st[i + (1 << j - 1)][j - 1]]) {
				st[i][j] = st[i][j - 1];
			}else st[i][j] = st[i + (1 << j - 1)][j - 1];
		}
	}
	auto query = [&](int l, int r) ->int{
		int cnt = log2(r - l + 1);
		if(a[st[l][cnt]] < a[st[r - (1 << cnt) + 1][cnt]]) return st[l][cnt];
		return st[r - (1 << cnt) + 1][cnt];
	};
	int ans = 0;
    for(int i = n; i; i -- ) {
        int r = i, l = pre[i] + 1;
        if(l == r) continue;
        ans = max(ans, r - query(l, r) + 1);
    }
    cout << ans << endl;
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