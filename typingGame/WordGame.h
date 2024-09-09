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
		RenderScore(); // スコアを描画
	}

private:
	static constexpr Vec2 TargetWordPosition{ 40, 80 };
	static constexpr Vec2 InputWordPosition{ 40, 80 };
	static constexpr Vec2 LastInputPosition{ 40, 240 };
	static constexpr Vec2 AlphabetChangeButtonPosition{ 600, 40 };
	static constexpr Vec2 ScorePosition{ 40, 320 }; // スコアの表示位置
	static constexpr int32 FontSize = 40;

	void HandleTextInput()
	{
		const String previousInput = input;
		TextInput::UpdateText(input, TextInputMode::DenyControl);
		if (HasInputChanged(previousInput, input))
		{
			StoreLastInput();
		}

		// ctrl key が押された場合に、lastInput の文字によってwordを変更する
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
		UpdateScore(); // スコアを更新
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

		CyrillicAlphabetList alphabet = CharToCyrillicAlphabet(lastInput[0]);
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
		font(U"スコア: {}"_fmt(score)).draw(ScorePosition, Palette::Black);
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
	}

	const WordColorTheme& theme;

	Array<String> words;
	String target;
	String input;
	String lastInput;
	int32 score = 0; // スコアを保持する変数

	const Font font{ FontMethod::MSDF, FontSize, Typeface::Bold };
};
