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
		// 問題文をランダムに選ぶ
		target = words.choice();
	}

	~WordGame() = default;

	// 更新処理
	void Update()
	{
		// テキスト入力（TextInputMode::DenyControl: エンターやタブ、バックスペースは受け付けない）
		UpdateTextInput();

		// 誤った入力が含まれていたら削除する
		DeleteWrongInput();

		// 一致したら次の問題へ移る
		if (input == target)
		{
			GoNextWord();
		}

		// ボタンが押されたら問題のアルファベットを変更
		if (SimpleGUI::Button(U"абв...", Vec2{ 600, 40 }))
		{
			words = CyrillicAlphabetToWords(GetRandomCyrillicAlphabet());
			GoNextWord();
		}
	}

	// 描画処理
	void Draw() const
	{
		// 問題文を描画する
		font(target).draw(40, Vec2{ 40, 80 }, theme.wordColor);

		// 入力中の文字を描画する
		font(input).draw(40, Vec2{ 40, 80 }, theme.correctWordColor);

		// 入力の最後の文字を描画する
		if (not lastInput.isEmpty())
		{
			font(U"| {}"_fmt(lastInput)).draw(40, Vec2{ 40, 240 }, theme.inputtingWordColor);
		}
	}

private:
	// テキスト入力を更新し、入力があったら最後の入力文字を記録する
	void UpdateTextInput()
	{
		const String previousInput = input;
		TextInput::UpdateText(input, TextInputMode::DenyControl);
		if (previousInput != input)
		{
			RecordLastInput();
		}
	}

	// 誤った入力を削除する
	bool DeleteWrongInput()
	{
		// 入力がターゲットの先頭と一致する場合は何もしない
		if (target.starts_with(input))
		{
			return false;
		}

		// 誤った入力の最後の文字を削除する
		RemoveLastInputCharacter();

		return true;
	}

	// 最後の入力文字を記録する
	void RecordLastInput()
	{
		lastInput = s3d::String(1, input.back());
	}

	// 最後の入力文字を削除する
	void RemoveLastInputCharacter()
	{
		input.pop_back();
	}

	// 次の問題に移る
	void GoNextWord()
	{
		// 問題文をランダムに選ぶ
		target = words.choice();

		// 入力文字列をクリアする
		input.clear();

		// 最後の入力文字をクリアする
		lastInput.clear();
	}

	// 色のテーマ
	const WordColorTheme& theme;

	// 問題の配列を選ぶ
	Array<String> words;

	// 問題文をランダムに選ぶ
	String target;

	// 入力中の文字列
	String input;

	// 最後の入力文字
	String lastInput;

	// フォント設定
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };
};
