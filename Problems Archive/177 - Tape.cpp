#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v;
priority_queue<int> pq;

int main() {
	int n, m, k; cin >> n >> m >> k; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	for (int i = 1; i < n; i++) { pq.push(v[i] - v[i - 1]); }
	int tape = 1, len = v.back() - v.front() + 1;
	while (tape != k) {
		len -= pq.top() - 1; pq.pop(); tape++;
	}
	cout << len << endl;
	cin.ignore(2); return 0;
}