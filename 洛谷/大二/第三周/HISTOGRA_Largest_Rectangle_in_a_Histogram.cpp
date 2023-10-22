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

struct node{
    int len, height;
};
void solve(){
	int n;
    while(cin >> n, n) {
        vector<int> a(n + 10);
        for(int i = 1; i <= n; i ++ ) cin >> a[i];
        a[n + 1] = 0;
        int t = 0;
        int ans = 0;
        stack<node> stk;
        for(int i = 0; i <= n + 1; i ++ ){
            if(!stk.size() || a[i] > stk.top().height) {
                stk.push({1, a[i]});
            }else {
                int len = 0;
                while(stk.size() && stk.top().height > a[i]) {
                    len += stk.top().len;
                    ans = max(ans, len * stk.top().height);
                    stk.pop();
                }
                stk.push({len + 1, a[i]});
            }
        }
        cout << ans << endl;
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