#include <iostream>
using namespace std;
#include <ctime>


void IntroMessage(int Diffculty) {
//Print Welcome message
cout << endl << "You are a secret agent breaking into a level "<< Diffculty ;
cout << " secure server room... Enter the correct code to continue..."<< endl;

}
bool PlayGame( int LevelDiffculty) {
srand(time(NULL)); //Create random sequence based on time of day
IntroMessage(LevelDiffculty);

const int CodeA = rand() % LevelDiffculty + LevelDiffculty;
const int CodeB = rand() % LevelDiffculty + LevelDiffculty;
const int CodeC = rand() % LevelDiffculty + LevelDiffculty;

const int CodeSum = CodeA + CodeB + CodeC;
const int CodeProduct = CodeA*CodeB*CodeC;

cout<<endl;
cout << "+ There are three numbers in the code "<< endl;
cout << "+ The codes add up to: "<< CodeSum << endl;
cout << "+ The codes multiple to: "<< CodeProduct << endl;

int GuessA, GuessB, GuessC;

int PlayerGuess;
cin>> GuessA >> GuessB >> GuessC;
int GuessSum = GuessA + GuessB + GuessC;
int GuessProduct = GuessC*GuessB*GuessA;
cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC << endl;

if (GuessSum == CodeSum && GuessProduct == CodeProduct)
{
cout << "\nYou Win!\n";
return true;
}
else
{
    cout << "\nYou lose!\n";
    return false;
}
}
int main() {

int LevelDiffculty = 1;
int const MaxDiffculty = 5;

while(LevelDiffculty <= MaxDiffculty)  {
bool bLevelConplete = PlayGame(LevelDiffculty);
cin.clear();
cin.ignore();

if (bLevelConplete) {
    ++LevelDiffculty;
}
}
cout << "Congrats! You have obtained all the secure data. Now run!"<< endl;
cout<<endl;
    return 0;
}