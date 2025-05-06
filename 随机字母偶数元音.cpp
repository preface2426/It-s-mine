#include<iostream>//标准设备的输入输出
#include<fstream>//磁盘文件的输入输出
#include<iomanip>//字符串处理函数
#include<cstring>//字符串处理函数
using namespace std;
#define N 100

void create_string(char str[]);
int is_even(char str[]);
int get_str(char strings[][11], char result[][11]);

int main()
{
    char strings[N][11], result[N][11];
    int n=0,i;
    ofstream fout("strings.txt");//创建文件流对象，并打开txt文件
    /*编写程序3：调用函数为数组strings中的各行赋值为随机字符串，再将数组内容分别输出到console窗口和txt文件*/
    for(i=0;i<N;i++)
    {
        create_string(strings[i]);
        cout<<strings[i]<<endl;
        fout<<strings[i]<<endl;
    }
    fout.close();//关闭文件流
    ofstream fout1("result.txt");//创建文件流对象，并打开txt文件
    /*调用函数，在函数内统计符合条件的字符串的个数，并将字符串存入数组result中*/
    n= get_str(strings, result);
    /*编写程序4：将统计结果分别输出到console窗口和txt文件*/
    for(i=0;i<n;i++)
    {
        cout<<result[i]<<endl;
        fout1<<result[i]<<endl;
    }
    fout1.close();//关闭文件流
    return 0;
}

/*编写程序6：请在此处给出函数create_string的定义（25分）*/
void create_string(char str[])
{
    int i;
    for(i=0;i<10;i++)
    {
        str[i]='A'+rand()%26;
    }
    str[i]='\0';
}

/*编写程序7：请在此处给出函数get_str的定义（25分）*/
int get_str(char strings[][11], char result[][11])
{
    int i,j=0;
    for(i=0;i<N;i++)
    {
        if(is_even(strings[i]))
        {
            strcpy(result[j],strings[i]);
            j++;
        }
    }
    return j;
}

/*编写程序8：请在此处给出函数is_even的定义（25分）*/
int is_even(char str[])
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if((str[i]-'A')%2==0)
        {
            return 1;
        }
    }
    return 0;
}