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
#include <iomanip>

using namespace std;

class Point{
public:
	int x;
	int y;
	Point(int a, int b){
		x = a;
		y = b;
	};
	bool operator==(const Point &anotherLine) const
	{
		return (x == anotherLine.x && y == anotherLine.y);
	}
};

namespace std
{
	template <>
	struct hash<Point>
	{
		size_t operator()(const Point& k) const
		{
			// Compute individual hash values for two data members and combine them using XOR and bit shifting
			return ((hash<int>()(k.x) ^ (hash<int>()(k.y) << 1)) >> 1);
		}
	};
}

unordered_set<Point> visited;
deque<char> path;

bool find(Point start, int max){
	if (start.x == 0 && start.y == 0){
		return true;
	}
	if (start.x < max){
		path.push_back('R');
		Point p(start.x + 1, start.y);
		if (visited.find(p) == visited.end()){
			visited.insert(p);
			bool val = find(p, max);
			if (val){
				return true;
			}
			visited.erase(p);
		}
		path.pop_back();
	}
	if (start.x > -max){
		path.push_back('L');
		Point p(start.x - 1, start.y);
		if (visited.find(p) == visited.end()){
			visited.insert(p);
			bool val = find(p, max);
			if (val){
				return true;
			}
			visited.erase(p);
		}
		path.pop_back();
	}
	if (start.y < max){
		path.push_back('U');
		Point p(start.x, start.y + 1);
		if (visited.find(p) == visited.end()){
			visited.insert(p);
			bool val = find(p, max);
			if (val){
				return true;
			}
			visited.erase(p);
		}
		path.pop_back();
	}
	if (start.y > -max){
		path.push_back('D');
		Point p(start.x, start.y - 1);
		if (visited.find(p) == visited.end()){
			visited.insert(p);
			bool val = find(p, max);
			if (val){
				return true;
			}
			visited.erase(p);
		}
		path.pop_back();
	}

	return false;
}

// https://www.hackerearth.com/april-circuits/approximate/2b-bear-and-walk-1/
void maze(){
	int t;
	cin >> t;
	while (t--){
		visited.clear();
		path.clear();
		string s;
		cin >> s;
		int size = s.size();
		int x = 0, y = 0, max = 0;
		for (int i = 0; i < size; i++){
			switch (s[i]){
			case 'R':
				x++;
				break;
			case 'L':
				x--;
				break;
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;
			}
			if (abs(x) > max){
				max = abs(x);
			}
			if (abs(y) > max){
				max = abs(y);
			}
			Point p(x, y);
			if (p.x == 0 && p.y == 0){
				continue;
			}
			visited.insert(p);
		}

		Point p(x, y);
		bool val = find(p, max);
		if (!val){
			cout << "IMPOSSIBLE" << endl;
		}
		else{
			while (!path.empty()){
				char direction = path.front();
				cout << direction;
				path.pop_front();
			}
			cout << endl;
		}
	}
}
