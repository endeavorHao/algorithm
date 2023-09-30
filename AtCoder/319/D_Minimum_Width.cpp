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
	int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    auto check = [&](int x) -> bool{
        int sum = 1;
        int len = 0;
        for(int i = 0; i < n; i ++ ){
            if(len + a[i] + 1 > x){
                sum ++;
                len = 0;
                i --;
            }else if(len + a[i] + 1 == x){
                sum ++;
                len = 0;
            }else{
                len = len + 1 + a[i];
            }
        }
        if(sum > m) return false;
        return true;
    };
    int l = 0, r = 1e18;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << endl;
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