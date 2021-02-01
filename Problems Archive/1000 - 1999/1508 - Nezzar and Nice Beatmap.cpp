#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> Point;

ll dist2(Point A, Point B) {
	ll dx = A.first - B.first;
	ll dy = A.second - B.second;
	return dx * dx + dy * dy;
}

vector<Point> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x.first >> x.second; }
	vector<int> vis(n), res(n); int cur = 0;
	for (int k = 0; k < n; k++) {
		vis[cur] = true; res[k] = cur + 1;

		int nextCur = cur; for (int i = 0; i < n; i++) if (!vis[i])
			if (dist2(v[cur], v[i]) > dist2(v[cur], v[nextCur])) nextCur = i;

		cur = nextCur;
	}
	for (auto& x : res) cout << x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}