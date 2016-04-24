#define _USE_MATH_DEFINES
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdarg>
#include <ctype.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

/*
* https://www.hackerearth.com/nutanix-backend-hiring-challenge/problems/2966b72f6e6b46ae9cbe84a3d6a8d34a/
*/
void Execute(){
	string s;
	cin >> s;
	int q;
	cin >> q;
	long long int a[26] = { 0 };
	for (int i = 0; i < s.length(); i++){
		char ch = s[i];
		i++;
		int j = i;
		while (isdigit(s[i]) && i < s.length()){
			i++;
		}
		string number = s.substr(j, i - j);
		long long num = stoll(number);
		a[ch - 'a'] += num;
		i--;
	}
	while (q--){
		long long int k;
		cin >> k;
		long long int sum = 0;
		bool found = false;
		for (int i = 0; i < 26; i++){
			sum += a[i];
			if (sum >= k){
				printf("%c\n", 'a' + i);
				found = true;
				break;
			}
		}
		if (!found){
			cout << "-1\n";
		}
	}
}