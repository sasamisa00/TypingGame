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
		: theme(wordColorTheme), words(shortparis_RedFlag) // shortparis_RedFlagから問題を作成するように変更
	{
		SetRandomMusicAndSetHeadWord();
	}

	~RedFlagTyping() = default;

	void Update()
	{
		HandleTextInput();
		HandleIncorrectInput();
		CheckAndAdvanceToNextWord();
		HandleAlphabetChange();
	}

	void Draw() const
	{
		RenderTargetWord();
		RenderInputWord();
		RenderLastInput();
		RenderScore();
	}

private:
	void ChangeMusic()
	{
		// ここに曲変更の処理を書く

	}

	void HandleTextInput()
	{
		const String previousInput = input;
		TextInput::UpdateText(input, TextInputMode::DenyControl);
		if (HasInputChanged(previousInput, input))
		{
			StoreLastInput();
		}

		if (KeyControl.down())
		{
			SetRandomMusicAlbum();
		}
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
		return !target.starts_with(input);
	}

	void CheckAndAdvanceToNextWord()
	{
		if (input != target) return;
		UpdateScore();
		AdvanceToNextTargetWord();
	}

	void HandleAlphabetChange()
	{
		if (not IsMusicChangeButtonPressed()) return;

		SetRandomMusicAlbum();
	}

	bool IsMusicChangeButtonPressed() const
	{
		return SimpleGUI::Button(U"曲変更", AlphabetChangeButtonPosition);
	}


	void SetRandomMusicAlbum()
	{
		words = shortparis_RedFlag;
		AdvanceToNextTargetWord();

		//if (lastInput.isEmpty()) return;

		/*const CyrillicAlphabetList alphabet = CharToCyrillicAlphabet(lastInput[0]);
		words = SelectAdjustedRandomWords(CyrillicAlphabetToWords(alphabet));
		AdvanceToNextTargetWord();*/
	}


	void RenderTargetWord() const
	{
		font(target).draw(TargetWordPosition, theme.wordColor);
	}

	void RenderInputWord() const
	{
		font(input).draw(InputWordPosition, theme.correctWordColor);
	}

	void RenderLastInput() const
	{
		if (lastInput.isEmpty()) return;
		font(U"| {}"_fmt(lastInput)).draw(LastInputPosition, theme.inputtingWordColor);
	}

	void RenderScore() const
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

	void AdvanceToNextTargetWord()
	{
		SetRandomMusicAndSetHeadWord();
		input.clear();
		lastInput.clear();
	}

	void SetRandomMusicAndSetHeadWord()
	{
		const Array<String>& selectedArray = words.choice();
		//target = selectedArray.choice();
		target = selectedArray[0];
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
	static constexpr Vec2 AlphabetChangeButtonPosition{ 600, 40 };
	static constexpr Vec2 ScorePosition{ 600, 10 };
	static constexpr int32 FontSize = 40;
	static constexpr int32 scoreFontSize = FontSize / 2;
	static constexpr int32 EncouragementThreshold = 30 / 2;

	Array<Array<String>> words;
	String target;
	String input;
	String lastInput;
	int32 score = 0;
	int32 lastEncouragementScore = 0;
	WordColorTheme theme;
	Font font{ FontSize };
};

