#pragma once
#include <Siv3D.hpp>
#include "AlphabetFunction.h"


class WordGame
{
public:

	WordGame(CyrillicAlphabetList cyrillicChar = CyrillicAlphabetList::а)
		: words(CyrillicAlphabetToWords(cyrillicChar))
	{
		// 問題文をランダムに選ぶ
		target = words.choice();

	}

	~WordGame()
	{
	}

	void Update()
	{
		// テキスト入力（TextInputMode::DenyControl: エンターやタブ、バックスペースは受け付けない）
		TextInput::UpdateText(input, TextInputMode::DenyControl);

		// 誤った入力が含まれていたら削除する
		DeleteWorongInput();

		// 一致したら次の問題へ移る
		if (input == target)
			GoNextWord();


		// ボタンが押されたら問題のアルファベットを変更
		if (SimpleGUI::Button(U"абв...", Vec2{ 600, 40 }))
		{
			words = CyrillicAlphabetToWords(GetRandomCyrillicAlphabet());
			GoNextWord();
		}

	}

	void Draw()
	{
		// 問題文を描画する
		font(target).draw(40, Vec2{ 40, 80 }, ColorF{ 0.98 });

		// 入力中の文字を描画する
		font(input).draw(40, Vec2{ 40, 80 }, ColorF{ 0.12 });

		// 削除された文字を描画する
		if (!worongInput.isEmpty())
		{
			font(U"削除された文字: {}"_fmt(worongInput)).draw(40, Vec2{ 40, 240 }, ColorF{ 0.5, 0.0, 0.0 });
		}
	}



	bool DeleteWorongInput()
	{
		// 入力がターゲットの先頭と一致しない場合
		if (not target.starts_with(input))
		{
			// 誤った入力を1文字だけ表示するために、worongInputをクリアする
			worongInput.clear();

			// 誤った入力の最後の文字を記録する
			worongInput.push_back(input.back());

			// 誤った入力の最後の文字を削除する
			input.pop_back();
			return true;
		}
		return false;
	}


	void GoNextWord()
	{
		// 問題文をランダムに選ぶ
		target = words.choice();

		// 入力文字列をクリアする	
		input.clear();

		// 削除された文字列をクリアする
		worongInput.clear();
	}

private:
	//問題の配列を選ぶ
	Array<String> words;

	// 問題文をランダムに選ぶ
	String target = words.choice();

	// 入力中の文字列
	String input;

	// 削除された文字列。本当は１文字でいいけど、複数の文字を削除することもあるかもしれないのでstring型にしている
	String worongInput;

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

};
