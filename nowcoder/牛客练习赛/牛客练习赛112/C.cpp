#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N], pos[N];
int q[N];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i ++ ){
		int x;
		cin >> x;
		pos[x] = i;
	}
	for(int i = 0; i < n; i ++ ){
		int x;
		cin >> x;
		a[i] = pos[x];
	}
	int len = 0;
	for(int i = 0; i < n; i ++ ){
		int l = 0, r = len;
		while(l < r){
			int mid = l + r + 1 >> 1;
			if(q[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		q[r + 1] = a[i];
		len = max(len, r + 1);
	}
	cout << n - len << endl;
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