//与えられた上限までのセクシー素数(差が６である素数の組)を出力

#include<iostream>

bool isPrime(int n){
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    std::cout << "input the number>";
    int n;
    std::cin >> n;

    for(int i=1;i<n;i++){
        if(isPrime(i) && isPrime(i+6)){
            std::cout << i << " & " << i+6 << " are one of the sexy prime pair" << std::endl;
        }
    }
}