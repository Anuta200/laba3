#include <string>
#include <iostream>
#include <locale.h>
#include "stack.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    
    TStack<int> stack(5);
    int k = 1;
    for (int i = 0; i < 5; i++)
    {
        stack.Push(k);
        k = k + 3;
    }

    cout << "стек: ";
    cout << stack << endl;
    

   // (9 + 36 * (7 - 8 / 4) * (77 + 2 * 8 - (3 + 7)))

    TCalc calculator;
    calculator.SetInfix("1.1+2.2");
    std::cout << "Инфиксное: " << calculator.GetInfix() << std::endl;
    calculator.ToPostfix();
    std::cout << "Постфиксное: " << calculator.GetPostfix() << std::endl;
    double result = calculator.CalcPostfix();
    cout << "Результат: " << result << endl;
    double res2 = calculator.Calc();
    cout << "Результат через Calc(): " << res2 << endl;
}
