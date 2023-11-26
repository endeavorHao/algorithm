#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
void solve(){
	string n, m;
	cin >> n >> m;
    reverse(n.begin(), n.end());
    reverse(m.begin(), m.end());
	int s1 = 0, s2 = 0;
	for(int i = 0; i < n.size(); i ++ )
        if(n[i] == '1') s1 += (1ll << i);
    for(int i = 0; i < m.size(); i ++ )
        if(m[i] == '1') s2 += (1ll << i);
    if(s1 == 0 && s2 != 0) cout << "-1" << endl; 
	else cout << abs(s2 - s1) << endl;
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