//与えられた正の整数を素因数分解する

#include<iostream>
#include<map>
std::map<unsigned long long, unsigned long long> solve(const unsigned long long n){
    unsigned long long tmp = n;
    std::map<unsigned long long, unsigned long long>mp;

    while(tmp!=1){
        for(unsigned long long i=2;i<=n;++i){
            while(tmp%i == 0){
                mp[i]++;
                //if(tmp/i != i)mp[tmp/i]++;
                tmp/=i;
                std::cout << i << std::endl;
            }        
        }
    std::cout << "aaaa" << tmp << "\n";
    }
    return mp;
}

int main(){
    unsigned long long n;
    std::cin>>n;
    std::map<unsigned long long,unsigned long long> mp = solve(n);
    auto last = mp.end();
    last--;
    for(auto ite = mp.begin();ite!=mp.end();ite++){
        std::cout << ite->first << "^" << ite->second;
        if(ite!=last)std::cout<<"*";
    }
    std::cout << "\n";
}