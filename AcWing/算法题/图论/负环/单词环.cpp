#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 710, M = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int n;
double dist[N];
int cnt[N];
bool st[N];
int h[N], e[M], ne[M], w[M], idx;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
bool spfa(double mid){
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    queue<int> q;
    for(int i = 0; i < 26 * 26; i ++ ){
        q.push(i);
        st[i] = true;
    }
    int count = 0;
    while(q.size()){
        auto t = q.front();
        q.pop();
        st[t] = false;

        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i] - mid){
                dist[j] = dist[t] + w[i] - mid;
                cnt[j] = cnt[t] + 1;
                if( ++count >= 5000) return true;
                if(cnt[j] >= N) return true;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}
void solve(){
	while(cin >> n, n){
        memset(h, -1, sizeof h);
        idx = 0;
        string s;
        for(int i = 0; i < n; i ++ ){
            cin >> s;
            int len = s.size();
            if(len >= 2){
                int left = (s[0] - 'a') * 26 + s[1] - 'a';
                int right = (s[len - 2] - 'a') * 26 + s[len - 1] - 'a';
                add(left, right, len);
            }
        }

        if(!spfa(0)) cout << "No solution" << endl;
        else{
            double l = 0, r = 1000;
            while(r - l > 1e-4){
                double mid = (l + r) / 2;
                if(spfa(mid)) l = mid;
                else r = mid;
            }
            cout << r << endl;
        }
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