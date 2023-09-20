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
	int n, x, y;
    cin >> n >> x >> y;
    vector<PII> a(n - 1);
    for(int i = 0; i < n - 1; i ++ ){
        cin >> a[i].x >> a[i].y;
    }
    map<int, int> mp;
    for(int i = 0; i < 840; i ++ ){
        int sum = i;
        for(int i = 0; i < n - 1; i ++ ){
            while(sum % a[i].x != 0) sum ++;
            sum += a[i].y;
        }
        mp[i] = sum;
    }
    int q;
    cin >> q;
    while(q -- ){
        int t;
        cin >> t;
        t += x;
        int ans = mp[t % 840];
        ans += t - t % 840;
        ans += y;
        cout << ans << endl;
    }
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