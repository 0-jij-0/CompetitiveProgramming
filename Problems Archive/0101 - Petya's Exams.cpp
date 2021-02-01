#include <iostream>
#include <vector>
#include <map>
using namespace std;

multimap<int, pair<int, int>> exam;
vector<int> c, exam_days;

void fill_sched(int n, int m) {
	vector<int> res; res.resize(n + 1);
	multimap<int, pair<int, int>>::iterator it = exam.begin();
	map<int, int> quest_given;
	for (int i = 1; i <= n; i++) {
		while (it != exam.end() && it->first == i) { 
			pair<int, int> p(it->second.first, it->second.second);
			quest_given.insert(p); it++;
		}
		if (exam_days[i] != 0) {
			if (c[exam_days[i]] != 0) { cout << -1 << endl; return; }
			res[i] = m + 1; continue;
		}
		if (quest_given.empty()) { res[i] = 0; continue; }
		int idx = quest_given.begin()->second;
		res[i] = idx;
		c[idx]--; if (c[idx] == 0) { quest_given.erase(quest_given.begin()); }
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i];
		if (i != n) { cout << " "; }
		else { cout << endl; return; }
	}
}

int main() {
	int n, m; cin >> n >> m;
	c.resize(m + 1); exam_days.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int s, d, c_; cin >> s >> d >> c_;
		pair<int, int> p1(d, i); pair<int, pair<int, int>> p(s, p1);
		exam_days[d] = i; exam.insert(p); c[i] = c_;
	}
	fill_sched(n, m);
	cin.ignore(2); return 0;
}