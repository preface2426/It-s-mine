#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

// 定义学生结构体，包含学号、姓名和成绩
struct student {
    char id[20];    // 学号
    char name[50];  // 姓名
    float score;    // 成绩
};

// 声明退出系统的函数
void backsystem();

// 声明添加学生信息的函数
void addStu();

// 声明显示所有学生信息的函数
void showStu();

// 声明查找学生信息的函数
void findStu();

// 声明按照成绩排序学生信息的函数
void sortStu();

// 更新学生成绩函数
void updateStuScore();

// 声明显示菜单的函数
void showMenu();