#include <iostream>

int main(int cnt, char* vctr[])
{
    if (cnt != 3) {return 1;}
    char* num1 = vctr[1];
    char* num2 = vctr[2];

    if (*num1 == '-')
    {
        if (*num2 != '-')
        {
            std::cout << "less" << std::endl;
            return 0;
        }
    }
    else if (*num1 != '-' && *num2 == '-')
    {
        std::cout << "greater" << std::endl;
        return 0;
    }
    
    if (*num1 == '+' || *num1 == '-') {num1++;}
    if (*num2 == '+' || *num2 == '-') {num2++;}
    char* end1 = num1;
    char* end2 = num2;
    while (*end1 != '.' && *end1 != '\0') {end1++;}
    while (*end2 != '.' && *end2 != '\0') {end2++;}
    int len1 = end1 - num1;
    int len2 = end2 - num2;
    if (len1 < len2)
    {
        if (vctr[1][0] == '-') {std::cout << "greater" << std::endl;} 
        else {std::cout << "less" << std::endl;}
        return 0;
    }
    else if (len1 > len2)
    {
        if (vctr[1][0] == '-') {std::cout << "less" << std::endl;}
        else {std::cout << "greater" << std::endl;}
        return 0;
    }

    else
    {
        while (*num1 != '\0' || *num2 != '\0')
        {
            if (*num1 == '.') {num1++;}
            if (*num2 == '.') {num2++;}
            char c1 = (*num1 != '\0') ? *num1 : '0';
            char c2 = (*num2 != '\0') ? *num2 : '0';
            if (c1 != c2)
            {
                if (vctr[1][0] == '-')
                {
                    if (c1 < c2) {std::cout << "greater" << std::endl; return 0;}
                    else {std::cout << "less" << std::endl; return 0;}
                }
                else
                {
                    if (c1 < c2) {std::cout << "less" << std::endl; return 0;}
                    else {std::cout << "greater" << std::endl; return 0;}
                }
            }
            if (*num1 != '\0') {num1++;};
            if (*num2 != '\0') {num2++;};
        }

        std::cout << "equal" << std::endl; return 0;
    }
}