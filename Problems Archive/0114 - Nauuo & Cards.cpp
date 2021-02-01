#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> dist;

int find_min(int n) {
	bool start = false;
	int back = v.back();
	int i = v.size() - 1;
	while (i > 0 && v[i-1] != 0 && v[i] == v[i - 1] + 1) { 
		i--;
	}
	if (v[i] == 1) { start = true; }
	if (start) {
		for (int i = back + 1; i <= n; i++) {
			if (dist[i] >= i - back) { start = false; break; }
		}
		if (start) { return n - back; }
	}
	int max = -1;
	for (int i = 1; i <= n; i++) {
		if (dist[i] >= i){
			int d = dist[i] - i;
			if (d > max) { max = d; }
		}
	}
	return n + max + 1;
}

int main() {
	int n; cin >> n;
	v.resize(n); dist.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a != 0) { dist[a] = 0; }
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v[i] = a;
		if (a != 0) { dist[a] = i + 1; }
	}
	cout << find_min(n) << endl;
	cin.ignore(2); return 0;
}