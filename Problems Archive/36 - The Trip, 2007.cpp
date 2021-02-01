#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count(vector<int> &bags) {
	int max_count = 0;
	int count = 0;

	for (unsigned int i = 0; i < bags.size(); i++) {
		int &current = bags[i];
		while (i < bags.size() && bags[i] == current) {
			count++; i++;
		}
		if (count > max_count) {
			max_count = count;
		}
		count = 0; i--;
	}
	return max_count;
}

void trip(vector<int> &bags) {
	int mode = count(bags);
	vector<vector<int> > pieces;
	pieces.resize(mode);
	for (unsigned int i = 0; i < bags.size(); i++) {
		int j = i % mode;
		pieces[j].push_back(bags[i]);
	}
	cout << mode << endl;
	for (int i = 0; i < mode; i++) {
		for (unsigned int j = 0; j < pieces[i].size(); j++) {
			cout << pieces[i][j];
			if (j + 1 != pieces[i].size()) { cout << " "; }
		}
		cout << endl;
	}
}

int main() {
	int n; cin >> n;
	while (n != 0) {
		vector<int> bags;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			bags.push_back(a);
		}
		sort(bags.begin(), bags.end());
		trip(bags);
		cin >> n;
		if (n != 0) { cout << endl; }
	}
	return 0;
}