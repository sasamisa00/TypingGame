#pragma once
#include <Siv3D.hpp>
#include "AlphabetFunction.h"
#include "ColorDefinition.h"


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
		DeleteWrongInput();

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
		if (!wrongInput.isEmpty())
		{
			font(U"wrong input: {}"_fmt(wrongInput)).draw(40, Vec2{ 40, 240 }, Palette::Aliceblue);
		}
	}



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


	void ClearWrongInput()
	{
		
		wrongInput.clear();
	}

	void RecordWrongInput()
	{
		
		wrongInput.push_back(input.back());
	}

	void RemoveLastInputCharacter()
	{
		
		input.pop_back();
	}



	void GoNextWord()
	{
		// 問題文をランダムに選ぶ
		target = words.choice();

		// 入力文字列をクリアする	
		input.clear();

		// 削除された文字列をクリアする
		wrongInput.clear();
	}

private:
	//問題の配列を選ぶ
	Array<String> words;

	// 問題文をランダムに選ぶ
	String target = words.choice();

	// 入力中の文字列
	String input;

	// 削除された文字列。本当は１文字でいいけど、複数の文字を削除することもあるかもしれないのでstring型にしている
	String wrongInput;

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

};
