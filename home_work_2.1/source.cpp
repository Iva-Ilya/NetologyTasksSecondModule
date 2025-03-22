#include <iostream>

// Для Задачи 1 - Месяцы
enum class Months
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

// Для задачи 2 - Счет. Обьявим структуру requisites и функцию изменения баланса
struct requisites
{
	int number;
	std::string name;
	float balance;
};

void balance_changed(requisites &client, float balance_new)
{
	client.balance = balance_new;
}

// Для задачи 3 - Вывод структуры. Обьявим структуру full_adress и функцию вывода в консоль экзэмпляров этой функции
struct full_adress
{
	std::string city;
	std::string street;
	int  house_number;
	int appart_number;
	int index;
};

void print_full_adress(full_adress& any_adress)
{
	std::cout << "Город: " << any_adress.city << std::endl;
	std::cout << "Улица: " << any_adress.street << std::endl;
	std::cout << "Номер дома: " << any_adress.house_number << std::endl;
	std::cout << "Номер квартиры: " << any_adress.appart_number << std::endl;
	std::cout << "Индекс: " << any_adress.index << std::endl;
}


enum Colors					// Обьявление констант. Работает только с int или '' единичными символами
{
	green,
	red = -10,
	blue
};

enum seasons
{
	spring,
	summer,
	autumn,
	winter
};

enum class Seasons {
	Spring = 22,
	Summer,
	Autumn,
	Winter
};

struct Person {
	std::string name;
	std::string surname;
	int age;
};

// Так нельзя делать, т.к будет создаваться копия существующей структуры
/*void foo(Person a)
{
	a.age = 30;
}*/

// Используем ссылку
void foo(Person &a)
{
	a.age = 30;
}

//const int green = 167;		// Обьявление констант (не отличается от enum)
//const int red = 167;

// Функция, возвращающая структуру
Person fun()
{
	Person a;
	a.age = 90;
	return a;
}

int main()
{
	setlocale(0, "");
	system("chcp 1251");


	/*
	//
	//int a = 3;
	//a = 2;
	//a = 1;
	//std::cout << a << std::endl;

	int color1 = 167;		// Зеленый
	int color2 = 326;		// Красный
	if (color1 == 167)
	{
		std::cout << "Зеленая линия!" << std::endl;
	}

	// Можно вывести константу enum на экран
	std::cout << green << std::endl;		// Выведется 0
	std::cout << red << std::endl;			// Выведется -10
	std::cout << blue << std::endl;			// Выведется -9

	// Можно значение константы enum положить в переменную int
	int a = green;
	std::cout << a << std::endl;

	Colors::red; // Обращаемся к типу enum - смотрим какие значения он хранит в себе

	// Можем объявить переменную типа Colors и присвоить ей значение green (объявили до main())
	Colors x = green;
	std::cout << x << std::endl;

	// Пример с сезонами года. Создали переменную season типа enum из существующего набора enum seasons, присвоили значение spring
	// seasons season = spring;			// Так можно, но не сразу понятно откуда достали spring
	seasons season = seasons::spring;	// Так лучше, понятней

	// Использование более защищенного типа перечислений - enum class. Ограничиваем работу, но и ограничиваем число потенциальных ошибок
	// Первые два варианта уже не будут работать, т.к использовали тип enum class Seasons
	//int v = Seasons::Spring;					//Не работает
	//int m = Spring;								// Не работает
	//Seasons c = (Seasons)0;						// Работает // Приведение к типу данных Seasons
	//Seasons d = static_cast < Seasons >(0);	// Работает	// Приведение к типу данных Seasons
	int e = static_cast<int>(Seasons::Spring);
	std::cout << e << std::endl;

	// Перейдем к понятию структура (почти такой же обект как и класс, но 1 отличие - public)
// Структура - это пользовательский тип данных, объединяющий разнородные данные
// Данные, которые содержит в себе структура, называются полями. Каждое поле — это как переменная, только существующая в рамках структуры.
// У структуры есть определение — в нём описывается, из каких полей состоит структура — и экземпляры, построенные с помощью определения

//Пример обявления структуры. Обявляется до main()
//struct Person {
//	string name;
//}

// Иницифализируем поля структуры для разных экземпляров структуры
	Person a1 = { "Иван", "Иванов", 20 };
	Person a2 = { "Иван", "Иванов" };
	Person a3 = { "Иван" };

	// Сама структура — это новый, пользовательский (то есть созданный пользователем языка) тип данных
	// Переменные, которые имеют тип данных созданной вами структуры, называются экземплярами этой структуры.

	std::cout << a1.name << ' ' << a1.surname << ' ' << a1.age << std::endl; // Выводим каждое поле структуры отдельно
	std::cin >> a1.age;
	std::cout << a1.name << ' ' << a1.surname << ' ' << a1.age << std::endl;
	// Иницифализируем поля структуры для 1 экземпляра структуры а1
	a1.name = "Алексей";
	a1.surname = "Петров";
	a1.age = 30;

	// Работа с указателями
	Person* pa = &a1;
	std::cout << (*pa).age << std::endl;

	// Или использовать не указатель, а ->, чтобы вывести в консоль
	std::cout << pa->age << std::endl;

	// Структуры и функции
	std::cout << a1.age << std::endl;
	foo(a1);
	std::cout << a1.age << std::endl;

	// Можно вернуть данные структуры из функции
	Person b1 = fun();
	std::cout << b1.age << std::endl;

	// Создаем массив экземпляров структуры. Массив Person - массив людей
	Person arr[5];
	arr[0].age = 10;
	arr[1].age = 20;
	arr[2].age = 30;
	arr[3].age = 40;
	arr[4].age = 50;

	// Создаем динамический массив
	// Person *arr = new Person[5];
	*/

	// Задача 1. Месяцы
	std::cout << "\nЗадача 1. Месяцы " << "\n";
	int input, mounth;
	do
	{
		std::cout << "Введите номер месяца: ";
		std::cin >> input;

		if (input > 12 || input < 0) { std::cout << "Неправильный номер!" << std::endl; }
		switch (input)
		{
		case static_cast<int>(Months::January):
			std::cout << "Январь" << std::endl;
			break;
		case static_cast<int>(Months::February):
			std::cout << "Февраль" << std::endl;
			break;
		case static_cast<int>(Months::March):
			std::cout << "Март" << std::endl;
			break;
		case static_cast<int>(Months::April):
			std::cout << "Апрель" << std::endl;
			break;
		case static_cast<int>(Months::May):
			std::cout << "Май" << std::endl;
			break;
		case static_cast<int>(Months::June):
			std::cout << "Июнь" << std::endl;
			break;
		case static_cast<int>(Months::July):
			std::cout << "Июль" << std::endl;
			break;
		case static_cast<int>(Months::August):
			std::cout << "Август" << std::endl;
			break;
		case static_cast<int>(Months::September):
			std::cout << "Сентябрьь" << std::endl;
			break;
		case static_cast<int>(Months::October):
			std::cout << "Октябрь" << std::endl;
			break;
		case static_cast<int>(Months::November):
			std::cout << "Ноябрь" << std::endl;
			break;
		case static_cast<int>(Months::December):
			std::cout << "Декабрь" << std::endl;
			break;
		}
	} while (input != 0);
		std::cout << "До свидания!" << std::endl;



		// Задача 2. Счет
		std::cout << "\nЗадача 2. Счет " << "\n";

		float balance_new;

		requisites client = {};
		std::cout << "Введите номер счета: ";
		std::cin >> client.number;
		std::cout << "Введите имя владельца: ";
		std::cin >> client.name;
		std::cout << "Введите баланс: ";
		std::cin >> client.balance;
		std::cout << "Введите новый баланс: ";
		std::cin >> balance_new;
		balance_changed(client, balance_new);
		std::cout << "Ваш счет: " << client.name << ", " << client.number << ", " << client.balance << std::endl;
		

		// Задача 3. Вывод структуры
		std::cout << "\nЗадача 3. Вывод структуры " << "\n";

		full_adress first = {"Хабаровск", "Муравьева-Амурского", 3, 1, 680000};
		print_full_adress(first);

}
