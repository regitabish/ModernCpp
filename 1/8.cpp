//3桁のアームストロング数を出力
//n桁のアームストロング数:n桁の各位の数をn乗した数の和が元の数に等しい

#include <iostream>
#include <cmath>
//拡張性を考慮しある数の桁数を返す関数を作成しておく
int getDigits(int n){
    int digits = 0;
    while(n){
        n/=10;
        digits++;
    }
    return digits;
}

int main(){
    int limit = 1000;
    for(int i=100;i<limit;i++){
        int digits = getDigits(i);
        long long sum = 0;
        int tmp = i;
        while(tmp){

            sum += pow(tmp%10,digits);
            tmp = tmp/10;
            //std::cout << tmp << " " << pow(tmp%10,digits) << std::endl;
        }
        if(sum == i)std::cout << i << "\n";
    }
}