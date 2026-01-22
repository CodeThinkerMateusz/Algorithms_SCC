#include <iostream>
#include <vector>
#include <stack>


using namespace std;



void DFS(vector<vector<int>>& graph, int u, vector<bool> &checked, stack<int> &mystack) {
	if (checked[u])return;
	checked[u] = true;
	for (int i = 0; i < graph[u].size(); i++) {
		if (!checked[graph[u][i]]) {
			checked[graph[u][i]] = true;
			DFS(graph, graph[u][i], checked, mystack);
		}
	}
	mystack.push(u);
}

//creating  graph
void assign(vector<vector<int>>&graph , int n, int m) {
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
	}
}

void make_Transposed(vector<vector<int>>&graphT, vector<vector<int>>&graph, int n) {
	for (int u = 0; u < n; u++) {
		for (int v : graph[u]) {
			graphT[v].push_back(u);
		}
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
		vector<vector<int>>graph(n);
		stack<int> mystack;
		vector<bool> checked(n, false);
		vector<vector<int>>graphT(n);
		assign(graph, n, m);
		
		for (int u = 0; u < n; u++) {
			DFS(graph, u, checked, mystack);
		}
		//nie wiem  czy sprawdzenie czy cala  tablica  jest  checked  jest  potrzbene
		make_Transposed(graph, graphT, n);
		
	}

	return 0;
}