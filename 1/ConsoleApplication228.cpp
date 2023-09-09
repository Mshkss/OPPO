
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct point
{
	double a, b;
	string colour;
};

int main()
{
	std::vector<point>points;

	point test1;
	ifstream in("Text.txt");	
		if (in.is_open()) {
			while(!in.eof()){
				in >> test1.a >> test1.b >> test1.colour;
				points.push_back(test1);

			}
	} 
		//cout << test1.a << " " << test1.b << " " << test1.colour << endl;
	for (int i = 0; i < points.size(); ++i ) {
		test1 = points[i];
		cout << test1.a << " " << test1.b << " " << test1.colour << endl;
	}
}