#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

bool convert_to_double_value(std::string v, double& value)
{
	const int START_ASCII_NUM = (int)'0';
	const int END_ASCII_NUM = (int)'9';
	const int DOT_ASCII = int('.');
	const int NEGATIVE_ASCII = int('-');

	double total_value = 0;
	int lenght = v.size();
	bool negative = false;
	bool dot = false;
	int int_deep = 0;
	int float_deep = 0;
	int curr_int_value = 0;
	int curr_float_value = 0;
	char curr_char = '\0';

	for (int i = 0; i < lenght; i++)
	{
		curr_char = v[i];
		if (!((curr_char >= START_ASCII_NUM && curr_char <= END_ASCII_NUM) || DOT_ASCII == curr_char || NEGATIVE_ASCII == curr_char))
		{
			value = 0;
			return false;
		}

		if (NEGATIVE_ASCII == curr_char && true == negative)
		{
			value = 0;
			return false;
		}
		if (NEGATIVE_ASCII == curr_char && 0 == int_deep && 0 == float_deep && false == negative)
		{
			negative = true;
		}

		if (DOT_ASCII == curr_char && true == dot)
		{
			value = 0;
			return false;
		}
		if (DOT_ASCII == curr_char && 0 == float_deep && false == dot)
		{
			dot = true;
		}

		if (curr_char >= START_ASCII_NUM && curr_char <= END_ASCII_NUM && false == dot)
		{
			curr_int_value = curr_int_value * 10 + (curr_char - START_ASCII_NUM);
			int_deep++;
		}
		if (curr_char >= START_ASCII_NUM && curr_char <= END_ASCII_NUM && true == dot)
		{
			curr_float_value = curr_float_value * 10 + (curr_char - START_ASCII_NUM);
			float_deep++;
		}
	}
	total_value = curr_int_value + curr_float_value * pow(10, (-1) * float_deep);
	if (negative)
		total_value *= (-1);
	value = total_value;

	return true;
}
void task1()
{
	const char FILE_NAME[] = "task1.txt";

	std::cout << "\t<Zaddacha> \"Fail\"\n"
		"\tProgramma sozdast fail s nazvaniem " << FILE_NAME << "\n"
		"\tV kotoriy neobhodimo zapisat 10 polzovatelskih chisel.\n"
		"\tV kontse buden vivedenna ih summa\n"
		"\tVvedite chisla:" << std::endl;

	std::ofstream fout(FILE_NAME);
	std::string user_value;
	double user_number = 0;

	if (!fout.is_open())
	{
		std::cout << "!!!: Ne udalos sozdat fail" << std::endl;
		return;
	}
	for (int i = 1; i < 11; i++)
	{
		while(true)
		{
			std::cout << "\t" << i << ". >> ";
			std::cin >> user_value;
			if (!convert_to_double_value(user_value, user_number))
				std::cout << "!!!: Neverno vvedeno chislo!" << std::endl;
			else break;
		}
		fout << user_number << "\n";
		
	}
	fout.close();

	std::ifstream fin(FILE_NAME);
	double summa = 0;

	if (!fin.is_open())
	{
		std::cout << "!!!: Ne udalos otkrit fail" << std::endl;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		fin >> user_number;
		summa += user_number;
	}
	fin.close();
	std::cout << "\tSumma chisel = " << summa << std::endl;
}
int sign(double x)
{
	if (x > 0)
		return 1;
	if (0 == x)
		return 0;
	return -1;
}
void task2()
{
	std::cout << "\t<Zaddacha> \"Znak chisla\"\n"
		"\tProgramma opredelyaet znak chisla, ispolzyya podprogrammy sign po sledyuyschim pravilam:\n"
		"\tEsli x > 0 , to vivodim 1\n"
		"\tEsli x = 0 , to vivodim 0\n"
		"\tEsli x < 0 , to vivodim -1\n"
		"\tx - polzovatelskoye chislo.\n" << std::endl;

	std::string uvalue;
	double value;
	while (true)
	{
		std::cout << "\tVvedite chislo x >> ";
		std::cin >> uvalue;
		if (!convert_to_double_value(uvalue, value))
			std::cout << "!!!: Neverno vvedeno chislo!" << std::endl;
		else break;
	}
	std::cout << "\tresultat: " << sign(value) << std::endl;
}
double s_rectangle()
{
	double lenght, wight;

	std::cout << "\tVvedite dliny pramougolnika >> ";
	std::cin >> lenght;
	if (0 >= lenght)
	{
		std::cout << "!!!: Necorrectnoye znacheniye dliny" << std::endl;
		return 0;
	}
	std::cout << "\tVvedite shiriny pramougolnika >> ";
	std::cin >> wight;
	if (0 >= wight)
	{
		std::cout << "!!!: Necorrectnoye znacheniye shiriny" << std::endl;
		return 0;
	}

	return lenght * wight;
}
double s_triangle()
{
	double base, height;

	std::cout << "\tVvedite visoty treugolnika >> ";
	std::cin >> height;
	if (0 >= height)
	{
		std::cout << "!!!: Necorrectnoye znacheniye visoty" << std::endl;
		return 0;
	}
	std::cout << "\tVvedite dliny osnovaniya treugolnika >> ";
	std::cin >> base;
	if (0 >= base)
	{
		std::cout << "!!!: Necorrectnoye znacheniye dliny osnovaniya" << std::endl;
		return 0;
	}

	return 0.5 * base * height;
}
double s_circle()
{
	const double PI = 3.1415926535;
	double radius;

	std::cout << "\tPI = " << PI << "\n";
	std::cout << "\tVvedite radius kruga >> ";
	std::cin >> radius;
	if (0 >= radius)
	{
		std::cout << "!!!: Necorrectnoye znacheniye radiusa" << std::endl;
		return 0;
	}

	return PI * radius * radius;
}
void task3()
{
	std::cout << "\t<Zaddacha> \"Geometricheskiye figury\"\n"
		"\tProgramma vichislyaet ploschadi geometricheskih figur, ispolzyya podprogrammi\n"
		"\tViberite figury dlya poiska ploschadi:\n"
		"\t1. Pramougolnik\n"
		"\t2. Treugolnik\n"
		"\t3. Krug" << std::endl;

	int user_value;
	double square;
	std::cout << "\t>> ";
	std::cin >> user_value;
	switch (user_value)
	{
		case 1:
			square = s_rectangle();
			break;
		case 2:
			square = s_triangle();
			break;
		case 3:
			square = s_circle();
			break;
		default:
			std::cout << "!!!: Neopredelyonnaya figura" << std::endl;
			return;
			break;
	}
	if (0 != square)
		std::cout << "\tPloschad = " << square << std::endl;
}
void task4()
{
	std::cout << "\t<Zaddacha> \"Bilaya slava\"\n"
		"\tProgramma vivedet amerikanskii flag obraztsa 1912 goda." << std::endl;

	for (int i = 0; i < 4; i++)
	{
		std::cout << "\t";
		for (int j = 0; j < 12; j++)
			std::cout << '*';
		for (int j = 0; j < 18; j++)
			std::cout << '_';
		std::cout << '\n';
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\t";
		for (int j = 0; j < 30; j++)
			std::cout << '_';
		std::cout << '\n';
	}
}
void task5()
{
	std::cout << "\t<Zaddacha> \"Sinysoida\"\n"
		"\tProgramma vivedet grafic functsii y = sin(x)" << std::endl;

	const int LENGHT = 120;
	const int WIGHT = 30;
	const int E = 6;

	char window[WIGHT][LENGHT];
	for (int w = 0; w < WIGHT; w++)
	{
		for (int l = 0; l < LENGHT; l++)
		{
			window[w][l] = ' ';
		}
	}

	int axes_Y = round(LENGHT / 2);
	for (int w = 0; w < WIGHT; w++)
	{
		window[w][axes_Y] = '|';
	}
	window[0][axes_Y] = '^';
	window[0][axes_Y + 1] = 'Y';

	int axes_X = round(WIGHT / 2);
	for (int l = 0; l < LENGHT; l++)
	{
		window[axes_X][l] = '-';
	}
	window[axes_X][LENGHT - 1] = '>';
	window[axes_X + 1][LENGHT - 1] = 'X';

	double y = 0;
	double x = 0;
	for (int i = 0; i < LENGHT; i++)
	{
		x = i - LENGHT / 2;
		y = sin(x / E) * E;
		y = round(y) * (-1);
		window[int(y) + (WIGHT / 2)][i] = '*';
	}

	const int START_ASCII_NUM = (int)'0';
	int start_Xmarkup = LENGHT / 2 % E;
	int start_Xnummarkap = (LENGHT / 2 / E) * (-1) - 1;
	for (int i = start_Xmarkup; i < LENGHT; i += E)
	{
		++start_Xnummarkap;

		if (start_Xnummarkap < 0)
		{
			window[WIGHT / 2 + 1][i - 1 >= 0 ? i - 1 : i] = '-';
			window[WIGHT / 2 + 1][i] = char(abs(start_Xnummarkap) + START_ASCII_NUM);
		}
		if (start_Xnummarkap > 0)
		{
			window[WIGHT / 2 + 1][i] = char(abs(start_Xnummarkap) + START_ASCII_NUM);
		}
		window[WIGHT / 2][i] = '|';
	}

	int start_Ymarkup = WIGHT / 2 % E;
	int start_Ynummarkup = (WIGHT / 2 / E);
	for (int i = start_Ymarkup; i < WIGHT; i += E)
	{
		if (start_Ynummarkup < 0)
		{
			window[i][LENGHT / 2 - 2] = '-';
			window[i][LENGHT / 2 - 1] = char(abs(start_Ynummarkup) + START_ASCII_NUM);
		}
		if (start_Ynummarkup > 0)
		{
			window[i][LENGHT / 2 - 1] = char(abs(start_Ynummarkup) + START_ASCII_NUM);
		}
		window[i][LENGHT / 2] = '-';
		start_Ynummarkup--;
	}
	window[WIGHT / 2][LENGHT / 2] = '|';
	window[WIGHT / 2 + 1][LENGHT / 2] = '0';

	for (int w = 0; w < WIGHT; w++)
	{
		for (int l = 0; l < LENGHT; l++)
		{
			std::cout << window[w][l];
		}
		std::cout << std::endl;
	}
}
void task6()
{
	std::cout << "\t<Zaddacha> \"Avtomainii raspoznovatel\"\n"
		"\tProgramma decodiryiet rimskyyu zapis chisla.\n"
		"\tDopustimiye znacheniya:\n"
		"\tI = 1\n"
		"\tV = 5\n"
		"\tX = 10\n"
		"\tL = 50\n"
		"\tC = 100\n"
		"\tD = 500\n"
		"\tM = 1000" << std::endl;

	std::string user_r;
	std::cout << "\tVvedite rimskoye chislo >> ";
	std::cin >> user_r;

	std::vector<int> arr;
	int lenght = user_r.length();
	bool correct_rim_value = true;
	for (int i = 0; i < lenght - 1; i++)
	{
		switch (user_r[i])
		{
			case 'M':
				break;
			case 'D':
				if (!('I' == user_r[i + 1] || 'V' == user_r[i + 1] || 'X' == user_r[i + 1] || 'L' == user_r[i + 1]))
					correct_rim_value = false;
				break;
			case 'C':
				break;
			case 'L':
				if (!('I' == user_r[i + 1] || 'V' == user_r[i + 1] || 'X' == user_r[i + 1]))
					correct_rim_value = false;
				break;
			case 'X':
				if (!('I' == user_r[i + 1] || 'V' == user_r[i + 1] || 'X' == user_r[i + 1] || 'L' == user_r[i + 1] || 'C' == user_r[i + 1]))
					correct_rim_value = false;
				break;
			case 'V':
				if (!('I' == user_r[i + 1] || 'V' == user_r[i + 1]))
					correct_rim_value = false;
				break;
			case 'I':
				if (!('I' == user_r[i + 1] || 'V' == user_r[i + 1] || 'X' == user_r[i + 1]))
					correct_rim_value = false;
				break;
			default:
				correct_rim_value = false;
				break;
		}
		if (!correct_rim_value)
		{
			std::cout << "!!!: Necorrectnaya zapis chisla" << std::endl;
			return;
		}
	}

	char previus_char = '\0';
	int k = 1;
	for (int i = 0; i < lenght; i++)
	{
		if (previus_char == user_r[i])
			k++;
		else
			k = 1;
		previus_char = user_r[i];
		if (k > 3)
		{
			std::cout << "!!!: Necorrectnaya zapis chisla" << std::endl;
			return;
		}
	}

	int curr_ichar;
	for (int i = 0; i < lenght; i++)
	{
		switch (user_r[i])
		{
			case 'M':
				curr_ichar = 1000;
				break;
			case 'D':
				curr_ichar = 500;
				break;
			case 'C':
				curr_ichar = 100;
				break;
			case 'L':
				curr_ichar = 50;
				break;
			case 'X':
				curr_ichar = 10;
				break;
			case 'V':
				curr_ichar = 5;
				break;
			case 'I':
				curr_ichar = 1;
				break;
			default:
				std::cout << "!!!: Necorrectnaya zapis chisla" << std::endl;
				return;
		}
		arr.push_back(curr_ichar);
	}
	arr.push_back(user_r[lenght - 1]);

	if (lenght > 2)
	{
		for (int i = 0; i < lenght - 2; i++)
		{
			if (arr[i] < arr[i + 1] && !(arr[i] > arr[i + 2]))
			{
				std::cout << "!!!: Necorrectnaya zapis chisla" << std::endl;
				return;
			}
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2])
			{
				continue;
			}
			if (arr[i] == arr[i + 1] && !(arr[i] > arr[i + 2]))
			{
				std::cout << "!!!: Necorrectnaya zapis chisla" << std::endl;
				return;
			}
		}
	}

	int r_int = 0;
	for (int i = 0; i < lenght - 1; i++)
	{
		if (arr[i] >= arr[i + 1])
			r_int += arr[i];
		else
			r_int -= arr[i];
	}
	r_int += arr[lenght - 1];
	std::cout << "\t" << user_r << " = " << r_int << std::endl;
}
int random_generator(int m, int i, int c)
{
	int si = 0;
	for (int r_i = 0; r_i < i; r_i++)
	{
		si = (m * si + r_i) % c - 1;
	}
	return si;
}
void task7()
{
	std::cout << "\t<Zaddacha> \"Generator slychainih chisel\"\n"
		"\tProgramma generiryiet psevdoslychainiye chisla, ispolzyya formyly:\n"
		"\tSi + 1 = (m*Si + i) mod c\n"
		"\tDlya 1 varianta: m = 37, i = 3, c = 64\n"
		"\tDlya 2 varianta: m = 25173, i = 13849, c = 65537"
		<< std::endl;

	std::cout << "\tVariant 1 >> " << random_generator(37, 3, 64) << '\n';
	std::cout << "\tVariant 2 >> " << random_generator(25173, 13849, 65537) << '\n';
}
void task8()
{
	const double matrix_A[3][4] =
	{
	{5, 2, 0, 10},
	{3, 5, 2, 5},
	{20, 0, 0, 0}
	};
	const double matrix_B[4][2] =
	{
	{1.2, 0.5},
	{2.8, 0.4},
	{5, 1},
	{2, 1.5}
	};

	std::cout << "\t<Zaddacha> \"Umnozheniye matrits\"\n"
		"\tProgramma umnozhit matritsi A i B, poluchiv matritsy C i otvetit na voprosi." << std::endl;

	double matrix_C[3][2];
	double ij_sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				ij_sum += matrix_A[i][k] * matrix_B[k][j];
			}
			matrix_C[i][j] = ij_sum;
			ij_sum = 0;
		}
	}

	std::cout << "\tMatritsa C:" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			std::cout << '\t' << matrix_C[i][j] << '\t';
		}
		std::cout << '\n';
	}

	double max_revenue = 0;
	int num_max_revenue_seller;
	double max_commission = 0;
	int num_max_commission_seller;
	double total_revenue = 0;
	double total_comission = 0;
	for (int i = 0; i < 3; i++)
	{
		if (max_revenue < matrix_C[i][0])
		{
			max_revenue = matrix_C[i][0];
			num_max_revenue_seller = i;
		}
		if (max_commission < matrix_C[i][1])
		{
			max_commission = matrix_C[i][1];
			num_max_commission_seller = i;
		}
		total_revenue += matrix_C[i][0];
		total_comission += matrix_C[i][1];
	}
	std::cout << "\t1. Naibolshaya virycha u " << num_max_revenue_seller + 1 << " prodavtsa" << std::endl;
	std::cout << "\t2. Naibolshaya comissionniye u " << num_max_commission_seller + 1 << " prodavtsa" << std::endl;
	std::cout << "\t3. Summa viruchki = " << total_revenue << std::endl;
	std::cout << "\t4. Summa comissionnih = " << total_comission << std::endl;
	std::cout << "\t5. Oborot = " << total_revenue + total_comission << std::endl;
}
void task9()
{
	std::cout << "\t<Zaddacha> \"Sistema schisleniya\"\n"
		"\tProgramma zaprashivayet chislo v odnoi sisteme schisleniya i vozvraschaye ego v zadannoi.\n"
		"\tSistemy schisleniya ot 2 do 16" << std::endl;

	std::string user_value;
	int user_n_system, n_system;

	std::cout << "\tPoryadok ishodnoi sistemy schisleniya >> ";
	std::cin >> user_n_system;
	if (2 > user_n_system || 16 < user_n_system)
	{
		std::cout << "!!!: Nedopystimaya sistema schisleniya" << std::endl;
		return;
	}
	std::cout << "\tChislo v zadannoi sisteme schisleniya >> ";
	std::cin >> user_value;
	std::cout << "\tPoryadok neobhodimoi sistemy schisleniya >> ";
	std::cin >> n_system;
	if (2 > n_system || 16 < n_system)
	{
		std::cout << "!!!: Nedopystimaya sistema schisleniya" << std::endl;
		return;
	}

	const int START_ASCII_DIGIT = int('0');
	const int START_ASCII_ABC = int('A');

	int lenght = user_value.length();
	std::vector<int> vec_ivalue;
	for (int i = 0; i < lenght; i++)
	{
		switch (user_value[i])
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				vec_ivalue.push_back(int(user_value[i]) - START_ASCII_DIGIT);
				break;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				vec_ivalue.push_back(int(user_value[i]) - START_ASCII_ABC + 10);
				break;
			default:
				std::cout << "!!!: Necorrectnoye chislo" << std::endl;
				return;
		}
	}
	for (int i = 0; i < lenght; i++)
	{
		if (vec_ivalue[i] > user_n_system - 1)
		{
			std::cout << "!!!: Necorrectnoye chislo" << std::endl;
			return;
		}
	}

	int value_to_10 = 0;
	for (int i = 0; i < lenght; i++)
	{
		value_to_10 += vec_ivalue[i] * pow(user_n_system, lenght - i - 1);
	}

	std::vector<int> vec_ivalue_to_n;
	int delta = value_to_10;
	while (delta != 0)
	{
		vec_ivalue_to_n.push_back(delta % n_system);
		delta /= n_system;
	}

	std::vector<int> vac_rivalue_to_n;
	for (int i = vec_ivalue_to_n.size() - 1; i > -1; i--)
	{
		vac_rivalue_to_n.push_back(vec_ivalue_to_n[i]);
	}

	std::cout << "\tResultat >> ";
	for (int i = 0; i < vac_rivalue_to_n.size(); i++)
	{
		switch (vac_rivalue_to_n[i])
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				std::cout << char(vac_rivalue_to_n[i] + START_ASCII_DIGIT);
				break;
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
				std::cout << char(vac_rivalue_to_n[i] + START_ASCII_ABC - 10);
				break;
		}
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "Viderite zadachu:\n"
		"1. Fail\n"
		"2. Znak chisla\n"
		"3. Geometricheskiye figury\n"
		"4. Bilaya svala\n"
		"5. Sinysoida\n"
		"6. Avtomainii raspoznovatel\n"
		"7. Generator slychainih chisel\n"
		"8. Umnozheniye matrits\n"
		"9. Sistema schisleniya\n"
		"Vvedite inoe znachenie dlya zaversheniya programmy."
		<< std::endl;

	bool cycle_working = true;
	int user_value;
	while (cycle_working)
	{
		std::cout << ">> ";
		std::cin >> user_value;

		switch (user_value)
		{
			case 1:
				task1();
				break;
			case 2:
				task2();
				break;
			case 3:
				task3();
				break;
			case 4:
				task4();
				break;
			case 5:
				task5();
				break;
			case 6:
				task6();
				break;
			case 7:
				task7();
				break;
			case 8:
				task8();
				break;
			case 9:
				task9();
				break;
			default:
				cycle_working = false;
				break;
		}
	}
}