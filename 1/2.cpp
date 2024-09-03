#include <iostream>
#include <numeric>
//与えられた2つの正の整数の最大公約数を出力

//ユークリッドの互除法
int euclid(int a,int b){
    while(b!=0){
        int tmp;
        tmp=a;
        a=b;
        b=tmp%a;
    }
    return a;
}

int main(){

    int a=0,b=0;
    int ans=1;
    std::cout << "input a number>" ;
    std::cin >> a;

    std::cout << std::endl;

    std::cout << "input another number>";
    std::cin >> b;

    std::cout << ""

    //using gcd function template
    std::cout << "using cpp function template gcd is;"  << std::gcd(a,b) << std::endl;
}