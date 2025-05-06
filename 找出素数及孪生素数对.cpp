#include<iostream>//标准设备的输入输出
#include<fstream>//磁盘文件的输入输出
#include<iomanip>//字符串处理函数
using namespace std;
#define N 400
bool is_Prime(int x);//验证x是否是素数
int get_Twin(int a[],int n, int b[][2]);//将素数数组a中的孪生素数保存到二维数组b中
void display(int a[], int n);//将数组a中的有效元素按要求在屏幕上输出
void save_file(int b[][2],int n);//将数组b中的孪生素数按要求写入文本文件
int main()
{
	int x[N] = {}, twin[N / 4][2] = {}, n = 0, m = 0, i;
	/*完善程序，调用函数is_Prime查寻1000内的素数，并将它们保存到一维数组x中，
	调用函数get_Twin将数组x的孪生素数存放在二维数组y中*/
	for (i = 2; i < 1000; i++)
	{
		if (is_Prime(i))
			x[n++] = i;
	}
	m = get_Twin(x,n, twin);
	display(x, n);
	save_file(twin, m); 
	return 0;
}
bool is_Prime(int x)
{
	int i;
	for (i = 2; i <= x/2; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
int get_Twin(int a[], int n,int b[][2])
{
	int i,j=0;
	for (i = 0; i <=n - 1; i++)
	{
		if (a[i] + 2 == a[i + 1])
		{
			b[j][0] = a[i];
			b[j][1] = a[i] + 2;
			j++;
		}
	}
	return j;
}
void display(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << setw(6) << a[i];
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
}

void save_file(int b[][2], int n)
{
	ofstream out("孪生素数对.txt");
	for (int i = 0; i < n; i++)
	{
		out << "(" << setw(6) << b[i][0] << "," << setw(6) << b[i][1] << ")\t";
		if ((i + 1) % 4 == 0)
			out << endl;
	}
	out.close();		
}