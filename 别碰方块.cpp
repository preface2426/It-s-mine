#include <easyx.h>
#include <conio.h>
#include <iostream>
using namespace std;
//在...处根据提示补全代码

int main() {
    // 游戏画面宽高、重力加速度
    float width, height, gravity;
    // 小球圆心坐标、y方向速度、半径大小
    float ball_x, ball_y, ball_vy, radius;
    // 方块障碍物的相关参数
    float rect_left_x, rect_top_y, rect_width, rect_height, rect_vx;
    int score = 0; // 得分
    int isBallOnFloor = 1; // 小球是否在地面上，避免重复起跳
    int x=0;
    // 初始化游戏参数
    width = 600; // 游戏画面宽度
    height = 400; // 游戏画面高度
    gravity = 0.6; // 重力加速度
    initgraph(width, height); // 新建一个画布

    radius = 20; // 小球半径
    ball_x = width / 4; // 小球x位置
    ball_y = height - radius; // 小球y位置
    ball_vy = 0; // 小球初始y速度为0

    rect_height = 100; // 方块高度
    rect_width = 20; // 方块宽度
    rect_left_x = width * 3 / 4; // 方块左边x坐标
    rect_vx = -3; // 方块x方向速度

    // 游戏主循环
    while (1) {
        // 检测按键输入
        if (_kbhit()) {
            char input = _getch(); // 获得输入字符
            if (input == ' '&&isBallOnFloor==1) { // 当按下空格键时
                ball_vy = -17;
                isBallOnFloor = 0; // 给小球一个向上的速度
            }
        }

        ball_vy += gravity;// 更新小球y方向速度和位置
        ball_y +=ball_vy; // 更新小球位置
        // 检测小球是否落到地面上
        if(ball_y>=height-radius){
            ball_vy = 0;
            ball_y=height-radius;
            isBallOnFloor = 1;
        }
        //.....................
        
        // 如果小球碰到方块
        if ((rect_left_x <= ball_x + radius)&& (rect_left_x + rect_width >= ball_x - radius)&& (height - rect_height <= ball_y + radius) ){
        Sleep(100);
        x--;
        }//慢动作效果
        
        // 更新方块位置
        rect_left_x = rect_left_x + rect_vx; // 方块向左移
        if (rect_left_x <= 0) { // 如果方块跑到最左边
            rect_left_x = width; // 在最右边重新出现
            score = score + 1;
            settextcolor(WHITE);// 得分+1
            if(x<0){
                score=score-2;
                x = 0;
                settextcolor(RED);
            }
            rect_height = rand() % int(height / 4) + height / 4; // 设置随机高度
            rect_vx = rand() / float(RAND_MAX) * 4 - 7; // 设置方块随机速度
        }


        if(rect_top_y==height-radius){
            ball_vy = 0;
            ball_y=height-radius;
        }

        cleardevice();
        fillcircle(ball_x, ball_y, radius); // 绘制小球
        fillrectangle(rect_left_x, height - rect_height,
            rect_left_x + rect_width, height); // 绘制方块
        TCHAR s1[20];
        _stprintf_s(s1, _T("%d"), score); // 将score转换为字符串
        settextstyle(40, 0, _T("宋体")); // 设置文字大小、字体
        outtextxy(50, 30, s1); // 输出得分文字

        // 清空画面并重新绘制
        Sleep(10); // 暂停10毫秒
    }

    closegraph();
    return 0;
}
