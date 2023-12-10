#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    map<int, int> mp;
    for(int i = 0; i < n; i ++ ) mp[a[i]] ++;
    vector<int> s(N + 10, 0);   
    for(int i = N; i >= 0; i -- ) {
        s[i] = s[i + 1] + mp[i] * i;
    }
    for(int i = 0; i < n; i ++ ) {
        cout << s[a[i] + 1] << " \n"[i == n - 1]; 
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