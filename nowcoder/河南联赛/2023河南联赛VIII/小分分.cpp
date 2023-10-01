#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int b[N], b2[N];
int qmi(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void solve(){
	int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l2 < l1) swap(l1, l2), swap(r1, r2);
        if(l2 > r1){
            b[l1] ++, b[r1 + 1] --, b[l2] ++, b[r2 + 1] --;
        }else if(l2 <= r1 && r2 >= r1){
            b[l1] ++, b[r2 + 1] --; 
        }else if(l2 <= r1 && r2 <= r1){
            b[l1] ++, b[r1 + 1] --;
        }
        b2[l1] ++, b2[r1 + 1] --, b2[l2] ++, b2[r2 + 1] --;
    }
    int ans = 0;
    for(int i = 1; i <= 5e5; i ++ ){
        b[i] += b[i - 1];
        b2[i] += b2[i - 1];
        if(b[i] == n){
            ans = (ans + qmi(2, b2[i] - n)) % mod;
        }
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