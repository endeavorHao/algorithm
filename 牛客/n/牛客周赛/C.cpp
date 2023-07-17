#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m, x;
int a[N];
void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int res = 0;
    for(int i = 0; i < 1e6; i++){
        int x = n, y = m;
        int ans = 0;
        if(x < i * 2 || y < i) continue;
        ans = i * a;
        x -= i * 2;
        y -= i;

        int cnt = min(x, y / 2);
        ans += cnt * b;
        res = max(res, ans);
    }
    cout << res << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}


