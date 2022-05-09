/*
2. Створити абстрактний базовий клас “Прогресія” з віртуальною функцією – обчислення суми прогресії.
Створити похідні класи: “Арифметична прогресія” і “Геометрична прогресія”.
Кожний клас має два поля типу double: перший член прогресії і постійна різниця
(для арифметичної) і постійне відношення (для геометричної).
Визначити функцію обчислення суми, де параметром є кількість елементів прогресії.
*/

#include <math.h>
#include <iostream>
#include <Windows.h>

using namespace std;

class Prog { 
protected:
    virtual double Sum(int n) = 0; 
};


class GeoProg : public Prog {
protected:
    double a;
    double c;
    double sum;

public:
    GeoProg(double a, double c) {
        this->a = a;
        this->c = c;
    }


    double Sum(int n) {
        if (c != 1) sum = (a * (1 - pow(c, n))) / (1 - c);
        return sum;
    }


    ~GeoProg() {}
};


class MeticProg : public Prog {
protected:
    double a;
    double d;
    double sum;


public:
    MeticProg(double a, double d) {
        this->a = a;
        this->d = d;
    }


    double Sum(int n) {
        sum = ((2 * a + (n - 1) * d) / 2) * n;
        return sum;
    }


    ~MeticProg() {};
};


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MeticProg M(2, 2);
    GeoProg G(4, 2);

    cout << "Сума арифметичної прогресії " << M.Sum(7) << endl;       
    cout << "Cума геометричної прогресії " << G.Sum(5) << endl;       
}