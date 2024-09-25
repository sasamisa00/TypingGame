#pragma once
#include <Siv3D.hpp>
#include "ColorDefinition.h"
#include "EncouragingMessages.h"
#include "FoxBoyImagePath.h"
#include "FoxBoySentences.h"
#include "pageContents.h"


class FoxTyping
{
public:
	FoxTyping()
		:
		book()
	{}
	~FoxTyping() = default;

	void Update()
	{
	}

	void Draw() const
	{
	}

private:
	FoxBoyBook book;
};




//class FoxTyping
//{
//public:
//	static constexpr int32 DEFAULT_WINDOW_WIDTH = 1200;
//	static constexpr int32 DEFAULT_WINDOW_HEIGHT = 800;
//
//	static constexpr int32 FONT_SIZE = 40;
//
//	static constexpr Vec2 IMAGE_POS = Vec2(0, 0);
//	static constexpr double IMAGE_SCALE = 0.5;
//
//	static constexpr Vec2 TARGET_SENTENCE_POS = Vec2(400, 80);
//	static constexpr Vec2 INPUT_SENTENCE_POS = Vec2(400, 150);
//	static constexpr Vec2 LAST_INPUT_POS = Vec2(400, 240);
//
//	static constexpr Vec2 NEXT_PAGE_BUTTON_POS = Vec2(600, 40);
//
//	//static constexpr Vec2 SCORE_POS = Vec2(600, 10);
//	//static constexpr int32 SCORE_FONT_SIZE = 40;
//
//
//	FoxTyping(const WordColorTheme& wordColorTheme = WordColorTheme())
//		: theme(wordColorTheme)
//		, targetSentence(FOX_BOY_SEBTENCES[0][0])
//		, input()
//		, lastInput()
//	{
//		// ウィンドウサイズを設定
//
//
//		const Size windowSize(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
//		Window::Resize(windowSize);
//
//	}
//
//	~FoxTyping() = default;
//
//	void Update()
//	{
//		UpdateTextInput();
//		UpdateLyricLine();
//		UpdatePage();
//	}
//
//	void Draw() const
//	{
//		DrawTargetSentence();
//		DrawInputWord();
//		DrawLastInput();
//		//DrawScore();
//		DrawTexture();
//	}
//
//private:
//	void UpdateTextInput()
//	{
//		const String previousInput = input;
//		TextInput::UpdateText(input);
//
//		// 未変換の文字入力を取得する
//		const String editingText = TextInput::GetEditingText();
//	}
//
//	bool HasInputChanged(const String& previousInput, const String& currentInput) const
//	{
//		return previousInput != currentInput;
//	}
//
//	void HandleIncorrectInput()
//	{
//		if (!IsInputIncorrect()) return;
//		RemoveLastInputCharacter();
//	}
//
//	bool IsInputIncorrect() const
//	{
//		return !targetSentence.starts_with(input);
//	}
//
//	bool IsInputCompleted() const
//	{
//		return input == targetSentence;
//	}
//
//	void ForwardLyricLine()
//	{
//		// Implement the logic to move to the next line of lyrics
//	}
//
//	void UpdateLyricLine()
//	{
//		if (!IsInputCompleted()) return;
//
//		//UpdateScore();
//		ForwardLyricLine();
//	}
//
//	void UpdatePage()
//	{
//		if (!SimpleGUI::Button(U"次のページ", NEXT_PAGE_BUTTON_POS)) return;
//
//		SetNextPage();
//	}
//
//	void SetNextPage()
//	{
//		currentPage = (currentPage + 1) % MAX_PAGE_NUM;
//		Initialize();
//	}
//
//	void Initialize()
//	{
//		texture = Texture{ FOX_BOY_IMAGE_PATH[currentPage], TextureDesc::Mipped };
//		targetSentence = FOX_BOY_SEBTENCES[currentPage][0];
//		input.clear();
//		lastInput.clear();
//	}
//
//	void DrawTargetSentence() const
//	{
//		font(targetSentence).draw(TARGET_SENTENCE_POS, theme.wordColor);
//	}
//
//	void DrawInputWord() const
//	{
//		font(input).draw(INPUT_SENTENCE_POS, theme.correctWordColor);
//	}
//
//	void DrawLastInput() const
//	{
//		// 未変換の文字入力を取得する
//		const String editingText = TextInput::GetEditingText();
//		font(input + U'|' + editingText).draw(LAST_INPUT_POS);
//	}
//
//	//void DrawScore() const
//	//{
//	//	ColorF scoreColor = GetScoreColor();
//	//	font(U"文字数: {}"_fmt(score)).draw(SCORE_FONT_SIZE, SCORE_POS, scoreColor);
//	//}
//
//	void DrawTexture() const
//	{
//		texture.scaled(IMAGE_SCALE).draw(IMAGE_POS);
//	}
//
//	void StoreLastInput()
//	{
//		lastInput = s3d::String(1, input.back());
//	}
//
//	void RemoveLastInputCharacter()
//	{
//		input.pop_back();
//	}
//
//	//void UpdateScore()
//	//{
//	//	score += static_cast<int32>(input.length());
//	//	SendEncouragementIfNeeded();
//	//}
//
//	/*void SendEncouragementIfNeeded()
//	{
//		if (score - lastEncouragementScore >= EncouragementThreshold)
//		{
//			lastEncouragementScore = score;
//			ShowEncouragementToast();
//		}
//	}
//
//	void ShowEncouragementToast() const
//	{
//		const String& message = encouragementMessagesInRussian.choice();
//		ToastNotificationItem item{ .title = U"応援", .message = message };
//		Platform::Windows::ToastNotification::Show(item);
//	}*/
//
//	//ColorF GetScoreColor() const
//	//{
//	//	double redIntensity = Min(1.0, 0.1 + score * 0.01);
//	//	double greenIntensity = 1.0 - redIntensity;
//	//	return ColorF(redIntensity, greenIntensity, 0.0);
//	//}
//
//	//static constexpr Vec2 targetSentencePosition{ 40, 80 };
//	////static constexpr Vec2 InputWordPosition{ 40, 80 };
//	//static constexpr Vec2 LastInputPosition{ 40, 240 };
//	//static constexpr Vec2 TrachChageButtonPos{ 600, 40 };
//	//static constexpr Vec2 ScorePosition{ 600, 10 };
//	//static constexpr int32 FontSize = 40;
//	//static constexpr int32 scoreFontSize = FontSize / 2;
//	//static constexpr int32 EncouragementThreshold = 30 / 2;
//	//static constexpr double imageScale = 0.3;
//	//static constexpr Point imagePos = Point(0, 400);
//	static constexpr int32 MAX_PAGE_NUM = 20;
//
//	String targetSentence;
//	String input;
//	String lastInput;
//	//int32 score = 0;
//	//int32 lastEncouragementScore = 0;
//	WordColorTheme theme;
//	Font font{ FONT_SIZE };
//	Texture texture{ FOX_BOY_IMAGE_PATH[0], TextureDesc::Mipped };
//	int32 currentPage = 0;
//	Array<PageContents> FoxBoyBook;
//};
