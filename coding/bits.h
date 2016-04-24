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

void memories(){
	// https://www.hackerearth.com/algorithms-qualifiers-round-3/algorithm/memories-1/
	int t;
	cin >> t;
	while (t--){
		int n, p;
		cin >> n >> p;
		int **a = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++){
			a[i] = (int*)malloc(sizeof(int) * n);
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				a[i][j] = 0;
			}
		}
		while (p--){
			int c, b;
			cin >> c >> b;
			a[c - 1][b - 1] = 1;
			a[b - 1][c - 1] = 1;
		}
		int ans = 0;
		for (int i = 1; i < 1 << n; i++){
			bool invalid = false;
			for (int j = 0; j < n; j++){
				if ((i & 1 << j)){
					for (int k = 0; k < n; k++){
						if ((a[j][k]) && (i & 1 << k)){
							ans++;
							invalid = true;
							break;
						}
					}
				}
				if (invalid){
					break;
				}
			}
		}
		cout << (1 << n) - (ans + 1) << endl;
	}
}
