//入力された二つの正の整数から最小公倍数を出力
//lcm = abs(a*b)/gcd(a,b)
#include <iostream>
#include <numeric>

int gcd(int a,int b){
    while(b!=0){
        int tmp=a;
        a=b;
        b=tmp%a;
    }

    return a;
}

int main(){
    int a,b;
    std::cout << "input the 2 numbers>";
    std::cin >> a >> b;
    std::cout << "lcm of the 2 numbers you input is " << std::abs(a*b)/gcd(a,b) << std::endl;

    std::cout << "when use std function template, the lcm is " << std::lcm(a,b) << std::endl;
}