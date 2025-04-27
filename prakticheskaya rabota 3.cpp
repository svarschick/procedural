#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

void zaem()
{
    std::cout << "<Zadacha \"Zaem\">" << std::endl;
    std::cout << "\tProgramma rasschitivayet mesyachuyu viplaty po kreditu (m), ispolzuya formuly:\n"
        "\tm = (S*r*(1+r)^n)/(12*((1+r)^n-1)) , r = p/100 , gde:\n"
        "\tm - mesyachuya viplata po zaemy\n"
        "\tS - summa zaema\n"
        "\tp - protsent po kreditu\n"
        "\tn - srok zaema (v godah)\n"
        "\tVvedite zaprashivaemiye znacheniya:" << std::endl;
    double S, p, n;
    std::cout << "\tS >> ";
    std::cin >> S;
    if (S < 0)
    {
        std::cout << "!!!:Summa kredita ne mozhet bit` menshe nulya" << std::endl;
        return;
    }
    std::cout << "\tp >> ";
    std::cin >> p;
    if (p <= -100)
    {
        std::cout << "!!!:Protsent ne mozhet bit menshe ili raven -100" << std::endl;
        return;
    }
    std::cout << "\tn >> ";
    std::cin >> n;
    if (n <= 0)
    {
        std::cout << "!!!: Necorrectnoe znacheniye dlya sroka viplat" << std::endl;
        return;
    }

    if (p)
    {
        double m, r;
        r = p / 100;
        m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
        std::cout << "\tSumma egemesyachnogo platezha m = " << m << std::endl;
    }
    else
    {
        std::cout << "\tSumma egemesyachnogo platezha m = " << S / (12 * n) << std::endl;
    }

}
void ssuda()
{
    std::cout << "\n<Zadacha \"Ssuda\">" << std::endl;
    std::cout << "\tProgramma rasschitivayet protsent (p) dlya vidannoi ssudi (S), ispolzuya formuli:\n"
        "\tm = (S*r*(1+r)^n)/(12*((1+r)^n-1)) , r = p/100 , gde:\n"
        "\tm - mesyachuya viplata po zaemy\n"
        "\tS - summa zaema\n"
        "\tp - protsent po kreditu\n"
        "\tn - srok zaema (v godah)\n"
        "\tVvedite zaprashivaemiye znacheniya:" << std::endl;
    double S, m, n;
    std::cout << "\tS >> ";
    std::cin >> S;
    if (S < 0)
    {
        std::cout << "!!!: Summa kredita ne mozhet bit` menshe nulya" << std::endl;
        return;
    }
    std::cout << "\tm >> ";
    std::cin >> m;
    if (m < 0)
    {
        std::cout << "!!!: Necorrectnoe znacheniye dlya ezhemesyachnogo platezha" << std::endl;
        return;
    }
    std::cout << "\tn >> ";
    std::cin >> n;
    if (n <= 0)
    {
        std::cout << "!!!: Necorrectnoe znacheniye dlya sroka viplat" << std::endl;
        return;
    }
    if (0 == S || 0 == m)
    {
        std::cout << "!!!: Protsent nevozmozhno rasschitat`" << std::endl;
        return;
    }

    const double E = 0.001; // tochnost`
    const double STARTSTEP = 10; //nachalnii shag

    double i = 0;
    double p = 1;
    double currm = 0;
    double step = STARTSTEP;
    double r;
    bool negative = false;

    if (fabs(S - 12 * m * n) <= E)
    {
        std::cout << "\t>> p = " << 0 << "%" << std::endl;
        return;
    }

    if (S - 12 * m * n > 0)
    {
        negative = true;
    }

    do {
        if (m > currm)
        {
            p += step;
            if (negative)
                step /= 2;
        }
        else
        {
            p -= step;
            if (!negative)
                step /= 2;
        }
        r = p / 100;
        currm = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
        std::cout << "\t" << ++i << ". p = " << p << "\tstep = " << step << "\tcurrm = " << currm << std::endl;
        if (fabs(100 - p) <= E*0.1)
        {
            std::cout << "\t>> p = " << -100 << "%" << std::endl;
            return;
        }

    } while (fabs(m - currm) > E);

    std::cout << "\t>> p = " << p << "%" << std::endl;
}
void kopirovaniyeFaila()
{
    const char DIR[] = "D:\\files\\cppstudio.txt";
    const char DATA[] = "tfasdfadsf";

    std::cout << "\n<Zadacha \"Kopirovanie Faila\">" << std::endl;
    std::cout << "\tProgramma sozdast fail v ukazannoi directorii:\n"
        << "\t" << DIR << "\n"
        << "\tI vivedet ego soderzhimoe v konsol" << std::endl;

    std::ofstream fout;
    fout.open(DIR);
    if (!fout.is_open())
    {
        std::cout << "!!!: Programme ne udalos sozdat fail v ukazannoi directorii:"
            "\n     " << DIR << std::endl;
        return;
    }
    fout << DATA;
    fout.close();

    std::ifstream fin;
    char c;
    fin.open(DIR);
    if (!fin.is_open())
    {
        std::cout << "!!!: Programme ne udalos otkrit fail v ukazannoi directorii:"
            "\n\t" << DIR << std::endl;
        return;
    }
    std::cout << "\t>> ";

    while (fin.get(c))
    {
        std::cout << c;
    }
    fin.clear();
    fin.seekg(0);
    std::cout << "\n\t>> ";
    while (fin.get(c))
    {
        std::cout << c;
    }
    fin.close();
}
void filter()
{
    const char DIR[] = "D:\\files\\cppfilter.txt";
    const char DATA[] = "9.11.204sH3 adslkj;nsgf;jlkod .1234.32.14 fsda23 sdff saed32 asdfa. 432";
    const int START_ASCII_NUM = (int)'0';
    const int END_ASCII_NUM = (int)'9';
    const int DOT_ASCII = int('.');
    const int NEGATIVE_ASCII = int('-');

    std::cout << "\n<Zadacha \"Filter\">\n"
        << "\tProgramma sozdast fail v ykazannoi directorii:\n"
        << "\t" << DIR << "\n"
        << "\tI zapishet tuda sleduyuschuy stroky:\n"
        << "\t" << DATA << "\n"
        << "\tPosle budet vivedena eta zhe stroka, no uzhe soderzhaschaya tolko tsifry." << std::endl;

    std::ofstream fout;
    fout.open(DIR);
    if (!fout.is_open())
    {
        std::cout << "!!!: Programme ne udalos sozdat fail v ukazannoi directorii:"
            "\n     " << DIR << std::endl;
        return;
    }
    fout << DATA;
    fout.close();

    std::ifstream fin;
    fin.open(DIR);
    if (!fin.is_open())
    {
        std::cout << "!!!: Programme ne udalos sozdat fail v ukazannoi directorii:"
            "\n     " << DIR << std::endl;
        return;
    }

    char c = 'a';
    std::vector<int> file;
    while (fin.get(c))
    {
        file.push_back(int(c));
    }
    file.push_back(int('\0'));
    
    std::vector<double> values;
    std::vector<int> deep_values;
    double curr_value = 0;
    int curr_int_value = 0, curr_float_value = 0;
    bool negative = false, dot = false;
    int step = 0, deep = 0;
    int curr_ichar;
    for (int i = 0; i < file.size(); i++)
    {
        curr_ichar = file[i];

        if (DOT_ASCII == curr_ichar && 0 != step && 0 == deep)
        {
            dot = true;
            continue;
        }
        if (NEGATIVE_ASCII == curr_ichar && 0 == step)
        {
            negative = true;
        }
        if (curr_ichar >= START_ASCII_NUM && curr_ichar <= END_ASCII_NUM && false == dot)
        {
            curr_int_value = curr_int_value * 10 + (curr_ichar - START_ASCII_NUM);
            step++;
        }
        if (curr_ichar >= START_ASCII_NUM && curr_ichar <= END_ASCII_NUM && true == dot)
        {
            curr_float_value = curr_float_value * 10 + (curr_ichar - START_ASCII_NUM);
            deep++;
        }
        if ((0 != step && (curr_ichar < START_ASCII_NUM || curr_ichar > END_ASCII_NUM)) || (DOT_ASCII == curr_ichar && true == dot))
        {
            curr_value = curr_int_value + curr_float_value * pow(10, (-1) * deep);
            if (negative)
                curr_value *= (-1);
            values.push_back(curr_value);
            deep_values.push_back(deep);

            curr_value = 0;
            curr_int_value = 0;
            curr_float_value = 0;
            step = 0;
            deep = 0;
            negative = false;
            dot = false;
        }
    }

    std::cout.setf(std::ios::fixed);
    for (int i = 0; i < values.size(); i++)
    {
        std::cout.precision(deep_values[i]);
        std::cout << "\t>> " << values[i] << ",\n";
    }
    fin.close();
}
void sortirovka_bukv()
{
    char arr[] = "igjvnqwPeiOzhDfiNatRbvLpqWebviZ";

    std::cout << "\n<Zadacha \"Sortirovka bukv\">" << std::endl;
    std::cout << "\tProgramma rasstavit bukvy v stroke:\n"
        << "\t" << arr << '\n'
        << "\tv alfovitnom poryadke\n" << std::endl;

    const int START_ASCII_UPPER_CASE = (int)'A';
    const int START_ASCII_LOWER_CASE = (int)'a';
    const int ABC_COUNT = 26;

    const int len = sizeof(arr);
    char narr[len];
    int k = 0;

    for (int case_step = 0; case_step < ABC_COUNT; case_step++)
    {
        for (int j = 0; j < len; j++)
        {
            if (START_ASCII_UPPER_CASE + case_step == (int)arr[j])
            {
                narr[k] = arr[j];
                k++;
            }
        }
        for (int j = 0; j < len; j++)
        {
            if (START_ASCII_LOWER_CASE + case_step == (int)arr[j])
            {
                narr[k] = arr[j];
                k++;
            }
        }
    }

    std::cout << "\t>> resultat:\n\t>> ";
    for (int i = 0; i < len - 1; i++)
        std::cout << narr[i] << ", ";

}

int main()
{
    std::cout << "Viberite zadachy:\n"
        << "1. Zaem\n"
        << "2. Ssuda\n"
        << "3. Kopirovaniye faila\n"
        << "4. Filter\n"
        << "5. Sortirovka bukov\n"
        << "Vvedite cho-to drugoye, chtobi zavershit programmy";

    int msg;
    bool cycle = true;
    while (cycle)
    {
        std::cout << "\n>> ";
        std::cin >> msg;
        switch (msg)
        {
            case 1:
                zaem();
                break;
            case 2:
                ssuda();
                break;
            case 3:
                kopirovaniyeFaila();
                break;
            case 4:
                filter();
                break;
            case 5:
                sortirovka_bukv();
                break;
            default:
                cycle = false;
                break;
        }
    }
    return 0;
}