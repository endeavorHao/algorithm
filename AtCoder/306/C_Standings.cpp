#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
struct node{
    int a, b;
    int id;
    bool operator<(const node&t) const{
        if(a * t.b != t.a * b) return a * t.b > t.a * b;
        return id < t.id;
    }
};
void solve(){
	int n;
    cin >> n;
    vector<node> a(n);
    map<int, int> pos;
    for(int i = 0; i < n; i ++ ){
        int x, y;
        cin >> x >> y;
        a[i] = {x, y, i + 1};
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i ++ ) cout << a[i].id << ' ';
    cout << endl;
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