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
		HandleTextInput();
		HandleWrongInput();
		CheckForNextWord();
		HandleAlphabetChange();
	}

	// 描画処理
	void Draw() const
	{
		DrawTargetWord();
		DrawInputWord();
		DrawLastInput();
	}

private:
	static constexpr Vec2 ButtonPosition{ 600, 40 };

	void HandleTextInput()
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

	void HandleWrongInput()
	{
		if (!target.starts_with(input))
		{
			RemoveLastInputCharacter();
		}
	}

	void CheckForNextWord()
	{
		if (input == target)
		{
			GoNextWord();
		}
	}

	void HandleAlphabetChange()
	{
		if (SimpleGUI::Button(U"абв...", ButtonPosition))
		{
			words = CyrillicAlphabetToWords(GetRandomCyrillicAlphabet());
			GoNextWord();
		}
	}

	void DrawTargetWord() const
	{
		font(target).draw(40, Vec2{ 40, 80 }, theme.wordColor);
	}

	void DrawInputWord() const
	{
		font(input).draw(40, Vec2{ 40, 80 }, theme.correctWordColor);
	}

	void DrawLastInput() const
	{
		if (!lastInput.isEmpty())
		{
			font(U"| {}"_fmt(lastInput)).draw(40, Vec2{ 40, 240 }, theme.inputtingWordColor);
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
