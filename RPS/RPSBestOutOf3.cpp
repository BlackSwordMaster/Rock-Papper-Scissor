#include <iostream>
using namespace std;

//Function for user choice
char userChoice(){
    char userChoice;
    cout << endl;
    cout << "Pick (r) for Rock (p) for Papper or (s) for Scissor ";
    cin >> userChoice;
    while(userChoice !='r' && userChoice !='p' && userChoice !='s'){
        cout << "Invalid input, Please enter a valid input, (r) for Rock (p) for Papper or (s) for Scissor ";
        cin >> userChoice;
    }
    return userChoice;
}

//Function for Computer Choice
char comChoice(){
    char comchoice[3] = {'r','p','s'};
    return comchoice[rand()%3];
}

//Function to choose winner
int determineWinner(char userChoice, char comChoice){
    if(userChoice == comChoice){
        return 0;
    }
    if((userChoice == 'r' && comChoice == 's') || 
        (userChoice == 'p' && comChoice == 'r') ||
            (userChoice == 's' && comChoice == 'p')){
                return 1;
            }else{
                return -1;
            }
}
//Function to display the choices
void displayChoices(char UserChoice, char ComputerChoice){
    cout << "Your Choice " << UserChoice 
    << " VS. " 
    << ComputerChoice << endl;
}

//Function for score
void displayScore(int userScore, int compScore){
    cout << "Current Score User: " << userScore << "\n" 
    << "Current Score Computer: " << compScore << endl;
}

int main(){
    srand(time(0));

    int userScore = 0;
    int compScore = 0;
    int toWin = 2;

    cout << endl;
    cout << "Best of three WINS.\n" << endl;

    while(userScore < toWin && compScore < toWin){
        char getUserChoice = userChoice();
        char getCompChoice = comChoice();

        displayChoices(getUserChoice, getCompChoice);
        cout << endl;

        int roundResault = determineWinner(getUserChoice, getCompChoice);
        if(roundResault == 1){
            cout << "You win this round\n" << endl;
            userScore++;
        }else if(roundResault == -1){
            cout << "Computer wins this round\n" << endl;
            compScore++;
        }else{
            cout << "This round is a tie\n" << endl;
        }

        displayScore(userScore, compScore);
    
    }

    if(userScore > compScore){
        cout << "\nGratz, you win.\n" << endl;
    }else{
        cout << "\nWomp Womp Computer wins, imagine losing L.\n" << endl;
    }
    
    return 0;

}
