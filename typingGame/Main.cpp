# include <Siv3D.hpp>
#include "wordList.h"

bool DeleteWorongInput(String& input, const String& target)
{
	if (not target.starts_with(input))
	{
		input.pop_back();
		return true;
	}
	return false;
}

void Main()
{
	Scene::SetBackground(Palette::Powderblue);

	//問題のアルファベットを選ぶ
	const Array<String> words = вWords;

    // 問題文をランダムに選ぶ
	String target = words.choice();

	// 入力中の文字列
	String input;

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	while (System::Update())
	{
		// テキスト入力（TextInputMode::DenyControl: エンターやタブ、バックスペースは受け付けない）
		TextInput::UpdateText(input, TextInputMode::DenyControl);

		// 誤った入力が含まれていたら削除する
		DeleteWorongInput(input, target);

		// 一致したら次の問題へ移る
		if (input == target)
		{
			// 問題文をランダムに選ぶ
			target = words.choice();

			// 入力文字列をクリアする	
			input.clear();
		}

		// 問題文を描画する
		font(target).draw(40, Vec2{ 40, 80 }, ColorF{ 0.98 });

		// 入力中の文字を描画する
		font(input).draw(40, Vec2{ 40, 80 }, ColorF{ 0.12 });
	}
}
