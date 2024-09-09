#pragma once
#include <Siv3D.hpp>
#include "AlphabetFunction.h"
#include "ColorDefinition.h"

class WordGame
{
public:
	WordGame(const WordColorTheme& wordColorTheme = WordColorTheme(), CyrillicAlphabetList cyrillicChar = CyrillicAlphabetList::а)
		: theme(wordColorTheme), words(CyrillicAlphabetToWords(cyrillicChar))
	{
		SelectRandomTargetWord();
	}

	~WordGame() = default;

	void Update()
	{
		HandleTextInput();
		HandleIncorrectInput();
		CheckAndAdvanceToNextWord();
		HandleAlphabetChange();
	}

	void Draw() const
	{
		RenderTargetWord();
		RenderInputWord();
		RenderLastInput();
		RenderScore(); // スコアを描画
	}

private:
	static constexpr Vec2 TargetWordPosition{ 40, 80 };
	static constexpr Vec2 InputWordPosition{ 40, 80 };
	static constexpr Vec2 LastInputPosition{ 40, 240 };
	static constexpr Vec2 AlphabetChangeButtonPosition{ 600, 40 };
	static constexpr Vec2 ScorePosition{ 600, 100 }; // スコアの表示位置をボタンと重ならないように調整
	static constexpr int32 FontSize = 40; // 文字サイズを40に統一
	static constexpr int32 scoreFontSize = FontSize / 2;
	static constexpr int32 EncouragementThreshold = 15; // エールを送るスコアの閾値


	void HandleTextInput()
	{
		const String previousInput = input;
		TextInput::UpdateText(input, TextInputMode::DenyControl);
		if (HasInputChanged(previousInput, input))
		{
			StoreLastInput();
		}

		// ctrl key が押された場合に、lastInput の文字によってwordを変更する
		if (KeyControl.down())
		{
			SetWordsStartingWithLastInput();
		}
	}

	bool HasInputChanged(const String& previousInput, const String& currentInput) const
	{
		return previousInput != currentInput;
	}

	void HandleIncorrectInput()
	{
		if (not IsInputIncorrect()) return;
		RemoveLastInputCharacter();
	}

	bool IsInputIncorrect() const
	{
		return !target.starts_with(input);
	}

	void CheckAndAdvanceToNextWord()
	{
		if (input != target) return;
		UpdateScore(); // スコアを更新
		AdvanceToNextTargetWord();
	}

	void HandleAlphabetChange()
	{
		if (not IsAlphabetChangeButtonPressed()) return;
		SetWordsStartingWithLastInput();
	}

	bool IsAlphabetChangeButtonPressed() const
	{
		return SimpleGUI::Button(U"文字変更", AlphabetChangeButtonPosition);
	}

	void UpdateWordsWithRandomAlphabet()
	{
		words = SelectAdjustedRandomWords(CyrillicAlphabetToWords(GetRandomCyrillicAlphabet()));
		AdvanceToNextTargetWord();
	}

	void SetWordsStartingWithLastInput()
	{
		if (lastInput.isEmpty()) return;

		CyrillicAlphabetList alphabet = CharToCyrillicAlphabet(lastInput[0]);
		words = SelectAdjustedRandomWords(CyrillicAlphabetToWords(alphabet));
		AdvanceToNextTargetWord();
	}

	void RenderTargetWord() const
	{
		font(target).draw(TargetWordPosition, theme.wordColor);
	}

	void RenderInputWord() const
	{
		font(input).draw(InputWordPosition, theme.correctWordColor);
	}

	void RenderLastInput() const
	{
		if (lastInput.isEmpty()) return;
		font(U"| {}"_fmt(lastInput)).draw(LastInputPosition, theme.inputtingWordColor);
	}

	void RenderScore() const
	{
		ColorF scoreColor = GetScoreColor();
		font(U"文字数: {}"_fmt(score)).draw(scoreFontSize, ScorePosition, scoreColor); // スコアの文字色を動的に変更
	}

	void StoreLastInput()
	{
		lastInput = s3d::String(1, input.back());
	}

	void RemoveLastInputCharacter()
	{
		input.pop_back();
	}

	void AdvanceToNextTargetWord()
	{
		SelectRandomTargetWord();
		input.clear();
		lastInput.clear();
	}

	void SelectRandomTargetWord()
	{
		target = words.choice();
	}

	void UpdateScore()
	{
		score += static_cast<int32>(input.length());
		SendEncouragementIfNeeded(); // スコアが30上がるたびにエールを送る
	}

	void SendEncouragementIfNeeded()
	{
		if (score - lastEncouragementScore >= EncouragementThreshold)
		{
			lastEncouragementScore = score;
			ShowEncouragementToast();
		}
	}

	void ShowEncouragementToast() const
	{
		ToastNotificationItem item{ .title = U"エール", .message = U"素晴らしい！頑張ってください！" };
		Platform::Windows::ToastNotification::Show(item);
	}

	ColorF GetScoreColor() const
	{
		// スコアに応じて色を変える。スコアが高いほどオレンジにする。
		double redIntensity = Min(1.0, 0.1 + score * 0.01);
		double greenIntensity = Min(0.5, 0.05 + score * 0.005);
		return ColorF(redIntensity, greenIntensity, 0.0);
	}

	const WordColorTheme& theme;
	Array<String> words;
	String target;
	String input;
	String lastInput;
	int32 score = 0; // スコアを保持する変数
	int32 lastEncouragementScore = 0; // 前回の通知時のスコア

	const Font font{ FontMethod::MSDF, FontSize, Typeface::Bold };
};
