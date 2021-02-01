#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll endpnts[20005], tasks[20005][205];
const ll mod = ll(1e9 + 7);

struct task {
	int taskNum, pt; ll r;
	vector<int> dependencies;
	int type; //0 runtime, 1 endpoint
	task() {}	
};

struct point {
	int f; vector<task> tasks;
	point() {}
};

ll endtime(point& p, vector<point>&v);

ll tasktime(point& p, task& t, vector<point>& v) {
	if (tasks[p.f][t.taskNum] != -1) { return tasks[p.f][t.taskNum]; }
	ll deppy = 0;
	for (int i = 0; i < (int)t.dependencies.size(); i++)
		deppy = max(tasktime(p, p.tasks[t.dependencies[i] - 1], v), deppy) % mod;

	if (t.type == 0) { deppy = (deppy + (t.r)) % mod; }
	else { deppy = (deppy + endtime(v[(int)t.r - 1], v) + 1ll) % mod; }
	tasks[p.f][t.taskNum] = deppy; return deppy;
}

ll endtime(point& p, vector<point>&v) {
	if (endpnts[p.f] != -1) { return endpnts[p.f]; }
	ll maxy = 0;
	for (int i = 0; i < (int)p.tasks.size(); i++) {
		maxy = (max(tasktime(p, p.tasks[i], v), maxy)) % mod;
	}
	endpnts[p.f] = maxy; return maxy;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i<20005; i++) {
		endpnts[i] = -1;
		for (int j = 0; j<205; j++) {
			tasks[i][j] = -1;
		}
	}
	vector<point> pts(n);
	for (int i = 0; i < n; i++) {
		pts[i].f = i; int k; cin >> k;
		pts[i].tasks.resize(k);
		for (int j = 0; j < k; j++) {
			pts[i].tasks[j].taskNum = j;
			pts[i].tasks[j].pt = i;

			int dep; cin >> dep;
			if (dep > 0) {
				for (int k = 0; k < dep; k++) {
					int temp; cin >> temp;
					pts[i].tasks[j].dependencies.push_back(temp);
				}
			}
			int t; cin >> t; pts[i].tasks[j].type = t;
			int e; cin >> e; pts[i].tasks[j].r = e;
		}
	}

	for (int i = 0; i < m; i++) {
		int q; cin >> q; q--;
		cout << endtime(pts[q], pts) << endl;
	}
	cin.ignore(2); return 0;
}