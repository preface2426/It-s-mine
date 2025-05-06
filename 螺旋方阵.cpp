#include <iostream>

int main() {
    constexpr int MAX{10};
    int a[MAX][MAX]{}; // 初始化二维数组
    int m{}; // m是实际的行数和列数
    std::cin >> m;
    
    // 补充剩余代码，输出符合要求的结果 
    int k = 1; // 初始化计数器
    int top = 0, bottom = m - 1, left = 0, right = m - 1; 

    while (k <= m * m) {
        for (int j = left; j <= right && k <= m * m; ++j) {
            a[top][j] = k++;
        }
        top++;

        for (int i = top; i <= bottom && k <= m * m; ++i) {
            a[i][right] = k++;
        }
        right--;

        for (int j = right; j >= left && k <= m * m; --j) {
            a[bottom][j] = k++;
        }
        bottom--;
    
        for (int i = bottom; i >= top && k <= m * m; --i) {
            a[i][left] = k++;
        }
        left++;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j < m - 1)
                std::cout << a[i][j] << " ";
            else 
                std::cout << a[i][j];
        }
        std::cout << std::endl;
    }
    
    return 0;
}