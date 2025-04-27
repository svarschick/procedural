#include <iostream>
#include <math.h>

void linearEquation(double b, double c)
{
    if (0 == b && 0 != c) std::cout << "\t -> net reshenii" << std::endl;
    else if (0 == b && 0 == c) std::cout << "\t -> x - cho ugodno" << std::endl;
    else std::cout << "\t -> x = " << -c / b << std::endl;
}

void arifmeticaT1()
{
    std::cout << "Task 1." << std::endl;
    std::cout << "\tSchitaet dva chisla, ispolzyya operatsii + , - , * , /\n"
                 "\tVvedite chislo A, nazhmite enter, zatem vvedite chislo B, i snova nazhmite enter" << std::endl;
    double A, B;
    std::cout << "\tEnter A: ";
    std::cin >> A;
    std::cout << "\tEnter B: ";
    std::cin >> B;
    std::cout << "\t -> A + B = " << A + B << std::endl;
    std::cout << "\t -> A - B = " << A - B << std::endl;
    std::cout << "\t -> A * B = " << A * B << std::endl;
    
    if (0 != B) std::cout << "\t -> A / B = " << A / B << std::endl;
    else std::cout << "\tPopitka deleniya na 0 nakazyema po statie 404 UK RF" << std::endl;
}
void linearEquationT2()
{
    double b, c;
    std::cout << "\nTask 2." << std::endl;
    std::cout << "\tReshaem uravnenie tipa: bx + c = 0\n"
                 "\tVvedite chislo b, nazhmite enter, zatem vvedite chislo c, i snova nazhmite enter" << std::endl;
    std::cout << "\tEnter b: ";
    std::cin >> b;
    std::cout << "\tEnter c: ";
    std::cin >> c;
    linearEquation(b, c);
}
void sqrEquationT3()
{
    double a, b, c, D;
    std::cout << "Task 3." << std::endl;
    std::cout << "\tReshaem uravnenie tipa: ax^2 + bx + c = 0\n"
                 "\tVvedite chislo a, nazhmite enter, zatem vvedite chislo b, snova nazhmite enter, potom vvedite chislo c i again vlopite knopky enter" << std::endl;
    std::cout << "\tEnter a: ";
    std::cin >> a;
    std::cout << "\tEnter b: ";
    std::cin >> b;
    std::cout << "\tEnter c: ";
    std::cin >> c;
    if (0 == a) linearEquation(b, c);
    else {
        D = b * b - 4 * a * c;

        if (D > 0) {
            std::cout << "\t -> x1 = " << (-b + sqrt(D)) / (2 * a) << std::endl;
            std::cout << "\t -> x2 = " << (-b - sqrt(D)) / (2 * a) << std::endl;
        } 
        else if (0 == D) std::cout << "\t -> x = " << (-1)*b / (2 * a) << std::endl; 
        else std::cout << "\t -> reshenii net" << std::endl;
    }
}
void komnataT4() {
    bool svetlo, lampa, stora;

    std::cout << "\nTask 4." << std::endl;
    std::cout << "\tProgramma opredilyaiet sostoyanie sveta i t`my. Otvetite na tri voprosa:" << std::endl;
    std::cout << "\tEsli na ulitse den`, vvedite \"1\", a esli noch, to vvedite \"0\": ";
    std::cin >> svetlo;
    std::cout << "\tEsli lampa rabotaiet, to vvedite 1, inache 0: ";
    std::cin >> lampa;
    std::cout << "\tEsli shtora otkrita, to vvedite 1, inache 0: ";
    std::cin >> stora;

    if (!lampa) {
        if (stora && svetlo) std::cout << "\t -> V komnate svetlo";
        else std::cout << "\t -> V komnate temno";
    }
    else std::cout << "\t -> V komnate svetlo";
}

int main()
{
    std::cout << "Domashka 1." << std::endl;
    arifmeticaT1();
    linearEquationT2();
    sqrEquationT3();
    komnataT4();
    return 0;
}