#include <iostream>
#include <math.h>

const double PI = 3.1415926535;

void Konus() {
    double h, R, l, r, V, S;

    std::cout << "<Zadacha \"Konus\">\n"
        << "\tProgramma vichislyaet ob`iom i ploschad` polnoi poverkhnosti konusa.\n"
        << "\tChislo pi prinyato za " << PI << std::endl
        << "\tVse velichini dolzhni bit` bolshe 0, tak kak eto fizichecheskii ob`ekt.\n\n"
        << "\tPozhaluista, vvodite zaprashivaemie znacheniya:\n"
        << "\t-> Bolshii radius (R)\t>> ";
    std::cin >> R;
    std::cout << "\t-> Men`shii radius (r)\t>> ";
    std::cin >> r;
    std::cout << "\t-> Visota konusa (h)\t>> ";
    std::cin >> h;

    l = sqrt(R * R + h * h);

    if (R < r) std::cout << "!!!: Bolshii radius konusa menshe menshigo: R < r." << std::endl;
    else if (R == r) std::cout << "!!!: Malyy radius raven bolshemy: R = r." << std::endl;
    else if (R > 0 && r > 0 && h > 0) {
        V = (1.0 / 3.0) * PI * h * (R * R + R * r + r * r);
        S = PI * (R * R + (R + r) * l + r * r);
        std::cout << "\n\tOb`iom konusa (V) = " << V << std::endl;
        std::cout << "\tPloschad` polnoi poverkhnosti konusa (S) = " << S << std::endl;
    }
    else std::cout << "!!!: Necorrectno vvedini znacheniya. Vse velichini dolzhni bit` bolshe 0";
}
void Razvetvlitel() {
    double x, a, val;

    std::cout << "\n<Zadacha \"Razvetvlitel`\">\n"
        << "\tProgramma vichislyaet znachenie functsii w(x,a).\n"
        << "\tw = a * ln(|x|),\tpri |x| < 1\n"
        << "\tw = (a - x * x)^0.5,\tpri |x| >= 1\n\n"
        << "\tPozhaluista, vvodite zaprashivaemie znacheniya:\n"
        << "\t-> x >> ";
    std::cin >> x;
    std::cout << "\t-> a >> ";
    std::cin >> a;

    if (0 == x) {
        std::cout << "!!!: Nedopustimoe znacherie argumenta x: x = 0" << std::endl;
    }
    else if ((a - x * x < 0) && abs(x) >= 1) {
        std::cout << "!!!: Argument dla operatsii izvlecheniya kornya menshe nulya: "
            << "a - x * x = " << a - x * x << std::endl;
    }
    else if (abs(x) < 1) {
        val = a * std::log(abs(x));
        std::cout << "\tw(" << x << "," << a << ") = " << val << std::endl;
    }
    else {
        val = sqrt((a - x * x));
        std::cout << "\tw(" << x << "," << a << ") = " << val << std::endl;
    }
}
void Functiya() {
    double x, y, b, z;

    std::cout << "\n<Zadacha \"Functiya\">\n"
        << "\tProgramma vichislyaet znachenie functsii z(x,y,b).\n"
        << "\tz(x,y,b) = ln(b - y) * (b - x)^0.5\n\n"
        << "\tPozhaluista, vvodite zaprashivaemie znacheniya:\n"
        << "\t-> x >> ";
    std::cin >> x;
    std::cout << "\t-> y >> ";
    std::cin >> y;
    std::cout << "\t-> b >> ";
    std::cin >> b;

    if (b - y <= 0) {
        std::cout << "!!!: Nedopustimoe znacherie dlya logarifmirovaniya: b - y = " 
            << b - y << " , " << b - y << " <= 0 " << std::endl;
    }
    else if (b - x < 0) {
        std::cout << "!!!: Argument dla operatsii izvlecheniya kornya menshe nulya : "
            << "b - x = " << b - x << " , b - x = 0" << std::endl;
    }
    else {
        z = std::log(b - y) * sqrt(b - x);
        std::cout << "\tz(" << x << "," << y << "," << b << ") = " << z << std::endl;
    }
}
void Poryadok() {
    int N;

    std::cout << "\n<Zadacha \"Poryadok\">\n"
        << "\tProgramma vivedet 10 posledyuschih naturalnih chisel, posle vved`onnogo N.\n"
        << "\tVivodimiye chisla dolzhi bit` naturalnimy, poetomy N >= 0 i N - tseloye chislo.\n"
        << "\tPozhaluista, vvedite znacheniye N: ";
    std::cin >> N;

    if (N >= 0) {
        std::cout << "\n\tPosleduyuschie 10 chisel:" << std::endl;
        for (int i = 1; i < 11; ++i) {
            std::cout << "\t" << i << ". " << ++N << std::endl;
        }
    }
    else std::cout << "!!!: N dolzho bit bolhe ili ravno 0" << std::endl;
}
void Tabulyatsiya() {
    double x = -4;
    double y;

    std::cout << "\n<Zadacha \"Tabulyatsiya\">\n"
        << "\tProgramma vivodit znachniya functsii y(x)\n"
        << "\ty(x) = (x^2 - 2x + 2)/(x - 1)\n" << std::endl;

    std::cout << "\t< x >\t< y >" << std::endl;
    while (x <= 4) {
        if (0 == x - 1) {
            std::cout << "\t" << x << "\t" << "ne opredeleno" << std::endl;
        }
        else {
            y = (x * x - 2 * x + 2) / (x - 1);
            std::cout << "\t" << x << "\t" << y << std::endl;
        }
        x += 0.5;
    }
}

int main()
{
    Konus();
    Razvetvlitel();
    Functiya();
    Poryadok();
    Tabulyatsiya();
    return 0;
}
