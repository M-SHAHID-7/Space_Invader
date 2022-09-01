#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<time.h>
using namespace std;


// field
char space[21][51]={{".................................................."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".                                                ."},
                    {".................................................."}
                    
};

char enemy[2][8]={{"< !!! >"},
                  {"   +  "}
                     };

char ship[2][6]={{"  ^ "},
                 {"<|=|>"},
                     };


// function prototypes 
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void heading();
void main_menu();
void move_enemy_right();
void move_enemy_left();
void move_ship_right();
void move_ship_left();
void enemy_fire_fun();
void ship_fire_fun();
void ship_fire_run();

// global variables
int rds=0;
int SCORE =0;
int ship_Lives =5;
int enemy_Lives=5;
int enemy_left=0;
int enemy_right=0;
bool run = true;
int ship_left=0;
int ship_right=0;

int enemy_fire1_x=0;
int  enemy_fire1_y=0;

int ship_fire1_x=0;
int ship_fire1_y=0;

int range=0;
int term =0;
bool first_while=true;
int check=0;// this variable is for resetting the values of while variable once they become false
int enemy_life_count=0;

// START OF MAIN FUNCTION


int main(){








while(first_while==true){
if(check==0){
  check++;
}
else if(check>0){
 rds=0;
SCORE =0;
ship_Lives =5;
enemy_left=0;
enemy_right=0;
 run = true;
ship_left=0;
ship_right=0;

enemy_fire1_x=0;
 enemy_fire1_y=0;

ship_fire1_x=0;
ship_fire1_y=0;

range=0;
term =0;
 first_while=true;
check=0;
enemy_life_count=0;

}
    system("cls");
heading();
char option;
main_menu();

while(true){
cin>>option ;
if(option=='1'|| option=='2'|| option=='3'|| option=='4'){
  break;
}
else 
cout<<"PRINT ENTER A VALID OPTION"<<endl;

}
system("cls");
if(option=='1'){
    // printing the space 
for(int i=0;i<20;i++){
    for(int j=0;j<50;j++){  
      
        cout<<space[i][j];
    }
    cout<<endl;
}
// printing enenmy
for(int i=0;i<2;i++){
    for(int j=0;j<8;j++){
     gotoxy(20+j,1+i);
     cout<<enemy[i][j];
     space[1+i][20+j]=enemy[i][j];
     if(enemy[i][j]=='<')
     enemy_left=20+j;
     else if(enemy[i][j]=='>')
     enemy_right=20+j;
    }
}
// printing space ship

for(int i=0;i<2;i++){
    for(int j=0;j<6;j++){
     gotoxy(20+j,17+i);
     cout<<ship[i][j];
     space[17+i][20+j]=ship[i][j];
        if(ship[i][j]=='<')
     ship_left=20+j;
     else if(ship[i][j]=='>')
     ship_right=20+j;
    }
}

    int a =0;
// MAIN WHILE FUNCTION

while(term ==0){
while(run ==true){
gotoxy(60,14);
cout<<"SCORE:"<<SCORE;
gotoxy(60,16);
cout<<"ship_Lives:"<<ship_Lives;
gotoxy(60,18);
cout<<"enemy_Lives:"<<enemy_Lives;
srand(time(0));
int k=rand()%10;
if(k%2==0){
 move_enemy_left();


}
else{
  move_enemy_right();
}
// MOVING THE SPACE SHIP
if(GetAsyncKeyState(VK_RIGHT)){
  move_ship_right();
}
if(GetAsyncKeyState(VK_LEFT)){
 move_ship_left();
}
if(enemy_fire1_x!=0&& enemy_fire1_x!=1){
  enemy_fire_fun();
}
if(GetAsyncKeyState(VK_UP)){
ship_fire_fun();
}
ship_fire_run();
}// END OF WHILE FUNCTION

if(SCORE>=range){
range =range+ SCORE;
rds ++ ;
Sleep(1000);
gotoxy(60,10);
cout<<"CONGRTULATIONS YOU'VE PASSED ROUND "<<rds<<endl;
   
   run =true;
Sleep(1000);
  // getch();
   ship_Lives=5;
}
else{
  system("cls");
  cout<<"GAME OVER"<<endl;
  cout<<"YOU COULD'NT MAKE IT FOR:" <<rds<<" ROUND "<<endl;
  cout<<"PRESS ANY KEY TO CONTINUE"<<endl;
  // getch();
term =1;
}

}
}
else if(option=='2'){
for(int i=0;i<20;i++){
    for(int j=0;j<50;j++){  
      
        cout<<space[i][j];
    }
    cout<<endl;
}
// printing enenmy
for(int i=0;i<2;i++){
    for(int j=0;j<8;j++){
     gotoxy(20+j,1+i);
     cout<<enemy[i][j];
     space[1+i][20+j]=enemy[i][j];
     if(enemy[i][j]=='<')
     enemy_left=20+j;
     else if(enemy[i][j]=='>')
     enemy_right=20+j;
    }
}
// printing space ship

for(int i=0;i<2;i++){
    for(int j=0;j<6;j++){
     gotoxy(20+j,17+i);
     cout<<ship[i][j];
     space[17+i][20+j]=ship[i][j];
        if(ship[i][j]=='<')
     ship_left=20+j;
     else if(ship[i][j]=='>')
     ship_right=20+j;
    }
}

    int a =0;
// MAIN WHILE FUNCTION










while(run ==true){
  gotoxy(60,12);
  cout<<"MISSION :   KILL THE TIROS";
gotoxy(60,14);
cout<<"SCORE:"<<SCORE;
gotoxy(60,16);
cout<<"ship_Lives:"<<ship_Lives;
gotoxy(60,18);
cout<<"enemy_Lives:"<<enemy_Lives;
srand(time(0));
int k=rand()%10;
if(k%2==0){
 move_enemy_left();


}
else{
  move_enemy_right();
}



// MOVING THE SPACE SHIP

if(GetAsyncKeyState(VK_RIGHT)){
  move_ship_right();
}
if(GetAsyncKeyState(VK_LEFT)){
 move_ship_left();
}
if(enemy_fire1_x!=0&& enemy_fire1_x!=1){
  enemy_fire_fun();
}
if(GetAsyncKeyState(VK_UP)){
ship_fire_fun();
}
ship_fire_run();
if(run==false){
cout<<" MISSION ACCOMPOLISHED"<<endl;
cout<<"GOD LUCK FOR NEXT MISSION "<<endl;

}
}// END OF WHILE FUNCTION

cout<<"PRESS ANY KEY TO CONTINUE"<<endl;
getch(); 

}




else if(option=='3'){
  cout<<"OPTION NEEDS TO  BE ADDED"<<endl;
  cout<<"PRESS ANY KEY TO CONTINUE"<<endl;
getch(); 
}
else if(option=='4'){
  cout<<"THANKS FOR VISITING "<<endl;
  first_while=false;
}



}
}



// END OF MAIN FUNCTION










void move_enemy_right(){
  if(enemy_fire1_x==0){
    enemy_fire1_x=3;
    enemy_fire1_y=enemy_left+2;
    gotoxy(enemy_fire1_y,enemy_fire1_x);
    cout<<'O';
    space[enemy_fire1_x][enemy_fire1_y]='O';
    enemy_fire_fun();
  }
 else if(enemy_fire1_x==1){
     enemy_fire1_x=3;
    enemy_fire1_y=enemy_left+2;
    gotoxy(enemy_fire1_y,enemy_fire1_x);
    cout<<'O';
    space[enemy_fire1_x][enemy_fire1_y]='O';
    enemy_fire_fun();
  }
  if(enemy_right<48){

for(int i=0;i<2;i++){
    for(int j=enemy_left-1;j<=enemy_right;j++){
     gotoxy(j,1+i);
     cout<<' ';
     space[1+i][j]=' ';
    }
    }
    enemy_left=enemy_left+1;
    enemy_right=enemy_right+1;
 for(int i=1;i<3;i++){
    int l=0;
       for(int j=enemy_left;j<=enemy_right;j++){
       gotoxy(j,i);
       cout<<enemy[i-1][l];
       space[i][j]=enemy[i-1][l];
        l=l+1;
      }



}
  }
}

void move_enemy_left(){


  if(enemy_left>2){

for(int i=0;i<2;i++){
    for(int j=enemy_left-1;j<=enemy_right;j++){
     gotoxy(j,i+1);
     cout<<' ';
     space[i+1][j]=' ';
    }
    }
    enemy_left=enemy_left-1;
    enemy_right=enemy_right-1;

for(int i=0;i<2;i++){
   int l=0;
    for(int j=enemy_left-1;j<=enemy_right;j++){

     gotoxy(j,i+1);
     cout<<enemy[i][l];
     space[i+1][j]=ship[i][l];
     l=l+1;

    }
      }


  }
}

void  move_ship_right(){
  if(space[17][ship_right+2]!='.'){
   

for(int i=0;i<2;i++){
    for(int j=ship_left-1;j<=ship_right;j++){
     gotoxy(j,17+i);
     cout<<' ';
     space[17+i][j]=' ';
    }
    }
    ship_left=ship_left+1;
    ship_right=ship_right+1;
    
for(int i=0;i<2;i++){
   int l=0;
    for(int j=ship_left-1;j<=ship_right;j++){

     gotoxy(j,17+i);
     cout<<ship[i][l];
     space[17+i][j]=ship[i][l];
     l=l+1;

    }
    }


 
  }
}
void move_ship_left(){
if(space[17][ship_left-2]!='.'){
for(int i=0;i<2;i++){
    for(int j=ship_left-1;j<=ship_right;j++){
     gotoxy(j,17+i);
     cout<<' ';
     space[17+i][j]=' ';
    }
    }
    ship_left=ship_left-1;
    ship_right=ship_right-1;

for(int i=0;i<2;i++){
   int l=0;
    for(int j=ship_left-1;j<=ship_right;j++){

     gotoxy(j,17+i);
     cout<<ship[i][l];
     space[17+i][j]=ship[i][l];
     l=l+1;

    }
    }
}
}
void enemy_fire_fun(){
  if(space[enemy_fire1_x+1][enemy_fire1_y]!='.'&& space[enemy_fire1_x+1][enemy_fire1_y]!=char(210)){
    if(space[enemy_fire1_x+1][enemy_fire1_y]=='^'||space[enemy_fire1_x+1][enemy_fire1_y]=='|'||space[enemy_fire1_x+1][enemy_fire1_y]=='<'||space[enemy_fire1_x+1][enemy_fire1_y]=='>'){
      --ship_Lives;
      if(ship_Lives<0)
      run =false;
    }

     space[enemy_fire1_x][enemy_fire1_y]=' ';
  gotoxy(enemy_fire1_y,enemy_fire1_x);
  cout<<' ';
  gotoxy(enemy_fire1_y,enemy_fire1_x+1);
  cout<<'O';
  space[enemy_fire1_x+1][enemy_fire1_y]='O';
  enemy_fire1_x++;
  }
    else if(space[enemy_fire1_x+1][enemy_fire1_y]=='.'||space[enemy_fire1_x+1][enemy_fire1_y]==char(210) ){
           space[enemy_fire1_x][enemy_fire1_y]=' ';
  gotoxy(enemy_fire1_y,enemy_fire1_x);
  cout<<' ';
      enemy_fire1_x=1;
      enemy_fire1_y=1;
    }
}


void ship_fire_fun(){
if(ship_fire1_x==0){
  ship_fire1_x=16;
  ship_fire1_y=ship_left+2;
  gotoxy(ship_fire1_y,ship_fire1_x-1);
  cout<<char(210);
  space[ship_fire1_x-1][ship_fire1_y]=char(210);
  ship_fire1_x--;
}




}// END OF SHIP FUNCTION

void ship_fire_run(){


  if(ship_fire1_x>0&& space[ship_fire1_x-1][ship_fire1_y]!='.'&&space[ship_fire1_x-1][ship_fire1_y]!='O'){
     if(space[ship_fire1_x-1][ship_fire1_y]=='+'||space[ship_fire1_x-1][ship_fire1_y]=='!'||space[ship_fire1_x-1][ship_fire1_y]=='>'||space[ship_fire1_x-1][ship_fire1_y]=='<'){
   SCORE=SCORE+1;
  //     if(enemy_life_count<2)
  enemy_life_count++;
  //else {
 if(enemy_Lives>0){
  enemy_Lives--;
  enemy_life_count=0;
 }
 else if(enemy_Lives<=0&&ship_Lives>0){
   run =false;
    enemy_Lives=ship_Lives=5;
    ship_Lives=5;
 }
         
    }
gotoxy(ship_fire1_y,ship_fire1_x);
cout<<' ';
space[ship_fire1_x][ship_fire1_y]=' ';
  gotoxy(ship_fire1_y,ship_fire1_x-1);
  cout<<char(210);
  space[ship_fire1_x-1][ship_fire1_y]=char(210);
  ship_fire1_x--;
    
}
if(space[ship_fire1_x-1][ship_fire1_y]=='.'||space[ship_fire1_x-1][ship_fire1_y]=='O'){
  gotoxy(ship_fire1_y,ship_fire1_x);
  cout<<' ';
  space[ship_fire1_x][ship_fire1_y]=' ';
ship_fire1_x=0;
ship_fire1_y=0;
}

}

void heading(){
  cout<<"SSSSSSSSSS   SSSSSSS      SS       SSSSSS    SSSSSSSSS    SS         SS      SS      SSSSSSS "      <<endl; 
Sleep(1000);   
cout<<"SS           SS   SS     SS SS     SS        SS           SS         SS     SS SS    SS   SS  "    <<endl;  
Sleep(1000);
cout<<"SSSSSSSSSS   SSSSSSS    SS   SS    SS        SSSSSSSSS    SS   SS    SS    SS   SS   SSSSSSS   "    <<endl; 
Sleep(1000);
cout<<"        SS   SS        SSSSSSSSS   SS        SS           SS SS   SS SS   SSSSSSSSS  SS SS      "    <<endl;
Sleep(1000);
cout<<"SSSSSSSSSS   SS       SS       SS  SSSSSSS   SSSSSSSSS    SSSS     SSSS  SS       SS SS   SSS    "  <<endl;

}
void main_menu(){
cout<<"1.PLAY ENDLESS MODE"<<endl;
cout<<"2.PLAY LEVEL MODE"<<endl;
cout<<"3.CHECK HIGH SCORE"<<endl;
cout<<"4.EXIT "<<endl;
}