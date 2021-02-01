#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> v;

int count_initial(int &w) {
	int min = INT_MAX, max = INT_MIN;
	int cur = 0;
	for (unsigned int i = 0; i < v.size(); i++) {
		cur += v[i];
		if (cur > max) { max = cur; }
		if (cur < min) { min = cur; }
	}
	if (max > w || min < -w || max - min > w) { return 0; }
	if (min >= 0) { return w - max + 1; }
	if (max <= 0) { return w + min + 1; }
	return (w - max) + min + 1;
}

int main() {
	int n, w; cin >> n >> w; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	cout << count_initial(w) << endl;
	cin.ignore(2); return 0;
}