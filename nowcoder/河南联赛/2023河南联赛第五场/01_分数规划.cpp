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
    string s;
    cin >> s;
    vector<int> dp(2);
    int ans = 0;
    for(int i = 0; i < s.size(); i ++ ){
        if(s[i] == '0'){
            dp[0] ++;
            dp[1] = 0;
        }else if(s[i] == '1'){
            dp[1] ++;
            dp[0] = 0;
        }else {
            dp[1] ++;
            dp[0] ++;
        }
        ans = max({ans, dp[0], dp[1]});
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