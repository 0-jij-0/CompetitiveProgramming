#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> points;

bool check(int i, int j, int k) {
	int &xi = points[i].first, &yi = points[i].second;
	int &xj = points[j].first, &yj = points[j].second;
	int &xk = points[k].first, &yk = points[k].second;

	if (xi == xj && xi == xk) { return true; }
	if (xi == xj || xi == xk) { return false; }

	return (yi - yj) * (xi - xk) == (yi - yk) * (xi - xj);
}

int main() {
	int n; cin >> n; points.resize(n);
	for (auto& x : points) cin >> x.first >> x.second;

	bool ok = false;
	for(int i = 0; i < n - 2 && !ok; i++)
		for(int j = i + 1; j < n - 1 && !ok; j++)
			for(int k = j + 1; k < n; k++)
				if (check(i, j, k)) { cout << "Yes" << '\n'; ok = true; break; }

	if (!ok) { cout << "No" << '\n'; }
	cin.ignore(2); return 0;
}