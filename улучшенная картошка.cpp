#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <String.h>
#include <ctime>
#include <fstream>
#include<locale>
using namespace std;
string imya; //ввод имени клиента на английском
int itogtsena; //для суммы чека
int vo, vn, dn, vnapi; //для свитч (не кейсов) во время заказа
int vc; //для свитч (не кейсов) вывода состава или нет
short ItogOsnovaCost, ItogNapolnCost, ItogNapolnCost2, ItogNapitokCost; //для цены выбранного
short ItogOsnovaVes, ItogNapolnVes, ItogNapolnVes2, ItogNapitokVes;//для веса выбранного
string nameosnovka, namenapoln, namenapoln2, namenapitok; //для названий в кейсах выбранного
string sostosnovka, sostnapoln, sostnapoln2, sostnapitok; //для состава выбранного в кейсах

class Product
{
public:  
	double weight;
	int price;
	vector<string> recipe = {};

	Product(double w, int p, string r)
	{
		this->weight = w;
		this->price = p;
		this->recipe.push_back(r);
	}
};

struct Osnova
{
	short ChedderBeacon;
	short SlivMaslo;
	short Sir;
	short UkropRastMaslo;
	short RastMaslo;
};
Osnova ViborOsnovy;
Product ChedderBeacon(275, 130, "Бекон");
Product SlivMaslo(250, 115, "Сливочное масло");
Product Sir( 260, 120, "Сыр");
Product UkropRastMaslo( 260, 105, "Укроп с растительным маслом");
Product RastMaslo(250, 105, "Растительное масло");
Product PremSirniy(470, 330, "Премиум картофель с сыром");
Product PremKuritsa(435, 350, "Премиум картофель с запечённой курицей");
Product PremRiba(420, 350, "Премиум картофель с красной рыбкой");
Product KlubBeacon(140, 115, "Клубенёк с беконом");
Product KlubRiba(155, 150, "Клубенёк с красной рыбкой");
Product KlubJul(155, 99, "Клубенёк по-французски");
Product KlubBakl(165, 99, "Клубенёк с баклажанами и курицей");

struct Napolnitel
{
	short KrabMayonez;
	short Kuriniy;
	short KrasnRiba;
	short Zakusochniy;
	short Sirniy;
	short BrinzUkrop;
	short SosisGorch;
	short SirVerchina;
	short MyasAssorti;
	short LososSir;
	short KrabIkra;
};
Napolnitel ViborNapolnitelya;
Product KrabMayonez(61,59,"KrabovoeMyasoSMayonezom");
Product Kuriniy(61, 59, "Kuriniy");
Product KrasnRiba(61, 125, "KrasnRiba");
Product Zakusochniy(62, 69, "Griby");
Product Sirniy(56, 69, "Sirniy");
Product BrinzUkrop(61, 69, "1");
Product SosisGorch(61, 59, "1");
Product SirVetchina(61, 69, "");
Product MyasAssorti(61, 75, "");
Product LososSir(56, 75, "");
Product KrabIkra(56, 69, "");

struct Napitok
{
	short YaMors;
	short BonAqua;
	short FuzeTea;
	short Pulpy;
	short Kvas;
};
Napitok ViborNapitka;
Product YaMors(500, 99, "Yagodniy mors");
Product BonAqua(500, 85, "Voda BonAqua");
Product FuzeTea(500, 105, "FuzeTea");
Product Pulpy(450, 135, "Pulpy");
Product Kvas(450, 110, "kvas");



int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Добро пожаловать в кафе Крошка Картошка!" << endl << "Вас обслуживает Olga Almaz. Как ваше имя?" << endl;
	cin >> imya;
	cout << imya << ", давайте сделаем заказ." << endl << "Для начала нам нужно выбрать основу для Крошки Картошки. Какая она будет? Введите цифру: " << endl;
	cout << "1. Чеддер Бекон." << " Вес: " << ChedderBeacon.weight << " гр. Цена: " << ChedderBeacon.price << " руб." << endl;
	cout << "2. Сливочное масло." << " Вес: " << SlivMaslo.weight <<  " гр. Цена: " << SlivMaslo.price << " руб." << endl;
	cout << "3. Сыр." << " Вес: " << Sir.weight << " гр. Цена: " << Sir.price << " руб." << endl;
	cout << "4. Укроп с растительным маслом." << " Вес:" << UkropRastMaslo.weight << " гр. Цена: " << UkropRastMaslo.price << endl;
	cout << "5. Растительное масло." << " Вес: " << RastMaslo.weight << " гр. Цена: " << RastMaslo.price << endl;
	cout << "6. Премиум картофель с сыром." << " Вес: " << PremSirniy.weight << " гр. Цена: " << PremSirniy.price << endl;
	cout << "7. Премиум картофель с запечённой курицей." << "Вес: " << PremKuritsa.weight << " гр. Цена: " << PremKuritsa.price << endl;
	cout << "8. Премиум картофель с красной рыбкой." << " Вес: " << PremRiba.weight << " гр. Цена: " << PremRiba.price << endl;
	cout << "9. Клубенёк с беконом." << " Вес: " << KlubBeacon.weight << " гр. Цена: " << KlubBeacon.price << endl;
	cout << "10. Клубенёк с красной рыбкой." << " Вес: " << KlubRiba.weight << " гр. Цена: " << KlubRiba.price << endl;
	cout << "11. Клубенёк по-французски." << " Вес: " << KlubJul.weight << " гр. Цена: " << KlubJul.price << endl;
	cout << "12. Клубенёк с баклажанами и курицей." << " Вес: " << KlubBakl.weight << " гр. Цена: " << KlubBakl.price << endl;

	cin >> vo;
	switch (vo)
	{
	case 1:
		nameosnovka = "с основой: Чеддер Бекон";
		ItogOsnovaCost = ChedderBeacon.price;
		ItogOsnovaVes = ChedderBeacon.weight;
		sostosnovka = "Большой печеный картофель, сыр Чеддер с заменителем молочного жира, бекон, сосиски, лук жареный, майонез, бульон, бекон, соль";
		break;
	case 2:
		nameosnovka = "с основой: Сливочное масло";
		ItogOsnovaCost = SlivMaslo.price;
		ItogOsnovaVes = SlivMaslo.weight;
		sostosnovka = "Большой печеный картофель, сливочное масло";
		break;
	case 3:
		nameosnovka = "с основой: Сыр";
		ItogOsnovaCost = Sir.price;
		ItogOsnovaVes = Sir.weight;
		sostosnovka = "Большой печеный картофель, сыр";
		break;
	case 4:
		nameosnovka = "с основой: Укроп с растительным маслом";
		ItogOsnovaCost = UkropRastMaslo.price;
		ItogOsnovaVes = UkropRastMaslo.weight;
		sostosnovka = "Большой печеный картофель, укроп, растительное масло!!!!";
		break;
	case 5:
		nameosnovka = "с основой: Растительное масло";
		ItogOsnovaCost = RastMaslo.price;
		ItogOsnovaVes = RastMaslo.weight;
		sostosnovka = "Большой печеный картофель, растительное масло";
		break;
	case 6:
		nameosnovka = "с основой: Премиум с сыром";
		ItogOsnovaCost = PremSirniy.price;
		ItogOsnovaVes = PremSirniy.weight;
		sostosnovka = "Картофель печеный, масло растительное с зеленью, салат Сырный, наполнитель Брынзовый с укропом, сыр тертый, салатный микс из айсберга и романо, помидоры в масле с зеленью, гренки, соль";
		break;
	case 7:
		nameosnovka = "с основой: Премиум с запечённой курицей";
		ItogOsnovaCost = PremKuritsa.price;
		ItogOsnovaVes = PremKuritsa.weight;
		sostosnovka = "Картофель печеный, запеченная курица, масло сливочное, укроп, соль, салатный микс (айсберг, романо), помидоры свежие, огурцы свежие, петрушка, гренки.";
		break;
	case 8:
		nameosnovka = "с основой: Премиум с красной рыбкой";
		ItogOsnovaCost = PremRiba.price;
		ItogOsnovaVes = PremRiba.weight;
		sostosnovka = "Картофель печеный, филе семги, филе кеты, маслины, салатный микс (айсберг, романо), маринованные огурцы, гренки, лимон и соус свит-релиш.";
		break;
	case 9:
		nameosnovka = "с основой: Клубенёк с беконом";
		ItogOsnovaCost = KlubBeacon.price;
		ItogOsnovaVes = KlubBeacon.weight;
		namenapoln = "без наполнителя";
		namenapoln2 = "без дополнительного наполнителя";
		sostnapoln = "отсутствует";
		sostnapoln2 = "отсутствует";
		sostosnovka = "Картофель печеный среднего размера, бекон, лук фри";
		goto klub;
		break;
	case 10:
		nameosnovka = "с основой: Клубенёк с красной рыбкой";
		ItogOsnovaCost = KlubRiba.price;
		ItogOsnovaVes = KlubRiba.weight;
		namenapoln = "без наполнителя";
		namenapoln2 = "без дополнительного наполнителя!!!!";
		sostnapoln = "отсутствует";
		sostnapoln2 = "отсутствует";
		sostosnovka = "Печёный картофель среднего размера, филе семги, филе кеты, масло растительное, соль, петрушка";
		goto klub;
		break;
	case 11:
		nameosnovka = "с основой: Клубенёк по-французски";
		ItogOsnovaCost = KlubJul.price;
		ItogOsnovaVes = KlubJul.weight;
		namenapoln = "без наполнителя";
		namenapoln2 = "без дополнительного наполнителя";
		sostnapoln = "отсутствует";
		sostnapoln2 = "отсутствует";
		sostosnovka = "Картофель печеный среднего размера, жюльен с курицей и грибами";
		goto klub;
		break;
	case 12:
		nameosnovka = "с основой: Клубенёк с баклажанами и курицей";
		ItogOsnovaCost = KlubBakl.price;
		ItogOsnovaVes = KlubBakl.weight;
		namenapoln = "без наполнителя";
		namenapoln2 = "без дополнительного наполнителя";
		sostnapoln = "отсутствует";
		sostnapoln2 = "отсутствует";
		sostosnovka = "Картофель свежий мытый, салат с курицей и баклажанами, соль поваренная пищевая";
		goto klub;
		break;
	};
	cout << "Вы выбрали Крошку картошку " << nameosnovka << endl;

	cout << imya << ", давайте выбирать дальше. Сейчас необходимо выбрать наполнитель для Крошки Картошки. Выберите цифру:" << endl;
	cout << "0. Не класть наполнитель." << endl;
	cout << "1. Крабовое мясо с майонезом." << " Вес: " << KrabMayonez.weight << " гр. Цена: " << KrabMayonez.price << " руб." << endl;
	cout << "2. Куриный." << " Вес: " << Kuriniy.weight << " гр. Цена: " << Kuriniy.price << " руб." << endl;
	cout << "3. Красная рыбка." << " Вес: " << KrasnRiba.weight << " гр. Цена: " << KrasnRiba.price << " руб." << endl;
	cout << "4. Закусочный (грибы)." << " Вес: " << Zakusochniy.weight << " гр. Цена: " << Zakusochniy.price << " руб." << endl;
	cout << "5. Сырный." << " Вес: " << Sirniy.weight << " гр. Цена: " << Sirniy.price << " руб." << endl;
	cin >> vn;
	switch (vn)
	{
	case 0:
		namenapoln = "без наполнителя";
		ItogNapolnCost = 0;
		ItogNapolnVes = 0;
		sostnapoln = "отсутствует";
		break;
	case 1:
		namenapoln = "с наполнителем: Крабовое мясо с майонезом";
		ItogNapolnCost = KrabMayonez.price;
		ItogNapolnVes = KrabMayonez.weight;
		sostnapoln = "Имитация из сурими, майонез";
		break;
	case 2:
		namenapoln = "с наполнителем: Куриный";
		ItogNapolnCost = Kuriniy.price;
		ItogNapolnVes = Kuriniy.weight;
		sostnapoln = "Филе куриное, огурцы маринованные, майонез";
		break;
	case 3:
		namenapoln = "с наполнителем: Красная рыбка";
		ItogNapolnCost = KrasnRiba.price;
		ItogNapolnVes = KrasnRiba.weight;
		sostnapoln = "Филе семги, филе кеты, соль, масло растительное";
		break;
	case 4:
		namenapoln = "с наполнителем: Закусочный (грибы)";
		ItogNapolnCost = Zakusochniy.price;
		ItogNapolnVes = Zakusochniy.weight;
		sostnapoln = "Опята, огурцы маринованные, чеснок";
		break;
	case 5:
		namenapoln = "с наполнителем: Сырный";
		ItogNapolnCost = Sirniy.price;
		ItogNapolnVes = Sirniy.weight;
		sostnapoln = "Продукт сыросодержащий Чеддер, чеснок сушеный, паприка, майонез, масло растительное";
		break;
	};

	cout << "Вы выбрали Крошку Картошку " << namenapoln << endl << ". Как насчёт второго наполнителя? Выберите цифру:" << endl;
	cout << "0. Не класть наполнитель." << endl;
	cout << "1. Крабовое мясо с майонезом." << " Вес: " << KrabMayonez.weight << " гр. Цена: " << KrabMayonez.price << " руб." << endl;
	cout << "2. Куриный." << " Вес: " << Kuriniy.weight << " гр. Цена: " << Kuriniy.price << " руб." << endl;
	cout << "3. Красная рыбка." << " Вес: " << KrasnRiba.weight << " гр. Цена: " << KrasnRiba.price << " руб." << endl;
	cout << "4. Закусочный (грибы)." << " Вес: " << Zakusochniy.weight << " гр. Цена: " << Zakusochniy.price << " руб." << endl;
	cout << "5. Сырный." << " Вес: " << Sirniy.weight << " гр. Цена: " << Sirniy.price << " руб." << endl;
	cin >> dn;
	switch (dn)
	{
	case 0:
		namenapoln2 = "без дополнительного наполнителя";
		ItogNapolnCost2 = 0;
		ItogNapolnVes2 = 0;
		sostnapoln2 = "отсутствует";
		break;
	case 1:
		namenapoln2 = "с наполнителем: Крабовое мясо с майонезом";
		ItogNapolnCost2 = KrabMayonez.price;
		ItogNapolnVes2 = KrabMayonez.weight;
		sostnapoln2 = "Имитация из сурими, майонез.";
		break;
	case 2:
		namenapoln2 = "с наполнителем: Куриный";
		ItogNapolnCost2 = Kuriniy.price;
		ItogNapolnVes2 = Kuriniy.weight;
		sostnapoln2 = "Филе куриное, огурцы маринованные, майонез.";
		break;
	case 3:
		namenapoln2 = "с наполнителем: Красная рыбка";
		ItogNapolnCost2 = KrasnRiba.price;
		ItogNapolnVes2 = KrasnRiba.weight;
		sostnapoln2 = "Филе семги, филе кеты, соль, масло растительное.";
		break;
	case 4:
		namenapoln2 = "с наполнителем: Закусочный (грибы)";
		ItogNapolnCost2 = Zakusochniy.price;
		ItogNapolnVes2 = Zakusochniy.weight;
		sostnapoln2 = "Опята, огурцы маринованные, чеснок.";
		break;
	case 5:
		namenapoln2 = "с наполнителем: Сырный";
		ItogNapolnCost2 = Sirniy.price;
		ItogNapolnVes2 = Sirniy.weight;
		sostnapoln2 = "Продукт сыросодержащий Чеддер, чеснок сушеный, паприка, майонез, масло растительное.";
		break;
	};
	cout << "Вы выбрали Крошку Картошку " << namenapoln2 << endl;

	klub:

	cout << "Добавить напиток к заказу? Выберите цифру: " << endl;
	cout << "0. Не добавлять напиток." << endl;
	cout << "1. Ягодный морс. Объём: " << YaMors.weight << " мл. Цена: " << YaMors.price << " руб." << endl;
	cout << "2. Вода BonAqua. Объём: " << BonAqua.weight << " мл. Цена: " << BonAqua.price << " руб." << endl;
	cout << "3. Холодный чай FuzeTea. Объём: " << FuzeTea.weight << " мл. Цена: " << FuzeTea.price << " руб." << endl;
	cout << "4. Сок Pulpy. Объём: " << Pulpy.weight << " мл. Цена: " << Pulpy.price << " руб." << endl;
	cout << "5. Квас. Объём: " << Kvas.weight << " мл. Цена: " << Kvas.price << " руб." << endl;
	cin >> vnapi;
	switch (vnapi)
	{
	case 0:
		namenapitok = "без напитка";
		ItogNapitokCost = 0;
		ItogNapitokVes = 0;
		sostnapitok = "отсутствует.";
		break;
	case 1:
		namenapitok = "с напитком: Ягодный морс";
		ItogNapitokCost = YaMors.price;
		ItogNapitokVes = YaMors.weight;
		sostnapitok = "Вода питьевая, сахар, свежемороженые ягоды (смородина черная, вишня без косточки, клюква, брусника), лимонная кислота.";
		break;
	case 2:
		namenapitok = "с напитком: Вода BonAqua";
		ItogNapitokCost = BonAqua.price;
		ItogNapitokVes = BonAqua.weight;
		sostnapitok = "Вода питьевая.";
		break;
	case 3:
		namenapitok = "с напитком: Холодный чай FuzeTea";
		ItogNapitokCost = FuzeTea.price;
		ItogNapitokVes = FuzeTea.weight;
		sostnapitok = "Состав меняется в зависимости от выбора вкуса напитка, спрашивайте у кассира.";
		break;
	case 4:
		namenapitok = "с напитком: Сок Pulpy";
		ItogNapitokCost = Pulpy.price;
		ItogNapitokVes = Pulpy.weight;
		sostnapitok = "апельсиновый сок, мякоть апельсина, сахар, регулятор кислотности-лимонная кислота; стабилизаторы: пектин, гуммиарабик, Е445; антиокислитель - аскорбиновая кислота, натуральный краситель - В-каротин; натуральные ароматизаторы, вода.";
		break;
	case 5:
		namenapitok = "с напитком: Квас";
		ItogNapitokCost = Kvas.price;
		ItogNapitokVes = Kvas.weight;
		sostnapitok = "Бутилированный натуральный квас двойного брожения";
		break;
	};
	cout << "Вы выбрали Крошку Картошку " << namenapitok << endl;

	cout << "Ваш заказ: Крошка картошка " << nameosnovka << ", " << namenapoln << ", " << namenapoln2 << ", " << namenapitok << endl;
	cout << "Стоимость основы: " << ItogOsnovaCost << " руб." << endl;
	cout << "Стоимость наполнителя: " << ItogNapolnCost << " руб." << endl;
	cout << "Стоимость дополнительного наполнителя: " << ItogNapolnCost2 << " руб." << endl;
	cout << "Стоимость напитка: " << ItogNapitokCost << " руб." << endl;
	itogtsena = ItogNapolnCost + ItogOsnovaCost + ItogNapolnCost2 + ItogNapitokCost;
	cout << "Итого к оплате: " << itogtsena << endl;

	cout << "Распечатать состав заказанной Крошки Картошки? Выберите цифру:" << endl;
	cout << "0 - нет" << endl << "1 - да" << endl;
	cin >> vc;
	switch (vc)
	{
	case 0:
		break;
	case 1:
		cout << "Состав вашего заказа:" << endl << endl;
		cout << "Основа: " << sostosnovka << endl << "Наполнитель: " << sostnapoln << endl << "Дополнительный наполнитель: " << sostnapoln2 << endl;
		cout << "Напиток: " << sostnapitok << endl;
		break;
	};
	cout << "Спасибо за заказ! Приятного аппетита! Приходите к нам снова!" << endl << "Дата и время оформления заказа: " << endl;
	{
	time_t t;
	t = time(0);
	cout << puts(ctime(&t)) << endl;
	}
}