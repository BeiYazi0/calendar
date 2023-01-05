#include "stdafx.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"
#include "mmsystem.h"
#include "time.h"
#include "string.h"
#include "windows.h"
#pragma comment(lib,"Winmm.lib")
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

void createarray(int year,int m[]);
int weekyear(int year);
int judge(int year);
void transform(int year,int sunmonth,int sunday);
void festival(int sunmonth,int sunday); 
void lunarfestival(int year,int sunmonth,int sunday);
void displayof1(int year,int month,int day);
void displayof2();
void displayof3();
void lifa(int year);
void exhibit(int year,int month,int day);
void music();
void image();

IMAGE img[18],img1[5],img2[3],img3;
MOUSEMSG m;
char str[20] = "";

void image()
{
	int i;
	srand((unsigned)time(NULL));
	i=rand()%17;
	initgraph(1200,852);
	putimage(0,0,&img[i]);
}

void music()
{
	int i;
	srand((unsigned)time(NULL));
	i=rand()%12;
	if(i==0){mciSendString(_T("open ./res/swear.mp3 alias mymusic"), NULL, 0, NULL);}
	if(i==1){mciSendString(_T("open ./res/Memento.mp3 alias mymusic"), NULL, 0, NULL);}
	if(i==2){mciSendString(_T("open ./res/Memory.mp3 alias mymusic"), NULL, 0, NULL);}
	if(i==3){mciSendString(_T("open ./res/bilibili.mp3 alias mymusic"), NULL, 0, NULL);}
	if(i==4){mciSendString(_T("open ./res/Trust.mp3 alias mymusic"), NULL, 0, NULL);}
	if(i==5){mciSendString(_T("open ./res/Wishing.mp3 alias mymusic"), NULL, 0, NULL);}
	if(i==6){mciSendString(_T("open ./res/background.mp3 alias mymusic"), NULL, 0, NULL);}
	if(i==7){mciSendString(_T("open ./res/sky.mp3 alias mymusic"), NULL, 0, NULL);}
	if(i==8){mciSendString(_T("open ./res/date.mp3 alias mymusic"), NULL, 0, NULL);}
	if(i==9){mciSendString(_T("open ./res/wings.mp3 alias mymusic"), NULL, 0, NULL);}
	if(i==10){mciSendString(_T("open ./res/firework.mp3 alias mymusic"), NULL, 0, NULL);}
	if(i==11){mciSendString(_T("open ./res/giant.mp3 alias mymusic"), NULL, 0, NULL);}
	mciSendString(_T("play mymusic repeat"), NULL, 0, NULL);
}

int main()
{
	char s[20]={'\0'},s1[10],s2[10];
music();
    loadimage(&img[0],"./res/1.jpg");loadimage(&img[1],"./res/2.jpg");loadimage(&img[2],"./res/3.jpg");
	loadimage(&img[3],"./res/4.jpg");loadimage(&img[4],"./res/5.jpg");loadimage(&img[5],"./res/6.jpg");
	loadimage(&img[6],"./res/7.jpg");loadimage(&img[7],"./res/8.jpg");loadimage(&img[8],"./res/9.jpg");
	loadimage(&img[9],"./res/10.jpg");loadimage(&img[10],"./res/11.jpg");loadimage(&img[11],"./res/12.jpg");
	loadimage(&img[12],"./res/13.jpg");loadimage(&img[13],"./res/14.jpg");loadimage(&img[14],"./res/15.jpg");
	loadimage(&img[15],"./res/16.jpg");loadimage(&img[16],"./res/17.jpg");loadimage(&img[17],"./res/0.jpg");
s:;
    struct tm *local;
    time_t t;
    t=time(NULL);
    local=localtime(&t);
	sprintf(s, "%d", local->tm_year+1900);
	sprintf(s1, "%d", local->tm_mon+1);
	sprintf(s2, "%d", local->tm_mday);
	strcat(s,"年");
	strcat(s,s1);
	strcat(s,"月");
	strcat(s,s2);
	strcat(s,"日");
  initgraph(780,750);
putimage(0,0,&img[17]);
setbkmode(0);
	settextcolor(CYAN);
    settextstyle(30,0,"楷体");
	outtextxy(610,420,"今天是");
    outtextxy(550,450,s);
while (1)
{
	while (MouseHit())
	{
		m = GetMouseMsg();
		if(m.uMsg == WM_LBUTTONDOWN)
		{
			if(m.x>=635&&m.x<=740&&m.y>=70&&m.y<=105)
			{closegraph();initgraph(873,341);loadimage(&img3,"./res/renwu.jpg");putimage(0,0,&img3);while(1){while (MouseHit()){	m = GetMouseMsg();if(m.uMsg == WM_LBUTTONDOWN){closegraph();goto s;}}}}
			if(m.x>=630&&m.x<=730&&m.y>=140&&m.y<=175)
			{closegraph();displayof2();goto s;}
			if(m.x>=670&&m.x<=700&&m.y>=210&&m.y<=240)
			{closegraph();displayof3();goto s;}
			if(m.x>=630&&m.x<=735&&m.y>=270&&m.y<=305)
			{closegraph();exit(0);}
		}
	}
}
return 0;
}


void displayof2()
{
    int year,sunmonth,week1,sunday,k,i=0,j,n,d;
    int a[13],b[6][7]={0};
	char s[20]={'\0'},s1[10],s2[10],*p,*q;
s1:;
    InputBox(s,20,"请输入时间");
	year=atoi(s);
	p=s;
	while(*p!=' ')p++;
	for(p++,q=s2;*p!='\0';p++,q++)*q=*p;
	*q='\0';
	sunmonth=atoi(s2);
	if(sunmonth<1||sunmonth>12)
	{
		i++;
		if(i==1){initgraph(720,522);loadimage(&img1[0],"./res/a.jpg");putimage(0,0,&img1[0]);}
		if(i==2){initgraph(640,640);loadimage(&img1[1],"./res/b.jpg");putimage(0,0,&img1[1]);}
		if(i==3){initgraph(535,535);loadimage(&img1[2],"./res/c.jpg");putimage(0,0,&img1[2]);}
		if(i==4){initgraph(560,442);loadimage(&img1[3],"./res/d.jpg");putimage(0,0,&img1[3]);}
		if(i==5){initgraph(720,720);loadimage(&img1[4],"./res/e.jpg");putimage(0,0,&img1[4]);system("cls");Sleep(1000);Sleep(1000);Sleep(1000);closegraph();exit(0);}
	    while (1)
		{
	         while (MouseHit())
			 {
				 m = GetMouseMsg();
		         if(m.uMsg == WM_LBUTTONDOWN)
				 {
					 system("cls");closegraph();goto s1;
				 }
			 }
		}
	}
s2:;
	image();
	loadimage(&img2[0],"./res/l.jpg");putimage(350,752,&img2[0]);
	loadimage(&img2[0],"./res/m.jpg");putimage(550,752,&img2[0]);
	loadimage(&img2[0],"./res/r.jpg");putimage(750,752,&img2[0]);
    week1=weekyear(year);
    createarray(year,a);
	for(i=1;i<=sunmonth-1;i++)
	{
		week1=week1+(a[i]%7);
	}
	while(week1>7)
		week1-=7;
	sprintf(s1, "%d", year);//将整形转换成字符串
	sprintf(s2, "%d", sunmonth);
	strcpy(s,s1);
	strcat(s,"年");
	strcat(s,s2);
	strcat(s,"月");
	setbkmode(0);
	settextcolor(GREEN);
    settextstyle(30,0,"楷体");
    outtextxy(0,0,s);
    if(judge(year)==1){
        strcpy(s,s1);strcat(s,"年是闰年");outtextxy(0,30,s);
    }
    if(judge(year)==0){
        strcpy(s,s1);strcat(s,"年是平年");outtextxy(0,30,s);
    }

	lifa(year);outtextxy(200,30,str);
	                                                                                                    	
       
		
		outtextxy(30,70,"周日       周一       周二       周三       周四       周五       周六");

	    settextstyle(25,0,"楷体");
		for(k=1;k<=week1-1;k++)                                                          
	    {b[0][k-1]=0;outtextxy(30+165*(k-1),110," ");}
		for(sunday=1;sunday<=8-week1;sunday++,k++)
	    {b[0][k-1]=sunday;sprintf(s1,"%d",sunday);outtextxy(30+165*(week1+sunday-2),110,s1);}
		
	   
		for(k=1;k<=week1-1;k++)                                                          
	    {outtextxy(30+165*(k-1),110," ");}
	    for(sunday=1;sunday<=8-week1;sunday++)
	    {transform(year,sunmonth,sunday);outtextxy(30+165*(week1+sunday-2),130,str);}
		
		
		for(k=1;k<=week1-1;k++)                                                          
	    {outtextxy(30+165*(k-1),110," ");}
	    for(sunday=1;sunday<=8-week1;sunday++)
		{festival(sunmonth,sunday);outtextxy(30+165*(week1+sunday-2),150,str);}

		
		for(k=1;k<=week1-1;k++)                                                          
	    {outtextxy(30+165*(k-1),110," ");}
	    for(sunday=1;sunday<=8-week1;sunday++)
		{lunarfestival(year,sunmonth,sunday);outtextxy(30+165*(week1+sunday-2),170,str);}
                       
	
		for(i=4;i<=23;i++)                                                               
	    {
		   if(i==4||i==8||i==12||i==16||i==20)                                            
	       {
			   settextstyle(25,0,"楷体");
			   for(j=1;j<=7;j++,sunday++)
			   {
				   n=week1+sunday%7-9;
				   while(n<0)
					   n+=7;
			      if(sunday>a[sunmonth])
			      {sunday=sunday+8-j;j=8;break;}
				  else
			      {d=i/4,k=j,b[i/4][j-1]=sunday;strcpy(s1,"\0");sprintf(s1,"%d",sunday);outtextxy(30+165*n,110+120*(i/4),s1);}
			   }
		   }

		   if(i==5||i==9||i==13||i==17||i==21)                                           
		   { sunday=sunday-7;
			   for(j=1;j<=7;j++,sunday++)
			   {
				   n=week1+sunday%7-9;
				   while(n<0)
					   n+=7;
			       if(sunday>a[sunmonth])
			       {sunday=sunday+8-j;j=8;break;}
			       else
				   {strcpy(str,"\0");transform(year,sunmonth,sunday);outtextxy(30+165*n,130+120*(i/4),str);}
			   }
		   }
		  
		   if(i==6||i==10||i==14||i==18||i==22)                                        
		   { 
			   sunday=sunday-7;
		        for(j=1;j<=7;j++,sunday++)
		   	    {
					n=week1+sunday%7-9;
				   while(n<0)
					   n+=7;
		   	   	  if(sunday>a[sunmonth])
			      {sunday=sunday+8-j;j=8;break;}
				 else		
				  {strcpy(str,"\0");festival(sunmonth,sunday);outtextxy(30+165*n,150+120*(i/4),str);}               
			    } 
           }
		   if(i==7||i==11||i==15||i==19||i==23)                                        
		   { 
			   sunday=sunday-7;
		        for(j=1;j<=7;j++,sunday++)
		   	    {
					n=week1+sunday%7-9;
				   while(n<0)
					   n+=7;
		   	   	  if(sunday>a[sunmonth])
			      {sunday=sunday+8-j;j=8;break;}
				 else		
				  {strcpy(str,"\0");lunarfestival(year,sunmonth,sunday);outtextxy(30+165*n,170+120*(i/4),str);}               
			    } 
           }
		     
		}
		for(i=d;i<6;i++)
		{
			for(;k<7;k++)
				b[i][k]=0;
			k=0;
		}
	while (1)
{
	while (MouseHit())
	{
		m = GetMouseMsg();
		if(m.uMsg == WM_LBUTTONDOWN)
		{
			if(m.x>=350&&m.x<=450&&m.y>=752&&m.y<=852)
			{system("cls");sunmonth--;if(sunmonth==0){sunmonth=12,year--;}closegraph();goto s2;}
			if(m.x>=550&&m.x<=650&&m.y>=752&&m.y<=852)
			{system("cls");closegraph();goto s3;}
			if(m.x>=750&&m.x<=850&&m.y>=752&&m.y<=852)
			{system("cls");sunmonth++;if(sunmonth==13){sunmonth=1,year++;}closegraph();goto s2;}
			if(m.x>=30&&m.y>=110)
			{
				j=(m.x-30)/165,i=(m.y-110)/120;
				if(b[i][j]!=0)
				{closegraph();displayof1(year,sunmonth,b[i][j]);goto s2;}
			}
		}
	}
}
s3:;
}

void displayof1(int year,int month,int day)
{
	int a[13],week1;
	char s[20]={'\0'},s1[10],s2[10],s3[10];
s2:;
	image();
	loadimage(&img2[0],"./res/l.jpg");putimage(350,752,&img2[0]);
	loadimage(&img2[0],"./res/m.jpg");putimage(550,752,&img2[0]);
	loadimage(&img2[0],"./res/r.jpg");putimage(750,752,&img2[0]);
    week1=weekyear(year);
    createarray(year,a);
	sprintf(s1, "%d", year);//将整形a转换成字符串
    sprintf(s2, "%d", month);
	sprintf(s3, "%d", day);
	strcpy(s,s1);
	strcat(s,"年");
	strcat(s,s2);
	strcat(s,"月");
	strcat(s,s3);
	strcat(s,"日");
		setbkmode(0);
	settextcolor(BLUE);
    settextstyle(30,0,"楷体");
	outtextxy(500,200,s);
	if(judge(year)==1){
        strcpy(s,s1);strcat(s,"年是闰年");outtextxy(500,50,s);
    }
    if(judge(year)==0){
        strcpy(s,s1);strcat(s,"年是平年");outtextxy(500,50,s);
    }
    lifa(year);outtextxy(550,100,str);
    exhibit(year,month,day);
	outtextxy(550,300,str);
    transform(year,month,day);
    outtextxy(530,400,str);
    festival(month,day);
    outtextxy(550,500,str);
	lunarfestival(year,month,day);
	outtextxy(550,600,str);
    while (1)
	{
	while (MouseHit())
	{
		m = GetMouseMsg();
		if(m.uMsg == WM_LBUTTONDOWN)
		{
			if(m.x>=350&&m.x<=450&&m.y>=752&&m.y<=852)
			{
				system("cls");day--;
			    if(day==0)
				{month--;
			       if(month==0)
				   {month=12,year--;day=a[month];}
			       else
				   {day=a[month];}
			       closegraph();
			   }
			goto s2;
			}
			if(m.x>=550&&m.x<=650&&m.y>=752&&m.y<=852)
			{system("cls");closegraph();goto s3;}
			if(m.x>=750&&m.x<=850&&m.y>=752&&m.y<=852)
			{
				system("cls");day++;
			    if(day>a[month])
				{
					day=1;month++;
					if(month==13)
					{month=1,year++;}
					closegraph();
				} 
				goto s2;
			}

		}
	}
}
s3:;
}

void displayof3()
{
    int year,month,day,week1,i=0;
    int a[13];
	char s[20]={'\0'},s1[10],s2[10],s3[10],*p,*q;
s1:;
    InputBox(s,20,"请输入时间");
	year=atoi(s);
	p=s;
	while(*p!=' ')p++;
	for(p++,q=s2;*p!=' ';p++,q++)*q=*p;
	*q='\0';
	month=atoi(s2);
	for(p++,q=s3;*p!='\0';p++,q++)*q=*p;
	*q='\0';
	day=atoi(s3);
	createarray(year,a);
	if(month<1||month>12||day<1||day>a[month])
	{
		i++;
		if(i==1){initgraph(720,522);loadimage(&img1[0],"./res/a.jpg");putimage(0,0,&img1[0]);}
		if(i==2){initgraph(640,640);loadimage(&img1[1],"./res/b.jpg");putimage(0,0,&img1[1]);}
		if(i==3){initgraph(535,535);loadimage(&img1[2],"./res/c.jpg");putimage(0,0,&img1[2]);}
		if(i==4){initgraph(560,442);loadimage(&img1[3],"./res/d.jpg");putimage(0,0,&img1[3]);}
		if(i==5){initgraph(720,720);loadimage(&img1[4],"./res/e.jpg");putimage(0,0,&img1[4]);system("cls");Sleep(1000);Sleep(1000);Sleep(1000);closegraph();exit(0);}
	    while (1)
		{
	         while (MouseHit())
			 {
				 m = GetMouseMsg();
		         if(m.uMsg == WM_LBUTTONDOWN)
				 {
					 system("cls");closegraph();goto s1;
				 }
			 }
		}
	}
s2:;
	image();
	loadimage(&img2[0],"./res/l.jpg");putimage(350,752,&img2[0]);
	loadimage(&img2[0],"./res/m.jpg");putimage(550,752,&img2[0]);
	loadimage(&img2[0],"./res/r.jpg");putimage(750,752,&img2[0]);
    week1=weekyear(year);
    createarray(year,a);
	sprintf(s1, "%d", year);//将整形a转换成字符串
    sprintf(s2, "%d", month);
	sprintf(s3, "%d", day);
	strcpy(s,s1);
	strcat(s,"年");
	strcat(s,s2);
	strcat(s,"月");
	strcat(s,s3);
	strcat(s,"日");
		setbkmode(0);
	settextcolor(BLUE);
    settextstyle(30,0,"楷体");
	outtextxy(500,200,s);
	if(judge(year)==1){
        strcpy(s,s1);strcat(s,"年是闰年");outtextxy(500,50,s);
    }
    if(judge(year)==0){
        strcpy(s,s1);strcat(s,"年是平年");outtextxy(500,50,s);
    }
    lifa(year);outtextxy(550,100,str);
    exhibit(year,month,day);
	outtextxy(550,300,str);
    transform(year,month,day);
    outtextxy(530,400,str);
    festival(month,day);
    outtextxy(550,500,str);
	lunarfestival(year,month,day);
	outtextxy(550,600,str);
    while (1)
	{
	while (MouseHit())
	{
		m = GetMouseMsg();
		if(m.uMsg == WM_LBUTTONDOWN)
		{
			if(m.x>=350&&m.x<=450&&m.y>=752&&m.y<=852)
			{
				system("cls");day--;
			    if(day==0)
				{month--;
			       if(month==0)
				   {month=12,year--;day=a[month];}
			       else
				   {day=a[month];}
			       closegraph();
			   }
			goto s2;
			}
			if(m.x>=550&&m.x<=650&&m.y>=752&&m.y<=852)
			{system("cls");closegraph();goto s3;}
			if(m.x>=750&&m.x<=850&&m.y>=752&&m.y<=852)
			{
				system("cls");day++;
			    if(day>a[month])
				{
					day=1;month++;
					if(month==13)
					{month=1,year++;}
					closegraph();
				} 
				goto s2;
			}

		}
	}
}
s3:;
}


int weekyear(int year)
{
	int a=0,b=0,week;
	a=year/4-year/100+year/400;
	if(judge(year)==1)
		a--;
	b=(year-1)*365+a;
	week=2+b%7;
	while(week>7)
		week-=7;
	return week;
}

void createarray(int year,int m[])
{
	int *p=m;
	*p=0,p++;
	*p=31,p++;
	if(judge(year)==1)
		*p=29,p++;
	else
		*p=28,p++;
	*p=31,p++;
	*p=30,p++;
	*p=31,p++;
	*p=30,p++;
	*p=31,p++;
	*p=31,p++;
	*p=30,p++;
	*p=31,p++;
	*p=30,p++;
	*p=31,p++;
}

int judge(int year)
{
	if(year>400&&year%400==0)
	{return 1;}
	
	if(year<4)
	{return 0;}
	
	if(year>=4&&year<100)
	{
	    if(year%4==0)
	    return 1;
	    else
	    return 0;
	}
	
	if(year>=100)
	{
		if(year%4==0&&year%100!=0)
		return 1;
		else
		return 0;	
	}
}

int LunarCalendarDay=0;
int LunarCalendarTable[199] =
{
	0x04AE53,0x0A5748,0x5526BD,0x0D2650,0x0D9544,0x46AAB9,0x056A4D,0x09AD42,0x24AEB6,0x04AE4A,/*1901-1910*/
	0x6A4DBE,0x0A4D52,0x0D2546,0x5D52BA,0x0B544E,0x0D6A43,0x296D37,0x095B4B,0x749BC1,0x049754,/*1911-1920*/
	0x0A4B48,0x5B25BC,0x06A550,0x06D445,0x4ADAB8,0x02B64D,0x095742,0x2497B7,0x04974A,0x664B3E,/*1921-1930*/
	0x0D4A51,0x0EA546,0x56D4BA,0x05AD4E,0x02B644,0x393738,0x092E4B,0x7C96BF,0x0C9553,0x0D4A48,/*1931-1940*/
	0x6DA53B,0x0B554F,0x056A45,0x4AADB9,0x025D4D,0x092D42,0x2C95B6,0x0A954A,0x7B4ABD,0x06CA51,/*1941-1950*/
	0x0B5546,0x555ABB,0x04DA4E,0x0A5B43,0x352BB8,0x052B4C,0x8A953F,0x0E9552,0x06AA48,0x6AD53C,/*1951-1960*/
	0x0AB54F,0x04B645,0x4A5739,0x0A574D,0x052642,0x3E9335,0x0D9549,0x75AABE,0x056A51,0x096D46,/*1961-1970*/
	0x54AEBB,0x04AD4F,0x0A4D43,0x4D26B7,0x0D254B,0x8D52BF,0x0B5452,0x0B6A47,0x696D3C,0x095B50,/*1971-1980*/
	0x049B45,0x4A4BB9,0x0A4B4D,0xAB25C2,0x06A554,0x06D449,0x6ADA3D,0x0AB651,0x093746,0x5497BB,/*1981-1990*/
	0x04974F,0x064B44,0x36A537,0x0EA54A,0x86B2BF,0x05AC53,0x0AB647,0x5936BC,0x092E50,0x0C9645,/*1991-2000*/
	0x4D4AB8,0x0D4A4C,0x0DA541,0x25AAB6,0x056A49,0x7AADBD,0x025D52,0x092D47,0x5C95BA,0x0A954E,/*2001-2010*/
	0x0B4A43,0x4B5537,0x0AD54A,0x955ABF,0x04BA53,0x0A5B48,0x652BBC,0x052B50,0x0A9345,0x474AB9,/*2011-2020*/
	0x06AA4C,0x0AD541,0x24DAB6,0x04B64A,0x69573D,0x0A4E51,0x0D2646,0x5E933A,0x0D534D,0x05AA43,/*2021-2030*/
	0x36B537,0x096D4B,0xB4AEBF,0x04AD53,0x0A4D48,0x6D25BC,0x0D254F,0x0D5244,0x5DAA38,0x0B5A4C,/*2031-2040*/
	0x056D41,0x24ADB6,0x049B4A,0x7A4BBE,0x0A4B51,0x0AA546,0x5B52BA,0x06D24E,0x0ADA42,0x355B37,/*2041-2050*/
	0x09374B,0x8497C1,0x049753,0x064B48,0x66A53C,0x0EA54F,0x06B244,0x4AB638,0x0AAE4C,0x092E42,/*2051-2060*/
	0x3C9735,0x0C9649,0x7D4ABD,0x0D4A51,0x0DA545,0x55AABA,0x056A4E,0x0A6D43,0x452EB7,0x052D4B,/*2061-2070*/
	0x8A95BF,0x0A9553,0x0B4A47,0x6B553B,0x0AD54F,0x055A45,0x4A5D38,0x0A5B4C,0x052B42,0x3A93B6,/*2071-2080*/
	0x069349,0x7729BD,0x06AA51,0x0AD546,0x54DABA,0x04B64E,0x0A5743,0x452738,0x0D264A,0x8E933E,/*2081-2090*/
	0x0D5252,0x0DAA47,0x66B53B,0x056D4F,0x04AE45,0x4A4EB9,0x0A4D4C,0x0D1541,0x2D92B5          /*2091-2099*/
};
int changeday(int year,int sunmonth,int sunday)
{
	int Spring_NY,Sun_NY=0,StaticDayCount;
	int index,flag;
	int month,day;
	//Spring_NY 记录春节离当年元旦的天数。
	//Sun_NY 记录阳历日离当年元旦的天数。
	int m[13],i;
	createarray(year,m);
	if ( ((LunarCalendarTable[year-1901] & 0x0060) >> 5) == 1)
		Spring_NY = (LunarCalendarTable[year-1901] & 0x001F) - 1;
	else
		Spring_NY = (LunarCalendarTable[year-1901] & 0x001F) - 1 + 31;
	for(i=1;i<=sunmonth-1;i++)
	{
		Sun_NY=Sun_NY+m[i];
	}
	Sun_NY=Sun_NY+sunday-1;  
	//StaticDayCount记录大小月的天数 29 或30
	//index 记录从哪个月开始来计算。
	//flag 是用来对闰月的特殊处理。
	//判断阳历日在春节前还是春节后
	if (Sun_NY >= Spring_NY)//阳历日在春节后（含春节那天）
	{
		Sun_NY -= Spring_NY;
		month = 1;
		index = 1;
		flag = 0;
		if ( ( LunarCalendarTable[year - 1901] & (0x80000 >> (index-1)) ) ==0)
			StaticDayCount = 29;
		else
			StaticDayCount = 30;
		while (Sun_NY >= StaticDayCount)
		{
			Sun_NY -= StaticDayCount;
			index++;
			if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20) )
			{
				flag++;
				if (flag == 2)
					month++;
			}
			else
				month++;
			if ( ( LunarCalendarTable[year - 1901] & (0x80000 >> (index-1)) ) ==0)
				StaticDayCount=29;
			else
				StaticDayCount=30;
		}
		day = Sun_NY + 1;
	}
	else //阳历日在春节前
	{
		Spring_NY -= Sun_NY;
		year--;
		month = 12;
		if ( ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20) == 0)
			index = 12;
		else
			index = 13;
		flag = 0;
		if ( ( LunarCalendarTable[year - 1901] & (0x80000 >> (index-1)) ) ==0)
			StaticDayCount = 29;
		else
			StaticDayCount = 30;
		while (Spring_NY > StaticDayCount)
		{
			Spring_NY -= StaticDayCount;
			index--;
			if (flag == 0)
				month--;
			if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
				flag++;
			if ( ( LunarCalendarTable[year - 1901] & (0x80000 >> (index-1)) ) ==0)
				StaticDayCount = 29;
			else
				StaticDayCount = 30;
		}
		day = StaticDayCount - Spring_NY + 1;
	}
	LunarCalendarDay=0;
	LunarCalendarDay |= day;
	LunarCalendarDay |= (month << 6);
	if (flag==1)
		return 1;
	else
		return 0;
}
void transform(int year,int sunmonth,int sunday)
{
	strcpy(str,"\0");
	const char *ChDay[] = {"*","初一","初二","初三","初四","初五",
	                       "初六","初七","初八","初九","初十",
	                       "十一","十二","十三","十四","十五",
	                       "十六","十七","十八","十九","二十",
	                       "廿一","廿二","廿三","廿四","廿五",
	                       "廿六","廿七","廿八","廿九","三十"
	                      };
	const char *ChMonth[] = {"*","正","二","三","四","五","六","七","八","九","十","冬","腊"};
	if (changeday(year,sunmonth,sunday))
	{
		if(year<1901||year>2099)goto s;
		strcat(str,"闰");
		strcat(str,ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
		strcat(str,"月");
	    strcat(str,ChDay[LunarCalendarDay & 0x3F]);
        
	}
	else
	{
		if(year<1901||year>2099)goto s;
		strcat(str,ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
		strcat(str,"月");
	    strcat(str,ChDay[LunarCalendarDay & 0x3F]);
	}
s:;
}
/*=========================================================================================================================================================*/

void festival(int sunmonth,int sunday)
{
    int a;
    a=sunmonth*100+sunday;
	strcpy(str,"\0");
    switch(a)	
	{
        case 101:strcpy(str,"元旦节");
        break;
        case 214:strcpy(str,"情人节");
        break;
        case 308:strcpy(str,"妇女节");
        break;
        case 312:strcpy(str,"植树节");
        break;
        case 401:strcpy(str,"愚人节");
        break;
		case 501:strcpy(str,"劳动节");
        break;
        case 504:strcpy(str,"青年节");
        break;
        case 531:strcpy(str,"无烟节");
        break;
        case 601:strcpy(str,"儿童节");
        break;
        case 605:strcpy(str,"环境保护日");
        break;
        case 606:strcpy(str,"爱眼日");
        break;
        case 701:strcpy(str,"建党节");
        break;
        case 707:strcpy(str,"七七节");
        break;
        case 801:strcpy(str,"建军节");
        break;
        case 806:strcpy(str,"电影节");
        break;
        case 910:strcpy(str,"教师节");
        break;
        case 1001:strcpy(str,"国庆节");
        break;
        case 1031:strcpy(str,"万圣节");
        break;
        case 1126:strcpy(str,"感恩节");
        break;  
        case 1213:strcpy(str,"公祭日");
        break;
        case 1224:strcpy(str,"平安夜");
        break;
        case 1225:strcpy(str,"圣诞节");
        break;
        default:break;
    }
}

void lunarfestival(int year,int sunmonth,int sunday)
{
	strcpy(str,"\0");
    int a,lunarmonth,lunarday;
	if(year<1901||year>2099)goto s;
	changeday(year,sunmonth,sunday);
	strcpy(str,"\0");
	lunarmonth=((LunarCalendarDay&0x3c0)>>6);
    lunarday=(LunarCalendarDay&0x3F);
	a=lunarmonth*100+lunarday;
	switch(a)
	{
	case 101:strcpy(str,"春节");break;
	case 115:strcpy(str,"元宵节");break;
	case 312:strcpy(str,"清明节");break;
	case 505:strcpy(str,"端午节");break;
	case 707:strcpy(str,"七夕");break;
	case 715:strcpy(str,"中元节");break;
	case 815:strcpy(str,"中秋节");break;
	case 909:strcpy(str,"重阳节");break;
	case 1208:strcpy(str,"腊八节");break;
	case 1223:strcpy(str,"小年");break;
	case 1230:strcpy(str,"除夕");break;
	default:break;
	}
s:;
}

void lifa(int year){
	int a=0;
	int b=0;
	a=(year-3)%10;
	b=(year-3)%12;
	strcpy(str,"\0");
	switch(a){
		case 1:
			strcat(str,"甲");
			break;
		case 2:
			strcat(str,"乙");
			break;
		case 3:
			strcat(str,"丙");
			break;
		case 4:
			strcat(str,"丁");
			break;
		case 5:
			strcat(str,"戊");
			break;
		case 6:
		    strcat(str,"己");
			break;
		case 7:
		    strcat(str,"庚");
			break;
		case 8:
		    strcat(str,"辛");
			break;
		case 9:
		    strcat(str,"壬");
			break;
		case 0: 
		    strcat(str,"癸");
			break; 
	}
	switch(b){
		case 1:
			strcat(str,"子");
			break;
		case 2:
			strcat(str,"丑");
			break;
		case 3:
			strcat(str,"寅");
			break;
		case 4:
			strcat(str,"卯");
			break;
		case 5:
			strcat(str,"辰");
			break;
		case 6:
		    strcat(str,"巳");
			break;
		case 7:
		    strcat(str,"午");
			break;
		case 8:
		    strcat(str,"未");
			break;
		case 9:
		    strcat(str,"申");
			break;
		case 10: 
		    strcat(str,"酉");
			break; 
		case 11:
			strcat(str,"戌");
			break;
		case 0:
			strcat(str,"亥");
			break;
	}
	strcat(str,"年");
}

void exhibit(int year,int month,int day)
{
	int week1,i;
	int m[13];
	week1=weekyear(year);
	createarray(year,m);
	strcpy(str,"\0");
	for(i=1;i<month;i++)
	{
		week1=week1+(m[i]%7);
	}
	week1=week1+(day-1)%7;
	while(week1>7)
		week1-=7;
	if(week1==1)strcat(str,"星期日");
	if(week1==2)strcat(str,"星期一");
	if(week1==3)strcat(str,"星期二");
	if(week1==4)strcat(str,"星期三");
	if(week1==5)strcat(str,"星期四");
	if(week1==6)strcat(str,"星期五");
	if(week1==7)strcat(str,"星期六");
}
