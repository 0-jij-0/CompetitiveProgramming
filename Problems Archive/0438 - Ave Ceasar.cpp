#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		char minel = 'Z';
		for (int i = 0; i < (int)s.size(); i++)
			minel = min(minel, s[i]);
		vector<int> sti;
		if (s[0] != minel) { cout << 0 << endl; }
		else {
			sti.push_back(0);
			for (int i = 0; i < (int)s.size(); i++)
				if (s[i] == minel && s[i - 1] != minel)
					sti.push_back(i);
			string acum = "", use = "";
			bool flag = 1;
			for (int i = 0; i < (int)sti.size(); i++) {
				string nowie;
				int st = sti[i], e;
				if (i == sti.size() - 1) { e = s.size(); }
				else { e = sti[i + 1]; }
				for (int j = st; j < e; j++) { nowie.push_back(s[j]); }
				if (nowie < use) { flag = 0; break; }
				else if (nowie == use) { use = nowie; acum.append(nowie); }
				else { acum.append(nowie); use = acum; }
			}
			cout << flag << endl;
		}
	}
	cin.ignore(2); return 0;
}
