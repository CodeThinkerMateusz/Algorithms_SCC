#include <iostream>
#include <vector>
#include <stack>


using namespace std;



void DFS(vector<vector<int>>& graph, int u, vector<bool> &checked, stack<int> &mystack) {
	if (checked[u])return;
	checked[u] = true;
	for (int i = 0; i < graph[u].size(); i++) {
		//if (!checked[graph[u][i]]) {
			//checked[graph[u][i]] = true;
			DFS(graph, graph[u][i], checked, mystack);
		//}
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

void DFS2(int v, vector<vector<int>>& graphT, vector<int>&component, int idx, vector<bool>&checked, vector<int>&	count) {
	if (checked[v])return;
	checked[v] = true;
	count[idx]++;
	component[v] = idx;
	for (int i = 0; i < graphT[v].size(); i++) {
		//if (!checked[graphT[v][i]]) {
			//checked[graphT[v][i]] = true;
		DFS2(graphT[v][i], graphT, component, idx ,checked,count);
		//}
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
		make_Transposed(graphT, graph, n);

		vector<int> component(n,0);
		//clear  the  checked  vaector 
		vector<bool> checked2(n, false);
		int idx = 0;
		int v;
		vector<int> component_count(n, 0);
		while (!mystack.empty()) {
			v = mystack.top();
			mystack.pop();
			if (!checked2[v]) {
				DFS2(v, graphT, component, idx, checked2, component_count);
				idx++;
			}
		}
		vector<bool>IsNotSink(idx, false);

		for (int u = 0; u < graph.size(); u++) {
			for (int v : graph[u]) {
				int c1 = component[u];
				int c2 = component[v];
				if (c1 != c2) {
					IsNotSink[c1] = true;
				}
			}
		}
		int min = INT_MAX;
		for (int i = 0; i < idx; i++) {
			if (IsNotSink[i] == false) {
				if (component_count[i] < min)min = component_count[i];
			}
		}
		cout << min << endl;
	}
	return 0;
}