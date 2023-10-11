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
	int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < m; i ++ ) cin >> b[i];
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i ++ ) sum1 += a[i];
    for(int i = 0; i < m; i ++ ) sum2 += b[i];
    int t = sum1 + sum2;
    int d1 = *min_element(all(a)), d2 = *max_element(all(a));
    int d3 = *min_element(all(b)), d4 = *max_element(all(b));
    int maxv2 = 0;
    int cnt = 0;
    for(int i = 0; i < m; i ++ ){
        if(b[i] == d4) cnt ++;
        else {
            maxv2 = max(maxv2, b[i]);
        }
        if(cnt == 2) maxv2 = d4;
    }
    if(k & 1){
        cout << sum1 + max(d4 - d1, 0ll) << endl;
    }else{
        if(d1 < d4){
            sum2 -= d4 - d1;
            d2 = max(d2, d4);
            d3 = min(d3, d1);
        } 
        sum2 += max(d2 - d3, 0ll);
        cout << t - sum2 << endl;
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