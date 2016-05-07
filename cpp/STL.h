#define _USE_MATH_DEFINES
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdarg>
#include <ctype.h>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// https://www.hackerearth.com/problem/algorithm/monks-birthday-party/
void stlSet(){
	int t, n;
	cin >> t;
	while (t--){
		set<string> hash;
		cin >> n;
		while (n--){
			string s;
			cin >> s;
			hash.insert(s);
		}
		for (set<string>::iterator it = hash.begin(); it != hash.end(); it++){
			cout << *it << endl;
		}
	}
}

// https://www.hackerearth.com/code-monk-c-stl/algorithm/monk-and-his-friends/
void stlSet2(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		set<long long int> students;
		for (int i = 0; i < n; i++){
			long long j;
			cin >> j;
			students.insert(j);
		}
		while (m--){
			long long int j;
			cin >> j;
			if (students.find(j) != students.end()){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
			students.insert(j);
		}
	}
}

// https://www.hackerearth.com/problem/algorithm/monk-and-the-magical-candy-bags/
void stlQueue(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		priority_queue<long long int> candies;
		for (int i = 0; i < n; i++){
			long long int j;
			cin >> j;
			candies.push(j);
		}
		long long int ans = 0;
		while (k--){
			long long int now = candies.top();
			candies.pop();
			candies.push(now / 2);
			ans += now;
		}
		cout << ans << endl;
	}
}

// https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/
class Student{
public:
	int marks;
	string name;

	bool operator()(Student s1, Student s2){
		if (s1.marks < s2.marks){
			return true;
		}
		else if (s1.marks == s2.marks && s1.name.compare(s2.name) > 0){
			return true;
		}

		return false;
	}
};

void stlQueue2(){
	int n;
	cin >> n;
	int t = n;
	priority_queue<Student, vector<Student>, Student> queue;
	while (n--){
		string s;
		int m;
		cin >> s;
		cin >> m;
		Student student;
		student.marks = m;
		student.name = s;
		queue.push(student);
	}

	while (t--){
		Student top = queue.top();
		queue.pop();
		cout << top.name << " " << top.marks << endl;
	}
}