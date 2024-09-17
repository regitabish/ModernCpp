//与えられた上限までのすべての過剰数(約数の総和がその数の2倍より大きい数)とその過剰を出力

#include <iostream>

int primeSum(int n){
    int sum = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            sum+=i;
            if(n/i != i){
                sum += n/i;
            }
        }
    }
    return sum;
}

int main(){
    int n;
    std::cout << "input the number>";
    std::cin >> n;

    for(int i=1;i<=n;++i){
        if(primeSum(i) > 2*i){
            std::cout <<  i << " is an abundant number" << std::endl;
            std::cout << "the diff prime sum and double of " << i << " is " << primeSum(i) - 2*i << std::endl;
        }
    }
}