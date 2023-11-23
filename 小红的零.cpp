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
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    vector<int> s2(n), s5(n);
    for(int i = 0; i < n; i ++ ) {
        int x = a[i];
        while(x % 2 == 0) {
            s2[i] ++;
            x /= 2;
        }
        while(x % 5 == 0) {
            s5[i] ++;
            x /= 5;
        }
    }   
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