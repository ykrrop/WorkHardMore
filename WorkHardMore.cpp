
#include <math.h>
#include <iostream>

using namespace std;


// Подставляем необходимую функцию
double func(double x)
{
    return 1/x;
}


// Интеграл методом левых (малых) прямоугольников
double IntegralLeft(double func(double x), double x1, double x2, double step)
{
    double x = x1;
    double summ = 0;
    int num_steps = (x2 - x1) / step;
    for (int i = 0; i < num_steps; i++)
    {
        summ += func(x) * (step);
        x += step;
    }
    return summ;
}


// Интеграл методом трапеций (средних прямоугольников)
double IntegralTrapeze(double func(double x), double x1, double x2, double step)
{
    double x = x1;
    double summ = 0;
    int num_steps = (x2 - x1) / step;
    for (int i = 0; i < num_steps; i++)
    {
        summ += func((2 * x + step) / 2) * (step);
        x += step;
    }
    return summ;
}


// Интеграл методом правых (больших) прямоугольников
double IntegralRight(double func(double x), double x1, double x2, double step)
{
    double x = x1 + step;
    double summ = 0;
    int num_steps = (x2 - x1) / step;
    for (int i = 0; i < num_steps; i++)
    {
        summ += func(x) * (step);
        x += step;
    }
    return summ;
}


// Интеграл методом Симпсона
double IntegralSimpson(double func(double x), double x1, double x2, double step)
{
    double x = x1;
    double Ystart = func(x1);
    double Yend = func(x2);
    double Ymedium = func(x2 - x1);
    double Y2 = 0;
    double Y1 = 0;
    int num_steps = (x2 - x1) / (step * 2);
    for (int i = 0; i < num_steps; i++)
    {
        if (i % 2 == 0)
        {
            Y2 += func(x) * (step);
        }
        else
        {
            Y1 += func(x) * (step);
        }
        x += step;
    }
    double f = ((x2 - x1) / 3) * (Ystart + Yend + (2 * Y2) + (4 * Y1));
    return f;
}


int main()
{
    double x1 = 1.0; // Значение из задания будет (0)

    double x2 = 2.7; // Значение из задания будет (1)

    double step = 0.01; // Значение из задания будет(0.01)

    cout << IntegralLeft(func, x1, x2, step) << endl;
    cout << IntegralTrapeze(func, x1, x2, step) << endl;
    cout << IntegralRight(func, x1, x2, step) << endl;
    cout << IntegralSimpson(func, x1, x2, step) << endl;
}








