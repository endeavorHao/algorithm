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
    vector<int> b(n);
    int ret = 0;
    auto merge_sort = [&](auto self, int l, int r)->int{
        if(l == r) return 0;
        int mid = l + r >> 1;
        ret = self(self, l, mid) + self(self, mid + 1, r);

        int k = 0, i = l, j = mid + 1;
        while(i <= mid && j <= r){
            if(a[i] < a[j]) b[k ++ ] = a[i ++ ];
            else b[k ++ ] = a[j ++ ], ret += (mid - i + 1);
        }
        while(i <= mid) b[k ++ ] = a[i ++ ];
        while(j <= r) b[k ++ ] = a[j ++ ];

        for(int i = l, j = 0; i <= r; i ++, j ++ ) a[i] = b[j];
        return ret;
    };
    cout << merge_sort(merge_sort, 0, n - 1) << endl;
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