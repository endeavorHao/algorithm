#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
int f[N], g[N];
int q[N];
int cnt;
void solve(){
	string line;
	getline(cin, line);
	stringstream ss(line);
	while(ss >> a[n]) n ++;
    for(int i = 0; i < n; i ++ ){
        f[i] = 1;
        for(int j = 0; j < i; j ++ )
            if(a[i] <= a[j]) f[i] = max(f[i], f[j] + 1);
    }
    int ans = 0;
    for(int i = 0; i < n; i ++ ) {
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    
    for(int i = 0; i < n; i ++ ){
        int k = 0;
        while(k < cnt && q[k] < a[i]) k ++;
        if(k == cnt) q[cnt ++] = a[i];
        else q[k] = a[i];
    }
    cout << cnt << endl;
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
// 	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}