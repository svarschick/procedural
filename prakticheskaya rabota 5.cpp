#include <iostream>
#include <fstream>

namespace str
{
    int lenght(const char* ptr_s)
    {
        if (0 != ptr_s)
        {
            int lenght = 0;
            while (*ptr_s++) lenght++;
            return lenght;
        }
        else return 0;
    }
    char* combine(const char* ptr_s1, const char* ptr_s2)
    {
        if (0 != ptr_s1 && 0 != ptr_s2)
        {
            int lenght1 = lenght(ptr_s1) + 1;
            int lenght2 = lenght(ptr_s2) + 1;
            char* ptr_new_s = new char[lenght1 + lenght2 - 1];
            while (*ptr_new_s++ = *ptr_s1++);
            ptr_new_s -= 1;
            while (*ptr_new_s++ = *ptr_s2++);
            ptr_new_s -= lenght1 + lenght2 - 1;
            return ptr_new_s;
        }
        if (0 != ptr_s1)
        {
            int lenght1 = lenght(ptr_s1) + 1;
            char* ptr_new_s = new char[lenght1];
            while (*ptr_new_s++ = *ptr_s1++);
            ptr_new_s -= lenght1;
            return ptr_new_s;
        }
        if (0 != ptr_s2)
        {
            int lenght2 = lenght(ptr_s2) + 1;
            char* ptr_new_s = new char[lenght2];
            while (*ptr_new_s++ = *ptr_s2++);
            ptr_new_s -= lenght2;
            return ptr_new_s;
        }
        return 0;
    }
    char* combine(const char* ptr_s, const char c)
    {
        if (0 != ptr_s)
        {
            int l = lenght(ptr_s);
            char* ptr_new_s = new char[l + 2];
            while (*ptr_new_s++ = *ptr_s++);
            ptr_new_s -= 1;
            *ptr_new_s++ = c;
            *ptr_new_s = 0;
            ptr_new_s -= (l + 1);
            return ptr_new_s;
        }
        if (0 != c)
        {
            char* ptr_new_s = new char[2];
            ptr_new_s[0] = c;
            ptr_new_s[1] = 0;
            return ptr_new_s;
        }
        return 0;
    }
    char* combine(const char c, const char* ptr_s)
    {
        if (0 != ptr_s)
        {
            int l = lenght(ptr_s);
            char* ptr_new_s = new char[l + 2];
            while (*ptr_new_s++ = *ptr_s++);
            ptr_new_s -= 1;
            *ptr_new_s++ = c;
            *ptr_new_s = 0;
            ptr_new_s -= (l + 1);
            return ptr_new_s;
        }
        if (0 != c)
        {
            char* ptr_new_s = new char[2];
            ptr_new_s[0] = c;
            ptr_new_s[1] = 0;
            return ptr_new_s;
        }
        return 0;
    }
    char* combine(const char c1, const char c2)
    {
        if (0 != c1 && 0 != c2)
        {
            char* ptr_new_s = new char[3];
            ptr_new_s[0] = c1;
            ptr_new_s[1] = c2;
            ptr_new_s[2] = 0;
            return ptr_new_s;
        }
        if (0 != c1)
        {
            char* ptr_new_s = new char[2];
            ptr_new_s[0] = c1;
            ptr_new_s[1] = 0;
            return ptr_new_s;
        }
        if (0 != c2)
        {
            char* ptr_new_s = new char[2];
            ptr_new_s[0] = c2;
            ptr_new_s[1] = 0;
            return ptr_new_s;
        }
        return 0;
    }
    char* reduction(char* ptr_s)
    {
        if (!ptr_s) return 0;

        int l = lenght(ptr_s) + 1;
        char* ptr_new_s = new char[l];
        while (*ptr_new_s++ = *ptr_s++);
        ptr_new_s -= l;
        return ptr_new_s;
    }
    char* copy(const char* ptr_s)
    {
        if (!ptr_s) return 0;

        int l = lenght(ptr_s);
        char* new_ptr_s = new char[l + 1];
        while (*new_ptr_s++ = *ptr_s++);
        *new_ptr_s = 0;
        new_ptr_s -= (l + 1);
        return new_ptr_s;
    }
    char* reader()
    {
        char* str = 0;
        char* old_str = 0;
        char temp = '\0';
        while (true)
        {
            std::cin.get(temp);
            if ('\n' == temp) break;
            if (0 != temp)
            {
                old_str = str;
                str = combine(str, temp);
                delete[] old_str;
            }
            else std::cout << "Error: temp is NULL" << std::endl;
        }
        return str;
    }

    int vec_lenght(char** pptr)
    {
        if (!pptr) return 0;
        int lenght = 0;
        while (*pptr++) lenght++;
        return lenght;
    }
    char** vec_append(char** pptr, char* str)
    {
        if (0 != pptr && 0 != str)
        {
            int lenght_vector = vec_lenght(pptr);
            char** new_pptr = new char* [lenght_vector + 2];
            while (*new_pptr++ = copy(*pptr++));
            new_pptr -= 1;
            *new_pptr++ = copy(str);
            *new_pptr = 0;
            new_pptr -= (lenght_vector + 1);
            return new_pptr;
        }
        if (0 == pptr && 0 != str)
        {
            char** new_pptr = new char* [2];
            *new_pptr = copy(str);
            *++new_pptr = 0;
            new_pptr -= 1;
            return new_pptr;
        }
        if (0 != pptr && 0 == str)
        {
            int lenght_vector = vec_lenght(pptr);
            char** new_pptr = new char* [lenght_vector + 1];
            while (*new_pptr++ = *pptr++);
            *new_pptr = 0;
            new_pptr -= (lenght_vector + 1);
            return new_pptr;
        }
        return 0;
    }
    void vec_delete(char**& pptr_str_vec)
    {
        if (0 == pptr_str_vec)
        {
            delete[] pptr_str_vec;
            return;
        }
        int lenght_str_vec = vec_lenght(pptr_str_vec);
        for (int i = 0; i < lenght_str_vec; i++)
        {
            delete[] pptr_str_vec[i];
        }
        delete[] pptr_str_vec[lenght_str_vec];
        delete[] pptr_str_vec;
    }
}
namespace convert
{
    bool _double(char* ptr_v, double& value)
    {
        if (!ptr_v) return false;

        const int START_ASCII_NUM = (int)'0';
        const int END_ASCII_NUM = (int)'9';
        const int DOT_ASCII = int('.');
        const int NEGATIVE_ASCII = int('-');

        double total_value = 0;
        int lenght = str::lenght(ptr_v);
        bool negative = false;
        bool dot = false;
        int int_deep = 0;
        int float_deep = 0;
        int curr_int_value = 0;
        int curr_float_value = 0;
        char curr_char = '\0';

        for (int i = 0; i < lenght; i++)
        {
            curr_char = *ptr_v++;
            if (!((curr_char >= START_ASCII_NUM && curr_char <= END_ASCII_NUM) || DOT_ASCII == curr_char || NEGATIVE_ASCII == curr_char))
                return false;

            if (NEGATIVE_ASCII == curr_char && true == negative)
                return false;
            if (NEGATIVE_ASCII == curr_char && 0 == int_deep && 0 == float_deep && false == negative)
                negative = true;

            if (DOT_ASCII == curr_char && true == dot)
                return false;
            if (DOT_ASCII == curr_char && 0 == float_deep && false == dot)
                dot = true;

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
    bool _int(char* ptr_v, int& value)
    {
        if (!ptr_v) return false;

        const int START_ASCII_NUM = (int)'0';
        const int END_ASCII_NUM = (int)'9';
        const int NEGATIVE_ASCII = int('-');

        int total_value = 0;
        int lenght = str::lenght(ptr_v);
        bool negative = false;
        int int_deep = 0;
        int curr_int_value = 0;
        char curr_char = '\0';

        for (int i = 0; i < lenght; i++)
        {
            curr_char = *ptr_v++;
            if (!((curr_char >= START_ASCII_NUM && curr_char <= END_ASCII_NUM) || NEGATIVE_ASCII == curr_char))
                return false;

            if (NEGATIVE_ASCII == curr_char && true == negative)
                return false;
            if (NEGATIVE_ASCII == curr_char && 0 == int_deep && false == negative)
                negative = true;

            if (curr_char >= START_ASCII_NUM && curr_char <= END_ASCII_NUM)
            {
                total_value = total_value * 10 + (curr_char - START_ASCII_NUM);
                int_deep++;
            }
        }
        if (negative) total_value *= (-1);
        value = total_value;

        return true;
    }
}
namespace vec_int
{
    int* copy(const int* ptr, int len)
    {
        int* new_ptr = new int[len];
        for (int i = 0; i < len; i++) new_ptr[i] = ptr[i];
        return new_ptr;
    }
    int* append(const int* ptr, const int v, int old_len)
    {
        if (nullptr != ptr && 0 < old_len)
        {
            int* new_ptr = new int[old_len + 1];
            for (int i = 0; i < old_len; i++) new_ptr[i] = ptr[i];
            new_ptr[old_len] = v;
            return new_ptr;
        }
        int* new_ptr = new int[1];
        new_ptr[0] = v;
        return new_ptr;
    }
    void display(const int* ptr, int len)
    {
        if (nullptr == ptr) return;
        for (int i = 0; i < len; i++)
            std::cout << ptr[i] << std::endl;
    }
}

template <typename T> T reader(T ud)
{
    if (std::cin >> ud)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ud;
    }
    else
    {
        std::cout << "Error: incorrect input" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return reader<T>(ud);
    }
}
template <typename T> T reader()
{
    T ud = 0;
    if (std::cin >> ud)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ud;
    }
    else
    {
        std::cout << "Error: incorrect input" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return reader<T>(ud);
    }
}
char* reader(char* ud)
{
    return str::reader();
}
char* reader()
{
    return str::reader();
}

int nod(int a, int b)
{
    while (true)
    {
        if (0 == a || 0 == b) return a + b;
        if (a > b) a = a % b;
        else b = b % a;
    }
}
void task1()
{
    const char TASK_TEXT[] =
        "\t<Zadacha 1> Algoritm Evklida\n"
        "\tProgramma ischet NOD (naibolshii obschii delitel) dlya dvyh tselih chisel a i b";
    std::cout << TASK_TEXT << std::endl;

    int a = 0, b = 0;
    char* str_user_value = 0;
    std::cout << "\tVvedite chislo a ";
    while (true)
    {
        std::cout << ">> ";
        str_user_value = reader();
        if (!convert::_int(str_user_value, a) || 0 >= a)
        {
            std::cout << "!!!: Necorrectnoye chislo!\n\t";
            continue;
        }
        else break;
    }
    std::cout << "\tVvedite chislo b";
    while (true)
    {
        std::cout << " >> ";
        str_user_value = reader();
        if (!convert::_int(str_user_value, b) || 0 >= b)
        {
            std::cout << "!!!: Necorrectnoye chislo!\n\t";
            continue;
        }
        else break;
    }
    delete[] str_user_value;

    int n = nod(a, b);
    std::cout << "\tNOD = " << n << std::endl;
    return;
}
void task2()
{
    const char TASK_TEXT[] =
        "\t<Zadacha 2> Resheto Eratosfena\n"
        "\tProgramma ischet vse prostiye chisla ot 1 do n i vovit ih";
    std::cout << TASK_TEXT << std::endl;

    int n = 0;
    char* str_user_value = 0;
    std::cout << "\tVvedite n ";
    while (true)
    {
        std::cout << ">> ";
        str_user_value = reader();
        if (!convert::_int(str_user_value, n))
        {
            std::cout << "!!!: Necorrectnoye chislo!\n\t";
            continue;
        }
        else if (n < 3) std::cout << "!!!: Necorrectnoye chislo!\n\t";
        else if (n > 100000) std::cout << "!!!: Chislo slishkom bolshoie!\n\t";
        else break;
    }
    delete[] str_user_value;

    bool* ptr_a = new bool[n];
    for (int i = 0; i < n; i++) ptr_a[i] = true;
    ptr_a[0] = false;
    ptr_a[1] = false;
    int m = 2;
    int j = 0;
    while (true)
    {
        if (m < n)
        {
            if (ptr_a[m] != false)
            {
                j = m * 2;
                while (true)
                {
                    if (j < n)
                    {
                        ptr_a[j] = false;
                        j += m;
                    }
                    else break;
                }
            }
            m++;
        }
        else break;
    }
    int count_prime_numbers = 0;
    for (int i = 0; i < n; i++)
        if (true == ptr_a[i]) count_prime_numbers++;

    int* ptr_prime_numbers = new int[count_prime_numbers];
    int k = 0;
    for (int i = 0; i < n; i++)
        if (true == ptr_a[i]) ptr_prime_numbers[k++] = i;
    delete[] ptr_a;

    std::cout << "\tVse prostiye chisla na otrezke [0, " << n << "]:";
    int q = 0;
    for (int i = 0; i < k; i++)
    {
        if (0 == q++ % 8) std::cout << '\n';
        std::cout << "\t" << ptr_prime_numbers[i];
        if (i != k - 1) std::cout << ",";
    }
    delete[] ptr_prime_numbers;
    std::cout << std::endl;
    return;
}
void task3()
{
    const char TASK_TEXT[] =
        "\t<Zadacha 3.14> Dobavleniye texta v konets faila\n"
        "\tProgramma zaprashivaiet fail dlya redactirovaniya, zatem osuschestvlyaet zapis v nego\n"
        "\tDlya vihoda iz programmi vvedite -end";
    std::cout << TASK_TEXT << std::endl;

    const char COMMAND_END[] = "-end";
    char* user_path_file = 0;
    std::ofstream ostream;

    bool select_path_cycle_working = true;
    while (select_path_cycle_working)
    {
        std::cout << "\tVvedite adres faila >> ";
        user_path_file = reader();
        int lenght_user_path_file = str::lenght(user_path_file);
        if (!user_path_file)
        {
            std::cout << "\n!!!: Necorrectnii adres faila!" << std::endl;
            continue;
        }

        if (4 == lenght_user_path_file)
        {
            for (int i = 0; i < 4; i++)
            {
                if (user_path_file[i] == COMMAND_END[i])
                    select_path_cycle_working = false;
                else
                {
                    select_path_cycle_working = true;
                    break;
                }
            }
            if (!select_path_cycle_working)
            {
                delete[] user_path_file;
                return;
            }
        }
        if (std::ifstream(user_path_file))
        {
            ostream.open(user_path_file, std::ios::app);
            if (ostream.is_open())
            {
                std::cout << "\t>> Uspeshnoye otkritiye: " << user_path_file << std::endl;
                break;
            }
            else std::cout << "!!!: Necorrectnii adres faila!" << std::endl;
        }
        else std::cout << "!!!: Necorrectnii adres faila!" << std::endl;
    }
    delete[] user_path_file;

    std::cout << "\tZapis osuschestvlyaetsya v konets faila.\n"
        "\tDlya zaversheniya redactirovaniya vvedite -end" << std::endl;

    char* user_text = 0;
    int lenght_user_text = 0;
    bool cycle_working = true;

    while (cycle_working)
    {
        std::cout << "\t> ";
        char* user_text = reader();
        if (!user_text)
        {
            std::cout << "!!!: Oshibka bufera stroki!" << std::endl;
            continue;
        }
        lenght_user_text = str::lenght(user_text);

        if (4 == lenght_user_text)
        {
            for (int i = 0; i < 4; i++)
            {
                if (user_text[i] == COMMAND_END[i])
                    cycle_working = false;
                else
                {
                    cycle_working = true;
                    break;
                }
            }
            if (!cycle_working)
            {
                ostream.close();
                delete[] user_text;
                return;
            }
        }

        ostream << user_text;
        ostream << '\n';
        if (ostream.good()) std::cout << "<!> Uspeshnaya zapis" << std::endl;
        else
        {
            std::cout << "!!!: blok zapisi povrezhden" << std::endl;
            cycle_working = false;
        }
        delete[] user_text;
        user_text = 0;
    }

    ostream.close();
    return;
}
void task5()
{
    const char TASK_TEXT[] =
        "\t<Zadacha 4.14> Vse unikalniye 4hznachnie chisla\n"
        "\tProgramma vivodit vse 4hznachniye chisla, v kotorih net odinakovih tsifr\n";
    std::cout << TASK_TEXT << std::endl;

    int a[] = { 0, 0, 0, 0 };
    bool different_digit = false;
    bool first_element = false;
    int k = 0;

    for (int i = 1000; i < 10000; i++)
    {
        a[0] = i / 1000;
        a[1] = i % 1000 / 100;
        a[2] = i % 100 / 10;
        a[3] = i % 10;
        different_digit = (a[0] != a[1] && a[0] != a[2] && a[0] != a[3]) && (a[1] != a[2] && a[1] != a[3]) && (a[2] != a[3]);
        if (different_digit)
        {
            first_element = true;
            std::cout << "\t" << i;
            if (0 == ++k % 8) std::cout << "\n";
        }
    }

    std::cout << std::endl;
    return;
}
int word_count(const char* ptr_str)
{
    const char BACKSPACE = ' ';
    char previous_char = '\0';
    int words;
    if (BACKSPACE == *ptr_str) words = 0;
    else words = 1;
    while (*ptr_str)
    {
        if (BACKSPACE == previous_char && BACKSPACE != *ptr_str)
        {
            words++;
        }
        previous_char = *ptr_str;
        ptr_str++;
    }
    return words;
}
void task6()
{
    const char TASK_TEXT[] =
        "\t<Zadacha 4.56> Massiv strok\n"
        "\tProgramma zaproshivaiet stroki dlya massiva, a zatem sortiryiet ego po kolichestvu slov\n";
    std::cout << TASK_TEXT << std::endl;
    std::cout << "\tVvodite stroki. Dlya zaversheniya vvedite -end" << std::endl;

    const char COMMAND_END[] = "-end";
    const int LENGHT_COMMAND_END = str::lenght(COMMAND_END);

    char* user_data = 0;
    char** str_vector = { };
    char** old_str_vector = 0;
    int str_l = 0;
    int word_l = 0;
    int* int_vec = 0;
    int* int_old_vec = 0;
    int int_vec_l = 0;
    bool cycle_working = true;

    while (cycle_working)
    {
        std::cout << "\t> ";
        user_data = reader();
        if (!user_data)
        {
            continue;
        }

        str_l = str::lenght(user_data);
        if (LENGHT_COMMAND_END == str_l)
        {
            for (int i = 0; i < 4; i++)
            {
                if (COMMAND_END[i] == user_data[i]) cycle_working = false;
                else
                {
                    cycle_working = true;
                    break;
                }
            }
        }
        if (!cycle_working)
        {
            delete[] user_data;
            break;
        }

        word_l = word_count(user_data);
        int_old_vec = int_vec;
        int_vec = vec_int::append(int_old_vec, word_l, int_vec_l++);
        delete[] int_old_vec;

        old_str_vector = str_vector;
        str_vector = str::vec_append(str_vector, user_data);
        delete[] old_str_vector;
        delete[] user_data;
    }

    int min = 100000000;
    int k = 0;
    int i, j;
    char* temp;
    for (i = 0; i < int_vec_l - 1; i++)
        for (j = 0; j < int_vec_l - i - 1; j++)
            if (int_vec[j] > int_vec[j + 1])
            {
                std::swap(int_vec[j], int_vec[j + 1]);
                temp = str_vector[j + 1];
                str_vector[j + 1] = str_vector[j];
                str_vector[j] = temp;
            }
    std::cout << "\tSortirovanniye stroki:\n";
    for (int i = 0; i < int_vec_l; i++)
        std::cout << "\t> " << str_vector[i] << std::endl;

    delete[] int_vec;
    delete[] str_vector;
    return;
}
int random_generator(int m, int i, int c, int s = 0)
{
    if (0 == i) return s;
    s = (m * s + i) % c;
    return random_generator(m, --i, c, s);
}
void task7()
{
    const int AMOUNT_OF_NUMBERS = 20;
    const int START_RANDOM_NUMBERS = 0;
    const int END_RANDOM_NUMBERS = 100;

    const int GENERATOR_M = 125;
    const int GENERATOR_I = 10;
    const int GENERATOR_C = 14;

    const char FILE_NAME[] = "chisla.txt";

    std::cout <<
        "\t<Zadacha 5.14> Otrezok odinakovih chisel\n"
        "\tProgramma sozdaiot fail s nazvaniem z514chisla.txt, esli ego net.\n"
        "\tZatem zapisivayet v nego " << AMOUNT_OF_NUMBERS << " slychainih chisel v diapazone ot" 
        << START_RANDOM_NUMBERS << " do " << END_RANDOM_NUMBERS << "\n"
        "\tv kontse budet vivedena dlina otrezka s naibolshim kolichestvom simmetrichih par s nachala i kontsa"
        << std::endl;

    bool generate_new_file;
    if (std::ifstream(FILE_NAME))
    {
        std::cout << "\t>> Fail " << FILE_NAME << " obnaryzhen" << std::endl;
        generate_new_file = false;
    }
    else
    {
        std::cout << "\t>> Fail " << FILE_NAME << " ne naiden. Budet sgenerirovan novii" << std::endl;
        generate_new_file = true;
    }
    if (generate_new_file)
    {
        std::ofstream fout(FILE_NAME);
        if (!fout.is_open())
        {
            std::cout << "!!!: Oshibka sozdaniya faila" << std::endl;
            return;
        }

        int value = 0;
        for (int i = 0; i < AMOUNT_OF_NUMBERS; i++)
        {
            value = random_generator(GENERATOR_M, i + GENERATOR_I, GENERATOR_C);
            value = value % (END_RANDOM_NUMBERS - START_RANDOM_NUMBERS) + START_RANDOM_NUMBERS;
            fout << value << '\n';
        }
        std::cout << "\t!: Fail sgenerirovan" << std::endl;
        fout.close();
    }

    std::ifstream fin(FILE_NAME);
    int cval;
    int* v = 0;
    int* old_v = 0;
    int len = 0;
    while (fin >> cval)
    {
        old_v = v;
        v = vec_int::append(v, cval, len++);
        delete[] old_v;
    }

    int s_max_deep = 0;
    int start_max_deep = 0;
    int curr_deep = 0;
    int curr_number = 0;
    int max_curr_value = 0;
    bool same_numbers = false;
    for (int i = 0; i < len; i++)
    {
        int max_deep = len - (i % 2) - 1;
        for (int j = max_deep; j > i; j -= 2)
        {
            if (v[i] == v[j])
            {
                same_numbers = true;
                curr_deep++;
                for (int k = 1; k < (j - i) / 2 + 1; k++)
                {
                    if (v[i + k] == v[j - k])
                    {
                        curr_deep++;
                        same_numbers = true;
                    }
                    else
                    {
                        same_numbers = false;
                        break;
                    }
                }
                if (same_numbers)
                {
                    if (curr_deep > s_max_deep)
                    {
                        s_max_deep = curr_deep;
                        start_max_deep = i;
                    }
                }
            }
            else same_numbers = false;
            curr_deep = 0;
        }
    }
    if (s_max_deep)
    {
        std::cout << "\tDlina otrezka: " << s_max_deep * 2 << std::endl;
        std::cout << "\tIskomii otrezok:" << std::endl;
        for (int i = start_max_deep; i < start_max_deep + s_max_deep * 2; i++)
        {
            std::cout << "\t" << v[i] << std::endl;
        }
    }
    else std::cout << "\tOtrezok ne naiden" << std::endl;

    delete[] v;
}

int main()
{
    std::cout << "Viberite zadachy:\n"
        "1. Algoritm Evklida\n"
        "2. Resheto Eratosfena\n"
        "3. Dobavleniye texta v konets faila\n"
        "5. Vse unikalniye 4hznachnie chisla\n"
        "6. Massiv strok\n"
        "7. Otrezok odinakovih chisel\n"
        "Dlya vihoda vvedite inoe znacheniye."
        << std::endl;

    int u;
    char* str_user_choose = 0;
    bool cycle_working = true;
    while (cycle_working)
    {
        std::cout << ">> ";
        u = reader<int>();

        switch (u)
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
            case 5:
                task5();
                break;
            case 6:
                task6();
                break;
            case 7:
                task7();
                break;
            default:
                cycle_working = false;
                break;
        }
    }

    return 0;
}