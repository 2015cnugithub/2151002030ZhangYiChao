#include <graphics.h>
#include"Figure.h"
#include"Vehicle.h"
#include"Windows.h"
#include"iostream.h"
#include"string.h"
//#include <graphics.h>   // 绘图库头文件，绘图语句需要
#include "conio.h"      // 控制台输入输出头文件， getch()语句需要 
#include <time.h> 

void delay(int sec)
{ 
   time_t start_time, cur_time; // 变量声明 
time(&start_time); 
do { time(&cur_time); 
} while((cur_time - start_time) < 1.0*sec/(1.0*1000 )); 
} 

void animate(Vehicle *p, int velo)
{
//	for(int i=0;i<10;i++)
	while(!p->Is_out())
	{
		p->erase();
		p->move(velo,0);
		p->draw();
//		delay(9);
		Sleep(50);
		 if(kbhit())
		 {
			 char c=getch();
			 switch(c)
			 {
			 case '=': velo+=10; break;
			 case '-': if(velo>=10) velo-=10; break;
			 case 'p':
				 {
					 while(1)
					 {
						 if(kbhit())
						 {
							 char cq=getch();
							 if (cq=='p') break;
						 }
					 }
				 }break;
			 case 'e': return;break;
			 default:;break;
			 }
		//	 else if(getch()
		 }
	}

}

int main() {  
	initgraph(640, 480);   // 初始化640x480的绘图屏幕  
//	cout<<"    !!!!"<<endl;
/*     setcolor(YELLOW);
    line(200, 240, 440, 240); // 画线(200,240) - (440,240) 
    line(320, 120, 320, 360); // 画线(320,120) - (320,360) 
	
	setfillcolor(0x5555FF);
	 setlinestyle(PS_SOLID, 3);
	fillcircle (150,150 ,40);
    getch();
	*/
/*
	Figure *sta[3];
	Point p(150,170),p1(250,240),p2(370,250),p3(420,440);
	Point p4(450,100),p5(560,100),p6(450,200),p7(560,200);
	Point k[4];
	k[0]=p4;
	k[1]=p5;
	k[2]=p7;
	k[3]=p6;
	Circle c(p,PS_SOLID,0,3,0,0x5555FF,40);
    Triangle t(p1,p2,p3,PS_SOLID,0,4,0,0xAA0000);
	sta[0]=&c;
	sta[0]->draw();
	sta[1]=&t;
	sta[1]->draw();

	Rectangler r1(k,PS_SOLID,0,5,0,0xAA0000);
	sta[2]=&r1;
	sta[2]->draw();
	

	*/
	Point p1(250,240),p2(370,250),p3(420,440),p4(50,350),p5(210,350),p6(50,370),p7(210,370);
	Point p8(85,380),p9(175,380),p10(75,350),p11(95,350),p12(95,330),p13(165,330),p14(165,350);
	Point p15(185,350),p16(70,360),p17(95,360),p18(185,360),p19(210,360),p20(255,360);
		Point k[4],k1[4];
	k[0]=p4;
	k[1]=p5;
	k[2]=p7;
	k[3]=p6;

	Point ea[4];
	ea[0]=p12;
    ea[1]=p13;
	ea[2]=p14;
	ea[3]=p11;

	Point cc[4],dd[4];
		cc[0](50,270);
		cc[1](230,270);
		cc[2](230,350);
		cc[3](50,350);
		dd[0](235,290);
		dd[1](275,290);
		dd[2](275,350);
		dd[3](235,350);
		Rectangler r1(k,PS_SOLID,0,2,0,0xAA0000),r2(ea,PS_SOLID,0,2,0,0xAA0000),r3(cc,PS_SOLID,0,2,0,0xAA0000);
		Rectangler r4(dd,PS_SOLID,0,2,0,0xAA0000);
		Circle c1(p8,PS_SOLID,0,2,0,0x5555FF,10),c2(p9,PS_SOLID,0,2,0,0x5555FF,10),c3(p16,PS_SOLID,0,2,0,0x5555FF,10);
		Circle c4(p17,PS_SOLID,0,2,0,0x5555FF,10),c5(p18,PS_SOLID,0,2,0,0x5555FF,10),c6(p19,PS_SOLID,0,2,0,0x5555FF,10);
		Circle c7(p20,PS_SOLID,0,2,0,0x5555FF,10);
	Triangle t(p10,p11,p12,PS_SOLID,0,2,0,0xAA0000),t1(p15,p14,p13,PS_SOLID,0,2,0,0xAA0000);
	Figure *sta[20];
	sta[0]=&t;
	sta[1]=&r1;
	sta[2]=&c1;
	sta[3]=&c2;
	sta[4]=&r2;
	sta[5]=&t1;

	Figure *mina[20];
	mina[0]=&r3;
	mina[1]=&c3;
	mina[2]=&c4;
	mina[3]=&c5;
	mina[4]=&c6;
	mina[5]=&r4;
	mina[6]=&c7;
	Car c(sta,6);
	Truck tr(mina,7);


//	Car test(sta,1);

	Vehicle *p=&c,*f=&tr/*,*v=&test*/;
//	p->draw();
//	animate(p,10);
	Vehicle *handle=NULL;

	RECT r = {0, 0, 150, 280 };
	RECT ra={50, 50, 450, 280 };
  //　drawtext("Hello World", &r, DT_CENTER);
	char* text={"Press <S> key to start moving\n Press <P> key to pause/continue moving \nPress <E> key to end moving \nPress <+> key to speed up\n	Press <-> key to speed down \n"};
	char* title={"1.car 2.Truck 3.Exit"};
	
    drawtext(title,&r,DT_CENTER);
	while(1)
	{
		if(kbhit())
		{
			 char ci=getch();
			 switch(ci)
			 {
			 case '1':handle=&c;break;
			 case '2':handle=&tr;break;
			 case '3':closegraph();break;
			 default:break;
			 }
		 drawtext(text,&ra,DT_CENTER);
		 break;
		}
	}
    if(handle)
	{
		handle->draw();
		while(1)
		{
			if(kbhit())
			{
			 char cx=getch();
			 if(cx=='s')
				{
				 animate(handle,10);
				 break;
				}
			 if(cx=='e') break;
			}

		}
	}


//	getch();
//    closegraph();
	cout<<endl<<"程序设计：张逸超"<<endl;

 return 0;
}

