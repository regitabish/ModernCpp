//1,000,000より小さい友愛数のペアを出力
//友愛数;異なる2つの自然数の組で、自分自身を除いた 約数の和が互いに他方と等しくなるような数
//例えば220は約数の和が284、284は約数の和が220なのでこれらは友愛数
#include<iostream>
#include<map>
long long sumDiv(int n){
    long long sum = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            sum += i;
            if(i==1)continue;
            if(n/i != i)sum+= n/i;
        }
    }
    return sum;
}

int main(){
    std::map<long,int>mp;
    int limit = 1e6;
    for(int i=1;i<=limit;++i){
        long long sum1 = sumDiv(i);
        long long sum2 = sumDiv(sum1);
        if(i == sum2 && i!=sum1){
            if(mp[i]==0 && mp[sum1]==0 )std::cout << i << " " << sum1 << "\n";
            mp[i]++;
            mp[sum1]++;
        }
    }
    return 0;
}