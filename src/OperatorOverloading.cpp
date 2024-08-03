#include "OperatorOverloading.h"

Box::Box()
{
	height = 0.0;
	width = nullptr;
	length = 0.0;
}

Box::Box(double& h, double& w, double& len)
{
	height = h;
	if (width == nullptr)
		width = new double(w);
	else
		*width = w;
	length = len;
}

Box::~Box()
{
	if(width != nullptr)
		delete width;
}

Box::Box(Box& box)
{
	height = box.height;
	width = new double(*(box.width));
	length = box.length;
}

Box Box::operator = (Box& box)
{
	// first check whether it is  self
	if (this != &box)
	{
		height = box.height;
		if (width != nullptr)
			delete width;
		width = new double(*(box.width));
		length = box.length;
	}
	return *this;
}

bool Box::operator == (Box& box)
{
	return ((height != box.height) && (width != box.width) && (length != box.length));
}
