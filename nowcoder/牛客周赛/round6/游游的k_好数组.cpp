#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    
    vector<int> p(k);
    for(int i = 1; i <= n; i ++ ){
        p[i % k] = max(p[i % k], a[i]);
    }

    for(int i = 1; i <= n; i ++ ){
        if(a[i] != p[i % k]){
            x -= p[i % k] - a[i];
            a[i] = p[i % k];
        }
    }

    if(x < 0){
        cout << -1 << endl;
    }else{
        vector<PII> alls(n + 1);
        for(int i = 1; i <= n; i ++ ){
            alls[i] = {a[i], i};
        }
        int ans = 0;
        stable_sort(alls.begin(), alls.end());
        for(int i = 1; i <= n; i ++ ){
            int t = alls[i].x, pos = alls[i].y;
            int s = (pos - k + k - 1) / k, s2 = (n - (pos + k) + k) / k;
            t += x / (s + s2 + 1);
            ans = max(ans, t);
        }
        cout << ans << endl;
    }
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