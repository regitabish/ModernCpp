//入力された自然数より小さい数のうち、最も大きな素数を出力

#include <iostream>

bool isPrime(int n){
    if(n==1)return false;

    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int main(){
    int n;
    std::cout << "input the number>";
    std::cin >> n;
    for(int i=n;i>0;i--){
        if(isPrime(i)){
            std::cout << i << " is the biggest prime number smaller than " << n << std::endl;
            return 0;
        }
    }
}