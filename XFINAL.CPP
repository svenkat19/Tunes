#include<dos.h>
#include<iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include<fstream.h>
#include <stdio.h>
#include <conio.h>
#include<string.h>
char user2[20],user[20],pass[20],pass2[20],curUsername[20],usingUsername[20];
class user{
	     char username[20];
			char password[20];
			public:
			void uInput()
			{
			  strcpy(username,user);
			 }
			 void pInput()
			 {
			  strcpy(password,pass);
			  }
	    char* retUsername()
			{
				return(username);
			}
	    char* retPassword()
			{
				return(password);
			}
}obj,a;
int kk,kj;
char w,k,z;
class song{
	    char songName[20];
	    char singer[20];
	    char genre[20];
	    public:
	    char * retsongName()
	    {return(songName);}
	    char * retsinger()
	    { return(singer);}
	    char * retgenre()
	     {return(genre);}
	    void inss(int j=17,int k=15)
	    {	 char ch;
		 for(int i=0;i<20;++i,j=j+1)
		{ch=getch();
		int r=ch;
		if(r!=13)
		 {

		  gotoxy(j,k);
		 printf("%c",ch);
		 songName[i]=ch;
		  }
		else
		break;
		}
		  songName[i]='\0';

	    }

	    void inssR(int j=38,int k=15)
	    {
	     char ch;
		 for(int i=0;i<20;++i,j=j+1)
		{

		 ch=getch();
		int r=ch;
		if(r!=13)
		 {

		  gotoxy(j,k);
		 printf("%c",ch);
		 singer[i]=ch;
		  }
		else
		break;
		}
		  singer[i]='\0';

	    }

	    void insg(int j=57,int k=15)
	    {
	     char ch;
		 for(int i=0;i<20;++i,j=j+1)
		{

		 ch=getch();
		int r=ch;
		if(r!=13)
		 {

		  gotoxy(j,k);
		 printf("%c",ch);
		 genre[i]=ch;
		  }
		else
		break;
		}
		  genre[i]='\0';}}q,s,l,d;
//--------------------------------------------------------------------------------------//
void logOut();void acceptSong();void deleteSong();void viewSong();
void introMenu();void login();void screenSignUp();void wrong();
void exist();void signup();void createPlaylist();void deletePlaylist();
void into();int check(char checkS[20]);void mainMenu();void viewList();
void help();
song u;
void viewList()
{
   cleardevice();
 char playU[20];
  strcpy(playU,usingUsername);
  strcat(playU,".DAT");
   setcolor(WHITE);
   char ch1[20],ch2[20],ch3[20];
   rectangle(15,10,625,460);
   settextstyle(0,0,1);
   fstream file(playU,ios::in|ios::app|ios::binary);
   file.seekg(0,ios::end);
   if(file.tellg()==0)
   {  outtextxy(270,120,"PLAYLIST EMPTY");file.close();goto afin;}
  else
  {
    file.seekg(0,ios::beg);
   int jj=0;
      int countx1,countx2,countx3,county;
   while(file.read((char*)&d,sizeof(d)))
    {
      if(jj%23==0)
      {
       cleardevice();
    settextstyle(2,0,7);
    outtextxy(30,10,"SINGER");
    outtextxy(310,10,"SONG_NAME");
    outtextxy(480,10,"GENRE");
       rectangle(15,10,625,460);
       settextstyle(0,0,1);
       strcpy(ch1,d.retsongName());
    strcpy(ch2,d.retsinger());
    strcpy(ch3,d.retgenre());
    delay(300);
    outtextxy(30,30,ch1);
    outtextxy(310,30,ch2);
    outtextxy(480,30,ch3);
    countx1=30;countx2=310;countx3=480;county=50;
    jj++; }
    else
    {
      strcpy(ch1,d.retsongName());
    strcpy(ch2,d.retsinger());
    strcpy(ch3,d.retgenre());
    delay(300);
    outtextxy(countx1,county,ch1);
    outtextxy(countx2,county,ch2);
    outtextxy(countx3,county,ch3);
    county+=20;
    jj++;
    }
   }
   }
   file.close();
   afin:
   getch();
}
int check(char checkS[20])
{
  char playU[20];
		   strcpy(playU,usingUsername);
		   strcat(playU,".DAT");
		 fstream F(playU,ios::in|ios::app|ios::binary);
		 song ob;
		 while(F.read((char*)&ob,sizeof(ob)))
		 {
		    if(strcmpi(ob.retsongName(),checkS)==0)
		     {F.close(); return (1);  }
		 }
	      F.close();
	      return 0;

}
void into()
{
   fstream tl("TEMP.DAT",ios::in|ios::app|ios::binary);
   tl.seekp(0,ios::end);
  tl.write((char*)&u,sizeof(u));
  tl.close();
}
void deletePlaylist()
{
    char playU[20],namee[20];
    int kntr=0;
		   clrscr();
		   cleardevice();
		   settextstyle(0,0,1);
		   strcpy(playU,usingUsername);
		   strcat(playU,".DAT");
		    rectangle(15,10,625,460);
		   rectangle(120,100,500,270);
		   outtextxy(122,150,"ENTER SONG NAME");
		   char ch;
		   int j=45,k=10;
		    for(int i=0;i<20;++i,j=j+1)
		{

		 ch=getch();
		int r=ch;
		if(r!=13)
		 {

		  gotoxy(j,k);
		 printf("%c",ch);
		 namee[i]=ch;
		  }
		else
		break;
		}
		  namee[i]='\0';

	      fstream file(playU,ios::in|ios::app|ios::binary);

	      while(file.read((char*)&u,sizeof(u)))
	      {
		if(strcmpi(u.retsongName(),namee)==0)
		   kntr++;
		else
		{
		 into();
		}

	      }
	       file.close();
	       remove(playU);
	       rename("TEMP.DAT",playU);
	       if(kntr==0)
		 {outtextxy(190,85,"ERROR:SONG NOT FOUND IN YOUR LIST!");}
		 else{outtextxy(200,85,"SUCCESS:SONG DELETED FROM YOUR LIST!");}
		 getch();
}
void createPlaylist()
{
	 char playU[20],namee[20];
	 char numr;
	 upk:
		   clrscr();
		   cleardevice();
		   settextstyle(0,0,1);
		   strcpy(playU,usingUsername);
		   strcat(playU,".DAT");
		   cout<<"\n\n\tDO YOU WANT TO CREATE A NEW PLAYLIST?(Y/N)";
		   cout<<"\t";
		   cin>>numr;
	 switch(numr)
	 {
	 case 'Y': remove(playU);break;
	 case 'y': remove(playU);break;
	 case 'n': break;
	 case 'N':break;
	 default:goto upk;
	 }

 int tot=0;
  settextstyle(0,0,1);
		  cleardevice();
		  rectangle(15,10,625,460);
		   rectangle(120,100,500,270);
		   outtextxy(122,150,"ENTER SONG NAME");
		   char ch;
		   int j=45,k=10;
		 for(int i=0;i<20;++i,j=j+1)
		{

		 ch=getch();
		int r=ch;
		if(r!=13)
		 {

		  gotoxy(j,k);
		 printf("%c",ch);
		 namee[i]=ch;
		  }
		else
		break;
		}
		  namee[i]='\0';

		   song t;
		   fstream fle("SONGD.DAT",ios::in|ios::app|ios::binary);
		   while(fle.read((char*)&t,sizeof(t)))
		   {
		     if(strcmpi(t.retsongName(),namee)==0)
		     {
			tot++;
			goto toto;
		     }

		   }
		    fle.close();
		    toto:
		   if(tot==0)
		    {
		       rectangle(15,10,625,460);
		       outtextxy(210,85,"ERROR:SONG NOT FOUND IN POOL");
		      getch();
		    }
		    else
		    {      //search
			int tt=check(namee);
			if(tt==0)
		       {	fstream tile(playU,ios::in|ios::app|ios::binary);
			 tile.seekp(0);
			tile.write((char*)&t,sizeof(t));
			tile.close();
			outtextxy(200,85,"SUCCESS:SONG ADDED TO YOUR LIST!");
			getch();
			}
			else
			{
		       rectangle(15,10,625,460);
		       outtextxy(200,85,"ERROR:SONG ALREADY EXISTS IN PLAYLIST");
		      getch();}}endt:}

 void acceptSong()
{
 bi:settextstyle(0,0,1);
		  clrscr();
		  cleardevice();
		  rectangle(15,10,625,460);
		   rectangle(120,100,500,270);
    outtextxy(122,150,"SONG NAME");
    outtextxy(122,190,"SINGER");
    outtextxy(122,230,"GENRE");


  int check=0;
  gotoxy(45,25);
  s.inss(45,10);
  s.inssR(45,12);
  s.insg(45,15);
  fstream file("SONGD.DAT",ios::in|ios::app|ios::binary);
  while(file.read((char*)&q,sizeof(q)))
  {
    char cname[20],aname[20];
    strcpy(cname,q.retsongName());
    strcpy(aname,s.retsongName());
    if(strcmpi(cname,aname)==0)
     {
       outtextxy(210,85,"ERROR:SONG ALREADY EXISTS");
       check++;
       getch();
     }
     }
     file.close();
     if(check==1)
	mainMenu();
     else
	 {
     ofstream fout("SONGD.DAT",ios::app|ios::binary);
  fout.write((char*)&s,sizeof(s));
  outtextxy(210,85,"SUCCESS:SONG ADDED TO POOL");
  getch();
  fout.close();}
}
void deleteSong()
{
  clrscr();
  cleardevice();
   char namee[20];
    int kntr=0;
    settextstyle(0,0,1);
  if(strcmp(usingUsername,"Admin")==0)
  {  rectangle(15,10,625,460);
  rectangle(120,100,500,270);
   outtextxy(122,150,"ENTER SONG NAME");
		   char ch;
		   int j=45,k=10;
		    for(int i=0;i<20;++i,j=j+1)
		{

		 ch=getch();
		int r=ch;
		if(r!=13)
		 {

		  gotoxy(j,k);
		 printf("%c",ch);
		 namee[i]=ch;
		  }
		else
		break;
		}
		  namee[i]='\0';

	      fstream file("SONGD.DAT",ios::in|ios::app|ios::binary);

	      while(file.read((char*)&u,sizeof(u)))
	      {
		if(strcmpi(u.retsongName(),namee)==0)
		   kntr++;
		else
		{
		 into();
		}

	      }

	       file.close();
	       remove("SONGD.DAT");
	       rename("TEMP.DAT","SONGD.DAT");
	       if(kntr==0)
		 {outtextxy(215,85,"ERROR:SONG NOT FOUND!");}
		 else { outtextxy(210,85,"SUCCESS:SONG DELETED FROM POOL!");  }
		 getch();
     }
     else
    {
  cleardevice();
  setcolor(RED);
     outtextxy(210,85,"ACCESS DENIED:LOGIN AS ADMINISTRATOR!");
     getch();
    }
  }
void load()
{
clrscr();
cleardevice();
setfillstyle(SOLID_FILL,BLACK);
bar(0,0,getmaxx(),getmaxy());
settextstyle(0,0,2);
setcolor(WHITE);
outtextxy(10,195,"LOADING");
char e=219;
for(int i=1;i<55;i++)
   {
setcolor(WHITE);
gotoxy(22+i,13);
printf("%c\n",e);
randomize();
int n=random(100);
delay(n);
 }
}
void logOut()
{
  cleardevice();
  setcolor(WHITE);
   gotoxy(5,5);
 rectangle(120,200,500,300);
 settextstyle(0,0,1);
    outtextxy(180,225,"ARE YOU SURE YOU WANT TO LOG OUT");
 outtextxy(180,250,"Y");
 outtextxy(425,250,"N");
 del:
 char w=getch();
 n:
 while(1)

 { m:
   switch(w)
    {
      case 'y':{
		  setcolor(10) ;
		  outtextxy(180,250,"Y");
		  setcolor(15);
		  outtextxy(425,250,"N");
		  kk=w;
		  w=getch();
		  int j=w;
		  if(j==13)

		   goto jz;

		  else
		   goto m;
	       }
      case 'n':{
		       setcolor(10) ;
		  outtextxy(425,250,"N");
		  setcolor(15);
		  outtextxy(180,250,"Y");
		  kk=w;
		  w=getch();
		  int j=w;
		  if(j==13)
		   goto jz;
		  else
		   goto m;
		 }
		 default:goto del;
		 } }jz:
 }
//To Display the Song Details
void viewSong()
{

   cleardevice();
   setcolor(WHITE);
   char ch1[20],ch2[20],ch3[20];
   rectangle(15,10,625,460);
   settextstyle(0,0,1);
   fstream file("SONGD.DAT",ios::in|ios::app|ios::binary);
   int jj=0;
      int countx1,countx2,countx3,county;
   while(file.read((char*)&d,sizeof(d)))
    {
      if(jj%23==0)
      {
       cleardevice();
    settextstyle(2,0,7);
    outtextxy(30,10,"SINGER");
    outtextxy(310,10,"SONG_NAME");
    outtextxy(480,10,"GENRE");
       rectangle(15,10,625,460);
       settextstyle(0,0,1);
       strcpy(ch1,d.retsongName());
    strcpy(ch2,d.retsinger());
    strcpy(ch3,d.retgenre());
    delay(300);
    outtextxy(30,30,ch1);
    outtextxy(310,30,ch2);
    outtextxy(480,30,ch3);
    countx1=30;countx2=310;countx3=480;county=50;
    jj++; }
    else
    {
      strcpy(ch1,d.retsongName());
    strcpy(ch2,d.retsinger());
    strcpy(ch3,d.retgenre());
    delay(300);
    outtextxy(countx1,county,ch1);
    outtextxy(countx2,county,ch2);
    outtextxy(countx3,county,ch3);
    county+=20;
    jj++;
    }}
    file.close();
   getch();
   }
//Main Menu of program
   void mainMenu()
   {
   load();
   upi:
     cleardevice();
     setcolor(WHITE);
rectangle(15,10,625,460);
settextstyle(0,0,2);
line(315,11,315,460);
line(13,100,625,100);
line(13,300,625,300);
settextstyle(0,0,2);
outtextxy(40,50,"VIEW ALL SONGS(V)");
outtextxy(40,200,"ADD NEW SONGS(A)");
outtextxy(40,350,"DELETE SONGS(D)");
outtextxy(345,50,"ADD TO PLAYLIST(C)");
outtextxy(345,200,"VIEW PLAYLISTS(P)");
outtextxy(325,350,"DELETE FROM LIST(E)");
settextstyle(0,0,0) ;
outtextxy(500,450,"LOGOUT(L)");
int j;
char ch;
def:
ch=getch();
while(1)
{
   l:
 switch(ch)
 {
   case 'v':  {
		 settextstyle(0,0,2);
		 setcolor(LIGHTGREEN);
outtextxy(40,50,"VIEW ALL SONGS(V)");
setcolor(WHITE);
outtextxy(40,200,"ADD NEW SONGS(A)");
outtextxy(40,350,"DELETE SONGS(D)");
outtextxy(345,50,"ADD TO PLAYLIST(C)");
outtextxy(345,200,"VIEW PLAYLISTS(P)");
outtextxy(325,350,"DELETE FROM LIST(E)");
settextstyle(0,0,0);
outtextxy(500,450,"LOGOUT(L)");
		 ch=getch();
		 j=ch;
		 if(j==13)
		 {
		  load();
		  viewSong();
		  goto upi;
		 }
		 else
		 goto l;
	      }
    case 'p':{
	       settextstyle(0,0,2);
	       setcolor(WHITE);
outtextxy(40,50,"VIEW ALL SONGS(V)");
outtextxy(40,200,"ADD NEW SONGS(A)");
outtextxy(40,350,"DELETE SONGS(D)");
outtextxy(345,50,"ADD TO PLAYLIST(C)");
setcolor(10);
outtextxy(345,200,"VIEW PLAYLISTS(P)");
setcolor(WHITE);
outtextxy(325,350,"DELETE FROM LIST(E)");
settextstyle(0,0,0);
outtextxy(500,450,"LOGOUT(L)");
		 settextstyle(0,0,0) ;
		 outtextxy(500,450,"LOGOUT(L)");
		 ch=getch();
		 j=ch;
		 if(j==13)
		 {
		  load();
		  viewList();
		  goto upi;
		 }
		 else
		  goto l;
	       }
       case 'c':{
		   settextstyle(0,0,2);
			       setcolor(WHITE);
outtextxy(40,50,"VIEW ALL SONGS(V)");
outtextxy(40,200,"ADD NEW SONGS(A)");
outtextxy(40,350,"DELETE SONGS(D)");
setcolor(10);
outtextxy(345,50,"ADD TO PLAYLIST(C)");
setcolor(WHITE);
outtextxy(345,200,"VIEW PLAYLISTS(P)");
outtextxy(325,350,"DELETE FROM LIST(E)");
		 settextstyle(0,0,0) ;
		 outtextxy(500,450,"LOGOUT(L)");
		 ch=getch();
		 j=ch;
		 if(j==13)
		 {
		  load();
		  createPlaylist();
		  goto upi;
		 }
		 else
		  goto l;
		    }
	case 'e':{
		     settextstyle(0,0,2);
			       setcolor(WHITE);
outtextxy(40,50,"VIEW ALL SONGS(V)");
outtextxy(40,200,"ADD NEW SONGS(A)");
outtextxy(40,350,"DELETE SONGS(D)");
outtextxy(345,50,"ADD TO PLAYLIST(C)");
outtextxy(345,200,"VIEW PLAYLISTS(P)");
setcolor(10);
outtextxy(325,350,"DELETE FROM LIST(E)");
setcolor(WHITE);
		 settextstyle(0,0,0) ;
		 outtextxy(500,450,"LOGOUT(L)");
		 ch=getch();
		 j=ch;
		 if(j==13)
		 {
		  load();
		  deletePlaylist();
		  goto upi;
		 }
		 else
		  goto l;
		     }
       case'a':{
		settextstyle(0,0,2);
			       setcolor(WHITE);
outtextxy(40,50,"VIEW ALL SONGS(V)");
setcolor(10);
outtextxy(40,200,"ADD NEW SONGS(A)");
setcolor(WHITE);
outtextxy(40,350,"DELETE SONGS(D)");
outtextxy(345,50,"ADD TO PLAYLIST(C)");
outtextxy(345,200,"VIEW PLAYLISTS(P)");
outtextxy(325,350,"DELETE FROM LIST(E)");
		 settextstyle(0,0,0) ;
		 outtextxy(500,450,"LOGOUT(L)");
		 ch=getch();
		 j=ch;
		 if(j==13)
		 {
		  load();
		  acceptSong();
		  goto upi;
		 }
		 else
		  goto l;
 }
       case'd':{
		 settextstyle(0,0,2);
			       setcolor(WHITE);
outtextxy(40,50,"VIEW ALL SONGS(V)");
outtextxy(40,200,"ADD NEW SONGS(A)");
setcolor(10);
outtextxy(40,350,"DELETE SONGS(D)");
setcolor(WHITE);
outtextxy(345,50,"ADD TO PLAYLIST(C)");
outtextxy(345,200,"VIEW PLAYLISTS(P)");
outtextxy(325,350,"DELETE FROM LIST(E)");
		 settextstyle(0,0,0) ;
		 outtextxy(500,450,"LOGOUT(L)");
		 ch=getch();
		 j=ch;
		 if(j==13)
		 {
		  load();
		  deleteSong();
		  goto upi;
		 }
		 else
		  goto def;}
       case'l':{
		  settextstyle(0,0,2);
		   setcolor(WHITE);
outtextxy(40,50,"VIEW ALL SONGS(V)");
outtextxy(40,200,"ADD NEW SONGS(A)");
outtextxy(40,350,"DELETE SONGS(D)");
outtextxy(345,50,"ADD TO PLAYLIST(C)");
outtextxy(345,200,"VIEW PLAYLISTS(P)");
outtextxy(325,350,"DELETE FROM LIST(E)");
		 settextstyle(0,0,0) ;
		 setcolor(10);
		 outtextxy(500,450,"LOGOUT(L)");
		 ch=getch();
		 j=ch;
		 if(j==13)
		 {
		   logOut();
		   int q=kk;
		   int m='y';
		       if(q==m)
		       {
			goto lala;
		       }
		       else
			goto upi ;
		   }
		   else
		     goto l;
		    }
		     default:goto def;}}
			lala:
   }
   //DRIVER FUNCTION
void main()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   introMenu();
   closegraph();
   end:
   }
void screenSignUp()
{
  cleardevice();
  setcolor(WHITE);
  rectangle(15,10,625,460);
settextstyle(0,0,2);
outtextxy(280,175,"SIGNUP");
settextstyle(2,0,5);
outtextxy(290,210,"USERNAME");
outtextxy(290,225,"PASSWORD");
outtextxy(290,240,"RET-PASS");
}
void wrong()
{
	screenSignUp();
	outtextxy(255,190,"Password miss match");
}
void exist()
{
	screenSignUp();
    outtextxy(240,190,"Username Already exists");
}
void signup()
{
     oi:
	clrscr();
    screenSignUp();
    qq:
 char ch;
 gotoxy(50,14);
 printf(" ");
 for(int i=0,j=50;i<20;++i,j=j+1)
 {
   ch=getch();
   int r=ch;
   if(r!=13)
   {
    gotoxy(j,14);
    printf("%c ",ch);
    user[i]=ch;
   }
   else
   break;
 }
 user[i]='\0';
 gotoxy(50,15);
 printf(" ");
  for( i=0,j=50;i<20;i++,j++)
  {
    ch=getch();
    int r=ch;
    if(r!=13)
   {
    gotoxy(j,15);
    printf("*");
    pass[i]=ch;
    }
    else
    {
      cout<<endl;
    goto app1;
    }
  }
  app1:
  pass[i]='\0';
   gotoxy(50,16);
 printf(" ");
  for( i=0,j=50;i<20;i++,j++)
  {
    ch=getch();
    int r=ch;
    if(r!=13)
   {
    gotoxy(j,16);
    printf("*");
    pass2[i]=ch;
    }
    else
    {
      cout<<endl;
    goto app2;
    }
  }
  app2:
  int che=0;
  pass2[i]='\0';
  obj.uInput();
  obj.pInput();
  fstream file ("USERD.DAT",ios::in|ios::ate|ios::binary);
  file.seekg(0);
  rr:
   char retUser[20];
	  char retUser2[20];
  while(file.read((char*)&a,sizeof(a)))
  {
	  strcpy(retUser,obj.retUsername());
	  strcpy(retUser2,a.retUsername());
	  if(strcmp(retUser,retUser2)==0)
	  {
		exist();
		che++;
		goto rr;
	   }
	  }
	  strcpy(curUsername,retUser);
	  file.close();
	   if(che==0)
	   {
		  if(strcmp(pass,pass2)==0)
		  {
		  ofstream fout("USERD.DAT",ios::app|ios::binary);
		  fout.seekp(0,ios::end);
		  fout.write((char*)&obj,sizeof(obj));goto end;
		  }
		  else
		  {wrong();getch();goto w;}
	    }

	  else
	  {
		    elif:
		    exist();
	    file.close();
	    getch();goto w;}
  end:
  file.close();
  w:
  introMenu();
  }
void login()
{
int test=0;
we:
cleardevice();
setcolor(WHITE);
rectangle(15,10,625,460);
if(test==99)
 outtextxy(275,190,"Wrong Credentials");
settextstyle(0,0,2);
outtextxy(280,175,"LOGIN");
settextstyle(2,0,5);
outtextxy(290,210,"USERNAME");
outtextxy(290,225,"PASSWORD");
 char ch;
 gotoxy(50,14);
 printf(" ");
 for(int i=0,j=50;i<20;++i,j=j+1)
 {

   ch=getch();
   int r=ch;
   if(r!=13)
   {

    gotoxy(j,14);
    printf("%c ",ch);
    user[i]=ch;
   }
   else
   break;
 }
 user[i]='\0';
 gotoxy(50,15);
 printf(" ");
  for( i=0,j=50;i<20;i++,j++)
  {
    ch=getch();
    int r=ch;
    if(r!=13)
   {
    gotoxy(j,15);
    printf("*");
    pass[i]=ch;
    }
    else
    {
      pass[i]='\0';
      cout<<endl;
    goto app1;
    }
  }
  app1:
  int fl=0;
  pass[i]='\0';
fstream file("USERD.DAT",ios::in|ios::app|ios::binary);
while(file.read((char*)&obj,sizeof(obj)))
{
  strcpy(user2,obj.retUsername());
  strcpy(pass2,obj.retPassword());
  if(strcmp(user,user2)==0 && strcmp(pass,pass2)==0)
    {
      clrscr();
      file.close();
      strcpy(usingUsername,user);
      file.close();
      mainMenu();
      fl++;
      break;
    }

 }
    if(fl==0)
     {
      file.close();
      test=99;
      goto we;}

   }
   void help()
   {
     char chh;
      cleardevice();
      setcolor(WHITE);
      settextstyle(2,0,9);
      outtextxy((getmaxx()/2)-50,0,"HELP");
     settextstyle(0,0,2);
     cout<<"\n\n\n";
     fstream R("HELP.TXT",ios::in|ios::app);
     while(!R.eof())
    {
     R.get(chh);
     cout<<chh;
    }
    R.close();
   }
void introMenu()
{
  h:
  cleardevice();
  rectangle(15,10,635,465);
settextstyle(0,0,2);
setcolor(WHITE);
outtextxy(200,175,"TUNES MUSIC APP");
settextstyle(2,0,5);
outtextxy(300,200,"LOGIN");
outtextxy(300,225,"SIGNUP");
outtextxy(540,450,"EXIT(X)");
outtextxy(50,450,"HELP(H)");
char ch=getch();
while(1)
{       re:
	switch(ch)
	{
	   case 'w':{
		       setcolor(WHITE);
				outtextxy(540,450,"EXIT(X)");
				outtextxy(300,225,"SIGNUP");
				outtextxy(50,450,"HELP(H)");
		 outtextxy(410,200,"<");
			setcolor(BLACK);
			 outtextxy(410,225,"<");
			 setcolor(10);
			 outtextxy(300,200,"LOGIN");
			 ch=getch();
			 int j=ch;
			 if(j==13)
			 {
			    load();
			    login();
			   goto end;
			 }
			 else
			 {
			   goto re;
			 }
		     }
	      case 's':{

			    setcolor(WHITE);
				outtextxy(540,450,"EXIT(X)");
				outtextxy(300,200,"LOGIN");
				outtextxy(50,450,"HELP(H)");
		 outtextxy(410,225,"<");
			setcolor(BLACK);
			 outtextxy(410,200,"<");
			 setcolor(10);
				outtextxy(300,225,"SIGNUP");
			 ch=getch();
			 int j=ch;
			 if(j==13)
			 {
			   load();
			   signup();
			   goto end;
			 }
			 else
			 {
			  goto re;
			 }
		     }
		     case 'x':{
				  setcolor(BLACK);
				outtextxy(410,225,"<");
				outtextxy(410,200,"<");
				setcolor(WHITE);
					outtextxy(300,200,"LOGIN");
					outtextxy(300,225,"SIGNUP");
					outtextxy(50,450,"HELP(H)");
				setcolor(10);
				outtextxy(540,450,"EXIT(X)");
				ch=getch();
				int i=ch;
				if(i==13)
				 goto end;
				else
				 goto re;
				 }
		     case 'h':{
				    setcolor(BLACK);
				outtextxy(410,225,"<");
				outtextxy(410,200,"<");
				setcolor(WHITE);
					outtextxy(300,200,"LOGIN");
					outtextxy(300,225,"SIGNUP");
					outtextxy(540,450,"EXIT(X)");
				setcolor(10);
				outtextxy(50,450,"HELP(H)");
				ch=getch();
				int i=ch;
				if(i==13)
				{
				help(); getch();goto h;}
				else
				 goto re;} default:ch=getch(); }}   end:}















