#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
//------------Linear transition lines move function-------------------------------------
void q0toq1(int,int,int);
void q1toq2(int,int,int);
void q2toq3(int,int,int);
void q3toq4(int,int,int);
//-----------Linear Tranistion Lines coordinates--------------------------------------------
int l1x1=   85 , l1x2 = 145 , l1y = 178 ;//q0toq1
int l2x1 = 206 , l2x2 = 265 , l2y = 178 ;//q1toq2
int l3x1 = 325 , l3x2 = 383 , l3y = 178 ;//q2toq3
int l4x1 = 445 , l4x2 = 500 , l4y = 178 ;//q3toq4
//------------------------------------------------------------------------------
void skeleton();//Main Machine structure
//-----------------jumper form q3 to q1------------------------------------------------
void q3toq1(int,int,int,int,int,int,int,int,int);  //_31 main fun calls all turnings
int jp2_1y1 = 95  , jp2_1y2 = 159 , jp2_1x = 414 ; //jumper_2 up q3 to q1 turn-1
int jp2_2x1 = 175 , jp2_2x2 = 415 , jp2_2y = 90  ; //jumper_2 L-to-R q3 to q1 turn-2
int jp2_3y1 = 87  , jp2_3y2 = 152 , jp2_3x = 175 ; //jumper_3 down q3 to q1 turn-3
void _31_up(int,int,int);//turn fun-1
void _31_L2R(int,int,int);//turn fun-2
void _31_down(int,int,int);//turn fun-3
//----------------------------------------------------------------------------------
void q2toq0(int,int,int,int,int,int,int,int,int);//_20 main fun calls all turnings
int jp1_1y1 = 210 , jp1_1y2 = 310 , jp1_1x = 294;//jumper_1 down q2 to q0 turn-1
int jp1_2x1 =  50 , jp1_2x2 = 300 , jp1_2y = 310;//jumper_1 R-to-J q2 to q0 turn-2
int jp1_3y1 = 225 , jp1_3y2 = 320 , jp1_3x =  50;//jumper_1 up q2 to q0 turn-3
void _20_down(int,int,int);//turn fun-1
void _20_R2L(int,int,int);//turn fun-2
void _20_up(int,int,int);//turn fun-3
//----------------------------------------------------------------------------------
int lp0_x1 =  40 , lp0_x2 =  60 , lp0_y = 140 ;
int lp1_x1 = 160 , lp1_x2 = 180 , lp1_y = 224 ;
int lp4_x1 = 520 , lp4_x2 = 548 , lp4_y = 135 ;
void q0s_loop(int,int,int);//q0 self loop
void q1s_loop(int,int,int);//q1 self loop
void q4s_loop(int,int,int);//q4 self loop
//------------------------------------------------------------------------------------
void showinput(char[]);//fun for input
//--------------------------------------------------------------------------------
int main()
{
	clrscr();
	char str[40];
	cout<<"Hello User please enter your string :";
	cin>>str;
	clrscr();
	setviewport(50,50,getmaxx()-50,getmaxy()-50,1);

	int gd=DETECT,gm;

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	//main logic
	int i;
	int state = 0;
	for(i=0 ; str[i] != '\0' ; i++)
	{
		cleardevice();
		showinput(str);
		skeleton();
		if(state == 0  && str[i] == '0')
		{
			q0s_loop(lp0_x1, lp0_x2, lp0_y);//q0 self loop
			state = 0;
		}
		else if(state == 0 && str[i] == '1')
		{
			q0toq1(l1x1,l1x2,l1y);
			state = 1;
		}
		else if(state == 1 && str[i] == '0')
		{
			q1toq2(l2x1,l2x2,l2y);
			state = 2;
		}
		else if(state == 1 && str[i] == '1')
		{
			q1s_loop(lp1_x1,lp1_x2,lp1_y);//q1 self loop
			state = 1;
		}
		else if(state == 2 && str[i] == '0')
		{
			q2toq0(jp1_1y1,jp1_1y2,jp1_1x,jp1_2x1, jp1_2x2,jp1_2y,jp1_3y1,jp1_3y2,jp1_3x);
			state = 0;
		}
		else if(state == 2 && str[i] == '1')
		{
			q2toq3(l3x1,l3x2,l3y);
			state = 3;
		}
		else if(state == 3 && str[i] == '0')
		{
			q3toq4(l4x1 , l4x2 , l4y);
			state = 4;
		}
		else if(state == 3 && str[i] == '1')
		{
			q3toq1(jp2_1y1,jp2_1y2,jp2_1x,jp2_2x1,jp2_2x2, jp2_2y,jp2_3y1,jp2_3y2,jp2_3x);
			state = 1;
		}
		else if(state == 4 && str[i] == '0')
		{
			q4s_loop(lp4_x1,lp4_x2,lp4_y);//q4 self loop
			state = 4;
		}
		else if(state == 4 && str[i] == '1')
		{
			q4s_loop(lp4_x1,lp4_x2,lp4_y);//q4 self loop
			state = 4;
		}
		else
		{
			cout<<"Invalid State and Symbol combination"<<endl;
			break;
		}

	}

	if(state == 4)
	{
		outtextxy(30,380,"Reached Final State");
		outtextxy(30,410,"Status : Accepted");
	}
	else
	{
		outtextxy(30,380,"Reached One of The Non-Final State");
		outtextxy(30,410,"Status : Rejected");
	}

	getch();
	closegraph();
	return 0;
}
void skeleton ()
	{
	settextstyle(EUROPEAN_FONT , HORIZ_DIR , 1);

	line(25,195,35,200);//initial line
	line(25,205,35,200);//arrow upper line
	line(5,200,35,200);//Starting line

	circle(60,200,25);//First State
	outtextxy(45,180,"q0");
	line(112,195,122,200);//State Arrow Upper
	line(112,205,122,200);//State Arrow Lower
	line(85,200,155,200);//q0-->q1
	outtextxy(105,145,"1");
	line(40,183,40,140);//|^
	line(40,140,80,140);//--
	line(80,140,80,183);//|v
	//From q0 to q2
	line(60,225,60,340);//|v//jp1_3
	line(60,340,300,340);//--//jp1_2
	line(300,340,300,225);//|^//jp1_1
	line(50,235,60,225);//Left-Arrow
	line(70,235,60,225);//Right-Arrow
	outtextxy(172,340,"0");
	//Self loop
	line(32,173,40,183);//Left-arrow
	line(40,183,48,173);//Right-arrow
	outtextxy(52,93,"0");

	circle(180,200,25);//Second State
	outtextxy(166,178,"q1");
	line(233,195,243,200);//State Arrow Upper
	line(233,205,243,200);//State Arrow Lower
	line(206,200,275,200);//q1-->q2
	outtextxy(230,143,"0");
	//From q1 to q3
	line(180,175,180,110);//|^//jp2_3
	line(180,110,420,110);//--//jp2_2
	line(420,110,420,175);//|v//jp2_1
	line(170,165,180,175);//Left Arrow Wing
	line(180,175,190,165);//Right Arrow Wing
	outtextxy(280,65,"1");
	//Self loop
	line(160,263,160,218);//|^
	line(160,264,200,264);//--
	line(200,264,200,218);//|v
	line(192,228,200,218);//Left-arrow
	line(210,228,200,218);//right-arrow
	outtextxy(170,260,"1");

	circle(300,200,25);//Third State
	outtextxy(285,180,"q2");
	line(352,195,362,200);//State Arrow Upper
	line(352,205,362,200);//State Arrow Lower
	line(325,200,395,200);//q2-->q3
	outtextxy(345,145,"1");

	circle(420,200,25);//Fourth State
	outtextxy(406,180,"q3");
	line(475,195,485,200);//State Arrow Upper
	line(475,205,485,200);//State Arrow Lower
	line(445,200,515,200);//q3-->q4
	outtextxy(472,145,"0");

	circle(540,200,25);
	circle(540,200,20);
	outtextxy(525,178,"q4");//Final State
	line(520,183,520,140);//|^
	line(520,140,560,140);//--
	line(560,140,560,183);//|v
	//Self Loop
	line(510,172,520,183);//Left-arraow
	line(520,183,528,172);//Rigth-arrow
	outtextxy(500,93,"0 ,1");
	delay(1000);
}
void q0toq1(int l1x1 , int l1x2 , int l1y)
{
	int i = 0;
	for (;i<=(l1x2-l1x1);i++)
	{
		outtextxy(l1x1+i , l1y , ">");
		delay(10);
	}
}
void q1toq2(int l2x1 , int l2x2 , int l2y)
{
	int i = 0;
	for (;i<=(l2x2-l2x1);i++)
	{
		outtextxy(l2x1+i , l2y , ">");
		delay(10);
	}
}
void q2toq3(int l3x1 , int l3x2 , int l3y)
{
	int i = 0;
	for(;i<=(l3x2-l3x1);i++)
	{
		outtextxy(l3x1+i , l3y , ">");
		delay(10);
	}
}
void q3toq4(int l4x1 , int l4x2 , int l4y)
{
	int i = 0;
	for(;i<=(l4x2-l4x1);i++)
	{
		outtextxy(l4x1+i , l4y , ">");
		delay(10);
	}
}

//---------------from q3 to q1----------------------------------------------------V
void q3toq1(int jp2_1y1,int jp2_1y2,int jp2_1x,int jp2_2x1,int jp2_2x2,int jp2_2y,int jp2_3y1,int jp2_3y2,int jp2_3x)
{
	_31_up  (jp2_1y1 , jp2_1y2 , jp2_1x);
	_31_L2R (jp2_2x1 , jp2_2x2 , jp2_2y);
	_31_down(jp2_3y1 , jp2_3y2 , jp2_3x);
}
void _31_up(int jp2_1y1,int jp2_1y2,int jp2_1x)
{
	int i;
	for(i=0;i<=(jp2_1y2-jp2_1y1); i++)
	{
		outtextxy(jp2_1x , jp2_1y2-i , "^");
		delay(5);
	}
}
void _31_L2R(int jp2_2x1,int jp2_2x2,int jp2_2y)
{
	int i;
	for(i=0;i<=(jp2_2x2-jp2_2x1); i++)
	{
		outtextxy(jp2_2x2-i , jp2_2y , "<");
		delay(5);
	}
}
void _31_down(int jp2_3y1,int jp2_3y2,int jp2_3x)
{
	int i;
	for(i=0;i<=(jp2_3y2-jp2_3y1); i++)
	{
		outtextxy(jp2_3x , jp2_3y1+i , "v");
		delay(5);
	}
}
//---------------------------------------------------------------------------^

//---------from q2 to q0---------------------------------------------------V
void q2toq0(int jp1_1y1,int jp1_1y2,int jp1_1x,int jp1_2x1,int jp1_2x2,int jp1_2y,int jp1_3y1,int jp1_3y2,int jp1_3x)
{
	_20_down(jp1_1y1,jp1_1y2,jp1_1x);
	_20_R2L (jp1_2x1, jp1_2x2,jp1_2y);
	_20_up  (jp1_3y1,jp1_3y2,jp1_3x);
}
void _20_down(int jp1_1y1 , int jp1_1y2 , int jp1_1x)
{
	int i;
	for(i=0;i<=(jp1_1y2-jp1_1y1); i++)
	{
		outtextxy(jp1_1x , jp1_1y1+i , "v");
		delay(5);
	}
}
void _20_R2L(int jp1_2x1 ,int jp1_2x2 , int jp1_2y)
{
	int i;
	for(i=0;i<=(jp1_2x2-jp1_2x1); i++)
	{
		outtextxy(jp1_2x2-i, jp1_2y , "<");
		delay(5);
	}
}
void _20_up(int jp1_3y1 , int jp1_3y2 , int jp1_3x)
{
	int i;
	for(i=0;i<=(jp1_3y2-jp1_3y1); i++)
	{
		outtextxy(jp1_3x,jp1_3y2-i,"^");
		delay(5);
	}
}
//-----------------------------------------------------------------------^

//----------------Self loops Section-------------------------------------v
void q0s_loop(int lp0_x1 , int lp0_x2, int lp0_y)
{
	int i;
	for(i=0; i<=(lp0_x2-lp0_x1); i++)
	{
		outtextxy(lp0_x2-i , lp0_y , "<");
		delay (30);
	}
}

void q1s_loop(int lp1_x1 , int lp1_x2 , int lp1_y)
{
	int i;
	for(i=0; i<=(lp1_x2-lp1_x1); i++)
	{
		outtextxy(lp1_x1+i , lp1_y , ">");
		delay (30);
	}
}

void q4s_loop(int lp4_x1 , int lp4_x2 , int lp4_y)
{
	int i;
	for(i=0; i<=(lp4_x2-lp4_x1); i++)
	{
		outtextxy(lp4_x2-i , lp4_y , "<");
		delay (30);
	}
}
void showinput(char str[])
{
	settextstyle(EUROPEAN_FONT , HORIZ_DIR , 1);
	outtextxy(1,20,"Input:");
	outtextxy(75,20,str);
}
//-----------------------------------------------------------------------^
