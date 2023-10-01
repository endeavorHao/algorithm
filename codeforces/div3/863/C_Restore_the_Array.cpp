#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    vector<int> b(n - 1);
    for(int i = 0; i < n - 1; i ++ ) cin >> b[i];
    vector<int> a(n);
    a[n - 1] = a[n - 2] = b[n - 2];
    for(int i = n - 3; i >= 0; i -- ){
        if(b[i] > a[i + 1]){
            a[i] = b[i];
        }else{
            a[i] = a[i + 1] = b[i];
        }
    }
    for(auto u: a) cout << u << ' ';
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