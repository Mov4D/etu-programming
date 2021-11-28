//
//  main.cpp
//  program_lab1
//
//  Created by Vadim Aleshin on 12.11.2021.
//

#include <iostream>
#include <math.h>
using namespace std;

// Получить факториал числа
double getFactorialNunber(double number) {
    if(number < 0) return 0;
    if (number == 0) return 1;
    else return number * getFactorialNunber(number - 1);
}

// Быстрое возведение в степень
double fastExponentiation(double number, int exp) {
    if(exp == 0) return 1;
    if(exp % 2 == 0) return fastExponentiation(number * number, exp / 2);
    return number * fastExponentiation(number, exp - 1);
}

// Взятие квадратного корня
long double takingSquareRoot(long double number) {
    long double root = number/3;
    int i;
    
    if (number <= 0) return 0;

    for (i=0; i<32; i++) root = (root + number / root) / 2;
    return root;
}

// Получить число pi
double getPi() {
    return 3.1415926536;
}

double getModNumber(double number, double divider) {
    
    bool flag = false;
    if (number < 0) {
        flag = true;
        number *= -1;
    }
    
    double dividend = number;
    double remainder = dividend;
    
    while (remainder >= divider) {
        dividend -= divider;
        remainder = dividend;
    }
    return remainder * ((-1) + (flag == false)*2);
}

// Получить косинус угла
long double getCosAngle(long double angle) {
    
    angle = getModNumber(angle, 360);
    long double rad = angle * getPi() / 180;
    long double cos = 0;

    int i;
    for(i = 0; i < 64; i++) {
        
        cos += fastExponentiation(-1, i) * fastExponentiation(rad, 2 * i) / getFactorialNunber(2 * i);
        
    }
    return cos;
    
}

// Получить arctg угла
long double getArctgAngle(double angle, int accuracy) {
    
    long double a = angle;
    long double sum = 0;
    long double b = a;
    long double E = 1 / accuracy;
    for(int i = 1; abs(a) > E; i++){
        b = fastExponentiation(-1, i - 1) * fastExponentiation(angle, 2*i - 1);
        a = b / (2 * i - 1);
        sum += a;
    }
    return sum * 180/getPi();
    
}

long double countingGivenFunc(long double a, long double b) {
    
    long double rez1 = getCosAngle(2*getPi()*fastExponentiation(b, 2)) + fastExponentiation(a, 3);
    long double rez2 = takingSquareRoot(1.87 + fastExponentiation(a, 2)/(b + getCosAngle(3.42*fastExponentiation(b, 2))));
    long double rez3 = rez1/rez2;
    if (rez3 > -1 && rez3 < 1) {
        long double rezFinal = getArctgAngle(rez3, 1000);
        return rezFinal;
    } else {
        cout << "The value passed to arctg is not in the range (-1, 1)" << endl;
        return 414;
    }
}

int main(int argc, const char * argv[]) {
    long double a;
    long double b;
    cout << "Enter value a: ";
    cin >> a;
    cout << "Enter value b: ";
    cin >> b;
    cout << "My result = " << countingGivenFunc(a, b) << endl;
    
    return 0;
}
