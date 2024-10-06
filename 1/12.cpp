//100万までの最長コラッツ数列になる数と数列の長さを求める
#include<iostream>
#include<math.h>

int main(){
    int max = 1000000;
    long long ansLong = 0;
    int ansNum = 0;
    for(int i=1;i<=max;i++){
        long long size = 0;
        int tmp = i;
        while(tmp>1){
            if(tmp%2==0)tmp/=2;
            else tmp = tmp*3 + 1;
            size++;
            //std::cout << "i=" << i << "\n" << "tmp=" << tmp << "\n";
        }
        if(ansLong<size){
            ansLong = size;
            ansNum = i;
        }
    }
    std::cout << "ansNum= " << ansNum << std::endl;
    std::cout << "ansLong=" << ansLong << std::endl; 
}