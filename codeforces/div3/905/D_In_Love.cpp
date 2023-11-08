#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
    int q;
    cin >> q;
    multiset<int> s, t;
    while(q -- ){
        char op;
        int l, r;
        cin >> op >> l >> r;
        if(op == '+') s.insert(l), t.insert(r);
        else s.erase(s.find(l)), t.erase(t.find(r));
        
        if(s.size() && *s.rbegin() > *t.begin()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
signed main() {
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