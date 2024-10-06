//2進数表記で5ビットのすべての数について
//2進数表現、グレイコード表現、グレイコード復号値を出力


#include<bitset>
#include<iostream>

int gray_decode(int gray){
    for(int bit = 1U << 31;bit>1;bit>>=1){
        if(gray & bit) gray ^= bit >> 1;
    }
    return gray;
}

int main(){
    int n=32;
    for(int i=0;i<n;++i){
        int encd = (i^(i>>1));
        std::cout<< i <<":\t" << std::bitset<5>(i) 
        << ":" << std::bitset<5>(encd) 
        << ":" << std::bitset<5>(gray_decode(encd)) << "\n";
    }
}