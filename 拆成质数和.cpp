#include <iostream>
using namespace std;

#define M 10
#define N 101

void rand_even(int a, int b, int *p, int n);
void split(int a[], int b[][N], int n);
void display(int a[], int b[][N], int n);
int is_prime(int a);

int main() {
    int a, b;
    cout << "请输入随机数的范围【a,b】" << endl;
    cin >> a >> b;
    int x[M], y[M][N] = {0};
    srand(time(0)); // 初始化随机数种子
    rand_even(a, b, x, M);
    split(x, y, M);
    display(x, y, M);
    return 0;
}

void split(int a[], int b[][N], int n) {
    for (int k = 0; k < n; k++) { // 从0开始
        int count = 0; // 计数器，记录找到的质数对数量
        for (int i = 2; i <= a[k]; i++) { // 检查到 a[k]
            int j = a[k] - i;
            if (is_prime(i) && is_prime(j) && i != j) {
                b[k][count * 2] = i; // 存储第一个质数
                b[k][count * 2 + 1] = j; // 存储第二个质数
                count++; 
            }
        }
    }
}

void rand_even(int a, int b, int *p, int n) {
    for (int i = 0; i < n; i++) {
        p[i] = rand() % (b - a + 1) + a;
        while (p[i] % 2 != 0)
            p[i] = rand() % (b - a + 1) + a;
    }
}

// 拆分数组 a 的元素并按要求保存到数组 b 中

// 按示例格式将结果输出，当组合数超过5时，每行输出5种组合
void display(int a[], int b[][N], int n) {
    cout << "被测数\t组合个数"<<"\t"<<"拆分表达式" << endl;
    for (int k = 0; k < n; k++) {
        int count = 0;
        cout << a[k] << "\t";
        for (int i = 0; i < N; i++) {
            if (b[k][i] != 0) count++;
        }
        cout << count/2 << "\t";
        int printed = 0;
        for (int i = 0; i < N; i+=2) {
            if (b[k][i] != 0) {
                cout << b[k][i] << "+" << b[k][i + 1] << "   ";
                printed++;
                if (printed % 5 == 0) {cout << endl;
                cout << "      " << "          " ;
            }
            }
        }
        cout << endl;
    }
}

int is_prime(int a) {
    if (a == 2) return 1;
    if (a % 2 == 0) return 0;
    for (int i = 3; i * i <= a; i += 2) {
        if (a % i == 0) return 0;
    }
    return 1;
}