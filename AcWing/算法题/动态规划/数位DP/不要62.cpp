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
	for(int i = 0; i <= 9; i ++ )
		if(i == 4) continue;
		else f[1][i] ++;
	for(int i = 2; i < N; i ++ )
		for(int j = 0; j <= 9; j ++ )
			for(int k = 0; k <= 9; k ++ )
				if(j == 4 || j == 6 && k == 2 || k == 4) continue;
				else f[i][j] += f[i-1][k];
}
int dp(int n){
	if(!n) return 1;
	vector<int> nums;
	while(n) nums.push_back(n % 10), n /= 10;

	int ans = 0, last = 0;
	for(int i = nums.size() - 1; i >= 0; i -- ){
		int x = nums[i];
		for(int j = 0; j < x; j ++ ){
			if(j == 4 || last == 6 && j == 2) continue;
			ans += f[i + 1][j];
		}
		
		if(x == 4 || last == 6 && x == 2) break;
		last = x;
		if(!i) ans ++;
	}
	return ans;
}
void solve(){
	int l, r;
	init();
	while(cin >> l >> r, l || r ){
		cout << dp(r) - dp(l - 1) << endl;
	}
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