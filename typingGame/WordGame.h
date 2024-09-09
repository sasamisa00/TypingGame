#pragma once
#include <Siv3D.hpp>
#include "AlphabetFunction.h"
#include "ColorDefinition.h"

class WordGame
{
public:
	WordGame(const WordColorTheme& wordColorTheme = WordColorTheme(), CyrillicAlphabetList cyrillicChar = CyrillicAlphabetList::а)
		: theme(wordColorTheme), words(CyrillicAlphabetToWords(cyrillicChar))
	{
		SelectRandomTargetWord();
	}

	~WordGame() = default;

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
	static constexpr Vec2 TargetWordPosition{ 40, 80 };
	static constexpr Vec2 InputWordPosition{ 40, 80 };
	static constexpr Vec2 LastInputPosition{ 40, 240 };
	static constexpr Vec2 AlphabetChangeButtonPosition{ 600, 40 };
	static constexpr Vec2 ScorePosition{ 600, 100 };
	static constexpr int32 FontSize = 40;
	static constexpr int32 scoreFontSize = FontSize / 2;
	static constexpr int32 EncouragementThreshold = 30 / 2;

	const Array<String> encouragementMessages = {
	U"フォースと共にあれ！",
	U"その調子だ、若きパダワン！",
	U"よくやった、ジェダイの騎士よ！",
	U"素晴らしい進歩だ、フォースを感じる！",
	U"そのまま続けるのだ、フォースが導く！",
	U"素晴らしい成果だ、ジェダイの道を歩んでいる！",
	U"君はフォースに満ちている！",
	U"その調子で頑張るのだ、ジェダイよ！",
	U"素晴らしい努力だ、フォースが共にある！",
	U"君は最高だ、フォースの守護者よ！",
	U"フォースの力を信じるのだ！",
	U"君の努力はフォースに認められている！",
	U"ジェダイの心を持ち続けるのだ！",
	U"フォースの導きに従うのだ！",
	U"君の成長はフォースの証だ！",
	U"フォースの力を感じるか？",
	U"その道を進むのだ、ジェダイよ！",
	U"フォースの光が君を照らしている！",
	U"君の努力は無駄ではない、フォースが証明している！",
	U"フォースの力を信じて、前進するのだ！"
	};


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
			SetWordsStartingWithLastInput();
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
		if (not IsAlphabetChangeButtonPressed()) return;
		SetWordsStartingWithLastInput();
	}

	bool IsAlphabetChangeButtonPressed() const
	{
		return SimpleGUI::Button(U"文字変更", AlphabetChangeButtonPosition);
	}

	void UpdateWordsWithRandomAlphabet()
	{
		words = SelectAdjustedRandomWords(CyrillicAlphabetToWords(GetRandomCyrillicAlphabet()));
		AdvanceToNextTargetWord();
	}

	void SetWordsStartingWithLastInput()
	{
		if (lastInput.isEmpty()) return;

		const CyrillicAlphabetList alphabet = CharToCyrillicAlphabet(lastInput[0]);
		words = SelectAdjustedRandomWords(CyrillicAlphabetToWords(alphabet));
		AdvanceToNextTargetWord();
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
		SelectRandomTargetWord();
		input.clear();
		lastInput.clear();
	}

	void SelectRandomTargetWord()
	{
		target = words.choice();
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
		const String& message = encouragementMessages.choice();
		ToastNotificationItem item{ .title = U"応援", .message = message };
		Platform::Windows::ToastNotification::Show(item);
	}

	ColorF GetScoreColor() const
	{
		double redIntensity = Min(1.0, 0.1 + score * 0.01);
		double greenIntensity = Min(0.5, 0.05 + score * 0.005);
		return ColorF(redIntensity, greenIntensity, 0.0);
	}

	const WordColorTheme& theme;
	Array<String> words;
	String target;
	String input;
	String lastInput;
	int32 score = 0;
	int32 lastEncouragementScore = 0;

	const Font font{ FontMethod::MSDF, FontSize, Typeface::Bold };
};
