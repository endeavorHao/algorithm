#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
typedef pair<int, int> PII;
void solve(){
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	set<PII> S;
	vector<int> las(n + 1, -1), nex(n + 1, n);
	for(int i = 0; i < n; i ++ ){
		las[i + 1] = s[i] == '0' ? i : las[i];
	}
	for(int i = n - 1; i >= 0; i -- ){
		nex[i] = s[i] == '1' ? i : nex[i + 1];
	}
	while(m -- ){
		int l, r;
		cin >> l >> r;
		l --;
		l = nex[l], r = las[r];
		if(l > r){
			l = r = -1;
		}
		S.emplace(l, r);
	}
	cout << S.size() << endl;
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