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
    vector<int> a(3), b(6);
    for(int i = 0; i < 3; i ++ ) cin >> a[i];
    for(int i = 0; i < 3; i ++ ) cin >> b[i], b[i + 3] = b[i];
    int maxv = 0, minv = 0;
    for(int i = 0; i < 3; i ++ ){
        maxv += min(a[i], b[i + 1]);
        minv += min(a[i], n - b[i + 1]);
    }
    cout << n - minv << ' ' << maxv << endl;
    
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