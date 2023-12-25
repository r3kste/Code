// ================== DO NOT TOUCH THIS FILE =================

#include <iostream>
#include "Fractions.cpp"

enum OpIdTy
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    EQUAL,
    UNEQUAL,
    LEQ,
    LESS,
    GEQ,
    GREAT,
    PRINT
};

int main()
{
    int N;
    std::cin >> N;

    while (N--)
    {
        int opId_;
        std::cin >> opId_;
        int n, d;
        std::cin >> n >> d;
        Fraction<int> f1 (n, d);
        std::cin >> n >> d;
        Fraction<int> f2 (n, d);
        OpIdTy opId = static_cast<OpIdTy> (opId_);

        switch (opId)
        {
        case ADD:
        {
            Fraction<int> f3 = f1 + f2;
            std::cout << f3.get_numerator() << " " << f3.get_denominator() << std::endl;
        }

        case SUBTRACT:
        {
            Fraction<int> f3 = f1 - f2;
            std::cout << f3.get_numerator() << " " << f3.get_denominator() << std::endl;
        }

        case MULTIPLY:
        {
            Fraction<int> f3 = f1 * f2;
            std::cout << f3.get_numerator() << " " << f3.get_denominator() << std::endl;
        }

        case DIVIDE:
        {
            Fraction<int> f3 = f1 / f2;
            std::cout << f3.get_numerator() << " " << f3.get_denominator() << std::endl;
        }

        case EQUAL:
        {
            Fraction<int> f3 (f1.get_numerator() * 2, f1.get_denominator() * 2);
            std::cout << (f3 == f1) << std::endl;
        }

        case UNEQUAL:
        {
            Fraction<int> f3 (f1.get_denominator(), f1.get_numerator());
            std::cout << (f3 != f1) << std::endl;
        }

        case LEQ:
        {
            std::cout << (f2 <= f1) << std::endl;
        }

        case LESS:
        {
            std::cout << (f2 < f1) << std::endl;
        }

        case GREAT:
        {
            std::cout << (f2 > f1) << std::endl;
        }

        case GEQ:
        {
            std::cout << (f2 >= f1) << std::endl;
        }

        case PRINT:
        {
            f2.print();
        }
        }
    }
}
