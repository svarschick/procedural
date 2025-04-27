#include <iostream>
#include <fstream>
#include <math.h>

void generate(const int vsego_sharikov, int* shariki, int& total_perestanovok, int t = 0)
{
    if (t == vsego_sharikov - 1)
    {
        for (int i = 0; i < vsego_sharikov; ++i)
        {
            if (shariki[i] == i)
            {
                total_perestanovok++;
                break;
            }
        }
    }
    else
    {
        for (int j = t; j < vsego_sharikov; ++j)
        {
            std::swap(shariki[t], shariki[j]);
            t++;
            generate(vsego_sharikov, shariki, total_perestanovok, t);
            t--;
            std::swap(shariki[t], shariki[j]);
        }
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
        return reader<T>();
    }
}

int main()
{
    int vsego_sharikov;

    std::cout << "Vvedite kolichestvo sharikov ";
    while (true)
    {
        std::cout << ">> ";
        vsego_sharikov = reader<int>();
        if (1 < vsego_sharikov && 12 > vsego_sharikov) break;
        else std::cout << "Nepodhodyaschee chislo" << std::endl;
    }

    int* shariki = new int[vsego_sharikov];
    int total_perestanovok = 0;

    for (int i = 0; i < vsego_sharikov; i++)
    {
        shariki[i] = i;
    }

    generate(vsego_sharikov, shariki, total_perestanovok);
    std::cout << "Kolichestvo perestanovok = " << total_perestanovok << std::endl;
    delete[] shariki;
    return 0;
}