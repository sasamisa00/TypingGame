# include <Siv3D.hpp>
#include "wordList.h"
#include "AlphabetFunction.h"
#include "ScreenshotManager.h"
#include "WordGame.h"







void Main()
{
	Scene::SetBackground(Palette::Powderblue);

	// ウィンドウサイズを可変に設定
	Window::SetStyle(WindowStyle::Sizable);

	int screenshotCount = 0; // スクリーンショットの番号を管理する変数


	//問題のアルファベットを選ぶ
	String cyrillicAlphabt;
	TextInput::UpdateText(cyrillicAlphabt, TextInputMode::DenyControl);



	WordGame wordGame(CyrillicAlphabetList::б);

	ScreenshotManager screenshotManager; // スクリーンショットマネージャのインスタンスを作成


	while (System::Update())
	{
		wordGame.Update();


		
		screenshotManager.Update();
	}
}
