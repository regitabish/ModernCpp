#include<iostream>
#include<math.h>

int main(){
    int max = 1000000;
    long long ansLong = 0;
    int ansNum = 0;
    
    int tmp = 57;
    while(tmp>1){
        if(tmp%2==0)tmp/=2;
        else tmp = tmp*3 + 1;
        
        std::cout  << "tmp=" << tmp << "\n";
    }

}