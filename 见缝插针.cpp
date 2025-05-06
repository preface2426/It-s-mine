#include <easyx.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <time.h>

// 将 HSV 颜色值转换成 RGB 颜色值的函数（需要自行实现）
// 这里提供一个简单的示例实现

// 显示 Game Over 消息
void showGameOverMessage(int width, int height, float scale_factor, int score) {
    settextcolor(RED); // 设置文字颜色为红色
    TCHAR s[50];
    _stprintf(s, _T("Game OVER,得分是%d分"), score); // 格式化得分消息
    settextstyle(100 * scale_factor, 0, _T("Consolas"));
    outtextxy(width / 10, height / 3, s); // 显示 Game Over 消息

    TCHAR restartMessage[] = _T("Press Space to Restart");
    settextstyle(50 * scale_factor, 0, _T("Consolas"));
    settextcolor(RGB(0, 0, 0)); // 黑色提示文字
    outtextxy(width / 4, height / 2, restartMessage); // 显示重启提示
    FlushBatchDraw(); // 刷新绘图
}

int main() {
    const float Pi = 3.14159265358979323846; // Pi常量
    int width = 1200;                        // 画面宽度
    int height = 900;                        // 画面高度
    initgraph(width, height);                // 新开一个画面
    setbkcolor(RGB(255, 255, 255));          // 背景为白色
    setlinestyle(PS_SOLID, 3);                // 线宽为3，这样针看起来更明显

    float lineLength = 200;                   // 针的长度
    float xEnd, yEnd;                         // 针的终点位置坐标（针起始位置为圆心）
    float rotateSpeed = Pi / 120;             // 针的旋转速度
    int lineNum = 15;                         // 初始旋转针数量
    float Angles[1000];                       // 浮点数数组，存储所有针的旋转角度，最多1000根针
    int score = 0;                            // 得分
    int i;

    srand((unsigned int)time(NULL));           // 初始化随机数种子

    while (1) { // 主游戏循环
        lineNum = 15;
        score = 0;
        rotateSpeed = Pi / 360;

        for (i = 0; i < lineNum; i++) {
            Angles[i] = ((float)rand() / RAND_MAX) * 2 * Pi; // 随机生成角度 [0, 2*Pi)
        }

        BeginBatchDraw(); // 开始批量绘制
        while (rotateSpeed != 0) { // 游戏循环，旋转速度为0时退出
            cleardevice(); // 以背景色清空背景
            setlinecolor(RGB(0, 0, 0)); // 设置针颜色为黑色
            line(0, height / 2, lineLength, height / 2); // 左边发射区域的一根针

            for (i = 0; i < lineNum; i++) {
                Angles[i] += rotateSpeed; // 针旋转速度逐渐增大
                if (Angles[i] > 2 * Pi) {
                    Angles[i] -= 2 * Pi; // 如果超过2*Pi，就减去2*Pi，防止数据无限增加
                }
                xEnd = lineLength * cos(-Angles[i]) + width / 2; // 计算终点的X坐标
                yEnd = lineLength * sin(-Angles[i]) + height / 2; // 计算终点的Y坐标
                setlinecolor(BLACK); // 设置针的颜色为红色
                line(width / 2, height / 2, xEnd, yEnd); // 绘制旋转针
            }

            // 用户发射新针   
            if (_kbhit() && rotateSpeed != 0) {
                char input = _getch();
                if (input == ' ') { // 如果为空格键
                    if (lineNum < 1000) { // 确保不会超出数组界限
                        Angles[lineNum] = Pi; // 新针的角度
                        lineNum++; // 针的数量增加1
                        for (i = 0; i < lineNum - 1; i++) {
                            if (abs(Angles[i] - Angles[lineNum-1]) < Pi / 60) { // 检查新针与已有针的碰撞
                                showGameOverMessage(width, height, 1.0f, score);
                                Sleep(10000); // 暂停10秒
                                return 0; // 游戏结束
                            }
                        }
                        score++; // 不碰撞增加得分
                    } else {
                        // 达到最大针数，游戏结束
                        showGameOverMessage(width, height, 1.0f, score);
                        Sleep(1000); // 暂停1秒
                        return 0; // 游戏结束
                    }
                }
            }

            if (lineNum > 0 && score > 0) {
                Angles[lineNum] += rotateSpeed; // 针旋转速度逐渐增大
                if (Angles[lineNum - 1] > 2 * Pi) {
                    Angles[lineNum - 1] -= 2 * Pi; // 如果超过2*Pi，就减去2*Pi，防止数据无限增加
                }
                xEnd = lineLength * cos(-Angles[lineNum - 1]) + width / 2; // 计算终点的X坐标
                yEnd = lineLength * sin(-Angles[lineNum - 1]) + height / 2; // 计算终点的Y坐标
                setlinecolor(RED); // 设置针的颜色为红色
                line(width / 2, height / 2, xEnd, yEnd); // 绘制旋转针
            }

            setfillcolor(HSVtoRGB(0, lineNum / 60.0, 0.8));
            setlinecolor(HSVtoRGB(0, 0.9, 0.8));
            fillcircle(width / 2, height / 2, 80); // 绘制中间的圆盘

            TCHAR scoreText[20];
            _stprintf(scoreText, _T("得分: %d"), score);
            settextstyle(60, 0, _T("Times"));
            settextcolor(RGB(50, 50, 50));
            outtextxy(80, 30, scoreText); // 修正得分显示位置

            FlushBatchDraw(); // 批量绘制
            Sleep(10); // 暂停10毫秒
        }

        showGameOverMessage(width, height, 1.0f, score);
        while (!_kbhit() || _getch() != ' ') {
            Sleep(10000); // 保留画面，暂停检测输入
        }
    }

    closegraph(); // 关闭画面
    return 0;
}