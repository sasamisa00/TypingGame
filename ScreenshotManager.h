#pragma once
#include <Siv3D.hpp>

class ScreenshotManager
{
public:
    ScreenshotManager();

    // スクリーンショットを撮影して保存する
    void TakeScreenshot();

private:
    int screenshotCount; // スクリーンショットの番号を管理する変数

    // 画面を白く塗りつぶす関数
    void FlashWhiteScreen();
};
