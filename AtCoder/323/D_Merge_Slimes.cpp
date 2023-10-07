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
	int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i ++ ) {
        int s, c;
        cin >> s >> c;
        mp[s] += c;
    }   
    int ans = 0;
    for(auto [x, y] : mp){
        ans += y % 2;
        mp[x * 2] += y / 2;
    }
    cout << ans << endl;
}
signed main() {
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