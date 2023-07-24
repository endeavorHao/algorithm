#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 11, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int f[N][N];
void init(){
	for(int i = 0; i <= 9; i ++ ) f[1][i] ++;
	
	for(int i = 2; i < N; i ++ )
		for(int j = 0; j <= 9; j ++ )
			for(int k = 0; k <= 9; k ++ )
				if(abs(j - k) >= 2) f[i][j] += f[i-1][k];
}
int dp(int n){
	if(!n) return 0;
	vector<int> nums;
	while(n) nums.push_back(n % 10), n /= 10;

	int ans = 0, last = -2;
	for(int i = nums.size() - 1; i >= 0; i -- ){
		int x = nums[i];
		for(int j = i == nums.size() - 1; j < x; j ++ )
			if(abs(j - last) >= 2) ans += f[i + 1][j];
		
		if(abs(x - last) < 2) break;
		last = x;
		if(!i) ans ++;
	}
	for(int i = 1; i < nums.size(); i ++ )
		for(int j = 1; j <= 9; j ++ ) ans += f[i][j];
	return ans;
}
void solve(){
	init();
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
	int T = 1;
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}