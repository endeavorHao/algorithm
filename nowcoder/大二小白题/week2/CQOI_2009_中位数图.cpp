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
	int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int pos = 0;
    for(int i = 0; i < n; i ++ ) if(a[i] == b) pos = i;
    map<int, int> pre, suf;
    int sum = 0;
    for(int i = pos - 1; i >= 0; i -- ){
        if(a[i] > b){
            sum ++;
        }else sum --;
        pre[sum] ++;
        // cout << sum << ' ';
    }
    // cout << endl;
    sum = 0;
    for(int i = pos + 1; i < n; i ++ ){
        if(a[i] > b) sum ++;
        else sum --;
        suf[sum] ++;
        // cout << sum << ' ';
    }
    // cout << endl;
    int ans = 1;
    for(auto [x, y]: pre){
        if(x) ans += suf[-x] * y;
        else ans += y;
    }
    ans += suf[0];
    ans += suf[0] * pre[0];
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