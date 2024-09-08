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
