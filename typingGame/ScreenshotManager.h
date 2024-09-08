#pragma once
#include <Siv3D.hpp>

class ScreenshotManager
{
public:
	// コンストラクタで背景色を指定できるようにする
	ScreenshotManager(const ColorF& bgColor = Palette::Powderblue);

	

	// 更新関数
	void Update();

private:
	int screenshotCount; // スクリーンショットの番号を管理する変数
	const ColorF backgroundColor; // 背景色を管理する変数

	// スクリーンショットを撮影して保存する
	void TakeScreenshot();

	// 画面を白く塗りつぶす関数
	void FlashWhiteScreen();

	// スクリーンショットを保存する関数
	void SaveScreenshot();
};
