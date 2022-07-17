#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student { int i = 0, m = 0, e = 0; };

bool compareMath(const Student& a, const Student& b) {
	return (a.m != b.m) ? a.m < b.m : a.i > b.i;
}

bool compareEnglish(const Student& a, const Student& b) {
	return (a.e != b.e) ? a.e < b.e : a.i > b.i;
}

bool compareSum(const Student& a, const Student& b) {
	return (a.m + a.e != b.m + b.e) ? a.m + a.e < b.m + b.e : a.i > b.i;
}

vector<Student> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, x, y, z; cin >> n >> x >> y >> z; v.resize(n); 
	for (int i = 0; i < n; i++) v[i].i = i;
	for (int i = 0; i < n; i++) cin >> v[i].m;
	for (int i = 0; i < n; i++) cin >> v[i].e;

	vector<int> res;

	sort(v.begin(), v.end(), compareMath);
	while (x--) { res.push_back(v.back().i + 1); v.pop_back(); }

	sort(v.begin(), v.end(), compareEnglish);
	while (y--) { res.push_back(v.back().i + 1); v.pop_back(); }

	sort(v.begin(), v.end(), compareSum);
	while (z--) { res.push_back(v.back().i + 1); v.pop_back(); }

	sort(res.begin(), res.end());
	for (auto& x : res) cout << x << '\n';
}