#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//For each i in the returned vector, the number represents the length of 
//the longest proper prefix equal to the suffix ending at index i, both in the substring s[0..i]
//Proper prefix means prefix != string
vector<int> prefixFunction(string& s) {
	vector<int> pf(s.size(), 0);
	for (int i = 1; i < s.size(); i++) {
		int j = pf[i - 1];
		while (j > 0 && s[j] != s[i]) { j = pf[j - 1]; }
		if (s[j] == s[i]) { j++; }
		pf[i] = j;
	}
	return pf;
}

//counts #occurence of p in s as a substring
//p and s can NOT contain the character #
int stringMatch(string& s, string& p) {
	string temp = p + '#' + s;
	vector<int> pf = prefixFunction(temp);

	return count(pf.begin() + p.size() + 1, pf.end(), p.size());
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}