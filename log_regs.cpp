#include<iostream>
#include<fstream>
using namespace std;
int main();
void login(){
    string username,password,id,pass;
    cout<<"Please enter your userName"<<endl;
    cin>>username;
    cout<<"please enter your password"<<endl;
    cin>>password;
    ifstream input("records.txt");
    bool flag=false;
    while(input>>id>>pass){
        if(username==id && password==pass){
            flag=true;
        }
    }
    system("cls");
    if(flag){
        cout<<"Thanks for login"<<endl;
    }
    else{
        cout<<"please check your username and password..we are not finding any records"<<endl;
    }
    input.close();
    main();
}
void registration(){
    string rusername,rpassword,ruser,rpass;
    cout<<"please enter your user name"<<endl;
    cin>>rusername;
    cout<<"please enter your password"<<endl;
    cin>>rpassword;
    fstream output("records.txt",ios::app);

    output<<rusername<<" "<<rpassword<<endl;
    system("cls");
    cout<<"you have succesfully registered"<<endl;
    main();
}
void forgot(){
    int op;
    cout<<"do you forgot your passowrd?..no worries"<<endl;
    cout<<"press 1 if you want to search it by userName"<<endl;
    cout<<"press 2 if you want to go to main menu"<<endl;
    cout<<"\n please enter your choice"<<endl;
    cin>>op;
    switch(op){
        case 1:
        {
          string username,userid,pass;
          cout<<"please enter your last username you remembered"<<endl;
          cin>>username;
          ifstream in("records.txt");
          bool flag=false;
          while(in>>userid>>pass){
            if(username==userid){
                flag=true;
                cout<<"account found!!"<<endl;
                cout<<"your password is "<<pass<<endl;
                break;
            }
          }
          if(!flag){
            cout<<"sorry we couldn't find your account...please check your username"<<endl;
          }
          in.close();
          main();
        }
        case 2:
        {
           main();
        }
        
        default:
        {
          cout<<"please enter a valid number"<<endl;
        }
          
    }
}
int main(){
    int choice;
    cout<<"\t\t\t\t   Welcome to our page            "<<endl;
    cout<<"\npress 1 for login"<<endl;
    cout<<"\npress 2 for registration"<<endl;
    cout<<"\n press 3 if you forget your password"<<endl;
    cout<<"\n press 4 if you want to exit our page"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
           login();
           break;
        case 2:
          registration();
          break;
        case 3:
          forgot();
           break;
        case 4:
          cout<<"Thank you for visiting our page..please visit again"<<endl;
          break;
          
          default:
          cout<<"please enter a number among above numbers"<<endl;
          main();
    }
  
    return 0;
}
