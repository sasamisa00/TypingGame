﻿#pragma once
#include <Siv3D.hpp>


// 調整された長さに基づいてランダムなインデックスから単語を選択する関数
Array<String> SelectRandomWords(const Array<String>& words, int32 adjustedLength);

// 単語リストを処理するメイン関数
Array<String> ProcessWords(const Array<String>& words);


// 問題文のリスト
const Array<String> аWords =
{
	U"август",
	U"автобус",
	U"авторучка",
	U"алкоголь",
	U"английский язык",
	U"апрель",

};

const Array<String> бWords =
{
    U"бабушка",
    U"багаж",
    U"банк",
    U"бассейн",
    U"бегать",
    U"белый",
    U"библиотека",
    U"билет",
    U"близкий",
    U"близко",
	U"блюдо",
	U"бодрый",
	U"болезнь",
	U"болеть",
	U"больница",
	U"большой",
	U"брат",
	U"брать",
	U"брюки",
	U"бумага",
	U"бумажник",
	U"быстрый",

};



const Array<String> вWords =
{
   U"в",
   U"ванная",
   U"велосипед",
   U"весёлый",
   U"весна",
   U"весь",
   U"ветер",
   U"вечер",
   U"вешать",
   U"взрослый",
   U"вилка",
   U"вино",
   U"вкусно",
   U"вне",
   U"возвращаться",
   U"вопрос",
   U"ворота",
   U"воскресенье",
   U"восток",
   U"впереди",
   U"впитывать",
   U"врач",
   U"время",
   U"все",
   U"вставать",
   U"встать",
   U"встретить",
   U"вторая половина дня",
   U"вторник",
   U"вход",
   U"вчера",
   U"вчера вечером",
   U"вы",
   U"высота",
   U"выход",
   U"выходить"

};

const Array<String> гWords =
{
	U"газета",
	U"галстук",
	U"где",
	U"гитара",
	U"глаз",
	U"говорить",
	U"говядина",
	U"год",
	U"голова",
	U"головной убор",
	U"голос",
	U"гостиница",
	U"градус",
	U"грязный",
};

const Array<String> дWords =
{
	U"да",
	U"далёкий",
	U"дверь",
	U"двоюродный брат",
	U"девочка",
	U"дедушка",
	U"декабрь",
	U"делать",
	U"день",
	U"деньги",
	U"дети",
	U"дешёвый",
	U"длинный",
	U"дождь",
	U"дом",
	U"домашнее задание",
	U"дорога",
	U"дорогой",
	U"друг",
	U"душ",
	U"дядя",
};


const Array<String> еWords =
{
	U"ездить",
	U"есть",
	U"ещё",
};

// ёWords 配列の追加
const Array<String> ёWords =
{
	U"ёлка",
};

// жWords 配列の追加
const Array<String> жWords =
{
	U"жаркий",
	U"жёлтый",
	U"жена",
	U"женщина",
	U"живот",
	U"жить",
	U"журнал",
};



// зWords 配列の追加
const Array<String> зWords =
{
	U"за",
	U"завтра",
	U"завтрак",
	U"заграница",
	U"закрыть",
	U"занятый",
	U"запад",
	U"здание",
	U"здесь",
	U"зелёный",
	U"зелёный чай",
	U"зима",
	U"значение",
	U"зонт",
	U"зуб",
};


// иWords 配列の追加
const Array<String> иWords =
{
	U"играть",
	U"идёт дождь",
	U"известный",
	U"извините",
	U"иногда",
	U"иностранец",
	U"иностранный студент",
	U"интересный",
	U"июль",
	U"июнь",
};

// йWords 配列の追加
const Array<String> йWords =
{
	U"йогурт",
};

// кWords 配列の追加
const Array<String> кWords =
{
	U"каждая неделя",
	U"каждый год",
	U"каждый месяц",
	U"как",
	U"какой",
	U"каникулы",
	U"карандаш",
	U"карман",
	U"карри",
	U"карта",
	U"картина",
	U"катакана",
	U"кафе",
	U"квартира",
	U"кино",
	U"китайский иероглиф",
	U"класс",
	U"класть",
	U"ключ",
	U"книга",
	U"книжная полка",
	U"когда",
	U"комната",
	U"компьютер",
	U"конверт",
	U"конфета",
	U"копирование",
	U"копировать",
	U"коридор",
	U"коричневый",
	U"короткий",
	U"который",
	U"кофе",
	U"красивый",
	U"красный",
	U"кровать",
	U"кто",
	U"кто-то",
	U"курица",
	U"кухня",
};


// лWords 配列の追加
const Array<String> лWords =
{
	U"лёгкий",
	U"лекарство",
	U"лестница",
	U"летать",
	U"летние каникулы",
	U"лето",
	U"лимон",
	U"лифт",
	U"лицо",
	U"ложиться спать",
	U"ложка",
	U"любить",
};

// мWords 配列の追加
const Array<String> мWords =
{
	U"магазин",
	U"магнитола",
	U"магнитофон",
	U"май",
	U"маленький",
	U"мальчик",
	U"марка",
	U"март",
	U"масло",
	U"мать",
	U"машина",
	U"медленно",
	U"меня зовут ～",
	U"месяц",
	U"метро",
	U"миска",
	U"многие",
	U"много народу",
	U"молодой",
	U"молоко",
	U"муж",
	U"мужчина",
	U"музыка",
	U"мы",
	U"мыть",
	U"мясо",
};

// нWords 配列の追加
const Array<String> нWords =
{
	U"на",
	U"наверное",
	U"надевать",
	U"надеть",
	U"наклеивать",
	U"налево",
	U"напиток",
	U"направо",
	U"начинаться",
	U"невкусный",
	U"неделя",
	U"ненавидеть",
	U"нет",
	U"нижнее бельё",
	U"низкий",
	U"новый",
	U"нога",
	U"нож",
	U"нос",
	U"носить",
	U"носки",
	U"носовой платок",
	U"ночь",
	U"ноябрь",
	U"нравиться",
	U"ну",
};



// оWords 配列の追加
const Array<String> оWords =
{
	U"обед",
	U"обувь",
	U"овощной магазин",
	U"овощь",
	U"одалживать",
	U"одеваться",
	U"одежда",
	U"окно",
	U"октябрь",
	U"он / она",
	U"они",
	U"опускать",
	U"осень",
	U"острый",
	U"отвечать",
	U"отдавать",
	U"отец",
	U"открывать",
	U"открытка",
	U"очки",
};

// пWords 配列の追加
const Array<String> пWords =
{
	U"палочки",
	U"пальто",
	U"парк",
	U"пасмурная погода",
	U"пепельница",
	U"первая половина дня",
	U"перед",
	U"передавать",
	U"перекрёсток",
	U"песня",
	U"петь",
	U"печь",
	U"пиджак",
	U"писать",
	U"письменный стол",
	U"письмо",
	U"пить",
	U"пища",
	U"плавать",
	U"пластинка",
	U"плёнка",
	U"плохо",
	U"плохой",
	U"поворачивать",
	U"погода",
	U"под",
	U"подсоединять",
	U"подстригать",
	U"поезд",
	U"поездка",
	U"пожалуйста",
	U"позавчера",
	U"позапрошлый год",
	U"поздний",
	U"пока",
	U"покрываться облаками",
	U"покупать",
	U"покупка",
	U"полицейская будка",
	U"полицейский",
	U"понедельник",
	U"послезавтра",
	U"посольство",
	U"почта",
	U"почтовый ящик",
	U"предложение",
	U"прибавлять",
	U"приезжать",
	U"принимать душ/ванну",
	U"прихожая",
	U"проверочная работа",
	U"прогулка",
	U"продавать",
	U"продольный",
	U"простуда",
	U"прохладный",
	U"прошлая неделя",
	U"прошлый год",
	U"прошлый месяц",
	U"проясняться",
	U"пруд",
	U"прямой",
	U"путешествовать",
	U"пятница",
};

// рWords 配列の追加
const Array<String> рWords =
{
	U"работа",
	U"работать",
	U"радио",
	U"разговор",
	U"рассказывать",
	U"река",
	U"ресторан",
	U"ровно",
	U"родители",
	U"рот",
	U"рубашка",
	U"рука",
	U"русский язык",
	U"ручка",
	U"рыба",
	U"рядом",
};

// сWords 配列の追加
const Array<String> сWords =
{
	U"сад",
	U"садиться",
	U"сам",
	U"самолёт",
	U"сахар",
	U"светлый",
	U"свинина",
	U"свитер",
	U"север",
	U"сегодня",
	U"семья",
	U"сентябрь",
	U"сестра",
	U"сжимать",
	U"сигарета",
	U"сильный",
	U"синий",
	U"сколько",
	U"скучный",
	U"слабый",
	U"сладкий",
	U"сладость",
	U"следующая неделя",
	U"следующий год",
	U"следующий месяц",
	U"словарь",
	U"слово",
	U"снег",
	U"снимать",
	U"соевый соус",
	U"соль",
	U"сочинение",
	U"спорт",
	U"спрашивать",
	U"сразу",
	U"среда",
	U"стакан",
	U"станция",
	U"старшая сестра",
	U"старший брат",
	U"старый",
	U"статься",
	U"стирать",
	U"стирка",
	U"стол",
	U"столовая",
	U"страна",
	U"студент",
	U"стул",
	U"суббота",
	U"сумка",
	U"супруги",
	U"сыр",
};


// тWords 配列の追加
const Array<String> тWords =
{
	U"так",
	U"такой",
	U"такси",
	U"там",
	U"тапочки",
	U"тарелка",
	U"телевизор",
	U"телефон",
	U"тело",
	U"тёмный",
	U"тёплый",
	U"тетрадь",
	U"тётя",
	U"тихий",
	U"толкать",
	U"толстый",
	U"том",
	U"тонкий",
	U"тот",
	U"трудный",
	U"туалет",
	U"ты",
	U"тяжёлый",
};

// уWords 配列の追加
const Array<String> уWords =
{
	U"у",
	U"убирать",
	U"уборка",
	U"удобный",
	U"уже",
	U"ужин",
	U"узкий",
	U"умирать",
	U"универмаг",
	U"университет",
	U"упражнение",
	U"упражняться",
	U"урок",
	U"утро",
	U"ухо",
	U"учёба",
	U"ученик",
	U"учитель",
	U"учить",
};

// фWords 配列の追加
const Array<String> фWords =
{
	U"февраль",
	U"фирма",
	U"фотоаппарат",
	U"фотография",
	U"французский язык",
	U"фрукт",
};


// хWords 配列の追加
const Array<String> хWords =
{
	U"хирагана",
	U"хлеб",
	U"ходить",
	U"холодильник",
	U"холодный",
	U"хороший",
	U"хорошо",
	U"хотеть",
};


// цWords 配列の追加
const Array<String> цWords =
{
	U"цвет",
};


// чWords 配列の追加
const Array<String> чWords =
{
	U"чай",
	U"час",
	U"часто",
	U"часы",
	U"чашка",
	U"человек",
	U"через два года",
	U"чёрный",
	U"четверг",
	U"читать",
};

// шWords 配列の追加
const Array<String> шWords =
{
	U"широкий",
	U"школа",
};


// щWords 配列の追加
const Array<String> щWords =
{
	U"щека",
};


// эWords 配列の追加
const Array<String> эWords =
{
	U"экзамен",
	U"экземпляр",
	U"эта неделя",
	U"этаж",
	U"этот",
	U"этот год",
	U"этот месяц",
};




// юWords 配列の追加
const Array<String> юWords =
{
	U"юбка",
	U"юг",
};




// яWords 配列の追加
const Array<String> яWords =
{
	U"я",
	U"язык",
	U"яйцо",
	U"январь",
	U"японский язык",
	U"ясная погода",
};

// ロシア語アルファベット
enum class CyrillicAlphabetList
{
	а, б, в, г, д, е, ё, ж, з, и, й, к, л, м, н, о, п, р, с, т, у, ф, х, ц, ч, ш, щ, ъ, ы, ь, э, ю, я
};
















































































































