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

    for(int i = 2; i <= N; i ++ )
        for(int j = 0; j <= 9; j ++ )
            for(int k = j; k <= 9; k ++ )
                f[i][j] += f[i-1][k];
}
int dp(int x){
    if(!x) return 1;
    vector<int> nums;
    while(x) nums.push_back(x % 10), x /= 10;

    int ans = 0, last = 0;
    for(int i = nums.size() - 1; i >= 0; i -- ){
        int t = nums[i];
        for(int j = last; j < t; j ++ ) ans += f[i + 1][j];

        if(t < last) break;
        if(i == 0) ans ++;
        last = t;
    }
    return ans;
}
void solve(){
    init();
    int l, r;
	while(cin >> l >> r){
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