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
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        ans = (ans + (a[i] + 1) * a[i] / 2) % mod;
    }
    for(int i = 1; i < n - 1; i ++ ){
        int j = 1;
        while(i - j >= 0 && i + j < n){
            if(a[i - j] == a[i + j]) ans = (ans + a[i - j]) % mod;
            else {
                ans = (ans + min(a[i - j], a[i + j])) % mod;
                break;
            }
            j ++;
        }
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