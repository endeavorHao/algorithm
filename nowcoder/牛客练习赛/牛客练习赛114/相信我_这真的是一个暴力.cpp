#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 210, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int a1, b1, c1;
    int a2, b2, c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    vector<double> dp(11);
    double ans = 0, sum = 0;
    double v = (a1 * (10 - a2) + b1 * (10 - b2) + c1 * (10 - c2)) * 1.0 / 100;
    if(v) printf("%.6lf\n", 1 / v);
    else {
        printf("Sorry,NoBruteForce\n");
    }
    // for(int i = 1; i <= 10; i ++ ){
    //     dp[i] += 1.0 / ans * (a1 * (10 - a2) + b1 * (10 - b2) + c1 * (10 - c2)) * 1.0 / 100;
    //     sum += i * dp[i];
    //     ans += dp[i];
    // }
}
signed main() {
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}