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
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < n; i ++ ) cin >> b[i];
    sort(all(b));
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j){
        return a[i] < a[j];
    });
    vector<int> c(n);
    for(int i = 0; i < x; i ++ ) {
        c[p[i + n - x]] = b[i];
        if(a[p[i + n - x]] <= b[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = 0; i < n - x; i ++ ) {
        c[p[i]] = b[i + x];
        if(a[p[i]] > b[i + x]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i ++ ) cout << c[i] << " \n"[i == n - 1];
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