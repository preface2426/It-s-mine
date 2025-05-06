#include <easyx.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main()
{
	float PI = 3.1415926;
	int width = 800;
	int height = 600;
	initgraph(width, height);
	setbkcolor(RGB(255, 255, 255));
	setlinestyle(PS_SOLID, 3);								     // 线宽为3

	float lineLength = 160;
	float xEnd, yEnd;
	float rotateSpeed = PI / 360;
	int lineNum = 0;
	float Angles[1000];
	int score = 0;
	int i;

	BeginBatchDraw();                                           
	while (1)
	{
		cleardevice();
		setlinecolor(RGB(0, 0, 0));
		line(0, height / 2, lineLength, height / 2);             // 左边发射区域的一根针

		for (i = 0; i < lineNum; i++)
		{
			Angles[i] += rotateSpeed;
			if (Angles[i] > 2 * PI)                              // 防止角度数据无限增加
			{
				Angles[i] -= 2 * PI;
			}
			xEnd = lineLength * cos(-Angles[i]) + width / 2;     // 计算针的末端坐标
			yEnd = lineLength * sin(-Angles[i]) + height / 2;
			setlinecolor(RGB(0, 0, 255));                        // 设定旋转针的颜色为蓝色
			if (i == lineNum - 1)
			{
				setlinecolor(RGB(255, 0, 0));                    // 新增的针为红色
			}
			line(width / 2, height / 2, xEnd, yEnd);             // 绘制一根针
		}

		if (_kbhit() && rotateSpeed != 0)
		{
			char input = _getch();
			if (input == ' ')                                    // 如果为空格键
			{
				lineNum++;
				Angles[lineNum - 1] = PI;
				xEnd = lineLength * cos(-Angles[lineNum - 1]) + width / 2;
				yEnd = lineLength * sin(-Angles[lineNum - 1]) + height / 2;
				line(width / 2, height / 2, xEnd, yEnd);
				for (i = 0; i < lineNum - 1; i++)                // 拿新的针和之前所有针比较
				{
					if (fabs(Angles[lineNum - 1] - Angles[i]) < PI / 60)
					{
						rotateSpeed = 0;                         // 如果碰撞，停止旋转
						break;
					}
				}
				score += 1;
			}
		}
		setfillcolor(HSVtoRGB(0, lineNum / 60.0, 0.8));          // 针越多，圆盘颜色越鲜艳
		setlinecolor(HSVtoRGB(0, 0.9, 0.8));                     // 圆盘线条颜色为红色
		fillcircle(width / 2, height / 2, 60);                   // 绘制中间的圆盘
		TCHAR s[20];                                             // 定义字符串数组
		swprintf_s(s, _T("%d"), score);
		settextstyle(50, 0, _T("Times"));                        // 设置文字大小、字体
		settextcolor(RGB(50, 50, 50));
		outtextxy(65, 200, s);

		FlushBatchDraw();
		Sleep(10);
	}
	closegraph();
	return 0;
}
