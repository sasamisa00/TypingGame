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
	FoxTyping(const WordColorTheme& wordColorTheme = WordColorTheme())
		: theme(wordColorTheme)
		, targetSentence(FOX_BOY_SEBTENCES[0][0])
		, input()
		, lastInput()
		//, currentLine(0)

	{
		for (auto i : step(FOX_BOY_SEBTENCES.size()))
		{
			FoxBoyBook.push_back(PageContents{ FOX_BOY_SEBTENCES[i], FOX_BOY_IMAGE_PATH[i] });
		}
	}

	~FoxTyping() = default;

	void Update()
	{
		UpdateTextInput();
		UpdateLylicLine();
		UpdatePage();

	}

	void Draw() const
	{
		DrawTagerSentence();
		DrawInputWord();
		DrawLastInput();
		DrawScore();
		DrawTextrue();

	}

private:
	void UpdateTextInput()
	{
		const String previousInput = input;
		//TextInput::UpdateText(input, TextInputMode::DenyControl);
		TextInput::UpdateText(input);

		// 未変換の文字入力を取得する
		const String editingText = TextInput::GetEditingText();

		const Rect box{ 50, 50, 700, 300 };
		box.draw(ColorF{ 0.3 });

		font(input + U'|' + editingText).draw(30, box.stretched(-20));

		/*if (HasInputChanged(previousInput, input))
		{
			StoreLastInput();
		}*/

		//HandleIncorrectInput();

	}

	bool HasInputChanged(const String& previousInput, const String& currentInput) const
	{
		return previousInput != currentInput;
	}

	void HandleIncorrectInput()
	{
		if (not IsInputIncorrect()) return;
		RemoveLastInputCharacter();
	}

	bool IsInputIncorrect() const
	{
		return not targetSentence.starts_with(input);
	}

	bool IsInputCompleted() const
	{
		return input == targetSentence;
	}

	void ForwardLylicLine()
	{
		//currentLine = (currentLine + 1) % track.size();
		//targetSentence = track[currentLine];
	}

	void UpdateLylicLine()
	{
		if (not IsInputCompleted()) return;

		UpdateScore();
		ForwardLylicLine();

	}

	void UpdatePage()
	{
		if (not SimpleGUI::Button(U"次のページ", TrachChageButtonPos)) return;

		SetNextPage();
	}




	void SetNextPage()
	{
		currentPage = (currentPage + 1) % MAX_PAGE_NUM;

		Initialize();
	}

	void Initialize()
	{
		texture = Texture{ FOX_BOY_IMAGE_PATH[currentPage], TextureDesc::Mipped };
		targetSentence = FOX_BOY_SEBTENCES[currentPage][0];
		input.clear();
		lastInput.clear();
		//currentLine = 0;
	}

	void DrawTrackTitle() const
	{

		//font(U"{}"_fmt(track[0])).draw(TrackTitlePos, theme.wordColor);
	}

	void DrawTagerSentence() const
	{
		font(targetSentence).draw(targetSentencePosition, theme.wordColor);
	}

	void DrawInputWord() const
	{
		font(input).draw(InputWordPosition, theme.correctWordColor);
	}

	void DrawLastInput() const
	{
		if (lastInput.isEmpty()) return;
		font(U"| {}"_fmt(lastInput)).draw(LastInputPosition, theme.inputtingWordColor);
	}

	void DrawScore() const
	{
		ColorF scoreColor = GetScoreColor();
		font(U"文字数: {}"_fmt(score)).draw(scoreFontSize, ScorePosition, scoreColor);
	}

	void DrawTextrue() const
	{
		texture.scaled(imageScale).draw(imagePos);
	}

	void StoreLastInput()
	{
		lastInput = s3d::String(1, input.back());
	}

	void RemoveLastInputCharacter()
	{
		input.pop_back();
	}



	void UpdateScore()
	{
		score += static_cast<int32>(input.length());
		SendEncouragementIfNeeded();
	}

	void SendEncouragementIfNeeded()
	{
		if (score - lastEncouragementScore >= EncouragementThreshold)
		{
			lastEncouragementScore = score;
			ShowEncouragementToast();
		}
	}

	void ShowEncouragementToast() const
	{
		const String& message = encouragementMessagesInRussian.choice();
		ToastNotificationItem item{ .title = U"応援", .message = message };
		Platform::Windows::ToastNotification::Show(item);
	}

	ColorF GetScoreColor() const
	{
		double redIntensity = Min(1.0, 0.1 + score * 0.01);
		double greenIntensity = 1.0 - redIntensity;
		return ColorF(redIntensity, greenIntensity, 0.0);
	}

	static constexpr Vec2 targetSentencePosition{ 40, 80 };
	static constexpr Vec2 InputWordPosition{ 40, 80 };
	static constexpr Vec2 LastInputPosition{ 40, 240 };
	static constexpr Vec2 TrachChageButtonPos{ 600, 40 };
	static constexpr Vec2 ScorePosition{ 600, 10 };
	static constexpr int32 FontSize = 40;
	static constexpr int32 scoreFontSize = FontSize / 2;
	static constexpr int32 EncouragementThreshold = 30 / 2;

	static constexpr double imageScale = 0.3;
	static constexpr Point imagePos = Point(0, 400);

	String targetSentence;
	String input;
	String lastInput;
	int32 score = 0;
	int32 lastEncouragementScore = 0;
	WordColorTheme theme;
	Font font{ FontSize };

	Texture texture{ FOX_BOY_IMAGE_PATH[0], TextureDesc::Mipped};
	int32 currentPage = 0;

	static constexpr int32 MAX_PAGE_NUM = 20;

	Array<PageContents> FoxBoyBook;
};


