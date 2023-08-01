#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010;
struct node{
    int a, b, c;
    bool operator<(const node& t){
        return c < t.c;
    }
}edge[N];

void solve(){
	int n, m, k;
    cin >> n >> m;
    for(int i = 0; i < m; i ++ ){
        int a, b, c;
		cin >> a >> b >> c;
		edge[i] = {a, b, c};
    }
	sort(edge, edge + m);
	cin >> k;
	vector<vector<int>> q(k);
	for(int i = 0; i < k; i ++ ){
		int x;
		cin >> x;
		for(int j = 0; j < x; j ++ ){
			int u;
			cin >> u;
			q[i].push_back(u);
		}
	}
	vector<int> p(n + 1);
	auto find = [&](auto self, int x) -> int{
		if(x != p[x]) p[x] = self(self, p[x]);
		return p[x];
	};
	auto check = [&](int mid) -> bool{
		for(int i = 1; i <= n; i ++ ){
			p[i] = i;
		}
		for(int i = 0; i < mid; i ++ ){
			int a = edge[i].a, b = edge[i].b;
			int pa = find(find, a), pb = find(find, b);
			if(pa != pb) p[pa] = pb;
		}
		for(int i = 0; i < k; i ++ ){
			int x = find(find, q[i][0]);
			for(int j = 0; j < q[i].size(); j ++ ){
				int b = q[i][j];
				int pb = find(find, b);
				if(x != pb){
					return false;
				}
			}
		}
		return true;
	};
	int l = 0, r = m;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)){
			r = mid;
		}else l = mid + 1;
	}
	cout << edge[r].c << endl;
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