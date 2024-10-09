//IPv4を表すクラスを書く
//IPv4アドレスをキーボードから入力しディスプレイに出力するのに必要な関数を書く
//ユーザは127.0.0.1や168.192.0.100のようにどっと形式で入力できる必要がある
//このドット形式は出力に使う形式でもある

class ipv4{
    *this = ipv4(1 + to_ulong());
    return *this;
}

ipv4 operator++(int){
    ipv4 result(*this);
    ++(*this);
    return result;
}

friend bool operator==(ipv4 const & a1, ipv4 const & a2) noexcept{
    return a1.data == a2.data;
}

friend bool operator!=(ipv4 const & a2, )