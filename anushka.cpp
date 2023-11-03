#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<cstdlib>
#include<cstdio>
#include<math.h>
#include<random>
using namespace std;
int acc_no=1000,serial_no=0,deleted_account_number[100],deleted_no_serial=0;
int amount,number,allow;
char garbage,sub_choice;

class ACCOUNT_INFO
{
    public:
    int ACCOUNT_NO;
    char ACCOUNT_NAME[30];
    char PERSON_NAME[30];
    char DATE_OF_BIRTH[30];
    char GENDER[20];
    char Address[30];


};

class BALANCE :public ACCOUNT_INFO{

    int Money,pin=0;
    public:

    int Create_Account(){
        system("cls");
        cout<<"\n\n\n\n\tENTER NAME FOR ACCOUNT:\t";
        cin>>ACCOUNT_NAME;
        cout<<"\n\t ENTER USER NAME: \t";
        fflush(stdout);
        cin>>PERSON_NAME;
        cout<<"\n\t ENTER YOUR DATE OF BIRTH:\t";
        fflush(stdout);
        cin>>DATE_OF_BIRTH;
        cout<<"\n\t ENTER YOUR GENDER:\t";
        fflush(stdout);
        cin>>GENDER;
        cout<<"\n\t ENTER YOUR ADDRESS:\t";
        fflush(stdout);
        cin>>Address;
        ACCOUNT_NO=acc_no;
        acc_no++;
        cout<<"\n\tYOUR ACCOUNT IS REGISTER TO:\t "<<ACCOUNT_NO;
        cout<<"\n\n\n\tENTER ANY KEY TO BACK\t";
        fflush(stdout);
        cin>>garbage;
        return 0;
    }
    
    void Entery(int amount){
       
        Money=Money+amount;    
    }

    int Withdraw(int amount){
       
        if(amount>Money){
            cout<<"\n\n\t not Enough Money\t";
            cout<<"Enter any key to go back\t";
            cin>>garbage;
            return 0;
        }
        Money=Money-amount;
        cout<<Money;
        return 0;
        
    }

    int show(int num){
        ACCOUNT_NO= num+1000;
        cout<<"\n\n\t ACCOUNT NO:-\t"<<ACCOUNT_NO;
        cout<<"\n\tBALANCE:-\t$"<<Money;

        cout<<"\n\tEnter any key to go back\t";
        fflush(stdout);
        cin>>garbage;
        return 0;
    }
      

    
    int password(){
    system("cls");
    cout<<"\n\n\tENTER YOUR PIN:-\t";
    cin>>number;
    if(number==pin)
     return 1;
    else 
     return 0;
    }  
    
    int change_pin(){
    system("cls");
    cout<<"\n\n\tENTER YOUR PIN\t";
    cin>>number;
    if(number==pin)
    {
        cout<<"\n\n\t ENTER NEW PIN\t";
        cin>>pin;

        cout<<"\n\t PIN CHANGED SUCESSFULY\t";
    }    
    else 
    cout<<"\n\n\t YOU ENTERED WRONG PIN\t";
    cout<<"\n\tENTER ANY KEY TO EXIT:\t";
    cin>>garbage;
    return 0;
    }

    
    
};

 BALANCE ACCOUNT[100],*ptr;
int check(int num){
    if(num>=serial_no||num<0||num>99)
    {   cout<<serial_no;
        cout<<"\n\n\n\t SUCH ACCOUNT DOES NOT EXITS\t"<<num;
        return 101;
   
    }
    else return num; 
}

int deposite( ){
    int deposite_acc_no;
    deposite_start:
    cout<<"\n\n\n\t ENETER THE ACCOUNT NUMBER YOU WANT TO DEPOSITE IN:\t";
    cin>>deposite_acc_no;
    deposite_acc_no=deposite_acc_no-1000;
    if(check(deposite_acc_no)==101){
     cout<<"\n\tWant to go Exit [Y]\t";
        fflush(stdout);
        cin>>sub_choice;
        if(sub_choice=='y'||sub_choice=='Y')
        return 101;
        else
        goto deposite_start;
    }
        
    ptr=&ACCOUNT[deposite_acc_no];
    number=ptr->password();
    if(number==0)
    return 0;
    cout<<"\n\t\t ENETER THE AMOUNT YOU WANT TO DEPOSITE:\t";
    fflush(stdout);
    cin>>amount;
    ptr->Entery(amount);
    ptr->show(deposite_acc_no);
     return 0;
}

int transfer( BALANCE ACCOUNT[])
{     
        system("cls");
        {cout<<"\n\n\tENTER THE SENDER ACCOUNT  NO\t:";
        int sender,reciver;
        fflush(stdout);
        cin>>sender;
        sender-=1000;
        number=check(sender);
        cout<<number;
        if(number==101)
        return 0;
        ptr=&ACCOUNT[number];
        number=ACCOUNT[number].password();
        if(number==0){
            return 0;
        }
        cout<<"\n\t ENTER THE AMOUNT:\t";
        fflush(stdout);
        cin>>amount;
       if( ptr->Withdraw(amount)==0){
        return 0;
       }
        cout<<"\n\n\tENTER THE RECIVER ACCOUNT NUMBER:\t";
        fflush(stdout);
        cin>>reciver;
        reciver-=1000;
        number=check(reciver);
        cout<<number;
        if(number==101)
        return 0;
        ptr=&ACCOUNT[number];
        ptr->Entery(amount);
        ptr->show(reciver);
        
        }
}
int display( ){
    int acc_no;
    display_start:
    system("cls");
    cout<<"\n\n\n\t ENTER ACCOUNT NUMBER:\t";
    fflush(stdout);
    cin>>acc_no;
    acc_no-=1000;
    if(check(acc_no)==101){
    cout<<"\n\tWant to go Exit [Y]\t";
        fflush(stdout);
        cin>>sub_choice;
        if(sub_choice=='y'||sub_choice=='Y')
        return 101;
        else
        goto display_start;
    }
    ptr=&ACCOUNT[acc_no];
    number=ptr->password();
    if(number==0)
    return 0;
    ptr->show(acc_no);
    return 0;
}

int change_Password(){
    int acc_no;
    change_password_start:
    system("cls");
    cout<<"\n\n\n\tENTER THE ACCOUNT NUMBER\t:";
    fflush(stdout); 
    cin>>acc_no;
    number=check(acc_no-1000);
    if(number==101){
        cout<<"Want to go Exit [Y]";
        fflush(stdout);
        cin>>sub_choice;
        if(sub_choice=='y'||sub_choice=='Y')
        return 101;
        else
        goto change_password_start;
        
    }
    ptr=&ACCOUNT[number];
    ptr->change_pin();   
    return 0;

}




int main()
{
    BALANCE ACCOUNT[100],*ptr;
    int choice;
    while(1){
    system("cls");
    cout<<"\n\n\n\t -**WELCOME TO OUR BANKING SOFTWARE**-";
    cout<<"\n\n\t WHAT DO YOU WANT TO DO";
    cout<<"\n\t1]Create a new Account";
    cout<<"\n\t2]Deposite into a Acoount";
    cout<<"\n\t3]Send money to an Person";
    cout<<"\n\t4]Display Balance ";
    cout<<"\n\t5]SET/Change Password";
    cout<<"\n\t6]Exit\n\n";
    cout<<"\tENTER CHOICE";
    fflush(stdout);
    cin>>choice;

    system("cls");

    switch(choice){

        case 1:
        system("cls");
        ptr=&ACCOUNT[serial_no];
        ptr->Create_Account();
        serial_no++;
        cout<<"\tWant to go Exit [Y]";
        fflush(stdout);
        cin>>sub_choice;
        if(sub_choice=='y'||sub_choice=='Y')
        return 0;
        break;

        case 2:
        system("cls");
        deposite();
        cout<<"Want to go Exit [Y]";
        fflush(stdout);
        cin>>sub_choice;
        if(sub_choice=='y'||sub_choice=='Y')
        return 0;
        break;

        case 3:
        transfer(ACCOUNT);
        cout<<"Want to go Exit [Y]";
        fflush(stdout);
        cin>>sub_choice;
        if(sub_choice=='y'||sub_choice=='Y')
        return 0;
        break;

        case 4:
        system("cls");
        display();
        break;

        case 5:
        system("cls");
        change_Password();
        break;

        case 6:
        return 0;
        
        default:
        system("cls");
        cout<<"Sorry no such option avaiable";
        cout<<"Want to go Exit [Y]";
        fflush(stdout);
        cin>>sub_choice;
        if(sub_choice=='y'||sub_choice=='Y')
        return 0;
        break;

       }
    }

    return 0;
}