#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
struct node{
    int a, b, g, k, id;
};
void solve(){
	int L;
    cin >> L;
    int n;
    cin >> n;
    vector<int> a(n);
    int minv = 0, maxv = 0;
    for(int i = 0; i < n; i ++ ) {
        cin >> a[i];
        minv = max(minv, min(a[i], L + 1 - a[i]));
        maxv = max(maxv, max(a[i], L + 1 - a[i]));
    }
    cout << minv << ' ' << maxv << endl;
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