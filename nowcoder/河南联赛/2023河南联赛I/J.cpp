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
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a, a + n);
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i ++ ){
        sum1 += a[i];
    }
    sum2 = sum1 - a[n - 1];
    sum1 = sum1 - a[0];
    n --;
    double l = (double) sum2 / n;
    double r = (double) sum1 / n;
    printf("%.6lf %.6lf\n", l, r);
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
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}