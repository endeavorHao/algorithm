#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
set<int> s;
void solve(){
	int x;
    cin >> x;
    for(int i = 1; i <= 1e4; i ++ ) 
        if(s.count(x - i * i * i)){
            cout << "YES" << endl;
            return;
        }  
    cout << "NO" << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    for(int i = 1; i <= 5e4; i ++ ) s.insert(i * i * i);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}