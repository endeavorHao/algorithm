#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 12, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m, p;
int f[N][N][110];
int mod(int x){
	return (x % p + p) % p;
}
void init(){
    memset(f, 0, sizeof f);
	for(int i = 0; i <= 9; i ++ ) f[1][i][i % p] ++;

	for(int i = 2; i < 11; i ++ )
		for(int j = 0; j <= 9; j ++ ){
			for(int k = 0; k < p; k ++ )
				for(int s = 0; s <= 9; s ++ )
					f[i][j][k] += f[i-1][s][mod(k - j)]; 
		}
}
int dp(int n){
	if(!n) return 1;
	vector<int> nums;
	while(n) nums.push_back(n % 10), n /= 10;

	int ans = 0, last = 0;
	for(int i = nums.size() - 1; i >= 0; i -- ){
		int x = nums[i];
		for(int j = 0; j < x; j ++ ){
			ans += f[i + 1][j][mod(-last)];
		}
		
		last += x;
		if(!i && last % p == 0) ans ++;
	}
	return ans;
}
void solve(){
	int l, r;
	while(cin >> l >> r >> p){
	    init();
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