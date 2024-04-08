
#include <iostream>
#include "set.h" 
#include "student.h"

void countCharacters(const std::string& expression)
{
    Set<char> digits;
    Set<char> arithmeticOperators;
    Set<char> brackets;

    for (char c : expression)
    {
        if (c >= '0' && c <= '9')
        {
            if (digits.Contains(c))
            {
                std::cout << "Repeated digit: " << c << std::endl;
            }
            else
            {
                digits.Add(c);
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (arithmeticOperators.Contains(c))
            {
                std::cout << "Repeated operator: " << c << std::endl;
            }
            else
            {
                arithmeticOperators.Add(c);
            }   
        }
        else if (c == '(' || c == ')')
        {
            brackets.Add(c);
        }
    }

   

    std::cout << "Number of digits: " << digits.Size() << std::endl;
    std::cout << "Number of arithmetic operators: " << arithmeticOperators.Size() << std::endl;

    if (brackets.Size() % 2 == 0)
    {
        std::cout << "The expression has the same number of opening and closing brackets." << std::endl;
    }
    else 
    {
        std::cout << "The expression doesn't have the same number of opening and closing brackets." << std::endl;
    }
}

int digits(int n) 
{
    bool seen[10] = { false }; 
    int count = 0;

    while (n > 0) 
    {
        int digit = n % 10; 

        
        if (!seen[digit])
        {
            count++;
            seen[digit] = true;
        }

        n /= 10; 
    }
    return count;
}

    

    int main()
    {
        std::string expression = "8 * (4 + 5) - 2 / (7 - 3)";
        countCharacters(expression); 

        std::cout << digits(2024) << std::endl;      
        std::cout << digits(5) << std::endl;         
        std::cout << digits(10110111) << std::endl;  

        return 0;
    }


