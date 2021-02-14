#include <iostream>
using namespace std;

constexpr int Fibonacci(int n) // function exextuded at compile-time
{
    int value = 0;
    switch(n)
    {
        case 0:
            value = 0;
            break;
        case 1:
            value = 1;
            break;
        default:
            value = Fibonacci(n-1) + Fibonacci(n-2);
    }
    return value;
}

int main()
{
    static_assert(Fibonacci(10) == 55, "Unexpected Fibonacci Number"); // stactic_assert function for compile-time
    return 0;
}