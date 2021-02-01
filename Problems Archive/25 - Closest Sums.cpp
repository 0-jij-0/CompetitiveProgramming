#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int closestSum(vector<int> &v, int x) {
	sort(v.begin(), v.end());
	int i = 0;
	int j = v.size() - 1;
	int closest = v[i] + v[j];
	while (i < j) {
		int sum = v[i] + v[j];
		if (sum == x) { return sum; }
		int a = (closest < x) ? x - closest : closest - x;
		int b = (sum < x) ? x - sum : sum - x;
		closest = (b < a) ? sum : closest;
		if (sum > x) { j--; continue; }
		i++;
	}
	return closest;
}

int main() {
	int n; cin >> n;
	int j = 1;
	while (n != 0) {
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			v.push_back(num);
		}
		int m; cin >> m;
		vector<int> queries;
		for (int i = 0; i < m; i++) {
			int num; cin >> num;
			queries.push_back(num);
		}
		cout << "Case " << j << ":" << endl;
		for (int i = 0; i < m; i++) {
			cout << "Closest sum to " << queries[i] << " is " << closestSum(v, queries[i]) << "." << endl;
		}
		j++; cin >> n;
	}
	cout << endl; cin.ignore(2); return 0;
}