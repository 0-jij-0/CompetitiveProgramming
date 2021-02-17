#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
 
struct interval {
	int l, r; 
	bool p, sorted;
 
	interval(int _l = -1, int _r = -1, bool _p = false, bool _s = false): l(_l), r(_r), p(_p), sorted(_s) {}
};
 
vector<int> parseNumbers(string &s, int &i) {
	vector<int> res; i++;
	int curNum = 0;
	while (true) {
		if (s[i] == ',' || s[i] == ']') { 
			res.emplace_back(curNum); curNum = 0; 
			if (s[i] == ']') { i++; break; }
		}
		else {
			curNum *= 10; curNum += (s[i] - '0');
		}
		i++;
	}
	return move(res);
}
 
vector<int> allNums(string &s) {
	int i = 0, n = s.size();
	
	vector<int> ans;
	while (i < n) {
		while (i < n && s[i] != '[') { i++; }
		if (i >= n || s[i] != '[') { break; }
		vector<int> cur = parseNumbers(s, i);
		for (auto &x : cur) { ans.emplace_back(x); }
	}
 
	return move(ans);
}
 
bool allAreEqual(vector<int> &nums, const int &l, const int &r) {
	if (l >= r) { return true; }
	int num = nums[l];
	for (int i = l + 1; i <= r; i++) { if (nums[i] != num) { return false; } }
	return true;
}
 
bool sameNumbers(vector<int> &numA, vector<int> &numB, const int &l, const int &r) {
	multiset<int> ms;
	for (int i = l; i <= r; i++) { ms.insert(numA[i]); }
	for (int i = l; i <= r; i++) {
		if (!ms.count(numB[i])) { return false; }
		ms.erase(ms.find(numB[i]));
	}
	return true;
}
 
//curF = -1:nthg, 0:shuffle, 1:sort
list<interval> parse(string &s, int &i, int &numCnt) {
	if (s[i] == 'c') { 
		i += 7;
		list<interval> int1 = parse(s, i, numCnt);
		i++;
		list<interval> int2 = parse(s, i, numCnt);
		i++;
 
		int1.splice(int1.end(), int2);
		/*
		if (int1.size() > int2.size()) {
			swap(int1, int2);
			for(auto it = int2.rbegin(); it != int2.rend(); it++){ int1.push_front(*it); }
		}
		else {
			for (auto &it : int2) { int1.emplace_back(it); }
		}
		*/
		return move(int1);
	}
	else if (s[i] == 's' && s[i + 1] == 'h') {
		i += 8; 
		list<interval> res = parse(s, i, numCnt);
		i++;
 
		int L = res.front().l, R = res.back().r;
		return { interval(L, R, 1, 0) };
	}
	else if (s[i] == 's') {
		i += 7;
		list<interval> res = parse(s, i, numCnt);
		i++;
 
		int L = res.front().l, R = res.back().r;
		return { interval(L, R, 0, 1) };
	}
 
	int l = numCnt;
	while (s[i] != ']') {
		if (s[i] == ',') { numCnt++; }
		i++; 
	}
	int r = numCnt++; i++;
 
	list<interval> res;
	res.emplace_back(interval(l, r, 0, 0));
	return move(res);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	string A, B; cin >> A >> B;
	list<interval> vAInt, vBInt;
	vector<int> vA, vB;
 
	int i = 0, numCnt = 0;
	vAInt = parse(A, i, numCnt); vA = allNums(A);
	i = numCnt = 0;
	vBInt = parse(B, i, numCnt); vB = allNums(B);
 
	for (auto &it : vAInt) {
		if (allAreEqual(vA, it.l, it.r)) { it.p = false; }
		if (it.sorted) { sort(vA.begin() + it.l, vA.begin() + it.r + 1); }
	}
	for (auto &it : vBInt) {
		if (allAreEqual(vB, it.l, it.r)) { it.p = false; }
		if (it.sorted) { sort(vB.begin() + it.l, vB.begin() + it.r + 1); }
	}
 
	bool OK = (vA.size() == vB.size());
	auto itA = vAInt.begin(), itB = vBInt.begin();
	//int aIdx = 0, bIdx = 0;
	i = 0;
	if (OK) {
		for (; i < vA.size(); i++) {
			if (itA->r < i) { itA++; }
			if (itB->r < i) { itB++; }
 
			if (itA->p || itB->p) {
				if (!(itA->p == itB->p && itA->l == itB->l && itA->r == itB->r)){
					OK = false; break;
				}
				else {
					if (!sameNumbers(vA, vB, itA->l, itA->r)) {
						OK = false; break;
					}
					else { i = itA->r; }
				}
			}
			else {
				if (!(vA[i] == vB[i])) { OK = false; break; }
			}
		}
	}
 
	cout << (OK ? "equal" : "not equal") << '\n';
}