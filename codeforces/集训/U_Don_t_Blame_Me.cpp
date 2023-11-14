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
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < 64; j ++ ){
            mp[j & a[i]] = (mp[j & a[i]] + mp[j]) % mod; 
        }
        mp[a[i]] ++;
    }
    int ans = 0;
    for(int i = 0; i < 64; i ++ ){
        int cnt = 0;
        for(int j = 0; j < 8; j ++ ){
            if(i >> j & 1) cnt ++;
        }
        if(cnt == k) ans = (ans + mp[i]) % mod;
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