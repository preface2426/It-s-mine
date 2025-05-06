
#include <iostream>

void calculate_next_position(int i, int j, int M, int &ni, int &nj) {
    // 计算右上方的坐标
    ni = i == 0 ? M - 1 : i - 1; // 上
    nj = j == M - 1 ? 0 : j + 1; // 右
}

int main() {
    const int M = 3;
    int a[M][M] = {0}; // 初始化二维数组
    int i = 0, j = M / 2; // i和j为确定赋值的坐标
    int ni = 0, nj = 0, k = 0; // ni,nj右上⽅的坐标

    // 填充二维数组
    for (k = 1; k <= M * M; ++k) {
        a[i][j] = k;
        calculate_next_position(i, j, M, ni, nj); // 调用函数更新ni和nj
        if (a[ni][nj] == 0) { // 右上方未填
            i = ni;
            j = nj;
        } else {
            ++i;
        }
    }

    // 输出二维数组
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << a[i][j] << "\t"; // 输出每个元素，用制表符分隔
        }
        std::cout << std::endl; // 换行
    }

    return 0;
}