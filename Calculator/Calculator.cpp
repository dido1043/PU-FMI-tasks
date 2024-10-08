#include <iostream>
#include <string>
using namespace std;
bool validSign(char& sign) {
    return sign == '+' || sign == '-' || sign == '*' || sign == '/';
}
double calc(double& n1, double& n2, char& sign) {
    double result;
    switch (sign) {
        case '+':
            result = n1 + n2;
            break;
        case '-':
            result = n1 - n2;
            break;
        case '/':
            result = n1 / n2;
            break;
        case '*':
            result = n1 * n2;
            break;
    }
    return result;
}
int main()
{
    double n1, n2;
    char sign;

    cout << "Enter n1: ";
    cin >> n1;
    cout << "Enter operator: ";
    cin >> sign;
    if (validSign(sign) == false)
    {
        cout << "Invalid operator!";
        return 0;
    }
    cout << "Enter n2: ";
    cin >> n2;

    cout << "Result: " << calc(n1, n2, sign) << endl;
    return 0;
}

