// Лабораторная работа 2. Построение проекции трёхмерной рёберной сцены.
// Задача 7. Призма.

#include "graphics.h"
#include "camera.h"
#include "wireframe.h"

#include "app.h"

bool App::running_ = false;


Wireframe model({
	{ 0, -1.4, 0 },
	{ 2.5, 0, 0 },
	{ 0, 1.4, 0},

	{ 0, -1.4, 3 },
	{ 2.5, 0, 3 },
	{ 0, 1.4, 3},
	}, {
		
		{ 0, 1 },
		{ 1, 2 },
		{ 2, 0 },
		{ 3, 4 },
		{ 4, 5 },
		{ 5, 3 },
		{ 0, 3 },
		{ 1, 4 },
		{ 2, 5 },
	});

void App::Run()
{
	running_ = true;
}

void App::Draw()
{
	Graphics g;

	// coordinate axes
	Camera::DrawLine(g, 0, 0, 0, 3, 0, 0, RGB(200, 0, 0));
	Camera::DrawLine(g, 0, 0, 0, 0, 3, 0, RGB(0, 200, 0));
	Camera::DrawLine(g, 0, 0, 0, 0, 0, 3, RGB(0, 0, 200));

	// model
	model.Draw(g);
}

void App::Update()
{
	if (running_) {
		model.Rotate(0, 0, -0.1);

		Draw();
	}
}

void App::Init()
{
	Camera::LookAt(2, 2, 1);
	Camera::Ortho(Graphics::width / 2, Graphics::height / 2, 50);

	Draw();
}
