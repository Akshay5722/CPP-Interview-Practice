#pragma once

class Box
{
private:
	double height = 0;
	double* width = nullptr;
	double length = 0;

public:
	Box();
	~Box();
	Box(double& h, double& w, double& len);
	Box(Box& box);
	Box operator = (Box& box);
	bool operator == (Box& box);
};

