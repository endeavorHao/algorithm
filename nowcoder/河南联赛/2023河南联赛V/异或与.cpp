#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    auto cal = [&](int x) -> int{
        int ans = 0;
        for(int i = 0; i < 63; i ++ ){
            int u = x >> i & 1, v = x >> i + 1 & 1;
            if(u == 1){
                ans += 1ll << i;
                ans += ((int)(v == 0) << i + 1);
                i ++;
            }
        }
        return ans;
    };
    map<int, int> mp;
    for(int i = 1; i <= n; i ++ ) mp[a[i]] = i;
    for(int i = 1; i <= n; i ++ ){
        int x = cal(a[i]);

        if(mp[x] && mp[x] != i){
            cout << i << ' ' << mp[x] << endl;
            return;
        }
    }
    cout << -1 << endl;
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