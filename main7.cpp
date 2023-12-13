#include<conio.h>
#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
initwindow(800,800);
int xmov,x,y;
for(xmov=1;xmov<200;xmov=xmov+5)
{
	line(0,400,639,400);
	circle(30+xmov,280,20); //head
	line(30+xmov,300,30+xmov,350);//body
	line(30+xmov,330,70+xmov,330); //hand
if(xmov%2==0)
{
	line(30+xmov,350,25+xmov,400); //left leg
	line(30+xmov,350,10+xmov,400); //right leg
}
else
{
line(30+xmov,350,25+xmov,400);
delay(25);
}
line(55+xmov,200,55+xmov,335); //umbrella
pieslice(60+xmov,250,0,180,50);
for(int i=0;i<=300;i++)
{
x=rand();
y=rand();
outtextxy(x,y,"/");
}
delay(600);
cleardevice();
}
getch();
return 0;
}

