#pragma once
#include <Siv3D.hpp>
#include "FoxBoyImagePath.h"
#include "FoxBoySentences.h"

struct PageContents
{
	Array<String> sentences;
	String imagePath;
};


struct FoxBoyBook
{
	FoxBoyBook()
	{
		for (auto i : step(FOX_BOY_SEBTENCES.size()))
		{
			pages.push_back(PageContents{ FOX_BOY_SEBTENCES[i], FOX_BOY_IMAGE_PATH[i] });
		}
	}

	Array<PageContents> pages;
};
