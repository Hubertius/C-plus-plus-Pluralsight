#include <iostream>
#include <vector>
#include <algorithm>
#include "lambda.h"
#include <memory>
using namespace std;

int main()
{

    auto isOdd = [](int canditate) {return canditate % 2 != 0;};

    bool is3Odd = isOdd(3);
    bool is4Odd = isOdd(4);

    cout << "is3Odd: " << is3Odd << endl;
    cout << "is4Odd: " << is4Odd << endl;

    vector<int> nums {2, 3, 4, -1, 1};

    int odds = count_if(begin(nums), end(nums), isOdd);

    int evens = count_if(begin(nums), end(nums), [](int canditate) {return canditate % 2 != 0;});

    cout << "Odds: " << odds << endl;
    cout << "Evens: " << evens << endl;


    int x = 3;
    int y = 7;
    string message = "elements between";
    cout << "x: " << x << "\n" << "y: " << y << endl;
    cout << "Message: " << message;
    message += std::to_string(x) + " and " + std::to_string(y) + " inclusive: ";
    for_each(begin(nums), end(nums), 
        [x, y, &message] (int n) 
        {
            if(n >= x && n <= y)
            {
                message += " " + std::to_string(n);
            }
        });
    cout << "x: " << x << "\n" << "y: " << y << endl;
    cout << "Message: " << message;
    x = y = 0;
    cout << "x: " << x << "\n" << "y: " << y << endl;
    for_each(begin(nums), end(nums), 
        [&, x] (int element) mutable   
        {
            x += element;
            y += element;
        });
    cout << "x: " << x << "\n" << "y: " << y << endl;
    cout << "Message: " << message;
    // [&, x]  capturing everything by reference, except x
    {
        auto pResource = make_unique<Resource>(", ");
        for_each(begin(nums), end(nums) ,
        [=, &message, &pResource](int n) {
            if(n >= x && n <= y)
            {
                message += pResource->GetName() + std::to_string(n);
            }
        });
    }
    cout << "Message: " << message;
    return 0;
}