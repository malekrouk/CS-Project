#pragma once
#include <iostream>
using namespace std;
class Plane
{
private:
	string name;
	bool status;

public:
	Plane();
	Plane(string n, bool s);
	void landing();
	bool landed();

};

