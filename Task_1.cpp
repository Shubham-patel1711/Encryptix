#include<iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;
int main(){
    cout <<"|| Welcome To Number Guessing Game ||"<< endl;
    cout <<"You have to guess a number between 1 and 100. "
            "You'll have limited choices based on the level you choose."
            " Good Luck!" << endl;

    while(true){
        cout<< "Enter difficulty Level"<< endl;
        cout<< "1 for Easy"<< endl;
        cout<< "2 for medium"<< endl;
        cout<< "3 for Hard"<< endl;
        cout<< "0 for Exit"<< endl;
        int level;
        cin>> level;
        srand(time(0));
        int secretNumber = 1 + (rand() % 100);
        int playerguess;
        if(level==1){
            cout <<" You have 5 chances to guess"<< endl;
            int chances=5;
            for(int i=1; i<=5; i++){
                cout <<" Enter your Guess"<< endl;
                cin>> playerguess;
                if(playerguess==secretNumber){
                    cout<<"Correct Guess"<< endl;
                    cout<< "-------------------------------------------"<<endl;
                    break;
                }
                else {
                    cout<< "Wrong Guess"<< endl;
                    if(playerguess>secretNumber){
                    cout<<"Too high (Try Again!)"<<endl;
                    cout<< endl;

                    
                }
                else{
                    cout<< "Too Low (Try Again!)"<< endl;
                    cout<< endl;
                }
                chances--;
                cout << chances<<" "<< "Chances left" << endl;
                cout << endl;
                if(chances==0){
                   cout<< "Hard Luck You lose "<< endl;
                   cout<<" Play again Later"<< endl;
                   cout<< "Correct answer is:"<<secretNumber<<endl;
                   cout<< "-----------------------------------------"<< endl;
                }
                }
            }

        }
        if(level==2){
            cout <<" You have 3 chances to guess"<< endl;
            int chances=3;
            for(int i=1; i<=3; i++){
                cout <<" Enter your Guess"<< endl;
                cin>> playerguess;
                if(playerguess==secretNumber){
                    cout<<"Correct Guess"<< endl;
                    cout<< "-------------------------------------------"<<endl;
                    break;
                }
                else {
                    cout<< "Wrong Guess"<< endl;
                    if(playerguess>secretNumber){
                    cout<<"Too high (Try Again!)"<<endl;
                    cout<<endl;
                    
                }
                else{
                    cout<< "Too Low (Try Again!)"<< endl;
                    cout<<endl;
                }
                chances--;
                cout << chances<<" "<< "Chances left" << endl;
                cout<<endl;
                if(chances==0){
                   cout<< "Hard Luck You lose "<< endl;
                   cout<<" Play again Later"<< endl;
                   cout<< "Correct answer is:"<<secretNumber<<endl;
                   cout<< "-----------------------------------------"<< endl;
                }
                }
            }

        }
        if(level==3){
            cout <<" You have 2 chances to guess"<< endl;
            int chances=2;
            for(int i=1; i<=2; i++){
                cout <<" Enter your Guess"<< endl;
                cin>> playerguess;
                if(playerguess==secretNumber){
                    cout<<"Correct Guess"<< endl;
                    cout<< "-------------------------------------------"<<endl;
                    break;
                }
                else {
                    cout<< "Wrong Guess"<< endl;
                    if(playerguess>secretNumber){
                    cout<<"Too high (Try Again!)"<<endl;
                    cout<<endl;
                    
                }
                else{
                    cout<< "Too Low (Try Again!)"<< endl;
                    cout<<endl;
                }
                chances--;
                cout << chances<<" "<< "Chances left" << endl;
                cout<<endl;
                if(chances==0){
                   cout<< "Hard Luck You lose "<< endl;
                   cout<<" Play again Later"<< endl;
                   cout<< "Correct answer is:"<<secretNumber<<endl;
                   cout<< "-----------------------------------------"<< endl;
                }
                }
            }

        }
        if (level == 0) {
            exit(0);
        }
        return 0;
         
       



        

        }

      

    }
    
    
