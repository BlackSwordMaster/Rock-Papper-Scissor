#include <iostream>
using namespace std;

//Function for user choice
char userChoice(){
    char userChoice;
    cout << endl;
    cout << "Pick (r) for Rock (p) for Papper or (s) for Scissor ";
    cin >> userChoice;
    return userChoice;
}

//Function for Computer Choice
char comChoice(){
    char comchoice[3] = {'r','p','s'};
    return comchoice[rand()%3];
}

//Function to choose winner
string winner(char userChoice, char comChoice){
    if(userChoice == comChoice){
        return "its a tie";
    }
    if((userChoice == 'r' && comChoice == 's') || 
        (userChoice == 'p' && comChoice == 'r') ||
            (userChoice == 's' && comChoice == 'p')){
                return "YOU WIN";
            }else{
                return "COMPUTER WIN";
            }
}
//Function to display the choices
void displayChoices(char UserChoice, char ComputerChoice){
    cout << "Your Choice " << UserChoice << " VS. " << ComputerChoice << endl;
}

int main(){
    srand(time(0));

    char getUserChoice = userChoice();
    char getComputerChoice = comChoice();

    cout << endl;
    displayChoices(getUserChoice, getComputerChoice);

    cout << endl;
    cout << winner(getUserChoice, getComputerChoice) << endl;
    cout << endl;
    
    return 0;

}