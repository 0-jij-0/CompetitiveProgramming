#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> seq;

void fill_right(string &res, int &prev, int &right) {
	while (seq[right] > prev && right >= 0) {
		res.push_back('R'); prev = seq[right]; right--;
	}
	cout << res.size() << endl;
	cout << res << endl;
}
void fill_left(string &res, int &prev, int &left) {
	while (seq[left] > prev && left < seq.size()) {
		res.push_back('L'); prev = seq[left]; left++;
	}
	cout << res.size() << endl;
	cout << res << endl;
}

bool decide(int left, int right) {
	int countL = 0;
	int countR = 0;
	int prev = 0;
	while (left < seq.size() && seq[left] > prev) {
		prev = seq[left]; left++; countL++;
	}
	prev = 0;
	while (right >= 0 && seq[right] > prev) {
		prev = seq[right]; right--; countR++;
	}
	return (countL < countR) ? true : false;
}

void increasing() {
	string res = ""; int prev = 0;
	int left = 0, right = seq.size() - 1;
	while (left <= right) {
		int a = seq[left];
		int b = seq[right];
		if (a <= prev && b <= prev) { break; }

		if (a == b) {
			bool b = decide(left, right);
			if (b == true) { fill_right(res, prev, right); return; }
			fill_left(res, prev, left); return;
		}

		if (a <= prev) { res.push_back('R'); right--; prev = b; continue; }
		if (b <= prev) { res.push_back('L'); left++; prev = a; continue; }
		int min = (a < b) ? a : b;
		char c = (a < b) ? 'L' : 'R';
		prev = min; res.push_back(c);
		if (a < b) { left++; }
		else { right--; }
	}
	cout << res.size() << endl;
	cout << res << endl;
}

int main() {
	int a; cin >> a;
	seq.resize(a);
	for (int i = 0; i < a; i++) { cin >> seq[i]; }
	increasing();
	cin.ignore(2); return 0;
}