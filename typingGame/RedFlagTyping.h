#pragma once
#include <Siv3D.hpp>
#include "AlphabetFunction.h"
#include "ColorDefinition.h"
#include "EncouragingMessages.h"
#include "shortparis.h"

class RedFlagTyping
{
public:
	RedFlagTyping(const WordColorTheme& wordColorTheme = WordColorTheme(), CyrillicAlphabetList cyrillicChar = CyrillicAlphabetList::а)
		: theme(wordColorTheme)//, words(shortparis_RedFlag) // shortparis_RedFlagから問題を作成するように変更
		, album(shortparis_RedFlag)
		, track(shortparis_RedFlag[0])
		, targetWord(track[0])
		, input()
		, lastInput()
		, currentLylicLine(0)

	{
		//Initialize();
	}

	~RedFlagTyping() = default;

	void Update()
	{
		UpdateTextInput();
		UpdateLylicLine();
		UpdateTrack();

	}

	void Draw() const
	{
		DrawTargetWord();
		DrawInputWord();
		DrawLastInput();
		DrawScore();
		DrawTrackTitle();
	}

private:
	void UpdateTextInput()
	{
		const String previousInput = input;
		TextInput::UpdateText(input, TextInputMode::DenyControl);

		if (HasInputChanged(previousInput, input))
		{
			StoreLastInput();
		}

		HandleIncorrectInput();

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
		return not targetWord.starts_with(input);
	}

	bool IsInputCompleted() const
	{
		return input == targetWord;
	}

	void ForwardLylicLine()
	{
		currentLylicLine = (currentLylicLine + 1) % track.size();
		targetWord = track[currentLylicLine];
	}

	void UpdateLylicLine()
	{
		if (not IsInputCompleted()) return;

		UpdateScore();
		ForwardLylicLine();
		
	}

	void UpdateTrack()
	{
		if (not SimpleGUI::Button(U"曲変更", TrachChageButtonPos)) return;

		SetRandomTrack();
	}


	void Initialize()
	{
		targetWord = track[0];
		input.clear();
		lastInput.clear();
		currentLylicLine = 0;
	}

	void SetRandomTrack()
	{
		track = album.choice();

		Initialize();
	}

	void DrawTrackTitle() const
	{

		font(U"{}"_fmt(track[0])).draw(TrackTitlePos, theme.wordColor);
	}

	void DrawTargetWord() const
	{
		font(targetWord).draw(TargetWordPosition, theme.wordColor);
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

	static constexpr Vec2 TargetWordPosition{ 40, 80 };
	static constexpr Vec2 InputWordPosition{ 40, 80 };
	static constexpr Vec2 LastInputPosition{ 40, 240 };
	static constexpr Vec2 TrachChageButtonPos{ 600, 40 };
	static constexpr Vec2 ScorePosition{ 600, 10 };
	static constexpr Vec2 TrackTitlePos{ 10,10 };
	static constexpr int32 FontSize = 40;
	static constexpr int32 scoreFontSize = FontSize / 2;
	static constexpr int32 EncouragementThreshold = 30 / 2;

	//Array<Array<String>> words;
	Array<Array<String>> album;
	Array<String> track;
	String targetWord;
	int32 currentLylicLine;
	String input;
	String lastInput;
	int32 score = 0;
	int32 lastEncouragementScore = 0;
	WordColorTheme theme;
	Font font{ FontSize };
};

