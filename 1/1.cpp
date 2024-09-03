#include <iostream>
int main(){
    //与えられた上限までの3または5で割り切れる数の総和を出力する
    int inputNum=0,ans=0 ;
    std::cout << "input the limit number" << std::endl;
    std::cin >> inputNum ;

    for(int i=1;i<=inputNum;++i){
        if(i%3==0 || i%5==0){
            std::cout << "ans+= " << i << std::endl;

            ans += i;
        }
    }

    std::cout << ans << std::endl;
    
}