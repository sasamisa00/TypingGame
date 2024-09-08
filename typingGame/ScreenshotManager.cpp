#include "ScreenshotManager.h"

ScreenshotManager::ScreenshotManager(const ColorF& bgColor)
	: screenshotCount(0), // 初期化
	backgroundColor(bgColor) // コンストラクタで指定された背景色を初期化
{
}

void ScreenshotManager::TakeScreenshot()
{
	// スクリーンショットを保存
	SaveScreenshot();

	// 画面を白く塗りつぶす
	FlashWhiteScreen();

	// スクリーンショットの番号をインクリメント
	screenshotCount++;
}

void ScreenshotManager::FlashWhiteScreen()
{
	Scene::SetBackground(ColorF{ 1.0 });
	System::Update(); // 画面を更新して白くする
	System::Sleep(100); // 100ミリ秒待機
	Scene::SetBackground(backgroundColor); // 元の背景色に戻す
}

void ScreenshotManager::SaveScreenshot()
{
	// スクリーンショットのファイル名に番号を追加
	const String screenshotPath = U"screenshot_{}.png"_fmt(screenshotCount);
	ScreenCapture::SaveCurrentFrame(screenshotPath);
	//Print << U"スクリーンショットを保存しました: " << screenshotPath;
}

void ScreenshotManager::Update()
{
	// 特定の条件でスクリーンショットを撮影
	if (KeyS.down()) // 例えば、Sキーが押されたときにスクリーンショットを撮影
	{
		TakeScreenshot();
	}
}
