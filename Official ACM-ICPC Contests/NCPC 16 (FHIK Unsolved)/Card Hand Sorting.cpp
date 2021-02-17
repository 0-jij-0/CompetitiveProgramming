#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
int minInsertionStepToSortArray(vector<int> arr, int N)
{
    // lis[i] is going to store length of lis
    // that ends with i.
    int lis[N];
 
    /* Initialize lis values for all indexes */
    for (int i = 0; i < N; i++)
        lis[i] = 1;
 
    /* Compute optimized lis values in bottom up manner */
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] >= arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    /* The overall LIS must end with of the array
       elements. Pick maximum of all lis values */
    int max = 0;
    for (int i = 0; i < N; i++)
        if (max < lis[i])
            max = lis[i];
 
    // return size of array minus length of LIS
    // as final result
    return (N - max);
}
int main() {
	int n; cin >> n;
 
	vector<pair<int, int>> cards;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		pair<int, int> p;
		if (s[0] == 'T') { p.first = 10; }
		else if (s[0] == 'J') { p.first = 11; }
		else if (s[0] == 'Q') { p.first = 12; }
		else if (s[0] == 'K') { p.first = 13; }
		else if (s[0] == 'A') { p.first = 14; }
		else { p.first = s[0] - '0'; }
 
		if (s[1] == 's') { p.second = 1; }
		else if (s[1] == 'h') { p.second = 2; }
		else if (s[1] == 'd') { p.second = 3; }
		else { p.second = 4; }
 
		cards.push_back(p);
	}
 
	vector<int> typeOrder = { 1,2,3,4 };
 
	int bestAns = n + 1;
	do {
		int upDown = 0;
		while (upDown < 1 << 4) {
			vector<int> inNumbers(n);
 
			int pos = 0;
			for (int type : typeOrder) {
				vector<pair<int, int>> curType;
				for (int i = 0; i < n; i++) {
					if (cards[i].second == type)
						curType.push_back({ cards[i].first, i });
				}
				sort(curType.begin(), curType.end());
				if ((upDown >> (type - 1)) & 1) {
					for (int i = 0; i < curType.size(); i++) {
						inNumbers[curType[i].second] = pos++;
					}
				}
				else {
					for (int i = curType.size() - 1; i >= 0; i--) {
						inNumbers[curType[i].second] = pos++;
					}
				}
			}
 
			int ans = minInsertionStepToSortArray(inNumbers,inNumbers.size());
		
			bestAns = min(bestAns, ans);
			upDown++;
		}
	} while (next_permutation(typeOrder.begin(), typeOrder.end()));
 
	cout << bestAns << endl;
}