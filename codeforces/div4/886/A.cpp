#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a + b >= 10 || a + c >= 10 || b + c >= 10) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
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