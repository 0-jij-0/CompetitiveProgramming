#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<int> skills;
vector<int> teams;

bool operator < (pair<int, int> &p1, pair<int, int> &p2) { return p1.first < p2.first; }

priority_queue<pair<int, int>> max_skills;

void fill_teams(int &k) {
	map<int, int> indices;
	for (unsigned int i = 0; i < skills.size(); i++) { indices[i] = i; }
	int team = 0;
	while (!max_skills.empty()) {
		team %= 2;

		while (teams[max_skills.top().second] != -1) { 
			max_skills.pop(); 
			if (max_skills.empty()) { break; }
		}
		if (max_skills.empty()) { break; }

		int idx = max_skills.top().second;
		max_skills.pop();
		teams[idx] = team;
		map<int, int>::iterator right = indices.find(idx);
		map<int, int>::iterator left = right; 
		bool b = true;
		if (left != indices.begin()) { left--; b = false; }
		right = indices.erase(right);

		int count = 0;
		while (count < k && right != indices.end()) { 
			teams[right->first] = team;
			right = indices.erase(right);
			count++; continue;
		}

		if (b) { team++; continue; }

		count = 0;
		while(count < k) {
			teams[left->first] = team;
			left = indices.erase(left);
			if (left == indices.begin()) { break; }
			left--; count++; continue;
		}
		team++;
	}
}

int main() {
	int n, k; cin >> n >> k;
	teams.resize(n, -1);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		skills.push_back(a);
		pair<int, int> p(a, i);
		max_skills.push(p);
	}
	fill_teams(k);
	for (int i = 0; i < n; i++) { cout << teams[i] + 1; }
	cout << endl;
	return 0;
}

