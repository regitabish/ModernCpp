//IPv4を表すクラスを書く
//IPv4アドレスをキーボードから入力しディスプレイに出力するのに必要な関数を書く
//ユーザは127.0.0.1や168.192.0.100のようにどっと形式で入力できる必要がある
//このドット形式は出力に使う形式でもある

#include <iostream>
#include <array>
#include <sstream>
#include <bitset>
class ipv4 {
    std::array<unsigned char, 4> data;  // IPv4アドレスを4つのバイトで保持する

public:
    // デフォルトコンストラクタ (0.0.0.0)
    constexpr ipv4() : ipv4(0, 0, 0, 0) {}

    // 4バイトそれぞれで初期化するコンストラクタ
    //adressの初期化をipv4 ip(192,162,0,0)のようにした場合に呼ばれる
    constexpr ipv4(unsigned char a, unsigned char b, unsigned char c, unsigned char d) 
        : data{{a, b, c, d}} {}

    // 32ビット整数からIPv4アドレスを初期化するコンストラクタ
    explicit constexpr ipv4(unsigned long a) 
        : ipv4( static_cast<unsigned char>((a >> 24) & 0xFF),
                static_cast<unsigned char>((a >> 16) & 0xFF),
                static_cast<unsigned char>((a >> 8) & 0xFF),
                static_cast<unsigned char>(a & 0xFF)) {}

    // コピーコンストラクタ
    ipv4(ipv4 const& other) noexcept : data(other.data) {}

    // コピー代入演算子
    ipv4& operator=(ipv4 const& other) noexcept {
        if (this != &other) {//自己代入チェック
            data = other.data;
        }
        return *this;
    }

    // 文字列形式での出力用の関数
    std::string to_string() const {
        std::ostringstream oss;
        oss << static_cast<int>(data[0]) << '.'
            << static_cast<int>(data[1]) << '.'
            << static_cast<int>(data[2]) << '.'
            << static_cast<int>(data[3]);
        return oss.str();
    }

    // 入力ストリームから読み込む関数
    friend std::istream& operator>>(std::istream& is, ipv4& ip) {
        char dot;
        int a, b, c, d;
        is >> a >> dot >> b >> dot >> c >> dot >> d;
        ip = ipv4(static_cast<unsigned char>(a), 
                  static_cast<unsigned char>(b), 
                  static_cast<unsigned char>(c), 
                  static_cast<unsigned char>(d));
        return is;
    }

    // 出力ストリームに書き込む関数
    friend std::ostream& operator<<(std::ostream& os, const ipv4& ip) {
        os << ip.to_string();
        return os;
    }

    std::string to_binary_string() const {
    std::ostringstream oss;
    for (int i = 0; i < 4; ++i) {
        oss << std::bitset<8>(data[i]); // 各バイトをバイナリ形式で表示
        if (i < 3) {
            oss << '.'; // バイト間のドット
        }
    }
    return oss.str();
}
};

int main() {
    ipv4 ip;
    std::cout << "Enter an IPv4 address: ";
    std::cin >> ip;
    std::cout << "The IPv4 address is: " << ip << std::endl;
    std::cout << "The IPv4 binary address is: " << ip.to_binary_string() << std::endl;

    ipv4 ip1(ip);  
    std::cout << "Copy IP: " << ip1 << std::endl;  // 出力: 0.0.0.0
    return 0;
}
