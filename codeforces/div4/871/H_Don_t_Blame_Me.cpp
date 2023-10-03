#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    map<int, int> mp;
    mp[a[0]] = 1;
    for(int i = 1; i < n; i ++ ){
        for(auto [x, y]: mp){
            mp[x & a[i]] = (mp[x & a[i]] + mp[x]) % mod;
        }
        mp[a[i]] ++;
    }
    int ans = 0;
    for(auto [x, y]: mp){
        int cnt = 0;
        for(int i = 0; i < 7; i ++ ){
            if(x >> i & 1) cnt ++;
        }
        if(cnt == k) ans = (ans + y) % mod;
    }
    cout << ans << endl;
}
signed main() {
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