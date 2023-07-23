#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int exgcd(int a, int b, int &x, int & y){
	if(!b){
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
void solve(){
	int a, b, n, L, R;
	cin >> a >> b >> n >> L >> R;
	int x, y;
	int d = exgcd(a, b, x, y);
	if(n % d) cout << "NO" << endl;
	else{
		x *= n / d;
		int l = -1e9, r = 1e9;
		while(l < r){
			int mid = l + r >> 1;
			if(x + b / d * mid >= L) r = mid;
			else l = mid + 1; 
		}
		int ans1 = l;
		l = -1e9, r = 1e9;
		while(l < r){
			int mid = l + r + 1 >> 1;
			if(x + b / d * mid <= R) l = mid;
			else r = mid - 1;
		}
		int ans2 = r;
		if(ans2 >= ans1) cout << "YES" << endl;
		else cout << "NO" << endl;

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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}