#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
void solve(){
	cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = 0;
    for(int i = 0; i < n; ){
    int j = i + 1;
    while(j < n && a[j] - a[j - 1] <= m) j++;
    res = max(res, j - i);
    i = j;
  }
  cout << n - res << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
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