#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
int f[N];
void solve(){
	cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n; i ++ ){
        f[i] = 1;
        for(int j = 1; j <= i; j ++ )
            if(a[i] < a[j]) f[i] = max(f[i], f[j] + 1);
    }
    cout << f[n] << endl;
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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}