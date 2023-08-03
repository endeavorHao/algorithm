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
    map<int, int> mp1, mp2, mp3, mp4;
    mp1.clear(), mp2.clear(), mp3.clear(), mp4.clear();
    for(int i = 1; i <= n; i ++ ){
      int x, y;
      cin >> x >> y;
      mp1[y - x] ++;
      mp2[x + y] ++;
      mp3[x] ++;
      mp4[y] ++;
    }
    int ans = 0;
    for(auto u: mp1){
      ans += u.y * (u.y - 1);
    }
    for(auto u: mp2){
      ans += u.y * (u.y - 1);
    }
    for(auto u: mp3){
      ans += u.y * (u.y - 1);
    }
    for(auto u: mp4){
      ans += u.y * (u.y - 1);
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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}