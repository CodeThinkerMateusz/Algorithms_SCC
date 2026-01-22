#include <iostream>
#include <vector>

using namespace std;


void assign(int n, int m) {
	vector<vector<int>>graph(n);

	for (int i = 0; i < m; i++) {

	}
}

int main() {
	int z;
	cin >> z;
	if (z <= 0)return 1;
	while (z--) {
		int n, m;
		cin >> n >> m;
		if (n <= 0 || m <= 0)return 1;

		assign(n, m);
	}

	return 0;
}