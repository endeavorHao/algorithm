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
	int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i ++ ) cin >> s[i];
    int ans = 1e18;
    for(int i = 0; i < n; i ++ ){
        for(int j = i + 1; j < n; j ++ ){
            vector<int> dp(26);
            for(int k = 0; k < m; k ++ ){
                int s1 = s[i][k] - 'a', s2 = s[j][k] - 'a';
                for(int z = 0; z < 26; z ++ ){
                    dp[z] += abs(z - s1) + abs(z - s2);
                }
                for(int z = 0; z < 26; z ++ ) dp[z] = *min_element(all(dp));
            }
            ans = min(ans, *min_element(all(dp)));
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