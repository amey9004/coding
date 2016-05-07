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