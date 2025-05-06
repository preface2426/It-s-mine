#include "student_management.h"
using namespace std;

const char* filename = "students.txt"; // 定义保存学生信息的文件名
ofstream writeFile; // 定义一个用于写入文件的输出文件流
student stu; // 定义一个 student 类型的变量，用于存储单个学生的信息

// 实现退出系统函数
void backsystem() {
    cout << "您已退出系统，欢迎下次使用" << endl;
    system("pause"); // 暂停程序，等待用户操作
    exit(0); // 退出程序
}

// 实现显示所有学生信息函数
void showStu() {
    ifstream readFile(filename); // 打开文件以供读取
    if (!readFile.is_open()) { // 检查文件是否成功打开
        cerr << "无法打开文件进行读取" << endl;
    }

    // 读取文件并显示学生信息
    cout << "学生信息如下：" << endl;
    int sum{0};
    int adverange {};
    int count{0};
    adverange = sum / count;
    while (readFile >> stu.id >> stu.name >> stu.score) { // 循环读取每个学生的信息
        cout << "学号：" << stu.id << ", 姓名：" << stu.name << ", 成绩：" << stu.score << endl;
        sum+= stu.score;
        count++;
    }
    adverange = sum / count;
    cout << "平均成绩为：" << adverange << endl;
    readFile.close(); // 关闭文件
}

// 实现添加学生信息函数
void addStu() {
    writeFile.open(filename, ios::out | ios::app); // 以追加模式打开文件以供写入

    if (!writeFile.is_open()) { // 检查文件是否成功打开
        cerr << "无法打开文件进行写入" << endl;
    }

    // 提示用户输入学生信息
    cout << "请输入学生信息（学号 姓名 成绩）,总共小于一百人，输入'end'结束：" << endl;
    while (true) { // 无限循环，直到用户输入 'end' 结束输入
        cout << "请输入学号: ";
        cin >> stu.id; // 读取学号
        // 检查是否结束输入
        if (strcmp(stu.id, "end") == 0) { // 如果输入 'end'，则结束循环
            break;
        }
        cout << "请输入姓名: ";
        cin >> stu.name; // 读取姓名

        cout << "请输入成绩: ";
        cin >> stu.score; // 读取成绩
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入流中的剩余部分
        // 写入文件
        writeFile << stu.id << " " << stu.name << " " << stu.score << endl;
    }

    writeFile.close(); // 关闭文件
}

// 实现查找学生信息函数
void findStu() {
    string code;
    cout << "请输入要寻找的学号" << endl;
    cin >> code;
    ifstream readFile(filename); // 打开文件以供读取
    if (!readFile.is_open()) { // 检查文件是否成功打开
        cerr << "无法打开文件进行读取" << endl;
    }
    while (readFile >> stu.id >> stu.name >> stu.score) { // 循环读取每个学生的信息
        if (code == stu.id) { // 如果找到匹配的学号
            cout << "学号：" << stu.id << ", 姓名：" << stu.name << ", 成绩：" << stu.score << endl;
        }
    }
    readFile.close(); // 关闭文件
}

// 实现排序学生信息函数
void sortStu() {
    ifstream readFile(filename); // 打开文件以供读取
    student arr[100]; // 定义一个学生数组，最多存储100个学生信息
    int i = 0;
    while (readFile >> stu.id >> stu.name >> stu.score) { // 循环读取每个学生的信息
        arr[i].score = stu.score;
        strcpy(arr[i].id, stu.id); // 复制学号
        strcpy(arr[i].name, stu.name); // 复制姓名
        i++;
    }
    readFile.close(); // 关闭文件

    for (int j = 0; j < 100 - 1; j++) { // 冒泡排序
        for (int i = 0; i < 100 - j - 1; i++) {
            if (arr[i].score < arr[i + 1].score) { // 如果当前学生成绩小于下一个学生成绩，则交换
                swap(arr[i], arr[i + 1]);
            }
        }
    }

    for (int j = 0; j < i; j++) { // 输出排序后的学生信息
        cout << "学号：" << arr[j].id << ", 姓名：" << arr[j].name << ", 成绩：" << arr[j].score << endl;
    }
}

// 实现更新学生成绩函数
void updateStuScore() {
    string id;
    cout << "请输入要更新成绩的学生学号: ";
    cin >> id;

    ifstream readFile(filename); // 打开文件以供读取
    if (!readFile.is_open()) {
        cerr << "无法打开文件进行读取" << endl;
        return;
    }

    // 读取文件到数组中
    student arr[100];
    int i = 0;
    while (readFile >> arr[i].id >> arr[i].name >> arr[i].score) {
        if (strcmp(arr[i].id, id.c_str()) == 0) {
            break;
        }
        i++;
    }
    readFile.close();

    // 如果找到了学生
    if (i < 100 && strcmp(arr[i].id, id.c_str()) == 0) {
        cout << "当前成绩为: " << arr[i].score << ", 请输入新成绩: ";
        cin >> arr[i].score;

        // 将更新后的学生信息写回文件
        ofstream writeFile(filename); // 覆盖原文件
        if (!writeFile.is_open()) {
            cerr << "无法打开文件进行写入" << endl;
            return;
        }
        for (int j = 0; j < 100; j++) {
            if (strcmp(arr[j].id, id.c_str()) != 0 || j == i) {
                writeFile << arr[j].id << " " << arr[j].name << " " << arr[j].score << endl;
            }
        }
        writeFile.close();
        cout << "成绩更新成功！" << endl;
    } else {
        cout << "未找到学号为 " << id << " 的学生。" << endl;
    }
}

// 实现显示菜单的函数
void showMenu() {
    cout << "********************************************" << endl;
    cout << "**********  欢迎使用学生管理系统！ *********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.显示学生信息  *************" << endl;
    cout << "*************  2.增加学生信息  *************" << endl;
    cout << "*************  3.查找学生信息  *************" << endl;
    cout << "*************  4.按照成绩排序  *************" << endl;
    cout << "*************  5.更新学生成绩  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

int main() {
    int choice = 0;
    cout << "是否读取文件:是1.否2" << endl;
    cin >> choice;
    if (choice == 2) {
        writeFile.open(filename, ios::out | ios::app);

        if (!writeFile.is_open()) {
            cerr << "无法打开文件进行写入" << endl;
            return 1;
        }

        cout << "请输入学生信息（学号 姓名 成绩）,小于一百人，输入'end'结束：" << endl;
        while (true) {
            cout << "请输入学号: ";
            cin >> stu.id;
            if (strcmp(stu.id, "end") == 0) {
                break;
            }
            cout << "请输入姓名: ";
            cin >> stu.name;

            cout << "请输入成绩: ";
            cin >> stu.score;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            writeFile << stu.id << " " << stu.name << " " << stu.score << endl;
        }

        writeFile.close();
    }

    int sel;
    while (true) {
        showMenu();
        cin >> sel;
        switch (sel) {
            case 0:
                backsystem();
                break;
            case 1:
                showStu();
                break;
            case 2:
                addStu();
                break;
            case 3:
                findStu();
                break;
            case 4:
                sortStu();
                break;
            case 5: // 处理新的菜单选项
                updateStuScore();
                break;
            default:
                system("cls");
                break;
        }
    }
}