#pragma once
#include <Siv3D.hpp>
#include "wordList.h"

Array<String> CyrillicAlphabetToWords(CyrillicAlphabetList cyrillicChar);
CyrillicAlphabetList GetRandomCyrillicAlphabet();

CyrillicAlphabetList CharToCyrillicAlphabet(const char32_t ch);
