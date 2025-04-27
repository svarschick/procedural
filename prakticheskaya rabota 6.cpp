#include <iostream>
#include <math.h>

namespace str
{
    int   lenght(const char* p_str);
    char* copy(const char* p_str);
    char* reduction(char* p_str);
    char* reverse(const char* p_str);
    char* reader();
    char* combine(const char* p_str1, const char* p_str2);
    char* combine(const char* p_str, const char c);
    char* combine(const char c, const char* p_str);
    char* combine(const char c1, const char c2);
    bool  equal(const char* p_str1, const char* p_str2);
    bool  equal(const char* p_str, const char c);
    bool  equal(const char c, const char* p_str);
    int   find(const char* p_str, const char* p_search_str);
    int   find(const char* p_str, const char c);
    int   find(const char c, const char* p_str);
    char* substring(const char* p_str, int begin, int end);
    char* replace(const char* p_str, const char find, const char change);
}
int   str::lenght(const char* ptr_s)
{
    if (nullptr != ptr_s)
    {
        int lenght = 0;
        while (*ptr_s++) lenght++;
        return lenght;
    }
    else return 0;
}
char* str::combine(const char* ptr_s1, const char* ptr_s2)
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
char* str::combine(const char* ptr_s, const char c)
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
char* str::combine(const char c, const char* ptr_s)
{
    if (0 != ptr_s)
    {
        int l = lenght(ptr_s);
        char* ptr_new_s = new char[l + 2];
        *ptr_new_s++ = c;
        while (*ptr_new_s++ = *ptr_s++);
        ptr_new_s -= (l + 2);
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
char* str::combine(const char c1, const char c2)
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
bool  str::equal(const char* ptr_s1, const char* ptr_s2)
{
    if (nullptr == ptr_s1 && nullptr == ptr_s2) return true;
    if (nullptr == ptr_s1 || nullptr == ptr_s2) return false;

    int len1 = lenght(ptr_s1);
    int len2 = lenght(ptr_s2);
    if (len1 != len2) return false;

    for (int i = 0; i < len1; i++)
        if (*ptr_s1++ != *ptr_s2++)
            return false;
    return true;
}
bool  str::equal(const char* ptr_s, const char c)
{
    if (nullptr == ptr_s) return false;

    if (1 != lenght(ptr_s)) return false;
    if (c != ptr_s[0]) return false;
    return true;
}
bool  str::equal(const char c, const char* ptr_s)
{
    if (nullptr == ptr_s) return false;

    if (1 != lenght(ptr_s)) return false;
    if (c != ptr_s[0]) return false;
    return true;
}
char* str::reduction(char* ptr_s)
{
    if (!ptr_s) return nullptr;

    int l = lenght(ptr_s) + 1;
    char* ptr_new_s = new char[l];
    while (*ptr_new_s++ = *ptr_s++);
    ptr_new_s -= l;
    return ptr_new_s;
}
char* str::copy(const char* ptr_s)
{
    if (!ptr_s) return nullptr;

    int l = lenght(ptr_s);
    char* new_ptr_s = new char[l + 1];
    while (*new_ptr_s++ = *ptr_s++);
    new_ptr_s -= (l + 1);
    return new_ptr_s;
}
char* str::reverse(const char* ptr_s)
{
    if (nullptr == ptr_s) return nullptr;

    int len = lenght(ptr_s);
    char* temp_s = new char[len + 1];
    char* new_s = new char[len + 1];
    while (*temp_s++ = *ptr_s++);
    ptr_s -= len + 1;
    temp_s -= 2;
    for (int i = len; i > 0; i--) 
        *new_s++ = *temp_s--;
    *new_s = '\0';
    new_s -= len;
    delete[] ++temp_s;
    return new_s;
}
char* str::reader()
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
int   str::find(const char* ptr_s, const char* ptr_v)
{
    if (nullptr == ptr_s || nullptr == ptr_v) return -1;

    int len_s = lenght(ptr_s);
    int len_v = lenght(ptr_v);
    bool same = false;
    for (int i = 0; i < len_s; i++)
    {
        if (ptr_s[i] == ptr_v[0] && len_s - i >= len_v)
        {
            for (int j = 0; j < len_v; j++)
            {
                if (ptr_s[i + j] == ptr_v[j])
                {
                    same = true;
                }
                else
                {
                    same = false;
                    break;
                }
            }
            if (same) return i;
        }
    }
    return -1;
}
int   str::find(const char* ptr_s, const char c)
{
    if (nullptr == ptr_s || 0 == c) return -1;

    int index = 0;
    while (*ptr_s)
    {
        if (c == *ptr_s++) return index;
        else index++;
    }
    return -1;
}
int   str::find(const char c, const char* ptr_s)
{
    if (nullptr == ptr_s || 0 == c) return -1;

    int index = 0;
    while (*ptr_s)
    {
        if (c == *ptr_s++) return index;
        else index++;
    }
    return -1;
}
char* str::substring(const char* p_str, int begin, int end)
{
    if (nullptr == p_str) return nullptr;
    
    int l = lenght(p_str);
    if (begin > end || end > l || 0 > begin || 0 > end)
        throw "Bad index for substring!";

    char* new_ptr = new char[end - begin + 1];
    for (int i = begin; i < end; i++)
    {
        new_ptr[i - begin] = p_str[i];
    }
    new_ptr[end - begin] = '\0';
    return new_ptr;
}
char* str::replace(const char* p_str, const char find, const char change)
{
    if (nullptr == p_str || '\0' == find || '\0' == change) return nullptr;

    int l = lenght(p_str);
    char* prev;
    char* future;
    char* new_ptr;
    for (int i = 0; i < l; i++)
    {
        if (find == p_str[i])
        {
            prev = substring(p_str, 0, i);
            new_ptr = str::combine(prev, change);
            char* tmp = new_ptr;
            future = substring(p_str, i + 1, l);
            new_ptr = str::combine(tmp, future);
            delete[] tmp;
            delete[] prev;
            delete[] future;
            return new_ptr;
        }
    }

    return nullptr;
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
    template <typename T> char* tostr_whole_num(T v)
    {
        const int ASCII_DIGIT = 48;
        char* result = 0;
        char* temp = 0;
        int digit = 0;
        bool negative = false;
        if (0 > v)
        {
            v *= -1;
            negative = true;
        }
        do
        {
            digit = v % 10;
            v /= 10;
            temp = result;
            result = str::combine(char(digit + ASCII_DIGIT), result);
            delete[] temp;
        } while (v);

        if (negative)
        {
            temp = result;
            result = str::combine('-', result);
            delete[] temp;
        }
        return result;
    }
    char* tostr_double(double v)
    {
        const int ASCII_DIGIT = 48;
        const double E = 0.1;
        char* result = 0;
        char* temp = 0;
        bool negative = false;
        if (0 > v)
        {
            v *= -1;
            negative = true;
        }
        long long whole_part = static_cast<double>(v);
        double float_part = v - whole_part;
        if (0 != float_part)
        {
            long long f_part = 0;
            while (fabs(f_part - float_part) > E)
            {
                float_part *= 10;
                f_part = static_cast<long long>(float_part);
            }

            result = str::combine(tostr_whole_num<long long>(whole_part), '.');
            temp = result;
            result = str::combine(result, tostr_whole_num<long long>(f_part));
            delete[] temp;
            if (negative)
            {
                temp = result;
                result = str::combine('-', result);
                delete[] temp;
            }
            return result;
        }
        else
        {
            if (negative) 
                result = str::combine('-', tostr_whole_num<long long>(whole_part));
            else 
                return tostr_whole_num<long long>(whole_part);
        }
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

int random_generator(int m, int i, int c, int s = 0)
{
    if (0 == i) return s;
    s = (m * s + i) % c;
    return random_generator(m, --i, c, s);
}
int random_sign(int m, int i, int c, int s = 0)
{
    int v = random_generator(m, --i, c);
    if (0 == v % 2) return -1;
    else return 1;
}
void task1()
{
    const int GEN_M = 135;
    const int GEN_I = 17;
    const int GEN_C = 14;

    std::cout << "\t<Zadacha 58> Summa elementov matritsi\n"
        "\tProgramma sgeneriryiet kvadratnyiu matritsy i naidet summy elementov v stroke, esli na\n"
        "\tglavnoi diagonali element menshe nulya" << std::endl;

    int n = random_generator(GEN_M, GEN_I, GEN_C) % 40;
    std::cout << "\t> Poryadok matritsi: n = " << n << std::endl;
    int** pptr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        pptr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pptr[i][j] = random_generator(GEN_M, GEN_I * (i + 1) * (j + 1), GEN_C) * random_sign(GEN_M + j, GEN_I + i + j, GEN_C + i);

    std::cout << "\tSgenerirovannaya matritsa:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "\t";
        for (int j = 0; j < n; j++)
            std::cout << pptr[i][j] << "\t";
        std::cout << std::endl;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (0 > pptr[i][i]) {
            for (int j = 0; j < n; j++)
                sum += pptr[i][j];
            std::cout << "\tsumma " << i + 1 << " stroki = " << sum << std::endl;
            sum = 0;
        }
    }

    for (int i = 0; i < n; i++)
        delete[] pptr[i];
    delete[] pptr;
}
namespace cplex
{
    struct Complex
    {
        double real;
        double imagine;
    };

    Complex plus(const Complex& cplex1, const Complex& cplex2)
    {
        return { cplex1.real + cplex2.real, cplex1.imagine + cplex2.imagine };
    }
    Complex plus(const Complex& cplex, const double v)
    {
        return { cplex.real + v, cplex.imagine };
    }
    Complex plus(const double v, const Complex& cplex)
    {
        return { cplex.real + v, cplex.imagine };
    }
    Complex plus(const double v1, const double v2)
    {
        return { v1 + v2, 0 };
    }
    Complex munis(const Complex& cplex1, const Complex& cplex2)
    {
        return { cplex1.real - cplex2.real, cplex1.imagine - cplex2.imagine };
    }
    Complex munis(const Complex& cplex, const double v)
    {
        return { cplex.real - v, cplex.imagine };
    }
    Complex munis(const double v, const Complex& cplex)
    {
        return { cplex.real - v, cplex.imagine };
    }
    Complex munis(const double v1, const double v2)
    {
        return { v1 - v2, 0 };
    }
    Complex multi(const Complex& cplex1, const Complex& cplex2)
    {
        return { cplex1.real * cplex2.real - cplex1.imagine * cplex2.imagine, cplex1.real * cplex2.imagine + cplex2.real * cplex1.imagine };
    }
    Complex multi(const Complex& cplex, const double v)
    {
        return { cplex.real * v, cplex.imagine * v };
    }
    Complex multi(const double v, const Complex& cplex)
    {
        return { cplex.real * v, cplex.imagine * v };
    }
    Complex multi(const double v1, const double v2)
    {
        return { v1 * v2, 0 };
    }
    Complex div(const Complex& cplex1, const Complex& cplex2)
    {
        double d = cplex2.real * cplex2.real + cplex2.imagine * cplex2.imagine;
        if (0 != d)
        {
            Complex cplex2_conjugate = { cplex2.real, cplex2.imagine * (-1) };
            Complex temp = multi(cplex1, cplex2_conjugate);
            temp.real /= d;
            temp.imagine /= d;
            return temp;
        }
        else
        {
            std::cout << "!: division by zero";
            return { 0, 0 };
        }
    }
    Complex div(const Complex& cplex, const double v)
    {
        if (0 != v)
        {
            return { cplex.real / v, cplex.imagine / v };
        }
        else
        {
            std::cout << "!: division by zero";
            return { 0, 0 };
        }
    }
    Complex div(const double v, const Complex& cplex)
    {
        if (0 != cplex.real && 0 != cplex.imagine)
        {
            return { v / cplex.real, v / cplex.imagine };
        }
        else
        {
            std::cout << "!: division by zero";
            return { 0, 0 };
        }
    }
    Complex div(const double v1, const double v2)
    {
        if (0 != v2)
        {
            return { v1 / v2, 0 };
        }
        else
        {
            std::cout << "!: division by zero";
            return { 0, 0 };
        }
    }

    template <typename T> Complex to_complex(const T real, const T imagine)
    {
        return { static_cast<double>(real), static_cast<double>(imagine) };
    }
    char* to_str(const Complex& cplex)
    {
        char* result = 0;
        char* temp = 0;
        if (0 != cplex.imagine)
        {
            result = str::combine(convert::tostr_double(cplex.real), " + ");
            temp = result;
            result = str::combine(result, convert::tostr_double(cplex.imagine));
            delete[] temp;
            temp = result;
            result = str::combine(result, 'i');
            delete[] temp;
            return result;
        }
        else return convert::tostr_double(cplex.real);
    }
    void display(const Complex& cplex)
    {
        std::cout << cplex.real << " + " << cplex.imagine << "i";
    }
}
void task2()
{
    const int GEN_M = 135;
    const int GEN_I = 17;
    const int GEN_C = 14;

    std::cout << "\t<Zadacha 76> Complexsniye chisla\n"
        "\tProgramma vipolnyaiet zadannie operatsii nad complexksnimy chislamy" << std::endl;

    double u1 = 4.24;
    double u2 = 7.12;
    double v1 = -5.3;
    double v2 = 9;
    double w1 = -10.725;
    double w2 = 0;

    using cplex::Complex;
    Complex u = { u1, u2 };
    Complex v = { v1, v2 };
    Complex w = { w1, w2 };

    std::cout << "\tDano: \n";
    std::cout << "\tu {u1, u2} = " << cplex::to_str(u) << '\n';
    std::cout << "\tv {v1, v2} = " << cplex::to_str(v) << '\n';
    std::cout << "\tw {w1, w2} = " << cplex::to_str(w) << '\n';

    Complex temp1 = cplex::multi(2, u);
    Complex temp2 = cplex::multi(cplex::multi(3, u), w);
    Complex temp3 = cplex::plus(2, cplex::munis(w, v));
    Complex total = cplex::div(temp2, temp3);
    total = cplex::plus(temp1, total);
    total = cplex::munis(total, 7);

    std::cout << "\tVirazheniye: 2u + 3uw / (2 + w - v) - 7 = ";
    cplex::display(total);
    std::cout << std::endl;
}
void findway(int** matrix, int sum, int n, int m, const int max_n, const int max_m, int& min_sum, char* trace, char** best_trace)
{
    char* strn = convert::tostr_whole_num<int>(n + 1);
    char* strm = convert::tostr_whole_num<int>(m + 1);
    char* curr_way = str::combine(strn, ",\t");
    char* t = curr_way;
    curr_way = str::combine(curr_way, strm);
    delete[] t;
    t = curr_way;
    curr_way = str::combine(curr_way, "\n");
    delete[] t;
    trace = str::combine(trace, curr_way);
    delete[] curr_way;
    delete[] strn;
    delete[] strm;

    if (max_n == n && max_m == m)
    {
        sum = sum + matrix[n][m];
        if (min_sum > sum)
        {
            min_sum = sum;
            delete[] *best_trace;
            *best_trace = str::copy(trace);
        }
        return;
    }
    if (max_n < n)
    {
        delete[] trace;
        return;
    }
    if (max_m < m)
    {
        delete[] trace;
        return;
    }
    char* way1 = str::copy(trace);
    findway(matrix, sum + matrix[n][m], n + 1, m, max_n, max_m, min_sum, way1, best_trace);
    char* way2 = str::copy(trace);
    findway(matrix, sum + matrix[n][m], n, m + 1, max_n, max_m, min_sum, way2, best_trace);
    delete[] trace;
}
void task4()
{
    const int GEN_M = 29;
    const int GEN_I = 17;
    const int GEN_C = 14;

    std::cout << "\t<Zadacha 86> Poisk puty\n"
        "\tProgramma ischet naimenenshyiy summy puty v sgenerirovannoi matritse" << std::endl;

    int n = 6;
    int m = 5;
    std::cout << "\t> n = " << n << " ; m = " << m << std::endl;
    int** pptr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        pptr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            pptr[i][j] = random_generator(GEN_M * (i + j + 1), GEN_I * (i + 1) * (j + 1), GEN_C) * random_sign(GEN_M + j, GEN_I + i + j, GEN_C + i);

    std::cout << "\tSgenerirovannaya matritsa:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "\t";
        for (int j = 0; j < m; j++)
            std::cout << pptr[i][j] << "\t";
        std::cout << std::endl;
    }

    int* vec = 0;
    int len_vec = 0;
    int min_sum = 1000000;
    char* trace = 0;
    char* best_trace = 0;
    findway(pptr, 0, 0, 0, n - 1, m - 1, min_sum, trace, &best_trace);
    std::cout << "Minimalnanya summa = " << min_sum << std::endl;
    std::cout << "Marshrut:\nn,\tm\n" << best_trace << std::endl;

    for (int i = 0; i < n; i++)
    {
        delete[] pptr[i];
    }
    delete[] pptr;
    delete[] vec;
}

struct v_int
{
private:
    int size;
    int* ptr;
public:
    v_int()
    {
        size = 0;
        ptr = nullptr;
    }
    v_int(const int* p, const int s)
    {
        size = s;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
            ptr[i] = p[i];
    }
    ~v_int()
    {
        if (size > 0 && 0 != ptr)
        {
            size = 0;
            delete[] ptr;
            ptr = 0;
        }
    }

    v_int copy()
    {
        return { ptr, size };
    }
    int lenght()
    {
        return size;
    }
    void append(int uvalue)
    {
        int* new_ptr = new int[size + 1];
        for (int i = 0; i < size; i++)
            new_ptr[i] = ptr[i];
        new_ptr[size] = uvalue;
        delete[] ptr;
        size += 1;
        ptr = new_ptr;
    }
    void del()
    {
        int* new_ptr = new int[size - 1];
        for (int i = 0; i < size - 1; i++)
            new_ptr[i] = ptr[i];
        delete[] ptr;
        size -= 1;
        ptr = new_ptr;
    }
    void display()
    {
        std::cout << "[";
        for (int i = 0; i < size; i++)
            if (size - 1 > i)
                std::cout << ptr[i] << ", ";
            else
                std::cout << ptr[i];
        std::cout << "]" << std::endl;
    }
    int& operator[](int i)
    {
        if (size < i)
            throw "Error: index is out of range!";
        if (0 > i)
        {
            i = size + i;
            if (0 > i)
                throw "Error: index is out of range!";
        }
        return ptr[i];
    }
    v_int& operator= (const v_int& v)
    {
        if (this == &v)
            return *this;

        if (0 < v.size && nullptr != v.ptr)
        {
            size = v.size;
            delete[] ptr;
            ptr = new int[size];
            for (int i = 0; i < size; i++)
                ptr[i] = v.ptr[i];
        }
        else
        {
            delete[] ptr;
            ptr = nullptr;
            size = 0;
        }
        return *this;
    }
};
namespace t3
{
    double fplus(const double a, const double b)
    {
        return a + b;
    }
    double fminus(const double a, const double b)
    {
        return a - b;
    }
    double fmulti(const double a, const double b)
    {
        return a * b;
    }
    double fdiv(const double a, const double b)
    {
        if (0 == b)
            throw "!: division by zero!";
        return a / b;
    }
    char get_operator(v_int& vec, int i)
    {
        switch (vec[i])
        {
            case 0: return '+';
            case 1: return '-';
            case 2: return '*';
            case 3: return '/';
            default: break;
        }
    }
    void display_equation(v_int& vec)
    {
        const int ASCII_DIGIT_START = 48;
        char equation[] = "((((1 ? 2) ? 3) ? 4) ? 5) ? 6";
        char* correct_equation = str::copy(equation);
        char* tmp = correct_equation;
        for (int i = 0; i < vec.lenght(); i++)
        {
            tmp = correct_equation;
            correct_equation = str::replace(tmp, '?', get_operator(vec, i));
            delete[] tmp;
        }
        std::cout << correct_equation;
        delete[] correct_equation;
    }
    typedef double (*f) (const double, const double);
    void enumeration(v_int& v, const double aim_value, v_int& trace, double prev_value = 1, int k = 0)
    {
        static f func[] = { fplus , fminus, fmulti, fdiv };

        double curr_value;
        if (v.lenght() - 1 == k && aim_value == prev_value)
        {
            display_equation(trace);
            std::cout << " = " << prev_value << std::endl;
            return;
        }
        else if (v.lenght() - 1 == k) return;
        for (int i = 0; i < 4; i++)
        {
            trace.append(i);
            double d = v[k + 1];
            curr_value = func[i](prev_value, d);
            v_int tmp = trace.copy();
            enumeration(v, aim_value, tmp, curr_value, k + 1);
            trace.del();
        }
    }
    void task3()
    {
        std::cout << "\t<Zadacha 81> 1000 - 7 ?\n"
            "\tProgramma ischet kombinatsiiy arifmeticheskih operatsii +, -, *, /\n"
            "\tdlya zameni ih v virazhenii: ((((1 ? 2) ? 3) ? 4) ? 5) ? 6 tak, chobi resultat bil raven 35" << std::endl;
        v_int strace = {};
        int v[] = { 1, 2, 3, 4, 5, 6 };
        int size = sizeof(v) / sizeof(v[0]);
        v_int vec_int = { v, size };
        enumeration(vec_int, 35, strace);
    }
}
namespace t5
{
    v_int start_v_int(int N)
    {
        v_int v;
        v.append(1);
        v.append(N - 1);
        return v;
    }
    bool display_combination(v_int& v, const int K)
    {
        int l = v.lenght();
        if (K == 0 || K == l)
        {
            std::cout << '\t';
            for (int i = 0; i < l; i++)
                if (i < l - 1)
                    std::cout << v[i] << " + ";
                else
                    std::cout << v[i];
            std::cout << std::endl;
            return true;
        }
        else return false;
    }
    bool check_sequence(v_int& v)
    {
        int l = v.lenght();
        for (int i = 0; i < l; i++)
            if (0 >= v[i])
                return false;
        return true;
    }
    bool generate_sequence(v_int& v, int j, int d, const int K)
    {
        int u;
        bool display = false;
        
        for (int i = 0; i < j; i++)
        {
            if (1 == d)
            {
                display = display_combination(v, K);
                v[1] = v[1] - d;
                v.append(d);
            }
            else
            {
                v[1] = v[1] - d;
                if (check_sequence(v))
                {
                    v.append(d);
                    display = display_combination(v, K);
                }
            }
        }
        return display;
    }
    void perestanovka(int N, int K)
    {
        v_int v = start_v_int(N);
        v_int backup = v.copy();
        v_int tmp;
        int d = 1;
        bool gs = false;
        for (int d = 1; d < N / 2; d++)
        {
            v = backup.copy();
            for (int i = 0; i < N / 2; i++)
            {
                if (v[0] < d)
                {
                    v[0] = v[0] + 1;
                    v[1] = v[1] - 1;
                    continue;
                }
                tmp = v.copy();
                int j = N - i * 2 - 1;
                gs = generate_sequence(tmp, j, d, K);
                v[0] = v[0] + 1;
                v[1] = v[1] - 1;
            }
            if (gs) std::cout << std::endl;
        }
    }
    void task5()
    {
        std::cout << "\t<Zadacha 91> Vse summy chisla\n"
            "\tProgramma ischet vse vozmozhiye summy chisla N iz K slogaemih\n" 
            "\tEsli K = 0, to budut vivedeni vse vozmozhiye summy" << std::endl;

        int N, K;
        while (true)
        {
            std::cout << "\tVvedite N >> ";
            N = reader<int>();
            if (N > 100)
            {
                std::cout << "Slishkom bolshoie chislo!" << std::endl;
            }
            if (4 > N)
            {
                std::cout << "Chislo dolzho bit bolshe!" << std::endl;
            }
            else break;
        }
        while (true)
        {
            std::cout << "\tVvedite K >> ";
            K = reader<int>();
            if (K > 10)
            {
                std::cout << "Slishkom bolshoie chislo!" << std::endl;
            }
            else if (K <= -1 || K == 1)
            {
                std::cout << "Chislo K dolzhno bit bolshe ili ravno 0!" << std::endl;
            }
            else break;
        }
        perestanovka(N, K);
    }
}

int main()
{
    std::cout << "Viberite zadachy:\n"
        "58. Summa elementov matritsi\n"
        "76. Complexsniye chisla\n"
        "81. 1000 - 7 ?\n"
        "86. Poisk puty\n"
        "91. Vse summy chisla\n"
        "Vvedite inoe znacheniye dlya zaversheniya\n";
    
    int user;
    bool cwork = true;
    while (cwork)
    {
        std::cout << ">> ";
        user = reader<int>();
        switch (user)
        {
            case 1:
            case 58:
                task1();
                break;
            case 2:
            case 76:
                task2();
                break;
            case 3:
            case 80:
                t3::task3();
                break;
            case 4:
            case 86:
                task4();
                break;
            case 5:
            case 91:
                t5::task5();
                break;
            default:
                cwork = false;
                break;
        }
    }

    return 0;
}