#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 10010, INF = 0x3f3f3f3f, mod = 1000000007, P = 131;

typedef pair<int, int> PII;
typedef unsigned long long UII;

void solve(){
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    stack<int> stk;
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i -- ){
        while(stk.size() && a[stk.top()] <= a[i]) stk.pop();
        if(stk.size()) ans[i] = stk.top() + 1;
        else ans[i] = 0;
        stk.push(i);
    }
    for(int i = 0; i < n; i ++ ) cout << ans[i] << ' ';
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