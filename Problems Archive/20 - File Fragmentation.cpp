#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

struct compare {
	bool operator ()(pair<string, int> p1, pair<string, int> p2) {
		return p1.second < p2.second;
	}
};

void remove_duplicates(vector<string> &fragments) {
	sort(fragments.begin(), fragments.end());
	for (int i = fragments.size() - 1; i > 0; i--) {
		if (fragments[i] == fragments[i - 1]) {
			fragments.erase(fragments.begin() + i);
		}
	}
}

int size(vector<string> &fragments) {
	int sum = 0;
	for (unsigned int i = 0; i < fragments.size(); i++) {
		sum += fragments[i].size();
	}
	return (2 * sum) / fragments.size();
}

string file(vector<string> &fragments) {
	int size_of_file = size(fragments);

	remove_duplicates(fragments);
	if (fragments.size() == 1) { return fragments[0] + fragments[0]; }

	map<string, int> files;
	for (unsigned int i = 0; i < fragments.size(); i++) {
		for (unsigned int j = 0; j < fragments.size(); j++) {
			if (i != j) {
				string a = fragments[i] + fragments[j];
				string b = fragments[j] + fragments[i];

				if (a.size() == size_of_file) {
					files[a]++; files[b]++;
				}
			}
		}
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, compare> all_files;
	map<string, int>::iterator it = files.begin();
	for (; it != files.end(); it++) {
		pair<string, int> p(it->first, it->second);
		all_files.emplace(p);
	}
	return all_files.top().first;
}

int main() {
	int n; cin >> n;
	string s;
	getline(cin, s);
	getline(cin, s);

	for (int i = 0; i < n; i++) {
		vector<string> fragments;
		while (getline(cin, s) && !s.empty()) {
			fragments.push_back(s);
		}
		cout << file(fragments) << endl;
		if (i + 1 != n) { cout << endl; }
	}

	cout << endl; cin.ignore(2); return 0;
}
