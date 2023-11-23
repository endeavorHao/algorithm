#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 998244353;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int> power(n + 1, 1);
    power[1] = 1;
    for(int i = 2; i <= n; i ++ ) power[i] = power[i - 1] * i % mod;
    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= n; j ++ ) {
            if(i == j) continue;
            if(j > i) ans += i * (n - j + 1) * power[n - 2];
            else ans += j * (n - i + 1) * power[n - 2];
        }
    }   
    cout << ans << endl;
    ans = 0;
    for(int i = 1; i <= n; i ++ ) {
        ans = (ans + power[n - 2] * (i * ((i + 1 + n) * (n - i - 1) / 2 ) + (n - i + 1) * ((1 + i) * i / 2)));
        cout << i * ((i + 1 + n) * (n - i - 1) / 2 ) << " " << (n - i + 1) * ((1 + i) * i / 2) << endl;
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