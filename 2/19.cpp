//push_backメゾットを備えたコンテナの末尾に任意個数の要素を追加できる汎用関数
#include<vector>
#include<list>
#include<iterator>
#include<iostream>

template<typename C, typename... Args>
void push_back(C& c, Args&& ... args){
    (c.push_back(args),...);
}


int main(){
    std::vector<int> v;
    push_back(v,1,2,3,4,5);
    std::copy(cbegin(v),cend(v),
        std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;
    std::list<int> l;
    push_back(l,10,20,30,40,50);
    std::copy(cbegin(l),cend(l),
        std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;
}