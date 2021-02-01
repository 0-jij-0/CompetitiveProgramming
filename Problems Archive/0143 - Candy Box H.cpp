#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<long long, int>> freq;
priority_queue<int> pq;

bool operator <(const pair<long long, int> &p1, const pair<long long, int> &p2) {
	return p1.first < p2.first;
}

void find_max() {
	vector<long long> choices;
	sort(freq.begin(), freq.end());
	long long num = freq.back().first, sum = 0;
	for (int i = freq.size() - 1; i >= 0; i--) {
		long long &a = freq[i].first;
		if (a >= num) { choices.push_back(num); sum += num; num--; }
		else { choices.push_back(a); sum += a; num = a - 1; }
		if (num <= 0) { break; }
	}
	int j = freq.size() - 1, ones = 0; num = 0;
	for (unsigned int i = 0; i < choices.size(); i++) {
		if (num != choices[i]) {
			for (; j >= 0; j--) {
				if (freq[j].first < choices[i]) { break; }
				pq.push(freq[j].second);
			}
			num = choices[i];
		}
		ones += (pq.top() < num) ? pq.top() : num; if (!pq.empty()) { pq.pop(); }
	}
	cout << sum << " " << ones << endl;
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int n; cin >> n; pair<int, int> z(0, 0);
		while (!pq.empty()) { pq.pop(); }
		freq.clear(); freq.resize(n + 1, z);
		for (int j = 0; j < n; j++) {
			int a, b; cin >> a >> b;
			freq[a].first++; freq[a].second += b;
		}
		find_max();
	}
	cin.ignore(2); return 0;
}