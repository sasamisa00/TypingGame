# include <Siv3D.hpp>
#include "wordList.h"

//頭文字によって問題のリストを変更する
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

//ランダムにアルファベットを選ぶ
CyrillicAlphabetList GetRandomCyrillicAlphabet()
{
	static const Array<CyrillicAlphabetList> allAlphabets = {
		CyrillicAlphabetList::а, CyrillicAlphabetList::б, CyrillicAlphabetList::в, CyrillicAlphabetList::г,
		CyrillicAlphabetList::д, CyrillicAlphabetList::е, CyrillicAlphabetList::ё, CyrillicAlphabetList::ж,
		CyrillicAlphabetList::з, CyrillicAlphabetList::и, CyrillicAlphabetList::й, CyrillicAlphabetList::к,
		CyrillicAlphabetList::л, CyrillicAlphabetList::м, CyrillicAlphabetList::н, CyrillicAlphabetList::о,
		CyrillicAlphabetList::п, CyrillicAlphabetList::р, CyrillicAlphabetList::с, CyrillicAlphabetList::т,
		CyrillicAlphabetList::у, CyrillicAlphabetList::ф, CyrillicAlphabetList::х, CyrillicAlphabetList::ц,
		CyrillicAlphabetList::ч, CyrillicAlphabetList::ш, CyrillicAlphabetList::щ, CyrillicAlphabetList::ъ,
		CyrillicAlphabetList::ы, CyrillicAlphabetList::ь, CyrillicAlphabetList::э, CyrillicAlphabetList::ю,
		CyrillicAlphabetList::я
	};

	return allAlphabets.choice();
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


		// ボタンが押されたら問題のアルファベットを変更
		if (SimpleGUI::Button(U"абв...", Vec2{ 600, 40 }))
		{
			words = CyrillicAlphabetToWords(GetRandomCyrillicAlphabet());
			GoNextWord();
		}

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
	//問題の配列を選ぶ
	Array<String> words;

	// 問題文をランダムに選ぶ
	String target = words.choice();

	// 入力中の文字列
	String input;

	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

};




void Main()
{
	Scene::SetBackground(Palette::Powderblue);

	// ウィンドウサイズを可変に設定
	Window::SetStyle(WindowStyle::Sizable);


	//問題のアルファベットを選ぶ
	String cyrillicAlphabt;
	TextInput::UpdateText(cyrillicAlphabt, TextInputMode::DenyControl);



	WordGame wordGame(CyrillicAlphabetList::б);

	while (System::Update())
	{
		wordGame.Update();

		// Sキーが押されたらスクリーンショットを撮る
		if (KeyS.down())
		{
			const String screenshotPath = U"screenshot.png";
			ScreenCapture::SaveCurrentFrame(screenshotPath);
			//Print << U"スクリーンショットを保存しました: " << screenshotPath;
			
		}

	}
}
