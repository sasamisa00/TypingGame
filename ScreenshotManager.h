#pragma once
#include <Siv3D.hpp>

class ScreenshotManager
{
public:
    ScreenshotManager();

    // �X�N���[���V���b�g���B�e���ĕۑ�����
    void TakeScreenshot();

private:
    int screenshotCount; // �X�N���[���V���b�g�̔ԍ����Ǘ�����ϐ�

    // ��ʂ𔒂��h��Ԃ��֐�
    void FlashWhiteScreen();
};
