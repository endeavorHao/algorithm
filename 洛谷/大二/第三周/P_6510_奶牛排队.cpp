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
	stack<int> stk;
	for(int i = 1; i <= n; i ++ ) {
		while(stk.size() && a[i] > a[stk.top()]) stk.pop();
		if(stk.size()) pre[i] = stk.top();
		else pre[i] = 0;
		stk.push(i);
	}
	while(stk.size()) stk.pop();
	for(int i = n; i; i -- ) {
		while(stk.size() && a[i] < a[stk.top()]) stk.pop();
		if(stk.size()) suf[i] = stk.top();
		else suf[i] = n + 1;
		stk.push(i);
	}
	int ans = 0;
	for(int i = n; i; i -- ) {
		ans = max(ans, suf[i] - pre[i] + 1);
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