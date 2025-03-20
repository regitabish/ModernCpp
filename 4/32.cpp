#include <iostream>
#include <vector>
#include <string> // stringの使用に必要
using namespace std;

// パスカルの三角形を生成して出力する関数
void printPascalsTriangle(int numRows) {
    vector<vector<int>> triangle;

    // パスカルの三角形を構築
    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1); // 各行の初期化（すべて1）
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }

    // パスカルの三角形を出力
    for (int i = 0; i < numRows; ++i) {
        // 三角形を中央に寄せるための空白を出力
        cout << string((numRows - i - 1) * 2, ' ');
        for (int j = 0; j <= i; ++j) {
            cout << triangle[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int numRows;
    cout << "パスカルの三角形の行数を入力してください: ";
    cin >> numRows;

    if (numRows > 0) {
        printPascalsTriangle(numRows);
    } else {
        cout << "正の整数を入力してください。" << endl;
    }

    return 0;
}
