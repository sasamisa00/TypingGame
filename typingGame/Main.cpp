# include <Siv3D.hpp>
#include "wordList.h"
#include "ScreenshotManager.h"
#include "WordGame.h"
#include "ColorDefinition.h"
#include "MathHelpers.h"  // 追加


void Main()
{
	const ColorF backgroundColor = Palette::Powderblue;
	Scene::SetBackground(backgroundColor);

	// ウィンドウサイズを可変に設定
	Window::SetStyle(WindowStyle::Sizable);

	WordGame wordGame;
	ScreenshotManager screenshotManager(backgroundColor); // スクリーンショットマネージャのインスタンスを作成

	/*const Array<String> words = SelectAdjustedRandomWords(вWords);
	for (size_t i = 0; i < words.size(); i++)
	{
		Print << words[i];
	}*/

	while (System::Update())
	{
		wordGame.Update();
		wordGame.Draw();
		screenshotManager.Update();
	}
}




