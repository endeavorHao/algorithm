#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i] >> b[i];
    map<int, int> mp;
    map<int, int> cnt;
    for(int i = 0; i < n; i ++ ){
        mp[a[i]] = b[i];
        cnt[a[i]] ++, cnt[b[i]] --;
    }
    int val = 0;
    for(auto [x, y]: cnt){
        if(y == 1) val = x;
    }
    int val2 = mp[0];
    while(1){
        if(val)
            cout << val << ' ';
        if(val2)
            cout << val2 << ' ';
        if(!val || !val2) break;
        val = mp[val];
        val2 = mp[val2];
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