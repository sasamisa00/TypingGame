// WordGame.h
#pragma once
#include <Siv3D.hpp>
#include "AlphabetFunction.h"
#include "ColorDefinition.h"

class WordGame
{
public:
	// コンストラクタで色のテーマを受け取る
	WordGame(const WordColorTheme& wordColorTheme = WordColorTheme(), CyrillicAlphabetList cyrillicChar = CyrillicAlphabetList::а)
		: theme(wordColorTheme), words(CyrillicAlphabetToWords(cyrillicChar))
	{
		SelectRandomTarget();
	}

	~WordGame() = default;

	// 更新処理
	void Update()
	{
		ProcessTextInput();
		ProcessWrongInput();
		CheckForNextWord();
		ProcessAlphabetChange();
	}

	// 描画処理
	void Draw() const
	{
		DrawTargetWord();
		DrawInputWord();
		DrawLastInput();
	}

private:
	// 定数の定義
	static constexpr Vec2 ButtonPosition{ 600, 40 };
	static constexpr Vec2 TargetWordPosition{ 40, 80 };
	static constexpr Vec2 InputWordPosition{ 40, 80 };
	static constexpr Vec2 LastInputPosition{ 40, 240 };

	void ProcessTextInput()
	{
		const String previousInput = input;
		TextInput::UpdateText(input, TextInputMode::DenyControl);
		if (HasInputChanged(previousInput, input))
		{
			RecordLastInput();
		}
	}

	bool HasInputChanged(const String& previousInput, const String& currentInput) const
	{
		return previousInput != currentInput;
	}

	void ProcessWrongInput()
	{
		if (IsWrongInput())
		{
			RemoveLastInputCharacter();
		}
	}

	bool IsWrongInput() const
	{
		return !target.starts_with(input);
	}

	void CheckForNextWord()
	{
		if (input == target)
		{
			GoNextWord();
		}
	}

	void ProcessAlphabetChange()
	{
		if (IsAlphabetChangeButtonClicked())
		{
			ChangeAlphabet();
		}
	}

	bool IsAlphabetChangeButtonClicked() const
	{
		return SimpleGUI::Button(U"абв...", ButtonPosition);
	}

	void ChangeAlphabet()
	{
		words = CyrillicAlphabetToWords(GetRandomCyrillicAlphabet());
		GoNextWord();
	}

	void DrawTargetWord() const
	{
		font(target).draw(40, TargetWordPosition, theme.wordColor);
	}

	void DrawInputWord() const
	{
		font(input).draw(40, InputWordPosition, theme.correctWordColor);
	}

	void DrawLastInput() const
	{
		if (!lastInput.isEmpty())
		{
			font(U"| {}"_fmt(lastInput)).draw(40, LastInputPosition, theme.inputtingWordColor);
		}
	}

	void RecordLastInput()
	{
		lastInput = s3d::String(1, input.back());
	}

	void RemoveLastInputCharacter()
	{
		input.pop_back();
	}

	void GoNextWord()
	{
		SelectRandomTarget();
		input.clear();
		lastInput.clear();
	}

	void SelectRandomTarget()
	{
		target = words.choice();
	}

	const WordColorTheme& theme;

	Array<String> words;
	String target;
	String input;
	String lastInput;

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };
};
