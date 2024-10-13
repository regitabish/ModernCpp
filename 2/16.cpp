#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include <algorithm>

class ipv4 {
    std::array<unsigned char, 4> data;

public:
    // デフォルトコンストラクタ
    constexpr ipv4() : ipv4(0, 0, 0, 0) {}

    // 4つのバイトで初期化するコンストラクタ
    constexpr ipv4(unsigned char const a, unsigned char const b, unsigned char const c, unsigned char const d)
        : data{{a, b, c, d}} {}

    // 32ビット整数から初期化するコンストラクタ
    explicit constexpr ipv4(unsigned long a)
        : ipv4(static_cast<unsigned char>((a >> 24) & 0xFF),
               static_cast<unsigned char>((a >> 16) & 0xFF),
               static_cast<unsigned char>((a >> 8) & 0xFF),
               static_cast<unsigned char>(a & 0xFF)) {}

    // コピーコンストラクタ
    ipv4(ipv4 const& other) noexcept : data(other.data) {}

    // コピー代入演算子
    ipv4& operator=(ipv4 const& other) noexcept {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    // IPv4アドレスを32ビット整数に変換する
    unsigned long to_ulong() const {
        return (static_cast<unsigned long>(data[0]) << 24) |
               (static_cast<unsigned long>(data[1]) << 16) |
               (static_cast<unsigned long>(data[2]) << 8)  |
               static_cast<unsigned long>(data[3]);
    }

    // ドット形式の文字列を受け取り、IPv4オブジェクトを生成する
    static ipv4 from_string(const std::string& ip_str) {
        std::array<unsigned char, 4> bytes{};
        std::stringstream ss(ip_str);
        std::string token;
        int i = 0;
        while (std::getline(ss, token, '.') && i < 4) {
            bytes[i++] = static_cast<unsigned char>(std::stoi(token));
        }
        return ipv4(bytes[0], bytes[1], bytes[2], bytes[3]);
    }

    // IPv4アドレスをドット形式で出力するためのメソッド
    std::string to_string() const {
        std::stringstream ss;
        ss << static_cast<int>(data[0]) << "."
           << static_cast<int>(data[1]) << "."
           << static_cast<int>(data[2]) << "."
           << static_cast<int>(data[3]);
        return ss.str();
    }

    // 演算子のオーバーロード: < (範囲チェック用)
    bool operator<(ipv4 const& other) const {
        return this->to_ulong() < other.to_ulong();
    }

    // 演算子のオーバーロード: == (範囲チェック用)
    bool operator==(ipv4 const& other) const {
        return this->to_ulong() == other.to_ulong();
    }
};

// 2つのIPアドレスの範囲内にあるすべてのIPアドレスを列挙する関数
void enumerate_ip_range(const ipv4& start_ip, const ipv4& end_ip) {
    if (start_ip.to_ulong() > end_ip.to_ulong()) {
        std::cerr << "Error: Start IP should be less than or equal to End IP." << std::endl;
        return;
    }

    for (unsigned long i = start_ip.to_ulong(); i <= end_ip.to_ulong(); ++i) {
        ipv4 current_ip(i);
        std::cout << current_ip.to_string() << std::endl;
    }
}

int main() {
    // ユーザから2つのIPアドレスを入力
    std::string ip1_str, ip2_str;
    std::cout << "Enter the start IP address: ";
    std::cin >> ip1_str;
    std::cout << "Enter the end IP address: ";
    std::cin >> ip2_str;

    ipv4 start_ip = ipv4::from_string(ip1_str);
    ipv4 end_ip = ipv4::from_string(ip2_str);

    std::cout << "Listing all IP addresses between " << start_ip.to_string() << " and " << end_ip.to_string() << ":" << std::endl;

    // IP範囲を列挙
    enumerate_ip_range(start_ip, end_ip);

    return 0;
}
