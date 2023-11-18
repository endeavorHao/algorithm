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
	int n;
    string t;
    cin >> n >> t;
    vector<string> s(n);
    for(int i = 0; i < n; i ++ ) cin >> s[i];
    vector<int> pre(n), suf(n);
    for(int i = 0; i < n; i ++ ) {
        int k = 0;
        for(int j = 0; j < s[i].size(); j ++ ){
            if(s[i][j] == t[k]) k ++;
        }
        pre[i] = k;
    }
    for(int i = 0; i < n; i ++ ) {
        int k = t.size() - 1;
        for(int j = s[i].size() - 1; j >= 0; j -- ){
            if(s[i][j] == t[k]) k --;
        }
        suf[i] = t.size() - k;
    }
    map<int, int> mp1, mp2;
    for(int i = 0; i < n; i ++ ) mp1[pre[i]] ++, mp2[suf[i]] ++;
    int ans = 0, sum = 0;
    for(int i = 0; i <= t.size(); i ++ ) {
        sum += mp2[t.size() - i + 1];
        ans += mp1[i] * sum;
    } 
    cout << ans << endl;
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