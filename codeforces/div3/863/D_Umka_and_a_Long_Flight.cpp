#include <bits/stdc++.h>
#define x first
#define y second
#define int unsigned long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, x, y;
    cin >> n >> x >> y;
    vector<int> f(n + 3);
    f[0] = f[1] = 1;
    for(int i = 2; i <= n + 1; i ++ ) f[i] = f[i - 1] + f[i - 2];
    int h = f[n], w = f[n + 1];
    for(int i = n; i; i --){
        if(h - x >= f[i]) h -= f[i];
        else if(x - 1 >= f[i]) x -= f[i], h -= f[i];
        else if(w - y >= f[i]) w -= f[i];
        else if(y - 1 >= f[i]) y -= f[i], w -= f[i];
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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