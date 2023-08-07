#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include"priority.h"
#include"srt.h"
#include"aging.h"
#include"mod_srt.h"


void choice();
void interface();
void choose_algo();
void after_choosing_algo();
void start_priority();
void start_srjf();
void start_priority_aging();
void start_srjf_modify();
void nxt_prev_button();
void priority();
void srjf();
void aging();
void modify();


union REGS in,out;
void showmouse()
{
	in.x.ax=1;
	int86(0x33,&in,&out);
}

void getmousepos(int *b,int *x,int *y)
{
	in.x.ax=3;
	int86(0x33,&in,&out);
	*b=out.x.bx;
	*x=out.x.cx;
	*y=out.x.dx;
}
void setposi(int xpos, int ypos)
{
in.x.ax=4;
in.x.cx=xpos;
in.x.dx=ypos;
int86(0x33,&in,&out);
}



void interface()          //first function
{
       // First interaction of user with the screen
	int i,b,x,y;
	while(!( kbhit()))
	{
		if(i>15)
		i=0;
		setcolor(i++);
		delay(100);
		settextstyle(TRIPLEX_FONT,0,4);
		outtextxy(120,160,"PERFORMANCE ANALYSIS ON ");
		outtextxy(120,200,"CPU SCHEDULING ALGORITHMS");
	}
	getch();
	cleardevice();
}

void choice()          //choose want to start the scheduling or exit
{                      //2 interface

	setcolor(WHITE);
	rectangle(30,30,90,60);
	rectangle(550,420,610,450);
	settextstyle(TRIPLEX_FONT,0,1);
	outtextxy(35,33,"START");
	outtextxy(563,423,"EXIT");
	outtextxy(140,190,"WANT TO START? CLICK ON START BUTTON");
	outtextxy(170,215,"WANT TO EXIT? CLICK ON EXIT BUTTON");

}


void choose_algo()
{	      //choose an algorithm by which u want to schedule your processes
	int b,x,y;      //3 interface
	while(!kbhit())
	{
		b=out.x.bx;
		x=out.x.cx;
		y=out.x.dx;
		getmousepos(&b,&x,&y);
		if((b & 1)==1)
		{
			if(x>=30 && y >=30 && x<=90 && y<=60)
			{
				cleardevice();
				outtextxy(10,40,"Click on your choice by which algorithm you want to execute your");
				outtextxy(10,60,"processes");
				rectangle(10,90,235,120);
				outtextxy(18,93,"PRIORITY SCHEDULING");
				rectangle(10,130,450,160);
				outtextxy(18,133,"PRIORITY SCHEDULING WITH AGING TECHNIQUE");
				rectangle(10,170,510,200);
				outtextxy(18,173,"SHORTEST REMAINING TIME FIRST(SRTF) SCHEDULING");
				rectangle(10,210,600,240);
				outtextxy(18,213,"MODIFIED SHORTEST REMAINING TIME FIRST(SRTF) SCHEDULING");
				after_choosing_algo();

			 }
		else                                        //to exit from the algorithm
		if(x>=550 && y>=420 && x<=610 && y<=450)
		{
			exit(0);
		}
	    }
	}
}

void nxt_prev_button()
{
	setcolor(WHITE);
	rectangle(550,420,610,450);
	settextstyle(TRIPLEX_FONT,0,1);
	outtextxy(558,423,"NEXT");
	rectangle(480,420,540,450);
	outtextxy(488,423,"PREV");
 }

void after_choosing_algo() //choose an algorithm
{                          //4interface
	int b,x,y;
	while(!kbhit())
	{
		b=out.x.bx;
		x=out.x.cx;
		y=out.x.dx;
		getmousepos(&b,&x,&y);
		if((b & 1)==1)
		{
			if(x>=10 && y>=90 && x<=235 && y<=120)   //priority interface
			{                                        //rectangle(10,90,300,120);
				cleardevice();
				settextstyle(TRIPLEX_FONT,0,4);
				outtextxy(150,160,"WELCOME IN THE PRIORITY ");
				outtextxy(230,200,"SCHEDULING ALGORITHM");
				nxt_prev_button();
				start_priority();
			}
			if(x>=10 && y>=130 && x<=450 && y<=160)   //priority interface
			{                                        //rectangle(10,90,300,120);
				cleardevice();
				settextstyle(TRIPLEX_FONT,0,4);
				outtextxy(150,160,"WELCOME IN THE PRIORITY ");
				outtextxy(230,200,"SCHEDULING ALGORITHM");
				outtextxy(230,240,"WITH AGING TECHNIQUE");
				nxt_prev_button();
				start_priority_aging();
			}
			if(x>=10 && y>=170 && x<=510 && y<=200)    //SRJF interface
			{                                          //rectangle(10,130,500,160);
				cleardevice();
				settextstyle(TRIPLEX_FONT,0,4);
				outtextxy(150,160,"WELCOME IN THE SRJF ");
				outtextxy(230,200,"SCHEDULING ALGORITHM");
				nxt_prev_button();
				start_srjf();

			}
			if(x>=10 && y>=210 && x<=600 && y<=240)   //priority interface
			{                                        //rectangle(10,90,300,120);
				cleardevice();
				settextstyle(TRIPLEX_FONT,0,4);
				outtextxy(140,160,"WELCOME IN THE MODIFIED SRJF ");
				outtextxy(230,200,"SCHEDULING ALGORITHM");
				nxt_prev_button();
				start_srjf_modify();
			}
		}
	}
}

void start_priority()
{
	int b,x,y;
	while(!kbhit())
	{
		b=out.x.bx;
		x=out.x.cx;
		y=out.x.dx;
		getmousepos(&b,&x,&y);
		if((b & 1)==1)
		{
			if(x>=550 && y>=420 && x<=610 && y<=450) // rectangle(550,420,610,450);
			{
				cleardevice();
				priority();

			}
			else
			 if(x>=480 && y>=420 && x<=510 && y<=450) // rectangle(480,420,540,450);
			 {
				cleardevice();
				choice();
				choose_algo();
			 }

		}
	}
}

void start_srjf()
{
	int b,x,y;
	while(!kbhit())
	{
		b=out.x.bx;
		x=out.x.cx;
		y=out.x.dx;
		getmousepos(&b,&x,&y);
		if((b & 1)==1)
		{
			if(x>=550 && y>=420 && x<=610 && y<=450) // rectangle(550,420,610,450);
			{
				cleardevice();
				srt();
			}
			else
			 if(x>=480 && y>=420 && x<=510 && y<=450) // rectangle(480,420,540,450);
			 {
				cleardevice();
				choice();
				choose_algo();
			 }

		}
	}
}

void start_priority_aging()
{
	int b,x,y;
	while(!kbhit())
	{
		b=out.x.bx;
		x=out.x.cx;
		y=out.x.dx;
		getmousepos(&b,&x,&y);
		if((b & 1)==1)
		{
			if(x>=550 && y>=420 && x<=610 && y<=450) // rectangle(550,420,610,450);
			{
				cleardevice();
				aging();
			}
			else
			 if(x>=480 && y>=420 && x<=510 && y<=450) // rectangle(480,420,540,450);
			 {
				cleardevice();
				choice();
				choose_algo();
			 }

		}
	}
}

void start_srjf_modify()
{
	int b,x,y;
	while(!kbhit())
	{
		b=out.x.bx;
		x=out.x.cx;
		y=out.x.dx;
		getmousepos(&b,&x,&y);
		if((b & 1)==1)
		{
			if(x>=550 && y>=420 && x<=610 && y<=450) // rectangle(550,420,610,450);
			{
				cleardevice();
				mod_srt();
			}
			else
			 if(x>=480 && y>=420 && x<=510 && y<=450) // rectangle(480,420,540,450);
			 {
				cleardevice();
				choice();
				choose_algo();
			 }

		}
	}
}


void main()
{
	int gd=DETECT,gm,b,x,y,X=320,Y=240;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	//1.
	interface();
	setposi(X,Y);
	showmouse();
	setcolor(BLACK);
	rectangle(0,0,639,479);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(10,10,BLACK);
	//2.
	choice();
	choose_algo();
	after_choosing_algo();
	getch();
}

