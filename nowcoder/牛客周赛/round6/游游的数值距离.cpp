#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    vector<int> f(22);
    f[0] = 1;
    for(int i = 1; i < 20; i ++ ) f[i] = f[i - 1] * i;
    int x = 1, y = 1;
    int t = n;
    for(int i = 3; i < 20; i ++ ){
        int j = n / (f[i] - 1);
        int h = abs(n - j * (f[i] - 1));
        if(h < t && j > 0 && j != 2){
            t = h;
            x = i, y = j;
        }
        j ++;
        h = abs(n - j * (f[i] - 1));
        if(h < t && j > 0 && j != 2){
            t = h;
            x = i, y = j;
        }
    }
    cout << x << ' ' << y << endl;
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