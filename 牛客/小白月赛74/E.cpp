#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int mod = 0;
void solve(){
	int n, m, k, b;
    cin >> n >> m >> k >> b;
    vector<int> h(n + 1);
    vector<int> a(n + 1);
    vector<int> ans(n + 1, 0);
    for(int i = 1; i <= n; i ++ ){
        cin >> h[i];
    }
    m --;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        int x = (k - h[i] + a[i]) / a[i];
        if(x > m){
            ans[i] = h[i] + a[i] * m;
        }else{
            int mm = m - x;
            int zq = (k - b + a[i]) / a[i];
            int now = mm % zq;
            ans[i] = now * a[i] + b;
        }
    }
    for(int i = 1; i <= n; i ++ ) cout << ans[i] << ' ';
    cout << endl;
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