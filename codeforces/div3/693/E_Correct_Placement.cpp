#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
void solve(){
	int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for(int i = 0; i < n; i ++ ){
        int h, w;
        cin >> h >> w;
        if(h > w) swap(h, w);
        a[i] = {h, w, i};
    }
    sort(all(a));
    vector<int> ans(n, -1);
    int mi = 1e9, pos = -1;
    for(int i = 0; i < n; i ++ ){
        int x = i;
        while(x < n && a[x][0] == a[i][0]){
            if(a[x][1] > mi){
                ans[a[x][2]] = pos + 1;
            }
            x ++;
        }
        x = i;
        while(x < n && a[x][0] == a[i][0]){
            if(a[x][1] < mi){
                mi = a[x][1];
                pos = a[x][2];
            }
            x ++;
        }
        i = x - 1;
    }
    for(auto u: ans) cout << u << ' ';
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