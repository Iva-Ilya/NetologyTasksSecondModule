#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class adress
{
private:
	std::string full_adress, city, street;

	int number_house, number_appart;

public:

	adress() {}

	adress(std::string any_city, std::string any_street, int any_number_house, int any_number_appart)
	{
		this->city = any_city;
		this->street = any_street;
		this->number_house = any_number_house;
		this->number_appart = any_number_appart;
	}

	std::string get_city_name()
	{
		return this->city;
	}

	std::string get_output_address()
	{
		// std::cout << city << ", " << street << ", " << number_house << ", " << number_appart << std::endl;
		full_adress = city + ", " + street + ", " + std::to_string(number_house) + ", " + std::to_string(number_appart);
		return full_adress;
	}
};

void Sort(adress* arr, int size)
{
	bool swapped = false;
	do
	{
		swapped = false;
		for (int i = size - 1; i > 0; i--)
		{
			if ((arr[i - 1].get_city_name()) > (arr[i].get_city_name()))
			{
				adress temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
				swapped = true;
			}
		}
	} while (swapped);
};




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	//Задача 1 - Адреса.
	std::cout << "Задача 1 - Адреса." << std::endl;

	std::string city, street;
	int number_house, number_appart;
	int N;
	std::ifstream in("in_ref.txt");
	if (!in.is_open()) {
		std::cout << "File in.txt not open" << "\n";
		return 1;
	}

	in >> N;

	adress* arr_adress = new adress[N];

	while (!in.eof())
	{
		for (int i = 0; i < N; i++)
		{
			in >> city;
			in >> street;
			in >> number_house;
			in >> number_appart;

			arr_adress[i] = adress(city, street, number_house, number_appart);
			// std::cout << array_adress[i].get_output_address() << std::endl;								// Only for debug
		}
	}
	in.close();

	std::ofstream out("out.txt");
	if (out.is_open())
	{
		for (int i = 0; i < N; i++)
		{
			out << arr_adress[i].get_output_address() << std::endl;
			// std::cout << arr_adress[i].get_output_address() << std::endl;								// Only for debug
		}
	}
	out.close();


	std::cout << std::endl;
	//Задача 2 - Сортируем адреса.
	std::cout << "Задача 2 - Сортируем адреса." << std::endl;

	adress temp;
	std::ofstream out_2("out_2.txt");
	if (out_2.is_open())
	{
		out << std::to_string(N) << std::endl;

		Sort(arr_adress, N);

		for (int i = 0; i < N; i++)
		{
			out_2 << arr_adress[i].get_output_address() << std::endl;
		}
	}
	out_2.close();
	delete[] arr_adress;

}


//std::string a = "Москва", b = "Москво";
//// int a1 = std::stoi(a);
//// int b1 = std::stoi(b);


/*int lenght;
if (a.length() < b.length())
{
	lenght = a.length();
}
else
{
	lenght = b.length();
}
for (int i = 0; i < lenght; i++)
{
	if (a[i] > b[i])
	{
		std::cout << a[i] << " < " << b[i] << std::endl;
		std::cout << b << std::endl;
		break;
	}
	else if (a[i] < b[i])
	{
		std::cout << a[i] << " > " << b[i] << std::endl;
		std::cout << a << std::endl;
		break;
	}
	else
	{
		std::cout << a[i] << " = " << b[i] << std::endl;
	}
}*/

/*std::cout << std::endl;
std::string str = array_adress[0].get_city_name();
std::cout << str << std::endl;
std::cout << str.length() << std::endl;*/


//for (int i = 0; i < N; i++)
		//{
		//	int lenght;
		//	for (int j = 0; j < N - 1; j++)
		//	{
		//	/*	if (arr_adress[j].get_city_name().length() < arr_adress[j + 1].get_city_name().length())
		//		{
		//			lenght = arr_adress[j].get_city_name().length();
		//		}
		//		else
		//		{
		//			lenght = arr_adress[j + 1].get_city_name().length();
		//		}*/

		//		if (arr_adress[j].get_city_name()[0] > arr_adress[j + 1].get_city_name()[0])
		//		{
		//			temp = arr_adress[j];
		//			arr_adress[j] = arr_adress[j + 1];
		//			arr_adress[j + 1] = temp;
		//		}
		//	}
		//}