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
	int k;
    string t;
    cin >> k >> t;
    auto smilar = [&](string &s, string &t)->bool{
        if(abs((int)s.size() - (int)t.size()) > 1) return false;
        if(s == t) return true;
        int l = 0, r = 0;
        while(l < s.size() && l < t.size() && s[l] == t[l]) l ++;
        while(r < s.size() && r < t.size() && s.end()[-1 - r] == t.end()[-1 - r]) r ++;
        return l + r >= max(s.size(), t.size()) - 1;
    };
    vector<int> ans;
    for(int i = 1; i <= k; i ++ ) {
        string s;
        cin >> s;
        if(smilar(s, t)) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << " ";
    cout << "\n";
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