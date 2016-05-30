#define _USE_MATH_DEFINES
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <tuple>

using namespace std;

int main() {
	int fn, bn;
	cin >> fn >> bn;
	vector<int> * child = (vector<int> *)malloc(sizeof(vector<int>) * fn);
	long long* wealth = (long long*)malloc(sizeof(long long) * bn);
	int * owner = (int *)malloc(sizeof(int) * fn);
	int * ans = (int *)malloc(sizeof(int) * bn);	
	
	for (int i = 1; i < fn; i++){
		int p;
		scanf_s("%d", &p);
		child[p - 1].push_back(i);
	}
	for (int i = 0; i < fn; i++){
		int o;
		scanf_s("%d", &o);
		owner[i] = o- 1;
	}
	for (int i = 0; i < bn; i++){
		long long t;
		scanf_s("%lld", &t);
		wealth[i] = t;
		ans[i] = 0;
	}
	int q;
	cin >> q;
	int time = q;
	while (q--)
	{
		int f, x, d;
		cin >> f >> x >> d;
		f--;
		int k = 0;
		vector<int> factories;
		factories.push_back(f);
		factories.push_back(-1);
		while (factories.size() > 0) {
			int current = factories[0];
			factories.erase(factories.begin());
			if (current == -1){
				k++;
				if (factories.size() > 0){
					factories.push_back(-1);
				}
				continue;
			}
			
			wealth[owner[current]] = wealth[owner[current]] - ((long long)x + (long long)k * d);
			if (wealth[owner[current]] <= 0 && ans[owner[current]] == 0){
				ans[owner[current]] = time - q;
			}
			for (int i = 0; i < child[current].size(); i++){
				factories.push_back(child[current][i]);
			}
		}
	}

	for (int i = 0; i < bn; i++){
		if (ans[i] == 0){
			cout << "rekt" << endl;
		}
		else{
			cout << ans[i] << endl;
		}
	}
}

void simpleMerge(int a, int b, int* arr){
	arr[b] = a;
	return;
}

int getParent(int i, int * arr){
	while (i != arr[i]){
		i = arr[i];
	}

	return i;
}

void SpanningTree(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		int* parent = new int[n];
		for (int i = 0; i < n; i++){
			parent[i] = i;
		}
		vector<pair<int, int>> stack;
		for (int i = 0; i < m; i++){
			int s, e;
			scanf_s("%d%d", &s, &e);
			stack.push_back(make_pair(s - 1, e - 1));
		}
		for (int i = 0; i < n - 1; i++){
			int e;
			scanf_s("%d", &e);
			pair<int, int> edge = stack[e - 1];
			int parentA = getParent(edge.first, parent);
			int parentB = getParent(edge.second, parent);
			simpleMerge(parentA, parentB, parent);
		}
		int p = getParent(0, parent);
		bool valid = true;
		for (int i = 1; i < n; i++){
			if (p != getParent(i, parent)){
				valid = false;
				break;
			}
		}

		if (valid){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}
