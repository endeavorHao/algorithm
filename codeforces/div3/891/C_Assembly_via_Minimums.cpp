#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve() {
    int n;
    cin >> n;
    vector<int> b(n * (n - 1) / 2);
    map<int, int> mp;
    int maxv = 0;
    for(int i = 0; i < n * (n - 1) / 2;  i ++ ) cin >> b[i], mp[b[i]] ++, maxv = max(maxv, b[i]);
    int cnt = n - 1;
    for(auto u: mp){
        if(u.y == cnt) cout << u.x << ' ', cnt --;
        else{
            while(u.y){
                u.y -= cnt;
                cnt --;
                cout << u.x << ' ';
            }
        }
    } 
    cout << maxv << ' ';
    cout << endl;
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