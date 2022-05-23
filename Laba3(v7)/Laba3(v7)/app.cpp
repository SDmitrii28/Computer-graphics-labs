// Лабораторная работа 3. Удаление нелицевых (невидимых) граней выпуклого тела.
// Вариант 2. Параллельная проекция, тело задано в СКМ.
// Задача 7. Призма.

#include <cmath>

#include "facets.h"
#include "app.h"

bool App::running_ = false;

Facets model({
	{ 0, -1.4, 0 },
	{ 2.5, 0, 0 },
	{ 0, 1.4, 0},

	{ 0, -1.4, 3 },
	{ 2.5, 0, 3 },
	{ 0, 1.4, 3},
	}, {

		{ 0, 1,2 },
		{ 1, 4,5,2 },
		{ 2, 5,3,0 },
		{ 0, 1,4,3 },
		{ 3, 4,5 },
	});

void App::Run()
{
	running_ = true;
}

void App::Draw()
{
	Graphics g;

	// coordinate axes
	Camera::DrawLine(g, 0, 0, 0, 4, 0, 0, RGB(200, 0, 0));
	Camera::DrawLine(g, 0, 0, 0, 0, 4, 0, RGB(0, 200, 0));
	Camera::DrawLine(g, 0, 0, 0, 0, 0, 4, RGB(0, 0, 200));

	//
	model.Draw(g);
}

void App::Update()
{
	static float i = 0;
	if (running_) {
		//Camera::LookAt(1.73f, cos(i), sin(i)); // x axis
		Camera::LookAt(cos(i), sin(i), 0.58f); // z axis

		i += pi / 180;

		//model.Rotate(1, 0, 0);

		Draw();
	}
}

void App::Init()
{
	//Camera::LookAt(1, 1, 0.5f);
	Camera::Ortho(Graphics::width / 2, Graphics::height / 2, 40);

	Draw();
}
