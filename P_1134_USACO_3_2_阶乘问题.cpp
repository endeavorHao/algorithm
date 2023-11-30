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
    cin >> n;
    int ans = 1;
    int c2 = 0, c5 = 0;
    for(int i = 1; i <= n; i ++ ) {
        int x = i;
        while(x % 2 == 0) {
            x /= 2;
            c2 ++;
        }
        while(x % 5 == 0) {
            x /= 5;
            c5 ++;
        }
        ans = ans * x % 10;
        ans %= 10;
    }   
    for(int i = 1; i <= c2 - c5; i ++ ) {
        ans = ans * 2 % 10;
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T -- ){
        solve();
    }
    return 0;
}