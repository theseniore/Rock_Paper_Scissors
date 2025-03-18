#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
enum enTools{Rock = 1,Paper = 2,Scissors = 3};
struct stGameResults
{
short GameRounds;
int Player1WonTimes;
int ComputerWonTimes;
int DrawTimes;
string FinalWinner;
};
void startGame();
void showRound(stGameResults& GameResults);
void green()
{
    cout << "\033[42m";
}
void red()
{
    cout << "\033[41m";
}
void yellow()
{
    cout << "\033[43m";
}
void reserColor()
{
    cout << "\033[0m";
}
int randomNumber(int From,int To)
{
    return rand()%(To-From+1)+From;
}
short howManyRounds()
{
    int Number;
    cout<<"How many rounds 1 to 10"<<endl;
    cin>>Number;
    while(Number<1||Number>10)
    {
    cout<<"Enter a valid value from 1 to 10"<<endl;
    cin>>Number;
    }
    return Number;
}
void roundInput(stGameResults& GameResults,int i)
{
    int UserToolChoice;
    cout<<"Your choice: [1]:Stone, [2]:Paper, [3]:Scissors ?"<<endl;
    cin>>UserToolChoice;
    int CompToolChoice = randomNumber(1,3);
    if (UserToolChoice == CompToolChoice)
    {
        yellow();
        GameResults.DrawTimes++;
    }
    else if((UserToolChoice == Rock && CompToolChoice == Scissors) ||
               (UserToolChoice == Paper && CompToolChoice == Rock) ||
               (UserToolChoice == Scissors && CompToolChoice == Paper))
    {
        green();
        GameResults.Player1WonTimes++;
    }
    else
    {
        red();
        GameResults.ComputerWonTimes++;
    }
    cout<<"\n_______________Round ["<<i<<"]_______________"<<endl;
    cout<<"Player1  choice: "<<UserToolChoice<<endl;
    cout<<"Computer choice: "<<CompToolChoice<<endl;
    if (UserToolChoice == CompToolChoice) {
    cout << "Round Winner   : [No winner]" << endl;
    } else if ((UserToolChoice == enTools::Rock && CompToolChoice == enTools::Scissors) ||
           (UserToolChoice == enTools::Paper && CompToolChoice == enTools::Rock) ||
           (UserToolChoice == enTools::Scissors && CompToolChoice == enTools::Paper)) {
    cout << "Round Winner   : [Player1]" << endl;
    } else {
    cout << "Round Winner   : [Computer]" << endl;
    }
    cout<<"_____________________________________________"<<endl;
}
void showGameOverScreen()
{
    cout<<"\t\t\t_____________________________________________________"<<endl;
    cout<<"\t\t\t\t\t+++ G a m e  O v e r +++"<<endl;
    cout<<"\t\t\t______________________________________________________"<<endl;
}
void showFinalGameResults(stGameResults& GameResults)
{
    if (GameResults.Player1WonTimes > GameResults.ComputerWonTimes)
    {
        green();
        GameResults.FinalWinner = "[Player 1]";
    }
    else if (GameResults.Player1WonTimes == GameResults.ComputerWonTimes)
    {
        yellow();
        GameResults.FinalWinner = "[No winner]";
    }
    else
    {
        red();
        GameResults.FinalWinner = "[Computer]";
    }
    cout<<"\t\t\t_______________[G a m e  R e s u l t s]_______________"<<endl;
    cout<<"Game Rounds : "<<GameResults.GameRounds<<endl;
    cout<<"Player1 won times : "<<GameResults.Player1WonTimes<<endl;
    cout<<"Computer won times : "<<GameResults.ComputerWonTimes<<endl;
    cout<<"Draw times : "<<GameResults.DrawTimes<<endl;
    cout<<"Final winner : "<<GameResults.FinalWinner<<endl;
    cout<<"\t\t\t______________________________________________________"<<endl;
}
void showRound(stGameResults& GameResults)
{
    for(int i=1;i<=GameResults.GameRounds;i++){
    cout<<"Round ["<<i<<"] begins:"<<endl;
    cout<<endl;
    roundInput(GameResults,i);
    }
    showGameOverScreen();
    showFinalGameResults(GameResults);
    char Checker;
    cout<<"Do you want to play again? Y/N"<<endl;
    cin>>Checker;
    if(Checker=='y'||Checker=='Y'){
    system("clear");
    startGame();
    }
}
void startGame()
{
    stGameResults GameResults = {0, 0, 0, 0, ""};
    GameResults.GameRounds = howManyRounds();
    showRound(GameResults);
}
int main()
{
    srand(time(NULL));
    startGame();
    return 0;
}
