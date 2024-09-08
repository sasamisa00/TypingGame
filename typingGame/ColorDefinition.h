#pragma once


// 色のテーマを管理する構造体
struct ColorTheme
{
	ColorF MainColor = Palette::Powderblue;  // メインカラー
	ColorF SubColor = Palette::Deepskyblue;  // サブカラー
	ColorF AccentColor = Palette::Gold;      // アクセントカラー
};


struct WordColorTheme
{
	const ColorF wordColor = Palette::Aliceblue;
	const ColorF correctWordColor = Palette::Dodgerblue;
	const ColorF inputtingWordColor = Palette::Black;
};

