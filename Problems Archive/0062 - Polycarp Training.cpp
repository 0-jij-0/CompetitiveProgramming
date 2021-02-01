#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> problems;

int training_days() {
	sort(problems.begin(), problems.end());
	int day = 1;
	for (int i = 0; i < problems.size(); i++) {
		if (problems[i] < day) { continue; }
		day++;
	}
	return day - 1;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		problems.push_back(a);
	}
	cout << training_days() << endl;
	return 0;
}

