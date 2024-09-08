# include <Siv3D.hpp>
#include "wordList.h"
#include "ScreenshotManager.h"
#include "WordGame.h"
#include "ColorDefinition.h"
#include "MathHelpers.h"  // 追加

// 調整された長さに基づいてランダムなインデックスから単語を選択する関数
Array<String> SelectRandomWords(const Array<String>& words, int32 adjustedLength)
{
	const int32 originalLength = words.size();
	Array<String> result;
	const int32 randomIndex = Random(0, originalLength / adjustedLength);

	for (int32 i = 0; i < adjustedLength; ++i)
	{
		const int32 safeIndex = randomIndex * adjustedLength + i;
		if (safeIndex >= originalLength)
		{
			break;
		}
		result.push_back(words[safeIndex]);
	}

	return result;
}

// 単語リストを処理するメイン関数
Array<String> ProcessWords(const Array<String>& words)
{
	const int32 originalLength = words.size();
	const int32 adjustedLength = GetAdjustedLength(originalLength);

	// 調整された長さが元の長さと同じ場合、そのままのリストを返す
	if (adjustedLength == originalLength)
	{
		return words;
	}

	// 調整された長さに基づいてランダムな単語を選択
	return SelectRandomWords(words, adjustedLength);
}

void Main()
{
	const ColorF backgroundColor = Palette::Powderblue;
	Scene::SetBackground(backgroundColor);

	// ウィンドウサイズを可変に設定
	Window::SetStyle(WindowStyle::Sizable);

	WordGame wordGame;
	ScreenshotManager screenshotManager(backgroundColor); // スクリーンショットマネージャのインスタンスを作成

	const Array<String> words = ProcessWords(вWords);
	for (size_t i = 0; i < words.size(); i++)
	{
		Print << words[i];
	}

	while (System::Update())
	{
		wordGame.Update();
		wordGame.Draw();
		screenshotManager.Update();
	}
}




