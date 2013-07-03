#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int PickNum();
int SpinWheel(int choice);
int StraightBet();
int RedBet();
int BlackBet();
int EvenBet();
int OddBet();
int First12();
int Second12();
int Third12();
void Stats();
double HighScore();
void Save();
void Load();
double bank=100;
double amountBet;
int SaveArr[5];
double HighScore1=0;
int NumBets=0;
int NumWon=0;
int NumLost=0;
double PercentWon;
double PercentLost; 
int main ()
{  
    cout<<setiosflags(ios::fixed|ios::showpoint);
    cout<<setprecision(2);
    int option;
    srand(unsigned(time(0)));
    do
    {
      bank=100.00;
      do
      {
          int choice=PickNum();
          SpinWheel(choice);
      }
      while(bank!=0);
      system("cls");
      if(bank==0.00)
          cout<<"\n\n\n\t\t You lose, you don't have any more money!\n\n\n\n\n";
      getch();
      cout<<"\n\n\t\tDo you want to play again? (1 for yes, 2 for no): ";
      cin>>option;
    }
    while(option!=2);
      return 0;
}
int PickNum()
{
    system("cls");
    int choice;
    cout<<"\n\t\t\t\tCASINO - ROULETTE\n"<<endl;
    cout<<"\n\t1. Straight bet"<<endl;
    cout<<"\t2. Red"<<endl;
    cout<<"\t3. Black"<<endl;
    cout<<"\t4. Even"<<endl;
    cout<<"\t5. Odd"<<"\t\t\t\tBank: $"<<bank<<"\n";
    cout<<"\t6. First 12"<<endl;
    cout<<"\t7. Second 12"<<endl;
    cout<<"\t8. Third 12"<<endl<<"\n\t*********\n";
    cout<<"\n\t9.  Stats"<<endl;
    cout<<"\t10. Save Game"<<endl;
    cout<<"\t11. Load Game"<<endl;
    cout<<"\n\tChoose an option: ";
    cin>>choice;
    HighScore();
    if(choice<=8)
    {
        cout<<"\n\n    Amount to bet from bank: ";
        cin>>amountBet;
        if(amountBet>bank)
        {
            cout<<"\n\tYou bet more than the bank! Press any key and try again.";
            getch();
            PickNum();
        }
    }
    if(amountBet<0)
    {
        cout<<"\n\tYou can't bet a negative number! Try again...";
        getch();
        PickNum();
    }
    if(choice==10)
    {
        cout<<"\n\t\t....Game Saved! Press any key to continue";
        getch();
    }
    if(choice==11)
    {
        cout<<"\n\t\t....Game Loaded! Press any key to continue.";
        getch();
    }
    if(choice==420)
    {
        int cheat=rand()%100+1;
        if(cheat==1)
            bank=bank+10000;
        if(cheat<99&&cheat>75)
            bank=bank+1000;
        else
            bank=bank+100;
    }
    if(choice>11&&choice!=420)
    {
        cout<<"\n\tInvalid choice, try again.";
        getch();
        PickNum();
    }
    return choice;
}
int SpinWheel(int choice)
{
    if(choice==1)
        StraightBet();
    if(choice==2)
        RedBet();
    if(choice==3)
        BlackBet();
    if(choice==4)
        EvenBet();
    if(choice==5)
        OddBet();
    if(choice==6)
        First12();
    if(choice==7)
        Second12();
    if(choice==8)
        Third12();
    if(choice==9)
        Stats();
    if(choice==10)
        Save();
    if(choice==11)
        Load();
    return 0;
}
int StraightBet()
{
    system("cls");
    NumBets++;
    int WinningNum=rand()%36+1;
    int StraightBetChoice;
    cout<<"\n\n\tChoose a number from 0-36:";
    cin>>StraightBetChoice;
    while(StraightBetChoice>=0&&StraightBetChoice<=36)
    {
    if(StraightBetChoice==WinningNum)
    {
        NumWon++;
        cout<<"\n\tWinner!";
        bank=bank+amountBet*25;
        cout<<"\tYou now have $"<<bank;
        getch();
    }
    if(StraightBetChoice!=WinningNum)
    {
        NumLost++;
        cout<<"\n\tLoser! The winning number was "<<WinningNum<<".\n\n";
        bank=bank-amountBet;
        cout<<"\tYou now have $"<<bank;
        getch();
    }
    return 0;
}}
int RedBet()
{
    system("cls");
    NumBets++;
    int WinningNum=rand()%2+1;
    if(WinningNum==1)
    {
        NumWon++;
        cout<<"\n\n\n\n\tThe number rolled ("<<WinningNum<<") was red, you are a winner!";
        bank=bank+(amountBet*2);
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    if(WinningNum==2)
    {
        NumLost++;
        cout<<"\n\n\n\n\tYou lose, the number rolled ("<<WinningNum<<") was black!";
        bank=bank-amountBet;
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    return 0;   
}
int BlackBet()
{
    system("cls");
    //1 is red and 2 is black
    NumBets++;
    int WinningNum=rand()%2+1;
    if(WinningNum==2)
    {
        NumWon++;
        cout<<"\n\n\n\n\tThe number rolled ("<<WinningNum<<") was black, you are a winner!";
        bank=bank+(amountBet*2);
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    if(WinningNum==1)
    {
        NumLost++;
        cout<<"\n\n\n\n\tYou lose, the number rolled ("<<WinningNum<<") was red!";
        bank=bank-amountBet;
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    return 0;   
}
int EvenBet()
{
    system("cls");
    NumBets++;
    int WinningNum=rand()%36+1;
    if(WinningNum%2==0)
    {
        NumWon++;
        cout<<"\n\n\n\n\tThe number rolled was even ("<<WinningNum<<"), you are a winner!";
        bank=bank+(amountBet*2);
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    if(WinningNum%2!=0)
    {
        NumLost++;
        cout<<"\n\n\n\n\tYou lose, the number rolled was odd! ("<<WinningNum<<").";
        bank=bank-amountBet;
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    return 0;   
}
int OddBet()
{
    system("cls");
    int WinningNum=rand()%36+1;
    NumBets++;
    if(WinningNum%2!=0)
    {
        NumWon++;
        cout<<"\n\n\n\n\tThe number rolled was odd ("<<WinningNum<<"), you are a winner!";
        bank=bank+(amountBet*2);
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    if(WinningNum%2==0)
    {
        NumLost++;
        cout<<"\n\n\n\n\tYou lose, the number rolled was even! ("<<WinningNum<<").";
        bank=bank-amountBet;
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    return 0;   
}
int First12()
{
    system("cls");
    int WinningNum=rand()%36+1;
    NumBets++;
    if(WinningNum>=0&&WinningNum<12)
    {
        NumWon++;
        cout<<"\n\n\n\n\tThe number rolled was in the first 12 ("<<WinningNum<<"), you are a winner!";
        bank=bank+(amountBet*3);
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    if(WinningNum>=12)
    {
        NumLost++;
        cout<<"\n\n\n\n\tThe number rolled was NOT in the first 12 ("<<WinningNum<<"), you lose!";
        bank=bank-amountBet;
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    return 0;
}
int Second12()
{
    system("cls");
    int WinningNum=rand()%36+1;
    NumBets++;
    if(WinningNum>=12&&WinningNum<=23)
    {
        NumWon++;
        cout<<"\n\n\n\n\tThe number rolled was in the second 12 ("<<WinningNum<<"), you are a winner!";
        bank=bank+(amountBet*3);
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    if(WinningNum<12||WinningNum>23)
    {
        NumLost++;
        cout<<"\n\n\n\n\tThe number rolled was NOT in the second 12 ("<<WinningNum<<"), you lose!";
        bank=bank-amountBet;
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    return 0;
}
int Third12()
{
    system("cls");
    int WinningNum=rand()%36+1;
    NumBets++;
    if(WinningNum>=24&&WinningNum<=35)
    {
        NumWon++;
        cout<<"\n\n\n\n\tThe number rolled was in the third 12 ("<<WinningNum<<"), you are a winner!";
        bank=bank+(amountBet*3);
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    if(WinningNum<24||WinningNum>35)
    {
        NumLost++;
        cout<<"\n\n\n\n\tThe number rolled was NOT in the third 12 ("<<WinningNum<<"), you lose!";
        bank=bank-amountBet;
        cout<<"\n\n\t\tYou now have $"<<bank;
        getch();
    }
    return 0;
}
void Save()
{
    ofstream outf("save.txt");
    outf<<bank<<endl;
    outf<<HighScore1<<endl;
    outf<<NumBets<<endl;
    outf<<NumWon<<endl;
    outf<<NumLost<<endl;
    outf.close();
}
void Load()
{
    ifstream inf("save.txt");
    inf>>bank;
    inf>>HighScore1;
    inf>>NumBets;
    inf>>NumWon;
    inf>>NumLost;
    inf.close();
}
void Stats()
{
    system("CLS");
    PercentWon=(double(NumWon)/NumBets)*100;
    PercentLost=(double(NumLost)/NumBets)*100;
    cout<<"\n\n\t\tStats\n\n";
    cout<<"\tHighest Amount Ever in Bank: $"<<HighScore();
    cout<<"\n\tNumber of Bets Made: "<<NumBets;
    cout<<"\n\tNumber of bets won: "<<NumWon;
    if(NumBets!=0)
        cout<<" ("<<PercentWon<<"%)";
    cout<<"\n\tNumber of bets lost: "<<NumLost;
    if(NumBets!=0)
        cout<<" ("<<PercentLost<<"%)";
    getch();
    system("CLS");
}
double HighScore()
{
    if(bank>HighScore1)
        HighScore1=bank;
    return HighScore1;
}
