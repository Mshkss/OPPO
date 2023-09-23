#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum class Color {
	Red, Green, Blue
};

Color string_to_color(const string& str) {
	if (str == "red") {
		return Color::Red;
	}
	else if (str == "green") {
		return Color::Green;
	}
	else if (str == "blue") {
		return Color::Blue;
	}
}	

std::string color_to_string(const Color c)
{
	switch (c)
	{
	case Color::Red: {
		return "red";
	}

	case Color::Blue: {
		return "blue";
	}

	case Color::Green: {
		return "green";
	}
	}
	//
}

struct Point
{
	double a, b;
	Color colour;

	Point() : a(0), b(0){}

	Point(double _a, double _b, Color _color) :
		a(_a), b(_b), colour(_color) {
	}

	static Point create(std::istream& in)
	{
		Point test1;
		in >> test1.a >> test1.b;
		std::string str;
		in >> str;

		const auto color = string_to_color(str);
		test1.colour = color;
		return test1;
	}
};

void print(const vector<Point> &points) {
	for (int i = 0; i < points.size(); ++i) { 
		cout << points[i].a << " " << points[i].b << " " << color_to_string(points[i].colour) << endl;
	}
}

int txttocpp() {
	vector<Point>points;
	ifstream in("Текст.txt");
	if (false == in.is_open()) {
		cout << "1";
		return 1;
	}
	while (!in.eof()) {
		Point test1 = Point::create(in);
		points.push_back(test1);
	}
	print(points);
}

int main()
{
	string str;
	Color color = string_to_color(str);
	txttocpp();
}