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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        if(a[i] < 0) a[i] = -1;
        else if(a[i] == 0) a[i] = 0;
        else a[i] = 1;
    }
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for(int i = 1; i <= n; i ++ ){
        if(a[i] == 0){
            dp[i][0] = i;
            dp[i][1] = 0;
            dp[i][2] = 0;
        }else if(a[i] == 1){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][2] = dp[i - 1][2];
        }else{
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][2];
            dp[i][2] = dp[i - 1][1] + 1;
        }
    }
    int s1 = 0, s2 = 0, s3 = 0;
    for(int i = 1; i <= n; i ++ ){
        s1 += dp[i][0];
        s2 += dp[i][1];
        s3 += dp[i][2];
    }
    cout << s3 << ' ' << s1 << ' ' << s2 << endl;
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