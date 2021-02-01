#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> vert_min;
vector<vector<int>> v;
int n, m;
long long g0, x, y, z;

long long g[10000000];

void fill_vert(int &k) {
	deque<int> d;
	for (int i = 0; i < m; i++) {
		d.clear();
		for (int j = 0; j < k; j++) {
			int &a = v[j][i];
			while (!d.empty() && a <= d.back()) { d.pop_back(); }
			d.push_back(a);
		}
		vert_min[i][0] = d.front();
		for (int j = 1; j <= n - k; j++) {
			int &a = v[j - 1][i], &b = v[j + k - 1][i];
			if (a == d.front()) { d.pop_front(); }
			while (!d.empty() && b <= d.back()) { d.pop_back(); }
			d.push_back(b); vert_min[i][j] = d.front();
		}
	}
}

void fill_g() {
	g[0] = g0;
	for (int i = 1; i < (n * m) + m + 5; i++) {
		g[i] = (g[i - 1] * x + y) % z;
	}
}

long long min_sum(const int &a, const int &b) {
	long long sum = 0; deque<int> d;
	for (int i = 0; i < n - a + 1; i++) {
		d.clear();
		for (int j = 0; j < b; j++) {
			int &u = vert_min[j][i];
			while (!d.empty() && u <= d.back()) { d.pop_back(); }
			d.push_back(u);
		}
		sum += d.front();
		for (int j = 1; j < m - b + 1; j++) {
			int &u = vert_min[j - 1][i]; int &v = vert_min[j + b - 1][i];
			if (u == d.front()) { d.pop_front(); }
			while (!d.empty() && v <= d.back()) { d.pop_back(); }
			d.push_back(v); sum += d.front();
		}
	}
	return sum;
}

int main() {
	int a, b; cin >> n >> m >> a >> b;
	v.resize(n); vert_min.resize(m); 
	for (auto &x : v) { x.resize(m); }	
	for (auto &x : vert_min) { x.resize(n - a + 1); }
	cin >> g0 >> x >> y >> z; fill_g(); 

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v[i][j] = (int) g[i*m + j];

	fill_vert(a);
	cout << min_sum(a, b) << endl;
	cin.ignore(2); return 0;

}