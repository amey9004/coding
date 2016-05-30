#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

set<pair<int, int>> size;

int getParent(int i, int * arr){
	while (i != arr[i]){
		i = arr[i];
	}

	return i;
}

void merge(int a, int b, int* count, int * arr){
	if (a == b){
		return;
	}

	if (count[a] < count[b]){
		int t = a;
		a = b;
		b = t;
	}

	size.erase(size.find(pair<int, int>(count[b], b)));
	size.erase(size.find(pair<int, int>(count[a], a)));

	arr[b] = a;
	count[a] += count[b];
	size.insert(pair<int, int>(count[a], a));
}

void simpleMerge(int a, int b, int* arr){
	arr[b] = a;
	return;
}

// https://www.hackerearth.com/code-monk-disjoint-set-union/algorithm/city-and-campers/description/
void cityAndCampers(){
	int n, q;
	cin >> n >> q;
	int * arr = (int *)malloc(sizeof(int) * n);
	int * count = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++){
		arr[i] = i;
		count[i] = 1;
		size.insert(pair<int, int>(1, i));
	}

	while (q--){
		int a, b;
		cin >> a >> b;
		a = a - 1;
		b = b - 1;
		int pa = getParent(a, arr);
		int pb = getParent(b, arr);
		merge(pa, pb, count, arr);

		set<pair<int, int>>::iterator min = ((size.begin()));
		set<pair<int, int>>::iterator max = ((size.end()));
		max--;
		cout << (*max).first - (*min).first << endl;
	}
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
			scanf("%d%d", &s, &e);
			stack.push_back(make_pair(s - 1, e - 1));
		}
		for (int i = 0; i < n - 1; i++){
			int s, e;
			scanf("%d%d", &s, &e);
			int parentA = getParent(s - 1, parent);
			int parentB = getParent(e - 1, parent);
			simpleMerge(parentA, parentB, parent);
		}
		int p = parent[0];
		bool valid = true;
		for (int i = 1; i < n; i++){
			if (p = parent[i]){
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