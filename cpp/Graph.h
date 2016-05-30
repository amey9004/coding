#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>

using namespace std;

void graphEdges(){
	int n, t;
	cin >> n;
	t = n;
	int total = 0;
	while (t--)
	{
		int j;
		cin >> j;
		if (j > n - 1){
			cout << "No" << endl;
			return;
		}
		total += j;
		if (total > 2 * (n - 1)){
			cout << "No" << endl;
			return;
		}
	}

	if (total == 2 * (n - 1)){
		cout << "Yes" << endl;
		return;
	}

	cout << "No" << endl;
	return;
}

// https://www.hackerearth.com/code-monk-minimum-spanning-tree/algorithm/maximum-spanning-tree/
void MaximumSpanningTree(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		int ** adj = (int **)malloc(sizeof(int*) * n);
		bool *visited = new bool[n];
		for (int i = 0; i < n; i++){
			visited[i] = false;
			adj[i] = (int *)malloc(sizeof(int) * n);
		}

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				adj[i][j] = 0;
			}
		}

		for (int i = 0; i < m; i++){
			int s, e, c;
			scanf("%d%d%d", &s, &e, &c);
			adj[s - 1][e - 1] = c;
			adj[e - 1][s - 1] = c;
		}

		int cost = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> queue;
		queue.push(make_pair(0, 0));
		int countEdges = 0;
		while (!queue.empty()){
			pair<int, int> top = queue.top();
			queue.pop();
			int e = top.second;
			if (visited[e]){
				continue;
			}
			visited[e] = true;
			countEdges++;
			cost += top.first;
			for (int i = 0; i < n; i++){
				if (adj[e][i] > 0 && !visited[i]){
					queue.push(make_pair(adj[e][i], i));
				}
			}
		}

		cout << cost << endl;
	}
}
