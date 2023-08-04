#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 20, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int f[N][2][N][N][N];
int nums[N], len;
int dfs(int pos, int lim, int has, int len, int cnt5, int cnt7){
	has |= len >= 7;
	auto &v = f[pos][has][len][cnt5][cnt7];
	if(~v && !lim) return v;
	if(!pos) return cnt5 + cnt7 * 3 + has * 300;
	int upper = lim ? nums[pos] : 9;
	int ans = 0;
	for(int i = 0; i <= upper; i ++ ){
		ans += dfs(pos - 1, lim & i == upper, has, i == 7? len + 1: 0, cnt5 + (i == 5), cnt7 + (i == 7));	
	}
	return lim ? ans: v = ans;
}
int dp(int n){
	len = 0;
	while(n) nums[++ len] = n % 10, n /= 10;
	return dfs(len, 1, 0, 0, 0, 0);
}
void solve(){
	int l, r;
	cin >> l >> r;
	cout << dp(r) - dp(l - 1) << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(f, -1, sizeof f);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}