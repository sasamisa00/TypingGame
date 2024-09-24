# include <Siv3D.hpp>
#include "wordList.h"
#include "ScreenshotManager.h"
#include "WordGame.h"
#include "ColorDefinition.h"
#include "MathHelpers.h"  // 追加
#include "RedFlagTyping.h"

// このコードは
// https://siv3d.github.io/ja-jp/samples/games/#5-%E3%82%BF%E3%82%A4%E3%83%94%E3%83%B3%E3%82%B0%E3%82%B2%E3%83%BC%E3%83%A0
// を参考にしています

void Main()
{
	const ColorF backgroundColor = Palette::Powderblue;
	Scene::SetBackground(backgroundColor);

	// ウィンドウサイズを可変に設定
	Window::SetStyle(WindowStyle::Sizable);

	//WordGame wordGame;
	RedFlagTyping wordGame;
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




