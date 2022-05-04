// Лабораторная работа 1. Двумерные геометрические преобразования.
// Задача 7. Снежный ком

#include "graphics.h"
#include "figure.h"
#include <iostream>
#include "app.h"

bool App::running_ = false;
Figure point({
	{ 0, 0 },
	{ 0, 20 },
	{ 15, 35 },
	{ 35, 35 },
	{50, 20 },
	{ 50, 0 },
	{ 35, -15 },
	{ 15, -15 },
	}, {
		{ 0, 1 },
		{ 1, 2 },
		{ 2, 3 },
		{ 3, 4 },
		{ 4, 5 },
		{ 5, 6 },
		{ 6, 7 },
		{ 7, 0 },
	});

Figure rectangle({
	{ 0, 0 },
	{ 0, 20 },
	{ 15, 35 },
	{ 35, 35 },
	{50, 20 },
	{ 50, 0 },
	{ 35, -15 },
	{ 15, -15 },
}, {
	{ 0, 1 },
	{ 1, 2 },
	{ 2, 3 },
	{ 3, 4 },
	{ 4, 5 },
	{ 5, 6 },
	{ 6, 7 },
	{ 7, 0 },
});

void App::Run()
{
	running_ = true;
}

void App::Draw()
{
	Graphics g;

	g.DrawLine(0, 50, Graphics::width - 1, Graphics::height - 1, RGB(0, 255, 0));
	point.DrawPoint(g);
	rectangle.Draw(g);
}

void App::Update()
{
	static const int a = 30;

	static uint32_t i = a;
	//float 
	if (running_)
	{
		if (i % a == 0)
		{
			rectangle.SetPivot(i / a % 8);
			point.SetPivot(i / a % 8);
		}
		point.Rotate(45.f / a);
		point.Translate(rectangle.GetDistanseX(point), rectangle.GetDistanseY(point));
		rectangle.Rotate(45.f / a);
		
		rectangle.Scaling(1.003, 1.003);

		Draw();

		i++;

		if (i / a == 15)
		{
			
			running_ = false;
		}
	}
}

void App::Init()
{
	// 1
	rectangle.Rotate(-56);
	rectangle.Translate(0, 49);
	point.Rotate(-56);
	point.Translate(0, 49);

	Draw();
}
