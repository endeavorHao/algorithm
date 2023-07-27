#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
typedef pair<int, string> PIS;
int n, m;
int a[N];
string start;
int f(string s){
	int cnt = 0;
	for(int i = 0; i < s.size(); i ++ ){
		if(s[i] != 'x'){
			int t = s[i] - '1';
			cnt += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
		}
	}
	return cnt;
}
void bfs(){
	string ed = "12345678x";
	map<string, int> dist;
	map<string, pair<string, char>> prev;
	priority_queue<PIS, vector<PIS>, greater<PIS>> heap;
	
	int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; 
	char op[] = {'l', 'u', 'r', 'd'};
	heap.push({f(start), start});
	dist[start] = 0;
	while(heap.size()){
		auto t = heap.top();
		heap.pop();

		string ver = t.y;
		int step = dist[ver];
		if(ver == ed) break;
		int k = ver.find('x');
		int x = k / 3, y = k % 3;
		string source = ver;
		for(int i = 0; i < 4; i ++ ){
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || a >= 3 || b < 0 || b >= 3) continue;
			swap(ver[a * 3 + b], ver[x * 3 + y]);
			if(!dist[ver] || dist[ver] > step + 1){
				dist[ver] = step + 1;
				heap.push({dist[ver] + f(ver), ver});
				prev[ver] = {source, op[i]};
			}
			swap(ver[a * 3 + b], ver[x * 3 + y]);
		}
	}
    string res;
    while(ed != start){
        res += prev[ed].y;
        ed = prev[ed].x;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}
void solve(){
	char x;
	while(cin >> x){
		start += x;
	}

	int cnt = 0;
	for(int i = 0; i < 9; i ++ )
		for(int j = i; j < 9; j ++ ){
			if(start[i] == 'x' || start[j] == 'x') continue;
			if(start[i] > start[j]) cnt ++;
		}
	if(cnt & 1) cout << "unsolvable" << endl;
	else{
		bfs();
		return;	
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