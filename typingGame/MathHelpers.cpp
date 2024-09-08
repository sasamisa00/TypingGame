#include "MathHelpers.h"

int GetAdjustedLength(int length)
{
	// length が10以下であればそのまま返す
	if (length <= 10)
	{
		return length;
	}

	// length が10より大きい場合、商が10より小さくなる最小のdividerを見つける
	for (int divider = 1; divider <= length; ++divider)
	{
		int quotient = length / divider;
		if (quotient < 10)
		{
			return quotient + 1;
		}
	}

	// ここに到達することはないはずだが、念のため
	return -1;
}
