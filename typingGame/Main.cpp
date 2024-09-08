# include <Siv3D.hpp>
#include "wordList.h"


Array<String> CyrillicAlphabetToWords(CyrillicAlphabetList cyrillicChar)
{
	Array<String> words;

	switch (cyrillicChar)
	{
	case CyrillicAlphabetList::а:
		words = аWords;
		break;
	case CyrillicAlphabetList::б:
		words = бWords;
		break;
	case CyrillicAlphabetList::в:
		words = вWords;
		break;
	case CyrillicAlphabetList::г:
		words = гWords;
		break;
	case CyrillicAlphabetList::д:
		words = дWords;
		break;
	case CyrillicAlphabetList::е:
		words = еWords;
		break;
	case CyrillicAlphabetList::ё:
		words = ёWords;
		break;
	case CyrillicAlphabetList::ж:
		words = жWords;
		break;
	case CyrillicAlphabetList::з:
		words = зWords;
		break;
	case CyrillicAlphabetList::и:
		words = иWords;
		break;
	case CyrillicAlphabetList::й:
		words = йWords;
		break;
	case CyrillicAlphabetList::к:
		words = кWords;
		break;
	case CyrillicAlphabetList::л:
		words = лWords;
		break;
	case CyrillicAlphabetList::м:
		words = мWords;
		break;
	case CyrillicAlphabetList::н:
		words = нWords;
		break;
	case CyrillicAlphabetList::о:
		words = оWords;
		break;
	case CyrillicAlphabetList::п:
		words = пWords;
		break;
	case CyrillicAlphabetList::р:
		words = рWords;
		break;
	case CyrillicAlphabetList::с:
		words = сWords;
		break;
	case CyrillicAlphabetList::т:
		words = тWords;
		break;
	case CyrillicAlphabetList::у:
		words = уWords;
		break;
	case CyrillicAlphabetList::ф:
		words = фWords;
		break;
	case CyrillicAlphabetList::х:
		words = хWords;
		break;
	case CyrillicAlphabetList::ц:
		words = цWords;
		break;
	case CyrillicAlphabetList::ч:
		words = чWords;
		break;
	case CyrillicAlphabetList::ш:
		words = шWords;
		break;
	case CyrillicAlphabetList::щ:
		words = щWords;
		break;
	case CyrillicAlphabetList::ъ:
		// words = ъWords;
		break;
	case CyrillicAlphabetList::ы:
		// words = ыWords;
		break;
	case CyrillicAlphabetList::ь:
		// words = ьWords;
		break;
	case CyrillicAlphabetList::э:
		words = эWords;
		break;
	case CyrillicAlphabetList::ю:
		words = юWords;
		break;
	case CyrillicAlphabetList::я:
		words = яWords;
		break;
	default:
		words = аWords;
		break;
	}

	return words;
}


class WordGame
{
public:

	WordGame(CyrillicAlphabetList cyrillicChar)
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

		//描画系
		Draw();
	}

	void Draw()
	{
		// 問題文を描画する
		font(target).draw(40, Vec2{ 40, 80 }, ColorF{ 0.98 });

		// 入力中の文字を描画する
		font(input).draw(40, Vec2{ 40, 80 }, ColorF{ 0.12 });
	}

	bool DeleteWorongInput()
	{
		if (not target.starts_with(input))
		{
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
	}

private:
	//問題のアルファベットを選ぶ
	const Array<String> words;

	// 問題文をランダムに選ぶ
	String target = words.choice();

	// 入力中の文字列
	String input;

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

};




void Main()
{
	Scene::SetBackground(Palette::Powderblue);


	//問題のアルファベットを選ぶ
	String cyrillicAlphabt;
	TextInput::UpdateText(cyrillicAlphabt, TextInputMode::DenyControl);



	WordGame wordGame(CyrillicAlphabetList::б);

	while (System::Update())
	{
		wordGame.Update();


	}
}
