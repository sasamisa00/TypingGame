#include "AlphabetFunction.h"

// 頭文字によって問題のリストを変更する
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
		words = аWords;//ъのリストは空だから、とりあえず'a'に対応するリストを返す
		break;
	case CyrillicAlphabetList::ы:
		// words = ыWords;
		words = аWords;//ыのリストは空だから、とりあえず'a'に対応するリストを返す
		break;
	case CyrillicAlphabetList::ь:
		// words = ьWords;
		words = аWords;//ьのリストは空だから、とりあえず'a'に対応するリストを返す
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
		words = аWords;//とりあえず'a'に対応するリストを返す
		break;
	}

	return words;
}

// ランダムにアルファベットを選ぶ
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


// 文字を対応するCyrillicAlphabetListの列挙型に変換する関数
CyrillicAlphabetList CharToCyrillicAlphabet(const char32_t ch)
{
	switch (ch)
	{
	case U'а': return CyrillicAlphabetList::а; // 'а' に対応する列挙型
	case U'б': return CyrillicAlphabetList::б; // 'б' に対応する列挙型
	case U'в': return CyrillicAlphabetList::в; // 'в' に対応する列挙型
	case U'г': return CyrillicAlphabetList::г; // 'г' に対応する列挙型
	case U'д': return CyrillicAlphabetList::д; // 'д' に対応する列挙型
	case U'е': return CyrillicAlphabetList::е; // 'е' に対応する列挙型
	case U'ё': return CyrillicAlphabetList::ё; // 'ё' に対応する列挙型
	case U'ж': return CyrillicAlphabetList::ж; // 'ж' に対応する列挙型
	case U'з': return CyrillicAlphabetList::з; // 'з' に対応する列挙型
	case U'и': return CyrillicAlphabetList::и; // 'и' に対応する列挙型
	case U'й': return CyrillicAlphabetList::й; // 'й' に対応する列挙型
	case U'к': return CyrillicAlphabetList::к; // 'к' に対応する列挙型
	case U'л': return CyrillicAlphabetList::л; // 'л' に対応する列挙型
	case U'м': return CyrillicAlphabetList::м; // 'м' に対応する列挙型
	case U'н': return CyrillicAlphabetList::н; // 'н' に対応する列挙型
	case U'о': return CyrillicAlphabetList::о; // 'о' に対応する列挙型
	case U'п': return CyrillicAlphabetList::п; // 'п' に対応する列挙型
	case U'р': return CyrillicAlphabetList::р; // 'р' に対応する列挙型
	case U'с': return CyrillicAlphabetList::с; // 'с' に対応する列挙型
	case U'т': return CyrillicAlphabetList::т; // 'т' に対応する列挙型
	case U'у': return CyrillicAlphabetList::у; // 'у' に対応する列挙型
	case U'ф': return CyrillicAlphabetList::ф; // 'ф' に対応する列挙型
	case U'х': return CyrillicAlphabetList::х; // 'х' に対応する列挙型
	case U'ц': return CyrillicAlphabetList::ц; // 'ц' に対応する列挙型
	case U'ч': return CyrillicAlphabetList::ч; // 'ч' に対応する列挙型
	case U'ш': return CyrillicAlphabetList::ш; // 'ш' に対応する列挙型
	case U'щ': return CyrillicAlphabetList::щ; // 'щ' に対応する列挙型
	case U'ъ': return CyrillicAlphabetList::ъ; // 'ъ' に対応する列挙型
	case U'ы': return CyrillicAlphabetList::ы; // 'ы' に対応する列挙型
	case U'ь': return CyrillicAlphabetList::ь; // 'ь' に対応する列挙型
	case U'э': return CyrillicAlphabetList::э; // 'э' に対応する列挙型
	case U'ю': return CyrillicAlphabetList::ю; // 'ю' に対応する列挙型
	case U'я': return CyrillicAlphabetList::я; // 'я' に対応する列挙型
	default: return CyrillicAlphabetList::а;//とりあえず'a'に対応する列挙型を返す
	//default: throw std::invalid_argument("Invalid Cyrillic character"); // 無効な文字の場合は例外を投げる
	}
}
