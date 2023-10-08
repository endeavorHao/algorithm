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
    int c1 = 0, c2 = 0, c0 = 0;
    for(int i = 0; i < n; i ++ ){
        if(a[i] % 3 == 0) c0 ++;
        else if(a[i] % 3 == 1) c1 ++;
        else c2 ++;
    }
    int t = n / 3;
    int ans = 0;
    if(c0 < t){
        if(c1 <= t){
            ans += (t - c0) + (t - c1) * 2;
        }else{
            if(c2 <= t) ans += (t - c0) * 2 + (t - c2);
            else {
                ans += (c1 - t) * 2 + (c2 - t);
            }
        }
    }else{
        if(c1 <= t){
            if(c2 <= t){
                ans += (t - c1) + (t - c2) * 2;
            }else{
                ans += (c0 - t) + (c2 - t) * 2;
            }
        }else{
            ans += (c0 - t) * 2 + (c1 - t);
        }
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