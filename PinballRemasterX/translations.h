#pragma once

enum class Msg : int
{
	Min = 0,
	STRING101 = 0,
	STRING102,
	STRING103,
	STRING104,
	STRING105,
	STRING106,
	STRING107,
	STRING108,
	STRING109,
	STRING110,
	STRING111,
	STRING112,
	STRING113,
	STRING114,
	STRING115,
	STRING116,
	STRING117,
	STRING118,
	STRING119,
	STRING120,
	STRING121,
	STRING122,
	STRING123,
	STRING124,
	STRING125,
	STRING126,
	STRING127,
	STRING128,
	STRING129,
	STRING130,
	STRING131,
	STRING132,
	STRING133,
	STRING134,
	STRING135,
	STRING136,
	STRING139,
	STRING141,
	STRING142,
	STRING144,
	STRING145,
	STRING146,
	STRING147,
	STRING148,
	STRING149,
	STRING150,
	STRING151,
	STRING152,
	STRING153,
	STRING154,
	STRING155,
	STRING156,
	STRING157,
	STRING158,
	STRING159,
	STRING160,
	STRING161,
	STRING162,
	STRING163,
	STRING164,
	STRING165,
	STRING166,
	STRING167,
	STRING168,
	STRING169,
	STRING170,
	STRING171,
	STRING172,
	STRING173,
	STRING174,
	STRING175,
	STRING176,
	STRING177,
	STRING178,
	STRING179,
	STRING180,
	STRING181,
	STRING182,
	STRING183,
	STRING184,
	STRING185,
	STRING186,
	STRING187,
	STRING188,
	STRING189,
	STRING190,
	STRING191,
	STRING192,
	STRING193,
	STRING194,
	STRING195,
	STRING196,
	STRING197,
	STRING198,
	STRING199,
	STRING200,
	STRING201,
	STRING204,
	STRING205,
	STRING206,
	STRING207,
	STRING208,
	STRING209,
	STRING210,
	STRING211,
	STRING212,
	STRING213,
	STRING214,
	STRING215,
	STRING216,
	STRING217,
	STRING218,
	STRING219,
	STRING220,
	STRING221,
	STRING222,
	STRING223,
	STRING224,
	STRING225,
	STRING226,
	STRING227,
	STRING228,
	STRING229,
	STRING230,
	STRING231,
	STRING232,
	STRING233,
	STRING234,
	STRING235,
	STRING236,
	STRING237,
	STRING238,
	STRING239,
	STRING240,
	STRING241,
	STRING242,
	STRING243,
	STRING244,
	STRING245,
	STRING246,
	STRING247,
	STRING248,
	STRING249,
	STRING250,
	STRING251,
	STRING252,
	STRING253,
	STRING254,
	STRING255,
	STRING256,
	TextBoxUseBitmapFont,
	STRING270,
	STRING271,
	STRING272,
	STRING273,
	STRING274,
	STRING275,
	STRING276,
	STRING277,
	STRING279,
	STRING280,
	STRING281,
	STRING282,
	STRING283,
	STRING284,
	STRING285,
	STRING286,
	STRING287,
	STRING288,
	TextBoxColor,

	HIGHSCORES_Caption,
	HIGHSCORES_Ok,
	HIGHSCORES_Cancel,
	HIGHSCORES_Clear,
	HIGHSCORES_Name,
	HIGHSCORES_Score,
	HIGHSCORES_Rank,
	KEYMAPPER_Caption,
	KEYMAPPER_Ok,
	KEYMAPPER_Cancel,
	KEYMAPPER_FlipperL,
	KEYMAPPER_FlipperR,
	KEYMAPPER_Plunger,
	KEYMAPPER_BumpLeft,
	KEYMAPPER_BumpRight,
	KEYMAPPER_BumpBottom,
	KEYMAPPER_Default,
	KEYMAPPER_Help1,
	KEYMAPPER_Help2,
	KEYMAPPER_Groupbox1,
	KEYMAPPER_Groupbox2,
	Menu1_New_Game,
	Menu1_About_Pinball,
	Menu1_High_Scores,
	Menu1_Exit,
	Menu1_Sounds,
	Menu1_Music,
	Menu1_Help_Topics,
	Menu1_Launch_Ball,
	Menu1_Pause_Resume_Game,
	Menu1_Full_Screen,
	Menu1_Demo,
	Menu1_Select_Table,
	Menu1_Player_Controls,
	Menu1_1Player,
	Menu1_2Players,
	Menu1_3Players,
	Menu1_4Players,
	Menu1_WindowUniformScale,
	Menu1_Game,
	Menu1_Options,
	Menu1_Select_Players,
	Menu1_Table_Resolution,
	Menu1_Help,

	Menu1_UseMaxResolution_640x480,
	Menu1_UseMaxResolution_800x600,
	Menu1_UseMaxResolution_1024x768,

	Max,
};

enum class Lang : int
{
	Min = 0,
	Arabic = 0,
	Czech,
	Danish,
	German,
	Greek,
	English,
	Spanish,
	Finnish,
	French,
	Hebrew,
	Hungarian,
	Italian,
	Japanese,
	Korean,
	Norwegian,
	Dutch,
	Polish,
	BrazilianPortuguese,
	Portuguese,
	Russian,
	Swedish,
	Turkish,
	SimplifiedChinese,
	TraditionalChinese,
	Max
};

struct TextArray
{
	TextArray(const std::initializer_list<std::pair<Msg, std::initializer_list<std::pair<Lang, LPCSTR>>>>& iList)
	{
		for (const auto& msgPair : iList)
		{
			for (const auto& languagePair : msgPair.second)
			{
				assertm(!contains(msgPair.first, languagePair.first), "Key redefinition");
				Set(msgPair.first, languagePair.first, languagePair.second);
			}
		}

		for (auto i = Msg::Min; i < Msg::Max; i = static_cast<Msg>(static_cast<int>(i) + 1))
		{
			assertm(contains(i, Lang::English), "English text is mandatory for all keys");
		}
	}

	LPCSTR Get(Msg msgId, Lang langId) const
	{
		assertm(TextArray::contains(msgId), "Message Id out of bounds");
		assertm(TextArray::contains(langId), "Language Id out of bounds");
		return Store[static_cast<int>(msgId)][static_cast<int>(langId)];
	}

	bool contains(Msg msgId, Lang langId) const
	{
		return contains(msgId) && Get(msgId, langId) != nullptr;
	}

	static bool contains(Msg msgId)
	{
		return msgId >= Msg::Min && msgId < Msg::Max;
	}

	static bool contains(Lang langId)
	{
		return langId >= Lang::Min && langId < Lang::Max;
	}

private:
	LPCSTR Store[static_cast<int>(Msg::Max )][static_cast<int>(Lang::Max)]{ nullptr };

	void Set(Msg msgId, Lang langId, LPCSTR value)
	{
		assertm(TextArray::contains(msgId), "Message Id out of bounds");
		assertm(TextArray::contains(langId), "Language Id out of bounds");
		Store[static_cast<int>(msgId)][static_cast<int>(langId)] = value;
	}
};

struct LanguageInfo
{
	const Lang Language;
	const char* ShortName;
	const char* DisplayName;
};

class translations
{
public:
	static const LanguageInfo Languages[static_cast<int>(Lang::Max)];

	static const char* GetTranslation(Msg id);
	static void SetCurrentLanguage(const char* short_name);
	static const LanguageInfo* GetCurrentLanguage();
	static void GetGlyphRange(ImVector<ImWchar>* ranges);

private:
	static const TextArray Translations;
	static Lang CurrentLanguage;
};
