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
    int l = 1, r = 1e6;
    while(l < r){
        int mid = l + r >> 1;
        if(n <= ((mid + 1) * mid / 2)) r = mid;
        else l = mid + 1;
    }
    int t = n - r * (r - 1) / 2;
    int ans = n * n;
    int cnt = 1;
    while(r -- ){
        for(int i = max(t - cnt, 1ll); i <= r && i <= t; i ++ ){
            ans += (r * (r - 1) / 2 + i) * (r * (r - 1) / 2 + i);
        }
        cnt ++;
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