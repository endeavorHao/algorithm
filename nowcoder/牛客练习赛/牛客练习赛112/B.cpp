#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N], cnt[35];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	int ans = 0, sum = 0;
	for(int i = 1, j = 1; i <= n; i ++ ){
		for(int t = 0; t < 32; t ++ ){
			if((a[i] >> t & 1) == 0){
                cnt[t] ++;
                if(cnt[t] == 1) sum ++;
            }
		}
		while(sum == 32 && j <= i && j <= n){
			ans += (n - i + 1);
			for(int t = 0; t < 32; t ++ ){
				if((a[j] >> t & 1) == 0) {
                    cnt[t] --;
                    if(!cnt[t]) sum --;
                }
			} 
			j ++;
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