#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;

long long count_pairs() {
	sort(ans.begin(), ans.end());
	long long count = 0; unsigned int j = 1;
	for (unsigned int i = 0; i < ans.size(); i++) {
		while (j < ans.size() && ans[j] <= 2 * ans[i]) { j++; }
		count += j - i - 1;
	}
	return count;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		ans.push_back(abs(a));
	}
	cout << count_pairs() << endl;
	return 0;
}

