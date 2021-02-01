#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;
vector<int> v;
int n, k;

int find_min(int k) {
	int sum = v.back() - v.front(); k--;
	while (k != 0) {
		int idx = pq.top().second; pq.pop();
		sum += v[idx] - v[idx + 1]; k--;
	}
	return sum;
}

int main() {
	cin >> n >> k; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	for (int i = 0; i < n - 1; i++) {
		pair<int, int> p(v[i + 1] - v[i], i);
		pq.push(p);
	}
	cout << find_min(k) << endl;
	cin.ignore(2); return 0;
}