#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 0;
typedef pair<int, int> PII;
void solve(){
	int n;
	string s;
	cin >> n >> s;
	s = ' ' + s;
	vector<array<int, 26>> dp(n + 1);
	// dp[i][j]表示第i个字符填j的最小代价
	for(int i = 0; i < 26; i ++ ) dp[0][i] = 0;
	for(int i = 1; i < s.size(); i ++ ){
		int x = s[i] - 'A';
		for(int j = 0; j < 26; j ++ ){
			dp[i][j] = INF;
			for(int k = 0; k <= j; k ++ ){
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - x));
			}
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << *min_element(dp[s.size() - 1].begin(), dp[s.size() - 1].end()) << endl;
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