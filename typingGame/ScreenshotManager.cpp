#include "ScreenshotManager.h"

ScreenshotManager::ScreenshotManager()
	: screenshotCount(0) // 初期化
{
}

void ScreenshotManager::TakeScreenshot()
{
	// スクリーンショットのファイル名に番号を追加
	const String screenshotPath = U"screenshot_{}.png"_fmt(screenshotCount);
	ScreenCapture::SaveCurrentFrame(screenshotPath);
	//Print << U"スクリーンショットを保存しました: " << screenshotPath;

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
	Scene::SetBackground(Palette::Powderblue); // 元の背景色に戻す
}
