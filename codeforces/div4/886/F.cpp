#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    map<int, int> mp1, mp2;
    for(int i = 0; i < n; i ++ ) mp1[a[i]] ++;
    int cnt = 0;
    for(auto u: mp1){
      if(u.x == 1){
        cnt++;
        continue;
      }
      for(int i = u.x; i <= n; i += u.x){
        mp2[i] += u.y;
      }
    }
    int ans = 0;
    for(auto v: mp2) ans = max(ans, v.y + cnt);
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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}