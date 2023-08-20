#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
void solve(){
	int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < n; i ++ ) cin >> b[i];
    map<PII, int> mp;
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        int d = gcd(a[i], b[i]);
        a[i] /= d, b[i] /= d;
        ans += mp[{b[i], a[i]}];
        mp[{a[i], b[i]}] ++;
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