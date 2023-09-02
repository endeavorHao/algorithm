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
    vector<int> cnt(4);
    for(int i = 0; i <= 31; i ++ ){
        if(n >> i & 1){
            cnt[i / 8] += 1 << (i % 8);
        }
    }
    sort(cnt.begin(), cnt.end());
    int ans = 0;
    for(int i = 0; i < 4; i ++ ){
        ans += cnt[i] *(1ll << i * 8);
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