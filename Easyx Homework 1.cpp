#include <iostream>
#include <easyx.h>
#include <cmath>
#include <conio.h>
#include <windows.h> // For Sleep function

int main()
{
  // 初始化变量
  float ball_x = 100, ball_y = 500; // 球的初始位置
  float r = 20;                     // 球的半径（用来参考圆心位置）
  float g = 9.8;                    // 重力加速度
  float v_x = 20;                   // 水平方向速度
  float v_y = -80;                  // 竖直方向初始速度，负值表示向上抛
  float time_step = 1;              // 时间步长
  int weight = 600, height = 600;   // 窗口的宽度和高度

  // 记录前一个位置
  float prev_ball_x = ball_x;
  float prev_ball_y = ball_y;

  // 初始化图形窗口
  initgraph(weight, height);
  // 设置轨迹线的颜色为蓝色

  // 第1次移动（上升）
setlinecolor(YELLOW);
for (int i = 0; i < 19; i++){
  ball_x = ball_x + v_x * time_step;
  ball_y = ball_y + v_y * time_step - 0.5 * g * time_step * time_step;
  line(prev_ball_x, prev_ball_y, ball_x, ball_y); // 连接前一个点与当前点
  v_y = v_y + g * time_step;                      // 更新竖直速度
  prev_ball_x = ball_x;
  prev_ball_y = ball_y; // 更新前一个位置
  Sleep(500);           // 暂停500毫秒
  }
for (int i = 0; i < 19; i++){
    ball_x = ball_x + v_x * time_step;
    ball_y = ball_y + v_y * time_step - 0.5 * g * time_step * time_step;
    line(prev_ball_x, prev_ball_y, ball_x, ball_y); // 连接前一个点与当前点
    v_y = v_y - g * time_step;                      // 更新竖直速度
    prev_ball_x = ball_x;
}
  // 关闭图形窗口
  system("pause");
  closegraph();
  return 0;
}
