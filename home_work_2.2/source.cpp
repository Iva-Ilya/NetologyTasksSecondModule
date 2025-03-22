#include <iostream>

class Calculator
{
private:
	double num1;
	double num2;
public:
	bool set_num1(double num1)
	{
		if (num1 != 0)
		{
			this->num1 = num1;
			return true;
		}
		// std::cout << "�������� ����!" << std::endl;
		return false;
	}
	bool set_num2(double num2)
	{
		if (num2 != 0)
		{
			this->num2 = num2;
			return true;
		}
		// std::cout << "�������� ����!" << std::endl;
		return false;
	}
	double add()
	{
		double sum = this->num1 + this->num2;
		return sum;
	}
	double multiply()
	{
		double mult = this->num1 * this->num2;
		return mult;
	}
	double subtract_1_2()
	{
		double sub_1_2 = this->num1 - this->num2;
		return sub_1_2;
	}
	double subtract_2_1()
	{
		double sub_2_1 = this->num2 - this->num1;
		return sub_2_1;
	}
	double divide_1_2()
	{
		double div_1_2 = this->num1 / this->num2;
		return div_1_2;
	}
	double divide_2_1()
	{
		double div_2_1 = this->num2 / this->num1;
		return div_2_1;
	}
};

class Counter
{
private:
	int state;
public:
	Counter() {}
	Counter(int value_init_state)
	{
		this->state = value_init_state;
	}

	int get_state()
	{
		std::cout << this->state << std::endl;
		return this->state;
	}
	void up()
	{
		this->state++;
	}
	void down()
	{
		this->state--;
	}
};

int main()
{
	setlocale(0, "");
	system("chcp 1251");

	//������ 1 - ����������� ���� �����.
	std::cout << "������ 1 - ����������� ���� �����." << std::endl;

	double num1, num2;
	Calculator first;

	std::cout << "������� num1: ";
	std::cin >> num1;
	while (first.set_num1(num1) == false)
	{
		std::cout << "�������� ����!" << std::endl;
		std::cout << "������� num1: ";
		std::cin >> num1;
	}

	std::cout << "������� num2: ";
	std::cin >> num2;
	while (first.set_num2(num2) == false)
	{
		std::cout << "�������� ����!" << std::endl;
		std::cout << "������� num2: ";
		std::cin >> num2;
	}
	
	std::cout << "num1 + num2 = " << first.add() << std::endl;
	std::cout << "num1 * num2 = " << first.multiply() << std::endl;
	std::cout << "num1 - num2 = " << first.subtract_1_2() << std::endl;
	std::cout << "num2 - num1 = " << first.subtract_2_1() << std::endl;
	std::cout << "num1 / num2 = " << first.divide_1_2() << std::endl;
	std::cout << "num2 / num1 = " << first.divide_2_1() << std::endl;


	std::cout << std::endl;
	//������ 2 - �������.
	std::cout << "������ 2 - �������." << std::endl;

	std::string init_state;
	int value_init_state = 0;
	char any_operation = '0';
	std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
	std::cin >> init_state;
	
	if (init_state == "��")
	{
		std::cout << "������� ��������� �������� ��������:";
		std::cin >> value_init_state;
		Counter first_counter(value_init_state);
		// while ((any_operation != 'x') || (any_operation != '�'))								// ������� '�' � ���������� 'x'.
		while (true)
		{
			std::cout << "������� ������� ('+', '-', '=' ��� 'x'):";
			std::cin >> any_operation;
			if (any_operation == '+')
			{
				first_counter.up();
			}
			else if (any_operation == '-')
			{
				first_counter.down();
			}
			else if (any_operation == '=')
			{
				first_counter.get_state();
			}
			else if (any_operation == 'x')
			{
				break;
			}
			else if (any_operation == '�')
			{
				break;
			}
		}
		std::cout << "�� ��������!" << std::endl;
	}
	else if (init_state == "���")
	{
		Counter first_counter;

		// while ((any_operation != 'x') || (any_operation != '�'))								// ������� '�' � ���������� 'x'.
		while (true)
		{
			std::cout << "������� ������� ('+', '-', '=' ��� 'x'):";
			std::cin >> any_operation;
			if (any_operation == '+')
			{
				first_counter.up();
			}
			else if (any_operation == '-')
			{
				first_counter.down();
			}
			else if (any_operation == '=')
			{
				first_counter.get_state();
			}
			else if (any_operation == 'x')
			{
				break;
			}
			else if (any_operation == '�')
			{
				break;
			}
		}
		std::cout << "�� ��������!" << std::endl;
	}
	else
	{
		std::cout << "�� ����� �������� �������. ��������� ������� ������." << std::endl;
	}
	
	









}