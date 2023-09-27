#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N], b[N], f[N][3];
int last[N];
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ ) cin >> b[i];
    for(int i = 1; i <= n; i ++ ){
        last[i] = last[i-1];
        if(b[i - 1] == 1) last[i] = i - 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++ ){
        if(b[i] == 1){
            if(i - last[i] >= 3){
                f[i][0] = max(f[last[i]][0], max(f[last[i]][1], f[last[i]][2])) + a[i-1];
                f[i][1] = max(f[last[i]][0], max(f[last[i]][1], f[last[i]][2])) + a[i];
                f[i][2] = max(f[last[i]][0], max(f[last[i]][1], f[last[i]][2])) + a[i + 1];
            }
            else if(i - last[i] == 2){
                f[i][0] = max(f[last[i]][0], f[last[i]][1]) + a[i-1];
                f[i][1] = max(f[last[i]][0], max(f[last[i]][1], f[last[i]][2])) + a[i];
                f[i][2] = max(f[last[i]][0], max(f[last[i]][1], f[last[i]][2])) + a[i + 1];
            }
            else{
                f[i][0] = f[last[i]][0] + a[i-1];
                f[i][1] = max(f[last[i]][0], f[last[i]][1]) + a[i];
                f[i][2] = max(f[last[i]][0], max(f[last[i]][1], f[last[i]][2])) + a[i + 1];
            }
            ans = max(ans, f[i][0]);
            ans = max(ans, f[i][1]);
            ans = max(ans, f[i][2]);
        }
        
    }
    cout << ans << endl;
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
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}