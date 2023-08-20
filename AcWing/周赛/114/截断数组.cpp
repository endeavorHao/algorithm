#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, p;
    cin >> n >> p;
    vector<int> a(n), s(n + 1);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < n; i ++ ) s[i + 1] = s[i] + a[i];
    int ans = 0;
    if(n == 2){
        ans = a[0] % p;
        ans += a[1] % p;
        cout << ans << endl;
        return;
    }
    for(int i = 1; i < n - 1; i ++ ){
        int sum = 0;
        sum += (s[i] % p);
        sum += (s[n] - s[i]) % p;
        ans = max(ans, sum);
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