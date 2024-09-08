# include <Siv3D.hpp>
#include "wordList.h"
#include "ScreenshotManager.h"
#include "WordGame.h"







void Main()
{
	Scene::SetBackground(Palette::Powderblue);

	// ウィンドウサイズを可変に設定
	Window::SetStyle(WindowStyle::Sizable);


	WordGame wordGame;

	ScreenshotManager screenshotManager; // スクリーンショットマネージャのインスタンスを作成


	while (System::Update())
	{
		wordGame.Update();
		wordGame.Draw();

		
		screenshotManager.Update();
	}
}
