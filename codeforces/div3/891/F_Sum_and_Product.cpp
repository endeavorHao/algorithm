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
    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i ++ ) cin >> a[i], mp[a[i]] ++;
    int q;
    cin >> q;
    while(q -- ){
        int x, y;
        cin >> x >> y;
        int sqr = sqrt(x * x - 4 * y);
        if(sqr * sqr == x * x - 4 * y){
            int v = (x + sqr), u = (x - sqr);
            int ans = 0;
            if(!(v & 1)){
                v /= 2;
                int t = x - v;
                if(t != v)
                    ans += mp[t] * mp[v];
                else{
                    ans += mp[v] * (mp[v] - 1) / 2;
                }
            }
            cout << ans << ' ';
        }else {
            cout << 0 << ' ';
        }
    }
    cout << endl;
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