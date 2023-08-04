#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, hp;
int son[N][2];
int ret[N * 32], idx;
void insert(int x, int t){
	int p = 0;
	for(int i = 31; i >= 0; i -- ){
		int u = x >> i & 1;
		if(!son[p][u]) son[p][u] = ++ idx;
		p = son[p][u];
		ret[p] += t;
	}
}
int query(int x, int h) {
  int p = 0, res = 0;
  for (int i = 31; ~i; i--) {
    int v = h >> i & 1;
    int u = x >> i & 1;
    if(v == 1){
		p = son[p][!u];
	}else{
		res += ret[son[p][!u]];
		p = son[p][u];
	}
	if(!p) return res;
  }
  return res;
}
void solve(){
	cin >> n >> hp;
	while(n -- ){
		int op, x;
		cin >> op >> x;
		if(op == 0) insert(x, 1);
		else if(op == 1) insert(x, -1);
		else{
			int h;
			cin >> h;
			int res = query(x, h);
			if(!res) hp --;
			cout << res << endl;
		}
	}
	cout << hp << endl;
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