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
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int mi = 0, mipos = -1, minum = 0;
    int ma = 0, mapos = -1, manum = 0;
    for(int i = 0; i < n; i ++ ){
        if(a[i] < 0){
            if(mi > a[i]){
                mi = a[i];
                mipos = i;
            }
            minum ++;
        }else if(a[i] > 0){
            if(ma < a[i]){
                ma = a[i];
                mapos = i;
            }
            manum ++;
        }
    }
    if(max(minum, manum) <= 12){
        ;
    }
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