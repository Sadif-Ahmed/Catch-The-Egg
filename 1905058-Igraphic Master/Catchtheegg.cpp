/*
	author: Sadif Ahmed
	last modified: December 8, 2020
*/
# include "iGraphics.h"
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<Windows.h>
#include<MMSystem.h>
struct mystruct
{
    int x;
    int y;
} bas,ch,ch2,shit,egg,egg5,egg2,egg3,egg4,timebs,shit2,doom,bt,basb;

int len;
int mode[8]= {0,1,2,3,4,5,6,7},i=7;
char str[80],tm[80];
int eggs=40;
int score=0;
int times=60;
int stopcount=1;
int basfl=0,bbuff=0,bsr=100;
int tmode=0,diffmode=1;
int textmode=0;
int airflag=0,af;
int btime=0,btflag=0;
int doomflag=0,doomtime=0;
int soundflag=1;
int ar1[10]= {0},ar2[10]= {0},ar3[10]= {0},p=0,q=0,r=0;
char scarr1[10][20]= {"NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll"};
char scarr2[10][20]= {"NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll"};
char scarr3[10][20]= {"NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll"};
char nstr[20],nstr2[20];
char names1[20][20]= {"NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll"};
char names2[20][20]= {"NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll"};
char names3[20][20]= {"NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll","NUll"};
/*
	function iDraw() is called again and again by the system.
*/
void vanisher(int* x)
{
    (*x)=2024;
}
void sound(void)
{
    if(soundflag==1)
    {
        PlaySound(TEXT("Sound.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    }
}
void airflow(void)
{
    af=airflag%4;
    airflag++;
}
void pauses(void)
{
    FILE *fp;
    fp=fopen("Pause Buff.txt","w");
    fprintf(fp,"%d\n",times);
    fprintf(fp,"%d\n",score);
    fprintf(fp,"%d\n",ch.x);
    fprintf(fp,"%d\n",ch.y);
    fprintf(fp,"%d\n",ch2.x);
    fprintf(fp,"%d\n",ch2.y);
    fprintf(fp,"%d\n",egg.x);
    fprintf(fp,"%d\n",egg.y);
    fprintf(fp,"%d\n",egg2.x);
    fprintf(fp,"%d\n",egg2.y);
    fprintf(fp,"%d\n",egg3.x);
    fprintf(fp,"%d\n",egg3.y);
    fprintf(fp,"%d\n",egg4.x);
    fprintf(fp,"%d\n",egg4.y);
    fprintf(fp,"%d\n",egg5.x);
    fprintf(fp,"%d\n",egg5.y);
    fprintf(fp,"%d\n",shit.x);
    fprintf(fp,"%d\n",shit.y);
    fprintf(fp,"%d\n",shit2.x);
    fprintf(fp,"%d\n",shit2.y);
    fprintf(fp,"%d\n",timebs.x);
    fprintf(fp,"%d\n",timebs.y);
    fprintf(fp,"%d\n",bt.x);
    fprintf(fp,"%d\n",bt.y);
    fprintf(fp,"%d\n",basb.x);
    fprintf(fp,"%d\n",basb.y);
    fprintf(fp,"%d\n",doom.x);
    fprintf(fp,"%d\n",doom.y);
    fprintf(fp,"%d\n",tmode);
    fprintf(fp,"%d\n",btime);
    fprintf(fp,"%d\n",doomtime);
    fprintf(fp,"%d\n",bbuff);
    fprintf(fp,"%d\n",diffmode);
    fprintf(fp,"%d\n",af);
    fclose(fp);

}
void pauser(void)
{
    FILE *fp;
    fp=fopen("Pause Buff.txt","r");
    fscanf(fp,"%d",&times);
    fscanf(fp,"%d",&score);
    fscanf(fp,"%d",&ch.x);
    fscanf(fp,"%d",&ch.y);
    fscanf(fp,"%d",&ch2.x);
    fscanf(fp,"%d",&ch2.y);
    fscanf(fp,"%d",&egg.x);
    fscanf(fp,"%d",&egg.y);
    fscanf(fp,"%d",&egg2.x);
    fscanf(fp,"%d",&egg2.y);
    fscanf(fp,"%d",&egg3.x);
    fscanf(fp,"%d",&egg3.y);
    fscanf(fp,"%d",&egg4.x);
    fscanf(fp,"%d",&egg4.y);
    fscanf(fp,"%d",&egg5.x);
    fscanf(fp,"%d",&egg5.y);
    fscanf(fp,"%d",&shit.x);
    fscanf(fp,"%d",&shit.y);
    fscanf(fp,"%d",&shit2.x);
    fscanf(fp,"%d",&shit2.y);
    fscanf(fp,"%d",&timebs.x);
    fscanf(fp,"%d",&timebs.y);
    fscanf(fp,"%d",&bt.x);
    fscanf(fp,"%d",&bt.y);
    fscanf(fp,"%d",&basb.x);
    fscanf(fp,"%d",&basb.y);
    fscanf(fp,"%d",&doom.x);
    fscanf(fp,"%d",&doom.y);
    fscanf(fp,"%d",&tmode);
    fscanf(fp,"%d",&btime);
    fscanf(fp,"%d",&doomtime);
    fscanf(fp,"%d",&bbuff);
    fscanf(fp,"%d",&diffmode);
    fscanf(fp,"%d",&af);
    fclose(fp);
}

void saves(int n)
{
    FILE *fop1,*fop2,*fop3;
    fop1=fopen("My Scores(1 minute).txt","a");
    fop2=fopen("My Scores(2 minute).txt","a");
    fop3=fopen("My Scores(3 minute).txt","a");
    if(tmode==1)
    {
        fprintf(fop1,"%d\n",n);

    }
    else if(tmode==2)
    {

        fprintf(fop2,"%d\n",n);

    }
    else if(tmode==3)
    {

        fprintf(fop3,"%d\n",n);

    }
    fclose(fop1);
    fclose(fop2);
    fclose(fop3);
}
void saven(char str[])
{
    FILE *fop1,*fop2,*fop3;
    fop1=fopen("My Scores(1 minute).txt","a");
    fop2=fopen("My Scores(2 minute).txt","a");
    fop3=fopen("My Scores(3 minute).txt","a");
    if(tmode==1)
    {
        fprintf(fop1,"%s\n",str);

    }
    else if(tmode==2)
    {

        fprintf(fop2,"%s\n",str);

    }
    else if(tmode==3)
    {

        fprintf(fop3,"%s\n",str);

    }
    fclose(fop1);
    fclose(fop2);
    fclose(fop3);
}
int Load1(int ar[],char name[][20])
{
    int p=0;
    FILE *fop;
    fop=fopen("My Scores(1 minute).txt","r");
    while(!feof(fop))
    {
        fscanf(fop,"%d",&ar[p]);
        fscanf(fop,"%s",&name[p]);
        if(!feof(fop))
        {
            p++;
        }
    }
    fclose(fop);
    return p;

}
int Load2(int ar[],char name[][20])
{
    int p=0;
    FILE *fop;
    fop=fopen("My Scores(2 minute).txt","r");
    while(!feof(fop))
    {
        fscanf(fop,"%d",&ar[p]);
        fscanf(fop,"%s",&name[p]);
        if(!feof(fop))
        {
            p++;
        }
    }
    fclose(fop);
    return p;

}
int Load3(int ar[],char name[][20])
{
    int p=0;
    FILE *fop;
    fop=fopen("My Scores(3 minute).txt","r");
    while(!feof(fop))
    {
        fscanf(fop,"%d",&ar[p]);
        fscanf(fop,"%s",&name[p]);
        if(!feof(fop))
        {
            p++;
        }
    }
    fclose(fop);
    return p;

}
void sorta(int ar[],int n,char name[][20])
{
    int temp;
    char tmp[20];
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(ar[j]>=ar[i])
            {
                temp=ar[i];
                strcpy(tmp,name[i]);
                ar[i]=ar[j];
                strcpy(name[i],name[j]);
                ar[j]=temp;
                strcpy(name[j],tmp);
            }

        }
    }
}
void strconv(char names[10][20],int ar[])
{
    for(int i=0; i<10; i++)
    {
        sprintf(names[i],"%d",ar[i]);
    }
}
void drawTextBox()
{
    iSetColor(250, 0, 0);
    iRectangle(500, 400, 250, 80);
}
void functionality()
{
    if(mode[i]==2)
    {
        iResumeTimer(0);
        iResumeTimer(1);
        iResumeTimer(2);
        iResumeTimer(3);
        iResumeTimer(4);
        iResumeTimer(5);
        iResumeTimer(6);
        iResumeTimer(7);
        iResumeTimer(8);


    }


    else
    {

        iPauseTimer(0);
        iPauseTimer(1);
        iPauseTimer(2);
        iPauseTimer(3);
        iPauseTimer(4);
        iPauseTimer(5);
        iPauseTimer(6);
        iPauseTimer(7);
        iPauseTimer(8);


    }
    if(times==0)
    {
        times=60;
        saves(score);
        score=0;
        stopcount=0;

    }
    if((score>150)&&(score<250))
    {
        diffmode=2;
    }
    else if(score>250)
    {
        diffmode=3;
    }


}
void timecounter()
{
    if(stopcount==1)
    {
        if(times>0)
        {
            times--;
        }
        if(times==0)
        {
            bas.x=100;
            bas.y=0;
            ch.x=200;
            ch.y=1000;
            ch2.x=300;
            ch2.y=820;
            shit.x=2056;
            shit.y=1020;
            shit2.x=2056;
            shit2.y=820;
            egg.x=2024;
            egg.y=1020;
            egg2.x=2050;
            egg2.y=2050;
            egg3.x=2050;
            egg3.y=2050;
            egg4.x=2050;
            egg4.y=820;
            egg5.x=2050;
            egg5.y=820;
            bt.x=1300;
            bt.y=1300;
            timebs.x=2056;
            timebs.y=1020;
            stopcount=1;
            len = 0;
            textmode = 0;
            diffmode=1;
            nstr[0]= 0;
            i=3;
        }

        sprintf(tm,"%d:%d",times/60,times%60);
        if(bbuff>0)
        {
            bbuff--;
            basfl=1;
            bsr=200;
        }
        else
        {
            basfl=0;
            bsr=100;
        }
        if(btime>0)
        {
            btime--;
            btflag=1;
        }
        else
        {
            btflag=0;
        }
        if(doomtime>0)
        {
            doomtime--;
            doomflag=1;
        }
        else
        {
            doomflag=0;
        }
    }

}
void scorecounter()
{
    if(stopcount==1)
    {
        if((egg.x>bas.x-bsr)&&(egg.x<bas.x+bsr)&&(egg.y>bas.y)&&(egg.y<bas.y+bsr))
        {
            score+=1;
            vanisher(&egg.x);
        }
        else if((egg2.x>bas.x-bsr)&&(egg2.x<bas.x+bsr)&&(egg2.y>bas.y)&&(egg2.y<bas.y+bsr))
        {
            score+=10;
            vanisher(&egg2.x);
        }
        else if((egg3.x>bas.x-bsr)&&(egg2.x<bas.x+bsr)&&(egg3.y>bas.y)&&(egg3.y<bas.y+bsr))
        {
            score+=5;
            vanisher(&egg3.x);
        }
        else if((egg4.x>bas.x-bsr)&&(egg4.x<bas.x+bsr)&&(egg4.y>bas.y)&&(egg4.y<bas.y+bsr))
        {
            score+=50;
            vanisher(&egg4.x);
        }
        else if((egg5.x>bas.x-bsr)&&(egg5.x<bas.x+bsr)&&(egg5.y>bas.y)&&(egg5.y<bas.y+bsr))
        {
            score+=5;
            vanisher(&egg5.x);
        }
        else if((shit.x>bas.x-bsr)&&(shit.x<bas.x+bsr)&&(shit.y>bas.y)&&(shit.y<bas.y+bsr))
        {
            score-=10;
            vanisher(&shit.x);
        }
        else if((shit2.x>bas.x-bsr)&&(shit2.x<bas.x+bsr)&&(shit2.y>bas.y)&&(shit2.y<bas.y+bsr))
        {
            score-=10;
            vanisher(&shit2.x);
        }

        else if((timebs.x>bas.x-bsr)&&(timebs.x<bas.x+bsr)&&(timebs.y>bas.y)&&(timebs.y<bas.y+bsr))
        {
            times+=15;
            vanisher(&timebs.x);
        }
        else if((bt.x>bas.x-bsr)&&(bt.x<bas.x+bsr)&&(bt.y>bas.y)&&(bt.y<bas.y+bsr))
        {
            btime+=10;
            vanisher(&bt.x);
        }
        else if((doom.x>bas.x-bsr)&&(doom.x<bas.x+bsr)&&(doom.y>bas.y)&&(doom.y<bas.y+bsr))
        {   doomtime+=10;
            vanisher(&doom.x);
        }
        else if((basb.x>bas.x-bsr)&&(basb.x<bas.x+bsr)&&(basb.y>bas.y)&&(basb.y<bas.y+bsr))
        {
            bbuff+=5;
            vanisher(&basb.x);
        }
        sprintf(str,"%d",score);
    }
}
void shitstmb()
{
    shit.x=rand()%1150;
    ch.x=shit.x;
    shit.y=1020;
    egg5.x=rand()%1150;
    ch2.x=egg5.x;
    egg5.y=820;

}
void gegg()
{
    egg2.x=rand()%1150;
    ch.x=egg2.x;
    egg2.y=1020;
    bt.x=rand()%1150;
    bt.y=1020;
}
void begg()
{
    egg3.x=rand()%1150;
    ch2.x=egg3.x;
    egg3.y=820;
    doom.x=rand()%1150;
    doom.y=1020;
}
void negg()
{
    egg.x=rand()%1150;
    ch.x=egg.x;
    egg.y=1020;
    shit2.x=rand()%1150;
    ch2.x=shit2.x;
    shit2.y=820;
}
void eegg()
{
    egg4.x=rand()%1150;
    ch2.x=egg4.x;
    egg4.y=820;
    timebs.x=rand()%1150;
    timebs.y=1020;
    basb.x=rand()%1150;
    basb.y=1020;
}
void eggm()
{
    if(btflag==1)
    {
        eggs=30;
    }
    else if(diffmode==1)
    {
        eggs=40;
    }
    else if(diffmode==2)
    {
        eggs=50;
    }
    else if(diffmode==3)
    {
        eggs=60;
    }
    if(doomflag==1)
    {
        eggs=80;
    }

    egg.y-=eggs;
    egg2.y-=eggs;
    shit.y-=eggs;
    shit2.y-=eggs;
    egg3.y-=eggs;
    egg5.y-=eggs;
    egg4.y-=(eggs*2);
    timebs.y-=eggs;
    bt.y-=(eggs*2);
    doom.y-=eggs;
    basb.y-=(eggs*2);
    if(af==0)
    {
        egg.x-=10;
        egg2.x-=10;
        shit.x-=10;
        shit2.x-=10;
        egg3.x-=10;
        egg4.x-=10;
        egg5.x-=10;
        timebs.x-=10;
        bt.x-=10;
        doom.x-=10;
        basb.x-=10;

    }
    else if(af==2)
    {
        egg.x+=10;
        egg2.x+=10;
        shit.x+=10;
        shit2.x+=10;
        egg3.x+=10;
        egg4.x+=10;
        egg5.x+=10;
        timebs.x+=10;
        bt.x+=10;
        doom.x+=10;
        basb.y+=10;

    }
}
void iDraw()
{
    //MAIN PAGE TOGGLER

    //MAIN PAGE
    if(mode[i]==7)
    {
        iClear();
        iShowBMP(0,0,"farm.bmp");
        iSetColor(255,0,0);
        iText(400,1000,"Catch The Egg",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(400,800,500,50);
        iText(410,810,"Start(Press s)",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(400,700,500,50);
        iText(410,710,"Resume(New game if no saved file present)(Press l)",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(400,600,500,50);
        iText(410,610,"See High Score(Press f)",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(400,500,500,50);
        iText(410,510,"Help Menue(Press h)",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(400,400,500,50);
        iText(410,410,"Exit(Press END)",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,0);

    }
    if(mode[i]==0)
    {
        iClear();
        iShowBMP(0,0,"farm.bmp");
        iSetColor(0,0,0);
        iText(450,1150,"HELP MENUE",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,1100,"Press b to return to Menue page",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,1050,"Press h to show help page while playing.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,1000,"Toggle Between  Pages  :  F1",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,950,"Move Basket While Keeping the left mouse button clicked on",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,900,"Move Basket to right: Right Movement Key",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,850,"Move Basket to left : Left Movement Key",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,800,"Pause  Animation  :  p/p",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,750,"Resume Animation  :  r/R",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,700,"Increase  Speed  :  +",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,650,"Decrease  Speed  :  -",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,600,"Game Rules:-(Points Given in accordance to position of the basket)",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,550,"White Eggs give 1 points.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,500,"Blue Eggs give 5 points.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,450,"Golden Eggs give 10 points.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,400,"Easter Eggs give 50 points.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,350,"Catching Shit takes away 10 points.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,300,"Catching Stopwatch grants 15 seconds.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,250,"Catching Star Slows down falling eggs for 10 seconds.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,100,"Catching Skull Increases egg speed for 10 seconds.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450,50,"Catching Donut Extends basket for 5 seconds.",GLUT_BITMAP_TIMES_ROMAN_24);

    }
    else if(mode[i]==1)
    {
        iClear();
        iShowBMP(0,0,"farm.bmp");
        iSetColor(0,0,0);
        iText(500,1000,"Press F1 to start the game",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,900,"Difficulty Ladder:-",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,800,"Easy:Score<150",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,750,"Medium:150<score<250",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,700,"Tough:250<score",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,600,"Give Time Duration:-",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,550,"1 minute:Press 1",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,500,"2 minute:Press 2",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,450,"3 minute:Press 3",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,300,"Game will be saved after pressing End",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,250,"End              :   END",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,200,"BackGround Changes According to Difficulty.",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,0);
    }

    else if(mode[i]==2)
    {
        if(diffmode==1)
        {
            iClear();
            iShowBMP(0,0,"bg1.bmp");
        }
        if(diffmode==2)
        {
            iClear();
            iShowBMP(0,0,"bg2.bmp");
        }
        if(diffmode==3)
        {
            iClear();
            iShowBMP(0,0,"bg3.bmp");
        }
        if(basfl==0)
        {
            iShowBMP2(bas.x,bas.y,"b1.bmp",0xFFFFFF);
        }
        if(basfl==1)
        {
            iShowBMP2(bas.x,bas.y,"extb1.bmp",0xFFFFFF);
        }
        iShowBMP2(ch.x,ch.y,"Chicken.bmp",0xFFFFFF);
        iShowBMP2(ch2.x,ch2.y,"Chicken.bmp",0xFFFFFF);
        iShowBMP2(egg.x,egg.y,"e2.bmp",0xFFFFFF);
        iShowBMP2(egg2.x,egg2.y,"e1.bmp",0xFFFFFF);
        iShowBMP2(egg5.x,egg5.y,"e2.bmp",0xFFFFFF);
        iShowBMP2(egg3.x,egg3.y,"blue.bmp",0xFFFFFF);
        iShowBMP2(egg4.x,egg4.y,"easteregg.bmp",0xFFFFFF);
        iShowBMP2(shit.x,shit.y,"Shit.bmp",0xFFFFFF);
        iShowBMP2(shit2.x,shit2.y,"Shit.bmp",0xFFFFFF);
        iShowBMP2(bt.x,bt.y,"Star.bmp",0xFFFFFF);
        iShowBMP2(doom.x,doom.y,"doom.bmp",0xFFFFFF);
        iShowBMP2(basb.x,basb.y,"donut.bmp",0xFFFFFF);
        iShowBMP2(timebs.x,timebs.y,"stopwatch.bmp",0xFFFFFF);
        iSetColor(0,255,0);
        iText(20,1150,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(100,1150,str,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1000,1150,"Time(s):",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1100,1150,tm,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,0,0);
        iLine(0,800,1200,800);
        iLine(0,1000,1200,1000);

    }
    else if(mode[i]==3)
    {
        iClear();
        iShowBMP(0,0,"farm.bmp");
        iSetColor(0,255,0);

        if(stopcount==1)
        {
            iSetColor(0,0,0);
            iText(400,600,"Pause Menue",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(400,500,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,500,str,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(400,400,"Time(s):",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,400,tm,GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(0,0,0);
        }
        if(stopcount==0)
        {
            iSetColor(0,0,0);
            iText(500,1100,"Press F3 to start again after entering your name.",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,1000,"Game Over",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,800,"Time is over.",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,700,"Your Score is:",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(700,700,str,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,600,"Give your Name(No Space Allowed):",GLUT_BITMAP_TIMES_ROMAN_24);
            drawTextBox();
            if(textmode == 1)
            {
                iSetColor(0,255,0);
                iText(525, 420, nstr,GLUT_BITMAP_TIMES_ROMAN_24);
            }

            iText(500, 320,"Press F4 to activate the box, enter to finish.",GLUT_BITMAP_TIMES_ROMAN_24);

        }
    }
    else if(mode[i]==4)
    {
        iClear();
        iShowBMP(0,0,"farm.bmp");
        iSetColor(125,0,125);
        iText(400,1000,"Press H To Load Hall of Fame",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(400,950,"HALL OF FAME(Category: 1 minute)",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(400,900,"1");
        iText(500,900,names1[0]);
        iText(600,900,scarr1[0]);
        iText(400,850,"2");
        iText(500,850,names1[1]);
        iText(600,850,scarr1[1]);
        iText(400,800,"3");
        iText(500,800,names1[2]);
        iText(600,800,scarr1[2]);
        iText(400,750,"4");
        iText(500,750,names1[3]);
        iText(600,750,scarr1[3]);
        iText(400,700,"5");
        iText(500,700,names1[4]);
        iText(600,700,scarr1[4]);
        iText(400,650,"6");
        iText(500,650,names1[5]);
        iText(600,650,scarr1[5]);
        iText(400,600,"7");
        iText(500,600,names1[6]);
        iText(600,600,scarr1[6]);
        iText(400,550,"8");
        iText(500,550,names1[7]);
        iText(600,550,scarr1[7]);
        iText(400,500,"9");
        iText(500,500,names1[8]);
        iText(600,500,scarr1[8]);
        iText(400,450,"10");
        iText(500,450,names1[9]);
        iText(600,450,scarr1[9]);
        iSetColor(0,0,0);
    }
    else if(mode[i]==5)
    {
        iClear();
        iShowBMP(0,0,"farm.bmp");
        iSetColor(125,0,125);
        iText(400,1000,"HALL OF FAME(Category: 2 minute)",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(400,900,"1");
        iText(500,900,names2[0]);
        iText(600,900,scarr2[0]);
        iText(400,850,"2");
        iText(500,850,names2[1]);
        iText(600,850,scarr2[1]);
        iText(400,800,"3");
        iText(500,800,names2[2]);
        iText(600,800,scarr2[2]);
        iText(400,750,"4");
        iText(500,750,names2[3]);
        iText(600,750,scarr2[3]);
        iText(400,700,"5");
        iText(500,700,names2[4]);
        iText(600,700,scarr2[4]);
        iText(400,650,"6");
        iText(500,650,names2[5]);
        iText(600,650,scarr2[5]);
        iText(400,600,"7");
        iText(500,600,names2[6]);
        iText(600,600,scarr2[6]);
        iText(400,550,"8");
        iText(500,550,names2[7]);
        iText(600,550,scarr2[7]);
        iText(400,500,"9");
        iText(500,500,names2[8]);
        iText(600,500,scarr2[8]);
        iText(400,450,"10");
        iText(500,450,names2[9]);
        iText(600,450,scarr2[9]);
        iSetColor(0,0,0);
    }
    else if(mode[i]==6)
    {
        iClear();
        iShowBMP(0,0,"farm.bmp");
        iSetColor(125,0,125);
        iText(400,1000,"HALL OF FAME(Category: 3 minute)",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(400,900,"1");
        iText(500,900,names3[0]);
        iText(600,900,scarr3[0]);
        iText(400,850,"2");
        iText(500,850,names3[1]);
        iText(600,850,scarr3[1]);
        iText(400,800,"3");
        iText(500,800,names3[2]);
        iText(600,800,scarr3[2]);
        iText(400,750,"4");
        iText(500,750,names3[3]);
        iText(600,750,scarr3[3]);
        iText(400,700,"5");
        iText(500,700,names3[4]);
        iText(600,700,scarr3[4]);
        iText(400,650,"6");
        iText(500,650,names3[5]);
        iText(600,650,scarr3[5]);
        iText(400,600,"7");
        iText(500,600,names3[6]);
        iText(600,600,scarr3[6]);
        iText(400,550,"8");
        iText(500,550,names3[7]);
        iText(600,550,scarr3[7]);
        iText(400,500,"9");
        iText(500,500,names3[8]);
        iText(600,500,scarr3[8]);
        iText(400,450,"10");
        iText(500,450,names3[9]);
        iText(600,450,scarr3[9]);
        iSetColor(0,0,0);
    }



//place your drawing codes here


}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    if(mode[i]==2)
    {
        if(((bas.x+bsr)-mx>=10)&&((bas.x+bsr)>40))
        {
            if(bas.x>40)
                bas.x-=40;
        }
        if(((mx-(bas.x+bsr))>=10)&&((bas.x+bsr)<1200))
        {
            if(bas.x<1160)
                bas.x+=40;
        }

    }


}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here


    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(textmode==0)
    {
        if(key== '+')
        {
            eggs++;

        }
        if(key == '-')
        {
            eggs--;
        }

        if(key=='1')
        {
            times=60;
            tmode=1;


        }
        if(key=='2')
        {
            times=120;
            tmode=2;


        }
        if(key=='3')
        {
            times=180;
            tmode=3;


        }
        if((key=='p')||(key=='P'))
        {
            if(i==2)
            {
                i=3;
            }

        }
        if((key=='r')||(key=='R'))
        {
            if(i==3)
            {
                i=2;
            }
        }

        if(key=='h')
        {
            if(i==2)
            {
                i=0;
            }
            else if(i==0)
            {
                i=2;
            }
            if(i==7)
            {
                i=0;
            }
        }
        if(key=='f')
        {
            if(i==7)
            {
                i=4;
            }
        }
        if(key=='H')
        {
            if(i>3)
            {
                p=Load1(ar1,names1);
                sorta(ar1,p,names1);
                strconv(scarr1,ar1);
                q=Load2(ar2,names2);
                sorta(ar2,q,names2);
                strconv(scarr2,ar2);
                r=Load3(ar3,names3);
                sorta(ar3,r,names3);
                strconv(scarr3,ar3);

            }
        }
        if(key=='l')
        {
            if(i==7)
            {
                pauser();
                i=2;
            }
        }
        if(key=='s')
        {

            if(i==7)
            {
                i=1;
            }
        }

        if((key=='b')||(key=='B'))
        {
            if(i!=7)
            {
                i=7;
            }
        }
    }
    else
    {
        if(key == '\r')
        {
            textmode = 0;
            strcpy(nstr2, nstr);
            saven(nstr2);
            for(int k = 0; k < len; k++)
                nstr[i] = 0;
            len = 0;
        }
        else if(key == 8)
        {
            len--;
        }
        else
        {
            nstr[len] = key;
            len++;
        }

    }
}



//place your codes for other keys here


/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        pauses();
        exit(0);
    }
    if(key == GLUT_KEY_LEFT)
    {
        if(bas.x>=40)
        {
            bas.x-=40;
        }
    }
    if(key == GLUT_KEY_RIGHT)
    {
        if(bas.x<=1160)
        {
            bas.x+=40;
        }
    }
    if(key == GLUT_KEY_F1)
    {
        if(i<6)
        {
            i++;
        }
    }
    if(key == GLUT_KEY_F4)
    {
        if(mode[i]==3)
        {
            textmode = 1;
        }
    }
    if(key == GLUT_KEY_F2)
    {
        if(i>0)
        {
            i--;
        }
    }
    if(key == GLUT_KEY_F3)
    {
        if(i==3)
        {
            bas.x=100;
            bas.y=0;
            ch.x=200;
            ch.y=1000;
            ch2.x=300;
            ch2.y=820;
            shit.x=2056;
            shit.y=1020;
            shit2.x=2056;
            shit2.y=820;
            egg.x=2024;
            egg.y=1020;
            egg2.x=2050;
            egg2.y=2050;
            egg3.x=2050;
            egg3.y=2050;
            egg4.x=2050;
            egg4.y=820;
            doom.x=1500;
            doom.y=1500;
            bt.x=1500;
            bt.y=1500;
            basb.x=1300;
            basb.y=1300;
            timebs.x=2056;
            timebs.y=1020;
            stopcount=1;
            len = 0;
            textmode = 0;
            diffmode=1;
            nstr[0]= 0;
            i=7;
        }

    }
    //place your codes for other keys here
}

int main()
{
    //place your own initialization codes here.
    bas.x=100;
    bas.y=0;
    ch.x=200;
    ch.y=1000;
    ch2.x=300;
    ch2.y=820;
    shit.x=2056;
    shit.y=1020;
    shit2.x=2056;
    shit2.y=820;
    egg.x=2024;
    egg.y=1020;
    egg2.x=2050;
    egg2.y=2050;
    egg3.x=2050;
    egg3.y=2050;
    egg4.x=2050;
    egg4.y=820;
    bt.x=1500;
    bt.y=1500;
    doom.x=1500;
    doom.y=1500;
    basb.x=1500;
    basb.y=1300;
    timebs.x=2056;
    timebs.y=1020;
    len = 0;
    textmode = 0;
    diffmode=1;
    nstr[0]= 0;
    sound();
    iSetTimer(200,scorecounter);
    iSetTimer(1000,timecounter);
    iSetTimer(2000*4.5,negg);
    iSetTimer(2000*4.75,begg);
    iSetTimer(2000*5,gegg);
    iSetTimer(2000*7,eegg);
    iSetTimer(2000*6,shitstmb);
    iSetTimer(200,eggm);
    iSetTimer(1000*2,airflow);
    iSetTimer(1000,functionality);
    iInitialize(1200, 1200, "Catch The Egg");
    return 0;
}
