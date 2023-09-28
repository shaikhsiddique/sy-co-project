#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


// int add_record( struct dairy pages[],int size);
int add_record(int size);
int view_record(int size);
int Edit_record(int size);
int delete_record(int size);
int password();
int change_password();


struct dairy
{
    int page_number;
    char date[20];
    char time[20];
    char name[20];
    char location[20];
    char record[500];
    

}pages[100];

char pass[]="SIDDIQUE";

char x;

int page_no=0;

int main(){
    int number_of_pages;
    printf("\t*********************************************************");
    printf("\n\t*\t\t DIARY MANAGEMENT SYSTEM \t\t* \n");
    printf("\t*********************************************************");

    printf("\t\n\n \t enter the number pages you want in your MAXIMUM PAGES 100 dairy:-");
    scanf("%d",&number_of_pages);

    // struct dairy pages[number_of_pages];
    
    int choice,i=1;
    
     while(i>=1)
     

    {   
        system("cls");
        printf("\n\n\n");
        printf("\n\t\t MAIN MENU\t \t\n");
        printf("\n\n\tADD RECORD\t[1]");
        printf("\n\tVIEW RECORD\t[2]");
        printf("\n\tEDIT RECORD\t[3]");
        printf("\n\tDELETE RECORD\t[4]");
        printf("\n\tEDIT PASSWORD\t[5]");
        printf("\n\tEXIT\t\t[6]");
        printf("\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&choice);

        switch(choice)

        {

        case 1:

            // add_record(pages[],number_of_pages);
            add_record(number_of_pages);

            break;

        case 2:

            view_record(number_of_pages);

            break;

        case 3:

            Edit_record(number_of_pages);

            break;

        case 4:

            delete_record(number_of_pages);

            break;

        case 5:

            change_password();

            break;

        case 6:
             system("cls");
            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE ");
            printf("\n\tENTER ANY KEY TO EXIT!");
            fflush(stdin);
            scanf("%c",&x);
            i=0;
            
            exit;
            break;

        default:

            printf("\nYOU ENTERED WRONG CHOICE..");

            printf("\nPRESS ANY KEY TO TRY AGAIN");

            getch();



        }
    }
        system("cls"); //use to clear screen


    
    //  printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE ");
     getch();

    return 0;
}


    int add_record(int size){

    int value;
    char ch='Y';
    start:
    
     system("cls");
    
    printf("\n\n\t\t***************************\n");

    printf("\t\t* WELCOME TO THE ADD MENU *");

    printf("\n\t\t***************************\n\n");
     for(int i=0;i<size;i++ ){

        
    printf("\n\n\tENTER PAGE N0:");
     fflush(stdin);
    scanf("%d",&page_no);
//   checking
     value=pages[page_no].page_number;
    if(page_no>size){
        printf("\n\tOUT OFF PAGES");
        printf("\n\n\t WANT TO GO BACK:[Y/N]");
         fflush(stdin);
        scanf("%c",&ch);
        if(ch=='Y'||ch=='y'){
            return 0;
        }
       else{
        goto start;
       }
    }
    
     if(value==page_no){
        printf("\n\n\tpage all ready exist");
        printf("\n\n\t WANT TO GO BACK:[Y/N]");
         fflush(stdin);
        scanf("%c",&ch);
        if(ch=='Y'||ch=='y'){
            return 0;
        }
        else{
            goto start;
        }
        
        
    }
        pages[page_no].page_number=page_no;
        printf("\n\n\t ENTER DATE:");
         fflush(stdin);
        scanf("%s",pages[page_no].date);
        
        printf("\n\n\t ENTER TIME:");
         fflush(stdin);
        scanf("%s",pages[page_no].time);
    
        printf("\n\n\tENTER THE NAME OF RECORD:");
         fflush(stdin);
        scanf("%s",pages[page_no].name);

        printf("\n\n\tENTER THE LOCATION:");
         fflush(stdin);
        scanf("%s",pages[page_no].location);

        printf("\n\n\t ENTER THE RECORD:");
         fflush(stdin);
        scanf("%s",pages[page_no].record);
       
    system("cls");
     printf("\n\n\n \t RECORD OF PAGE %d ADDED",page_no);    
    printf("\n\n \t DO YOU WANT TO ADD MORE RECORDS: [y/n]:");
     fflush(stdin);
    scanf("%s",&x);
    if(ch=='N'||ch=='n'){
        printf("%c",ch);
        break;
        
    }
     }   
    return 1;

}
int view_record(int size){
    
    if(password()!=0){
        printf ("\n\n\t YOU ENTERED WRONG PASSWORD");
        printf("\n\t PRESS ANY KEY TO GO BACK");
        fflush(stdin);
        scanf("%c",&x);
        return 1;
    }
   
     system("cls");
    
     printf("\n\n\t\t*******************************\n");

    printf("\t\t* HERE IS THE VIEWING MENU *");

    printf("\n\t\t*******************************\n\n");

    
    char choice;
    start:
    printf("\n\n\tENTER PAGE NO:");
    fflush(stdin);
    scanf("%d",&page_no);
    if(page_no>size||page_no!=pages[page_no].page_number){
    printf("\n \n \t NO SUCH PAGE EXIST");
     printf("\n\n\t WANT TO GO BACK[Y/N]");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='Y'||choice=='y'){
        return 1;
    }
    else{
     goto start;
    }
    
    }
    
    
    
    printf("\n\t%d",pages[page_no].page_number);
    printf("\n\t%s",pages[page_no].date);
    printf("\n\t%s",pages[page_no].time);
    printf("\n\t%s",pages[page_no].name);
    printf("\n\t%s",pages[page_no].location);  
    printf("\n\t%s",pages[page_no].record);
    
    printf("\n\n\t WANT TO SEE ANY OTHER RECORD[Y/N]");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='Y'||choice=='y'){
    goto start;
    }
    
    return (1);

}

int Edit_record( int size){
    
    if(password()!=0){
        printf ("\n\n\t YOU ENTERED WRONG PASSWORD");
        printf("\n\t PRESS ANY KEY TO GO BACK");
        fflush(stdin);
        scanf("%c",&x);
        return 1;
    }

     system("cls");
    
    printf("\n\n\t\t*******************************\n");

    printf("\t\t* WELCOME TO THE EDITING MENU *");

    printf("\n\t\t*******************************\n\n");

    
    char choice;
    start:
    printf("\n\n\t ENTER THE PAGE NO:");
     fflush(stdin);
    scanf("%d",&page_no);

    if(page_no>size||page_no!=pages[page_no].page_number){
        printf("\n\n\t NO SUCH PAGE EXIST");
        printf("\n\n\t WANT TO GO BACK[Y/N]");
         fflush(stdin);
        scanf("%c",&choice);
        if(choice=='Y'||choice=='y'){
        return (1);
         }
        else{
        goto start;
        }

    }
   
    printf("\n\n\t WHAT RECORD YOU WANT TO CHANGE:");

        printf("\n\n\tRECORD: DATE[1]");

        printf("\n\tRECORD: TIME[2]");

        printf("\n\tRECORD: NAME[3]");

        printf("\n\tRECORD: LOCATION[4]");

        printf("\n\tEDIT RECORD[5]");

        printf("\n\tEDIT ALL RECORD[6]");

        printf("\n\tEXIT\t\t[7]");

        printf("\n\n\tENTER YOUR CHOICE:");

         fflush(stdin);

        scanf("%d",&choice);

        system("cls");

        switch(choice){

            case 1:

            printf("\n\t RECORD: DATE");
            printf("\n\t ENTER NEW DATE");
            fflush(stdin);
            gets(pages[page_no].date);
            printf("\n\t RECORD CHANGED:");
            printf("\n\n\t WANT TO SEE ANY OTHER RECORD[Y/N]");
            fflush(stdin);
            scanf("%c",&choice);
            if(choice=='Y'||choice=='y'){
            goto start;
            }
            break;

            case 2:
            printf("\n\t RECORD TIME");
            printf("\n\t NEW TIME");
             fflush(stdin);
             gets(pages[page_no].time);
            printf("\n\t RECORD CHANGED:");
            printf("\n\n\t WANT TO SEE ANY OTHER RECORD[Y/N]");
            fflush(stdin);
            scanf("%c",&choice);
            if(choice=='Y'||choice=='y'){
            goto start;
            }
            break;

            case 3: 
            printf("\n\tRECORD: NAME");
            printf("\n\t NEW NAME");
             fflush(stdin);
             gets(pages[page_no].name);
            printf("\n\t RECORD CHANGED:");
            printf("\n\n\t WANT TO SEE ANY OTHER RECORD[Y/N]");
            fflush(stdin);
            scanf("%c",&choice);
            if(choice=='Y'||choice=='y'){
            goto start;
            }
            break;

            case 4:
            printf("\n\t RECORD: LOCATION");
            printf("\n\tNEW LOCATION");
             fflush(stdin);
             gets(pages[page_no].location);
            printf("\n\t RECORD CHANGED:");
            printf("\n\n\t WANT TO SEE ANY OTHER RECORD[Y/N]");
            fflush(stdin);
            scanf("%c",&choice);
            if(choice=='Y'||choice=='y'){
            goto start;
            }
            break;

            case 5:
            printf("\n\t EDIT RECORD");
            printf("\n\t NEW RECORD");
             fflush(stdin);
             gets(pages[page_no].record);
            printf("\n\t RECORD CHANGED:");
            printf("\n\n\t WANT TO SEE ANY OTHER RECORD[Y/N]");
            fflush(stdin);
            scanf("%c",&choice);
            if(choice=='Y'||choice=='y'){
            goto start;
            }
            break;

            case 6:
            printf("\n\t EDIT ALL RECORD");
             printf("\n\n\t ENTER DATE:");
            fflush(stdin);
            scanf("%s",pages[page_no].date);
        
            printf("\n\n\t ENTER TIME:");
            fflush(stdin);
            scanf("%s",pages[page_no].time);
    
            printf("\n\n\tENTER THE NAME OF RECORD:");
            fflush(stdin);
            scanf("%s",pages[page_no].name);

            printf("\n\n\tENTER THE LOCATION:");
            fflush(stdin);
            scanf("%s",pages[page_no].location);

            printf("\n\n\t ENTER THE RECORD:");
            fflush(stdin);
            scanf("%s",pages[page_no].record);
            
            printf("\n\t RECORD CHANGED:");
            printf("\n\n\t WANT TO SEE ANY OTHER RECORD[Y/N]");
            fflush(stdin);
            scanf("%c",&choice);
            if(choice=='Y'||choice=='y'){
            goto start;
            }
            break;

            default:
            printf("\n\t WRONG CHOICE");
            printf("\n\t PRESS ANY KEY TO GO BACK");
            scanf("%d",page_no);
            return 1;
            

        }
        system("cls");
        return 1;


}

int delete_record(int size){
    
    if(password()!=0){
        printf ("\n\n\t YOU ENTERED WRONG PASSWORD");
        printf("\n\t PRESS ANY KEY TO GO BACK");
        fflush(stdin);
        scanf("%c",&x);
        return 1;
    }
     system("cls");
    printf("\t*********************************************************");
    printf("\n\t*\t\t DIARY MANAGEMENT SYSTEM \t\t* \n");
    printf("\t*********************************************************");
    printf("\n\n\t\t*******************************\n");

    printf("\t\t* WELCOME TO THE DELETING MENU *");

    printf("\n\t\t*******************************\n\n");

    
    char choice;
    char empty[500]={""};
    
    start:
    printf("\n\n\t ENTER THE PAGE NO:");
    fflush(stdin);
    scanf("%d",&page_no);

     if(page_no>size||page_no!=pages[page_no].page_number){
        printf("\n \n \t NO SUCH PAGE EXIST");
        printf("\n\n\t WANT TO GO BACK[Y/N]");
         fflush(stdin);
        scanf("%c",&choice);
        if(choice=='Y'||choice=='y'){
        return (1);
         }
        else{
        goto start;
        }
    }
   
    pages[page_no].page_number=0;
    strcpy(pages[page_no].date,empty);
    strcpy(pages[page_no].time,empty);
    strcpy(pages[page_no].name,empty);
    strcpy(pages[page_no].location,empty);
    strcpy(pages[page_no].record,empty);

   printf("\n\n\t RECORD SUCCESFULY DELETED OF PAGE %d",page_no);
   printf("\n\t ENTER ANY KEY TO GO BACK!");
   scanf("%d",&page_no);
   return 1;    


}

int password(){
    system("cls");
    char enter_pass[100];
    printf("\n\n\t ENTER THE PASSWORD:\t");
    fflush(stdin);
    scanf("%s",&enter_pass);
    return strcmp(pass,enter_pass);
    
    

}
int change_password(){
      system("cls");
    printf("\t*********************************************************");
    printf("\n\t*\t\t DIARY MANAGEMENT SYSTEM \t\t* \n");
    printf("\t*********************************************************");

     
    printf("\t*********************************************************");
    printf("\n\t*\t\t PASSWORD CHANGE MENU:\t\t* \n");
    printf("\t*********************************************************");
    char enter_pass[100];
    printf("\n\n\t ENTER THE PASSWORD:\t");
    fflush(stdin);
    scanf("%s",&enter_pass);
     if( strcmp(pass,enter_pass)==0)
    {
        printf("\n\n\t ENTER NEW PASSWORD!");
        scanf("%s",pass);
        printf("\n \t PASSWORD CHANGED");
        printf("\n\t ENTER ANY KEY TO GO BACK!\t");
         fflush(stdin); 
        scanf("%c",&x);
        return 1;
    }    
    else{
        printf("\n\n\t YOU ENTERED WRONG PASSWORD!");
        printf("\n\t ENTER ANY KEY TO GO BACK!\t");
         fflush(stdin);
        scanf("%c",&x);
        return 1;
    }


}
