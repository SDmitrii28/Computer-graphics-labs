// Лабораторная работа 4. Удаление невидимых линий поверхности методом плавающего горизонта.
// Вариант 4. Поворот вокруг осей y, x, рисование отрезками.
// Задача 7 Пик.

#include <cmath>

#include "graphics.h"
#include "surface.h"
#include "app.h"

bool App::running_ = false;

// 1
//Surface surface(-5, 5, -1, 1, [](float x, float z) { return abs(x) + abs(z); });

// 2
//Surface surface(-2, 2, -2, 0, [](float x, float z) { return abs(x * z); });

// 3
//Surface surface(-2, 2, -2, 2, [](float x, float z) { return x * x - z * z; });

// 4
//Surface surface(-2, 2, -2, 2, [](float x, float z) { return x * x + z * z; });

// 5
//Surface surface(-5, 5, -2, 2, [](float x, float z) { return z * z * z + x * z; });

// 6
//Surface surface(-2, 2, -2, 2, [](float x, float z) { return x * z * (x + z) * (x - z); });

// 7
Surface surface(-2, 2, -2, 2, [](float x, float z) { return exp(-sqrt(x * x + z * z)) - 0.5f; });

// 8
//Surface surface(-2 * pi, 2 * pi, -2 * pi, 2 * pi, [](float x, float z) { return cos(sqrt(x * x + z * z)); });

// 9
//Surface surface(0, pi, 0, pi, [](float x, float z) { return sin(x) * sin(z); });
//Surface surface(-pi / 2, pi / 2, -pi / 2, pi / 2, [](float x, float z) { return sin(x + pi / 2) * sin(z + pi / 2); });

// 10
//Surface surface(-2 * pi, 2 * pi, -2 * pi, 2 * pi, [](float x, float z) { float a = sqrt(x * x + z * z); return cos(a) / (a + 1); });

// 11
//Surface surface(0, pi, 0, pi, [](float x, float z) { return (sin(x) + sin(16 * x) / 16) * sin(z); });
//Surface surface(-pi / 2, pi / 2, -pi / 2, pi / 2, [](float x, float z) { return (sin(x + pi / 2) + sin(16 * x + 8 * pi) / 16) * sin(z + pi / 2); });

// 12
//Surface surface(-1.5f * pi, 1.5f * pi, -pi / 2, pi / 2, [](float x, float z) { return cos(x) * cos(z) / (abs(x) + 1); });

// 13
//Surface surface(-pi, pi, -pi, pi, [](float x, float z) { float a = x * x + z * z; return -1.5f * cos(1.75f * a) * exp(-a) + 0.2f * sin(x + pi) * cos(z + pi); });

// 14
//Surface surface(-6 * pi, 6 * pi, -3 * pi, 3 * pi, [](float x, float z) { float a = sqrt((x + 3 * pi) * (x + 3 * pi) + z * z); float b = sqrt((x - 3 * pi) * (x - 3 * pi) + z * z); return cos(a) / (a + 1) + cos(b) / (b + 1); });

// 15
//Surface surface(-5, 5, -5, 5, [](float x, float z) { return -log(abs(x * x * (x * x - z * z)) + 0.15f); });

void App::Run()
{

}

void App::Draw()
{
	Graphics g;

	// surface - поверхность
	surface.Draw(g);
}

void App::Update()
{
	
		static int32_t a = 0; // angle
		static int32_t i = 1; // increment

		//surface.SetAngles(25, a);

		a += i;

		if (a >= 60 || a <= -60)
		{
			i = -i;
		}

		Draw();
}

void App::Init()
{
	//Camera::LookAt(0, 0, -1);
	Camera::Ortho(Graphics::width / 2, Graphics::height / 2, 1);

	surface.SetAngles(15, 45);

	//Draw();
}
