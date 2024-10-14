//任意個数の引数を受け取れて、その最小値を返す関数テンプレート
//比較にoperator演算子<を使って書く

#include<iostream>


template<typename T>
T minimum(T const a, T const b){
    return a<b ? a:b;
}

template<typename T1, typename... T>
T1 minimum(T1 a, T... args){
    return minimum(a,minimum(args...));
}

int main(){
    auto x = minimum(5,4,3,2,1,0,-1);
    std::cout << x << std::endl;
}