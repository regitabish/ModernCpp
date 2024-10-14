//18を変更し、operatorの代わりに引数として与えられた2項比較演算子を使う
//関数テンプレートの修正版

#include<iostream>

template<class Compare, typename T>
T minimumc(Compare comp, T const a, T const b){
    return comp(a,b)? a:b;
}

template <class Compare, typename T1, typename... T>
T1 minimumc(Compare comp, T1 a, T... args){
    return minimumc(comp, a, minimumc(comp, args...));
}


int main(){
    auto y = minimumc(std::less<>(),3,2,1,0,-10);
    std::cout << y << std::endl;
}