#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<vector<int>> freq;

int main() {
	int n; cin >> n; v.resize(n);
	freq.resize(1000001);
	for (int i = 0; i < n; i++) {
		cin >> v[i]; freq[v[i]].push_back(i);
	}
	int max_freq = 1, min_size = n + 1, l = -1, r = -1;
	for (int i = 0; i <= 1000000; i++) {
		if (freq[i].size() < max_freq) { continue; }
		int size = freq[i].back() - freq[i].front() + 1;
		if (freq[i].size() > max_freq) {
			max_freq = freq[i].size(); min_size = size;
			l = freq[i].front(); r = freq[i].back();
			continue;
		}
		if (size >= min_size) { continue; }
		l = freq[i].front(); r = freq[i].back(); min_size = size;		
	}
	cout << l + 1 << ' ' << r + 1 << endl;
	cin.ignore(2); return 0;
}