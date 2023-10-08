#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
struct node{
    int x, id;
    bool operator< (const node & t) const{
        return x < t.x;
    }
}a[N];
int n;
bool check(int mid){
    int sum = 0;
    for(int i = 1; i <= mid; i ++ ){
        sum += a[i].x;
    }
    for(int i = mid + 1; i <= n; i ++ ){
        if(sum < a[i].x) return false;
        sum += a[i].x;
    }
    return true;
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    while(l < r){
        int mid = l + r  >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << n - r + 1  << endl;
    vector<int> ans;
    for(int i = r; i <= n; i ++ ) ans.push_back(a[i].id);
    sort(all(ans));
    for(auto u: ans) cout << u << " ";
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