#include<iostream>
using namespace std;
#include<cmath>
int main(){
float a,b;
char op;
cout<<" Welcome to Calculator"<<endl;
bool run=true;
while (run)
{
cout<<"Enter the operation you want to perform"<< endl;
cout<<"+ for Addition"<< endl;
cout<<"- for Subtraction"<< endl;
cout<<"* for Multiplication"<< endl;
cout<<"/ for Division"<< endl;
cin>> op;
if(op=='+'||op=='-'|| op=='*'|| op=='/' ){
cout<< "Enter two numbers with maximum 2 decimal places"<< endl;
cin>>a;
cin>>b;}


switch(op){
    case'+': cout<<a+b<<endl;
            break;
    case'-': cout<<a-b<<endl;
            break;
    case'*': cout<<a*b<<endl;
            break;
    case'/': cout<<a/b<<endl;
            break;
    default: cout<< "Invalid Operation"<<endl;


}
 cout << "Do you want to perform another operation? (y/n): ";
        char cont;
        cin >> cont;
        if (cont == 'n' || cont == 'N') {
            run = false;
        }
        
    }

}