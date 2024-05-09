#include <iostream>

class IEngine
{
public:
	virtual void start() = 0;
	virtual void stop() = 0;
};

class MPFIEngine : public IEngine
{
public:
	void start() {}
	void stop() {}
};

class GDIEngine : public IEngine
{
public:
	void start() {}
	void stop() {}
};

class XUV3X0
{
	IEngine* engine;
public:
	XUV3X0(IEngine* engineArg) :engine{ engineArg } {}
	void drive()
	{
		this->engine->start();
	}

	void halt()
	{
		this->engine->stop();
	}
};

int main()
{
	MPFIEngine napEngine;
	GDIEngine turboEngine;
	XUV3X0 car{ &napEngine };
	car.drive();
	car.halt();
	XUV3X0 turboSeries{ &turboEngine };
	car.drive();
	car.halt();
	return 0;
}