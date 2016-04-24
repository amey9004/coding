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

void Problem(){
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n, k;
	cin >> n >> k;
	string s;
	getline(cin, s);
	getline(cin, s);
	int prev = s[0] - 48;
	printf("%d", prev);
	for (int i = 1; i<k; i++){
		int item = 0;
		if (s[i] == '0'){
			printf("%d", prev);
		}
		else{
			if (prev == 0){
				printf("1");
				prev = 1;
			}
			else{
				printf("0");
			}
		}
	}
}