#include <iostream>

// ��� ������ 1 - ������
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

// ��� ������ 2 - ����. ������� ��������� requisites � ������� ��������� �������
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

// ��� ������ 3 - ����� ���������. ������� ��������� full_adress � ������� ������ � ������� ����������� ���� �������
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
	std::cout << "�����: " << any_adress.city << std::endl;
	std::cout << "�����: " << any_adress.street << std::endl;
	std::cout << "����� ����: " << any_adress.house_number << std::endl;
	std::cout << "����� ��������: " << any_adress.appart_number << std::endl;
	std::cout << "������: " << any_adress.index << std::endl;
}


enum Colors					// ���������� ��������. �������� ������ � int ��� '' ���������� ���������
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

// ��� ������ ������, �.� ����� ����������� ����� ������������ ���������
/*void foo(Person a)
{
	a.age = 30;
}*/

// ���������� ������
void foo(Person &a)
{
	a.age = 30;
}

//const int green = 167;		// ���������� �������� (�� ���������� �� enum)
//const int red = 167;

// �������, ������������ ���������
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

	int color1 = 167;		// �������
	int color2 = 326;		// �������
	if (color1 == 167)
	{
		std::cout << "������� �����!" << std::endl;
	}

	// ����� ������� ��������� enum �� �����
	std::cout << green << std::endl;		// ��������� 0
	std::cout << red << std::endl;			// ��������� -10
	std::cout << blue << std::endl;			// ��������� -9

	// ����� �������� ��������� enum �������� � ���������� int
	int a = green;
	std::cout << a << std::endl;

	Colors::red; // ���������� � ���� enum - ������� ����� �������� �� ������ � ����

	// ����� �������� ���������� ���� Colors � ��������� �� �������� green (�������� �� main())
	Colors x = green;
	std::cout << x << std::endl;

	// ������ � �������� ����. ������� ���������� season ���� enum �� ������������� ������ enum seasons, ��������� �������� spring
	// seasons season = spring;			// ��� �����, �� �� ����� ������� ������ ������� spring
	seasons season = seasons::spring;	// ��� �����, ��������

	// ������������� ����� ����������� ���� ������������ - enum class. ������������ ������, �� � ������������ ����� ������������� ������
	// ������ ��� �������� ��� �� ����� ��������, �.� ������������ ��� enum class Seasons
	//int v = Seasons::Spring;					//�� ��������
	//int m = Spring;								// �� ��������
	//Seasons c = (Seasons)0;						// �������� // ���������� � ���� ������ Seasons
	//Seasons d = static_cast < Seasons >(0);	// ��������	// ���������� � ���� ������ Seasons
	int e = static_cast<int>(Seasons::Spring);
	std::cout << e << std::endl;

	// �������� � ������� ��������� (����� ����� �� ����� ��� � �����, �� 1 ������� - public)
// ��������� - ��� ���������������� ��� ������, ������������ ����������� ������
// ������, ������� �������� � ���� ���������, ���������� ������. ������ ���� � ��� ��� ����������, ������ ������������ � ������ ���������.
// � ��������� ���� ����������� � � �� �����������, �� ����� ����� ������� ��������� � � ����������, ����������� � ������� �����������

//������ ��������� ���������. ���������� �� main()
//struct Person {
//	string name;
//}

// ��������������� ���� ��������� ��� ������ ����������� ���������
	Person a1 = { "����", "������", 20 };
	Person a2 = { "����", "������" };
	Person a3 = { "����" };

	// ���� ��������� � ��� �����, ���������������� (�� ���� ��������� ������������� �����) ��� ������
	// ����������, ������� ����� ��� ������ ��������� ���� ���������, ���������� ������������ ���� ���������.

	std::cout << a1.name << ' ' << a1.surname << ' ' << a1.age << std::endl; // ������� ������ ���� ��������� ��������
	std::cin >> a1.age;
	std::cout << a1.name << ' ' << a1.surname << ' ' << a1.age << std::endl;
	// ��������������� ���� ��������� ��� 1 ���������� ��������� �1
	a1.name = "�������";
	a1.surname = "������";
	a1.age = 30;

	// ������ � �����������
	Person* pa = &a1;
	std::cout << (*pa).age << std::endl;

	// ��� ������������ �� ���������, � ->, ����� ������� � �������
	std::cout << pa->age << std::endl;

	// ��������� � �������
	std::cout << a1.age << std::endl;
	foo(a1);
	std::cout << a1.age << std::endl;

	// ����� ������� ������ ��������� �� �������
	Person b1 = fun();
	std::cout << b1.age << std::endl;

	// ������� ������ ����������� ���������. ������ Person - ������ �����
	Person arr[5];
	arr[0].age = 10;
	arr[1].age = 20;
	arr[2].age = 30;
	arr[3].age = 40;
	arr[4].age = 50;

	// ������� ������������ ������
	// Person *arr = new Person[5];
	*/

	// ������ 1. ������
	std::cout << "\n������ 1. ������ " << "\n";
	int input, mounth;
	do
	{
		std::cout << "������� ����� ������: ";
		std::cin >> input;

		if (input > 12 || input < 0) { std::cout << "������������ �����!" << std::endl; }
		switch (input)
		{
		case static_cast<int>(Months::January):
			std::cout << "������" << std::endl;
			break;
		case static_cast<int>(Months::February):
			std::cout << "�������" << std::endl;
			break;
		case static_cast<int>(Months::March):
			std::cout << "����" << std::endl;
			break;
		case static_cast<int>(Months::April):
			std::cout << "������" << std::endl;
			break;
		case static_cast<int>(Months::May):
			std::cout << "���" << std::endl;
			break;
		case static_cast<int>(Months::June):
			std::cout << "����" << std::endl;
			break;
		case static_cast<int>(Months::July):
			std::cout << "����" << std::endl;
			break;
		case static_cast<int>(Months::August):
			std::cout << "������" << std::endl;
			break;
		case static_cast<int>(Months::September):
			std::cout << "���������" << std::endl;
			break;
		case static_cast<int>(Months::October):
			std::cout << "�������" << std::endl;
			break;
		case static_cast<int>(Months::November):
			std::cout << "������" << std::endl;
			break;
		case static_cast<int>(Months::December):
			std::cout << "�������" << std::endl;
			break;
		}
	} while (input != 0);
		std::cout << "�� ��������!" << std::endl;



		// ������ 2. ����
		std::cout << "\n������ 2. ���� " << "\n";

		float balance_new;

		requisites client = {};
		std::cout << "������� ����� �����: ";
		std::cin >> client.number;
		std::cout << "������� ��� ���������: ";
		std::cin >> client.name;
		std::cout << "������� ������: ";
		std::cin >> client.balance;
		std::cout << "������� ����� ������: ";
		std::cin >> balance_new;
		balance_changed(client, balance_new);
		std::cout << "��� ����: " << client.name << ", " << client.number << ", " << client.balance << std::endl;
		

		// ������ 3. ����� ���������
		std::cout << "\n������ 3. ����� ��������� " << "\n";

		full_adress first = {"���������", "���������-���������", 3, 1, 680000};
		print_full_adress(first);

}
