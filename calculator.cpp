#include <iostream>
#include <limits>   

int main()
{
    std::cout << "==============================\n";
    std::cout << "       SIMPLE CALCULATOR      \n";
    std::cout << "  (type q or any letter to exit)\n";
    std::cout << "==============================\n\n";

    double num1, num2, result;
    char   op;

    while (true)
    {
        std::cout << "Enter first number: ";
        if (!(std::cin >> num1))            
            break;

        std::cout << "Enter operator (+  -  *  /): ";
        std::cin  >> op;

        std::cout << "Enter second number: ";
        if (!(std::cin >> num2))
            break;

        switch (op)
        {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if (num2 == 0)
                {
                    std::cout << "Error: division by zero is undefined.\n\n";
                    continue;              
                }
                result = num1 / num2; break;
            default:
                std::cout << "Invalid operator.\n\n";
                continue;
        }

        std::cout << "Result: " << result << "\n\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nThanks for using the calculator. Goodbye!\n";
    return 0;
}

