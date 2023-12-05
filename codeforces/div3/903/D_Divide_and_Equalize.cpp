#include <bits/stdc++.h>
#define x first
#define y second
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
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    map<int, int> mp;
    for(int i = 0; i < n; i ++ ){ 
        for(int j = 2; j * j <= a[i]; j ++ ) {
            if(a[i] % j == 0) {
                int s = 0;
                while(a[i] % j == 0) {
                    a[i] /= j;
                    s ++;
                }
                mp[j] += s;
            } 
        }
        if(a[i] > 1) mp[a[i]] ++;
    }
    for(auto [x, y]: mp) {
        if(y % n) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
signed main() {
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