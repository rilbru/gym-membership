/*****************************************************************************
# Author:           Devri Anderson 
# Lab:              Assignment #3
# Date:             January 28, 2022
# Description:      This program will calculate a gym membership cost
# Input:            char choice, char passType, int passLength, int trainSesh
# Output:           double memTotal, double trainTotal, double totalCost
# Sources:          Zybooks
******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
using namespace std;

//CHANGE THE TOTALS FROM INT TO DOUBLE STATIC CAST

// setting constants
const int SPASS = 20, UPASS = 30;

// function prototypes
void welcome();
void MenuFunction();
char readOption(char choice);
char readChar(string prompt);
int readInt(string prompt);
void userInput(char &passType, int &passLength, int &trainSesh);
void calcCost(char passType, int passLength, int trainSesh, double totalCost, double trainTotal, double memTotal);

int main() {
  // declaring variables
  char choice, passType;
  int passLength, trainSesh = 0;
  double memTotal, trainTotal, totalCost = 0.0;

  welcome();

  //setting decimal 2 places
  cout << fixed << setprecision(2);

  do
  {
    MenuFunction();
    choice = readOption(choice);
    userInput(passType, passLength, trainSesh);
    calcCost(passType, passLength, trainSesh, totalCost, trainTotal, memTotal);
  }while(choice != 'q');
  // THIS IS NOT WORKING! :(

  cout << "Thank you for checking out my fitClub center!! Come back and be fit!" << endl;

  return 0;
}

// welcome message function
void welcome()
{
  cout << "Welcome to my fitClub Program!" << endl;

  cout << "The cost to become a member of the fitClub Center is as follows: \n\n-The membership fee per month for Sports Club is $20.00 \n-The membership fee per month for Ultra Sports Club is $30.00 \n-If the membership is bought and paid for 12 or more months, the discount is 10% off membership cost \n-Personal training sessions are $10.00 per session \n-If more than five personal training sessions are bought and paid for, the discount on each session is 20%" << endl;
}

// function that displays calculate or quit
void MenuFunction()
{
  cout << "\nPlease pick one of the following options: \n\n(C/c) Calculate membership costs \n(Q/q) Quit this program\n" << endl;
}


//char function to take users input and validate
char readOption(char choice)
{
  cin >> choice;
  choice = (tolower(choice));
  while (choice != 'c' && choice != 'q')
  {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Invalid option! Please try again." << endl;
    cin >> choice;
    choice = (tolower(choice));
  }
  return choice;
}


// char function to get pass type
void userInput(char &passType, int &passLength, int &trainSesh)
{
  passType = readChar("Would you prefer (S)ports or (U)ltra sports club?: ");
  while (passType != 's' && passType != 'u')
  {
    cout << "Invalid option! Try again.\n" << endl;
    passType = readChar("Would you prefer (S)ports or (U)ltra sports club?: ");
  }

  passLength = readInt("How many months of membership would you like?: ");
  while (passLength < 0)
  {
    cout << "Invalid amount! Please enter again.\n" << endl;
    passLength = readInt("How many months of membership would you like?: ");
  }

  trainSesh = readInt("How many personal training sessions would you like?: ");
  while (trainSesh < 0)
  {
    cout << "Invalid amount! Please enter again.\n" << endl;
    trainSesh = readInt("How many personal training sessions would you like?: ");
  }
}

// char function to read chars and validate input
char readChar(string prompt)
{
  char temp;
  cout << prompt;
  cin >> temp;
  temp = (tolower(temp));
  while (!cin) 
  {
    cout << "Invalid option!\n" << endl;
    cout << prompt;
    cin >> temp;
    temp = (tolower(temp));
  }
  return temp;
}

// int function to read integers and validate input
int readInt(string prompt)
{
  int temp = 0;
  cout << prompt;
  cin >> temp;
  while (!cin)
  { 
    cout << "Invalid option!\n" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << prompt;
    cin >> temp;
  }
  return temp;
}





// function that calculates membership cost
void calcCost(char passType, int passLength, int trainSesh, double totalCost, double trainTotal, double memTotal)
{
  trainTotal = static_cast<double>(trainSesh * 10);

  if (passType == 's' && passLength < 12)
  {
    memTotal = static_cast<double>(SPASS * passLength);
  }

  else if(passType == 's' && passLength >= 12)
  {
    memTotal = static_cast<double>(SPASS * passLength) - (SPASS * passLength * .10);
  }
  
  if (passType == 'u' && passLength < 12)
  {
    memTotal = static_cast<double>(UPASS * passLength);
  }
   
  else if (passType == 'u' && passLength >= 12)
  {
    memTotal = static_cast<double>(UPASS * passLength) - (UPASS * passLength * .10);
  }
   
  if (trainSesh >= 5)
  {
    trainTotal = static_cast<double>(trainSesh * 10) - (trainSesh * 10 * .20);
  }


  if (passLength >= 12)
  {
    cout << "\nYour membership cost after the 10% off is $" << memTotal << endl;
  }
  if (passLength < 12)
  {
    cout << "\nYour membership cost is $" << memTotal << endl;
  }


  totalCost = static_cast<double>(memTotal + trainTotal);

  cout << "Your personal training cost for " << trainSesh << " sessions is $" << trainTotal << endl;
  cout << "Your total membership cost is $" << totalCost << endl;
}
