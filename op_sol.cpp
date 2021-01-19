#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		// create a two - dimensional vector
		vector<int> v[1001];
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			// store the indexes of every element
			v[x].emplace_back(i);
		}
		int cur = 0;
		int ans = -1;
		for (int i = 1; i <= 1000; i++) {
			// check if the current element exists
			if (v[i].empty()) {
				continue;
			}
			int cnt = 0;
			int prev = -1;
			// check the occurrences of the current element using the indices provided
			for (int j : v[i]) {
				// if the current index is not adjacent index of the previous index,
				// then count the number of frequencies
				if (j > prev) {
					cnt++;
					prev = j + 1;
				}
			}
			// get the minimum element with the largest frequency
			if (cur < cnt) {
				cur = cnt;
				ans = i;
			}
		}
		cout << ans << '\n';
	}
	return 0; 
}
