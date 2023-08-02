#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
struct node{
	int x, y, v;
}point[N];
struct Node{
	int a, b, t;
	bool operator<(const Node&w)const{
		return t < w.t;
	}
}s[N];
int cnt;
int p[N];
int ans[N];
int find(int x){
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ ){
		int x, y, v;
		cin >> x >> y >> v;
		point[i] = {x, y, v};
	}
	for(int i = 1; i <= n; i ++ ){
		for(int j = i + 1; j <= n; j ++ ){
			int x1 = point[i].x, y1 = point[i].y;
			int x2 = point[j].x, y2 = point[j].y;
			double dist = sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2));
			int v = point[i].v + point[j].v;
			int t = 0;
			int d = 0;
			if(!v) t = 1001;
			else{
				
				if(dist - (int)dist < 1e-6) d = dist;
				else d = dist + 1;
				t = (d + v - 1) / v;
			}
			s[cnt ++ ] = {i, j, t};
		}
	}
	sort(s, s + cnt);
	for(int i = 1; i <= n; i ++ ) p[i] = i;
	int sum = n;
	for(int i = 0, j = 0; i <= 1001 || j < cnt; i ++ ){
		while(j < cnt && s[j].t <= i){
			int a = s[j].a, b = s[j].b;
			int pa = find(a), pb = find(b);
			if(pa != pb){
				p[pa] = pb;
				sum --;
			}
			j ++;
		}
		ans[i] = sum;
	}
	int q;
	cin >> q;
	while(q -- ){
		int t;
		cin >> t;
		cout << ans[t] << endl;
	}
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
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