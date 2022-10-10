#include <bits/stdc++.h>
using namespace std;

string t = "";

int bfs() {
	if ("123456789" == t) { return 0; }
	string s = "123456789";
	unordered_map<string, int> dist; 
	dist[s] = 0; dist.reserve(500009);
	queue<string> Q; Q.push(s); 
	
	while (!Q.empty()) {
		string cur = Q.front(); Q.pop();
		string U = cur;	for (int i = 0; i < 9; i++){
			if (i % 3) {
				swap(cur[i], cur[i - 1]);
				if (cur == t) { return 1 + dist[U]; }
				if (!dist.count(cur)) { Q.push(cur); dist[cur] = 1 + dist[U]; }
				swap(cur[i], cur[i - 1]);
			}
			if (i > 2) {
				swap(cur[i], cur[i - 3]);
				if (cur == t) { return 1 + dist[U]; }
				if (!dist.count(cur)) { Q.push(cur); dist[cur] = 1 + dist[U]; }
				swap(cur[i], cur[i - 3]);
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++) {
		char c; cin >> c;
		t.push_back(c);
	}

	cout << bfs() << '\n';
}