#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int f[15][10];
void init(){
    for(int i = 0; i < 10; i ++ ) if(i != 4) f[1][i] = 1;
    for(int i = 2; i <= 13; i ++ ){
        for(int j = 0; j < 10; j ++ ){
            if(j == 4) continue;
            for(int k = 0; k < 10; k ++ ){
                if(k == 4) continue;
                f[i][j] += f[i - 1][k];
            }
        }
    }
}
int dp(int n){
    if(!n) return 1;
    vector<int> nums;
    while(n) nums.push_back(n % 10), n /= 10;

    int ans = 0;
    for(int i = nums.size() - 1; i >= 0; i -- ){
        int x = nums[i];
        for(int j = 0; j < x; j ++ ){
            if(j == 4) continue;
            ans += f[i + 1][j];
        }
        if(x == 4) break;
        if(!i) ans ++;
    }
    return ans;
}
void solve(){
    init();
    int T;
    cin >> T;
    while(T -- ){
        int x;
        cin >> x;
        int l = 0, r = 1e13;
        while(l < r){
            int mid = l + r >> 1;
            if(dp(mid) - 1 >= x) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }
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