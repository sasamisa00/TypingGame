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
		TextInput::UpdateText(input, TextInputMode::DenyControl);

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
		font(input).draw(40, Vec2{ 40, 80 }, theme.inputtingWordColor);

		// 削除された文字を描画する
		if (not wrongInput.isEmpty())
		{
			font(U"| {}"_fmt(wrongInput)).draw(40, Vec2{ 40, 240 }, theme.correctWordColor);
		}
	}

private:
	// 誤った入力を削除する
	bool DeleteWrongInput()
	{
		// 入力がターゲットの先頭と一致する場合は何もしない
		if (target.starts_with(input))
		{
			return false;
		}

		// 誤った入力を1文字だけ表示するために、wrongInputをクリアする
		ClearWrongInput();
		// 誤った入力の最後の文字を記録する
		RecordWrongInput();
		// 誤った入力の最後の文字を削除する
		RemoveLastInputCharacter();

		return true;
	}

	// 誤った入力をクリアする
	void ClearWrongInput()
	{
		wrongInput.clear();
	}

	// 誤った入力を記録する
	void RecordWrongInput()
	{
		wrongInput.push_back(input.back());
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

		// 削除された文字列をクリアする
		wrongInput.clear();
	}

	// 色のテーマ
	const WordColorTheme& theme;

	// 問題の配列を選ぶ
	Array<String> words;

	// 問題文をランダムに選ぶ
	String target;

	// 入力中の文字列
	String input;

	// 削除された文字列
	String wrongInput;

	// フォント設定
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };
};
