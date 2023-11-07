#include<iostream>
#include <stdlib.h>


using namespace std;
char garbage;
int i,nm,opt;
struct marks
{
int phy;
int chem;
int math;
int eng;
int asses;
float perc;
};
struct marks s[100];

class sample
{
public:
int l,upmrk,n,roll,sub_code,k;
char up[15];
sample(int nm)
{

n=nm;
}


int addmarks(int l)
{
    system("cls");
cout<<"\n\n\n\t\t\t\t\t****Wel-come To Come Examination Management System****\n\n\n"<<endl;
label1:
cout<<"\t\tFor roll no "<<l<<endl<<endl;
if(l>nm){
cout<<"\t\tno such student";
cout<<"\nEnter any key to back\t";
fflush(stdout);
cin>>garbage;
return 0;
}
cout<<"\t\tenter physics marks : ";
cin>>s[l].phy;
if(s[l].phy>100 || s[l].phy<0)
{
    cout<<"\tmarks invalid"<<endl;
    goto label1;
}
label2:
cout<<"\t\tenter chemistery marks : ";
cin>>s[l].chem;
if(s[l].chem>100 || s[l].chem<0)
{
    cout<<"\tmarks invalid"<<endl;
    goto label2;
}
label3:
cout<<"\t\tenter maths marks : ";
cin>>s[l].math;
if(s[l].math>100 || s[l].math<0)
{
    cout<<"\tmarks invalid"<<endl;
    goto label3;
}
label4:
cout<<"\t\tenter english marks : ";
cin>>s[l].eng;
if(s[l].eng>100 || s[l].eng<0)
{
    cout<<"\tmarks invalid"<<endl;
    goto label4;
}
label5:
cout<<"\t\tenter assesment marks : ";
cin>>s[l].asses;
if(s[l].asses>100 || s[l].asses<0)
{
    cout<<"\tmarks invalid"<<endl;
    goto label5;
}
s[l].perc=(s[l].phy+s[l].chem+s[l].math+s[l].eng+s[l].asses)/5;
system("cls");
return 0;
}


int update ()
{
    cout<<"\n\n\n\t\t\t\t\t****Wel-come To Come Examination Management System****\n\n\n"<<endl;
cout<<"\t\tenter roll no of student  : "<<endl;
cin>>roll;
if(roll>nm){
cout<<"\t\tno such student";
cout<<"\nEnter any key to back\t";
fflush(stdout);
cin>>garbage;
return 0;
}
ll:
cout<<"\t\tphy-1\n\t\tchem-2\n\t\tmath-3\n\t\teng-4\n\t\tasses-5"<<endl;
cout<<"\t\tentet subject code you want to update marks "<<endl;
cin>>sub_code;
cout<<"\t\tenter marks : "<<endl;
cin>>upmrk;

if(sub_code==1)
{
s[roll].phy=upmrk;
s[roll].perc=(s[roll].phy+s[roll].chem+s[roll].math+s[roll].eng+s[roll].asses)/5;
}

else if(sub_code==2)
{
s[roll].chem=upmrk;
s[roll].perc=(s[roll].phy+s[roll].chem+s[roll].math+s[roll].eng+s[roll].asses)/5;
}

else if(sub_code==3)
{
s[roll].math=upmrk;
s[roll].perc=(s[roll].phy+s[roll].chem+s[roll].math+s[roll].eng+s[roll].asses)/5;
}

else if(sub_code==4)
{
s[roll].eng=upmrk;
s[roll].perc=(s[roll].phy+s[roll].chem+s[roll].math+s[roll].eng+s[roll].asses)/5;
}

else if(sub_code==5)
{
s[roll].asses=upmrk;
s[roll].perc=(s[roll].phy+s[roll].chem+s[roll].math+s[roll].eng+s[roll].asses)/5;
}
else
{
    cout<<"\twrong subject code";
    goto ll;
}

return 0;

}




void display()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t****Wel-come To Come Examination Management System****\n\n\n"<<endl;
cout<<"roll_no"<<"  "<<"physics"<<"  "<<"chemistry"<<"  "<<"math"<<"  "<<"english"<<"  "<<"assesment"<<"  "<<"percentage"<<"   "<<"result"<<endl;
cout<<"---------------------------------------------------------------------------------------"<<endl;
for(k=1;k<=n;k++)
{
cout<<"\n";    
cout<<"     ";    
cout<<k;
cout<<"        ";
cout<<s[k].phy;
cout<<"       ";
cout<<s[k].chem;
cout<<"      ";
cout<<s[k].math;
cout<<"       ";
cout<<s[k].eng;
cout<<"       ";
cout<<s[k].asses;
cout<<"         ";
cout<<s[k].perc<<"%";
cout<<"    ";

if(s[k].perc>=40)
{
cout<<"\tpassed"<<endl;
}
else
{  
cout<<"\t  failed"<<endl;
}

cout<<"---------------------------------------------------------------------------------------"<<endl;


}

cout<<"\t\tenter any key to go back";
cin>>garbage;

}



};


int main ()
{
system("cls");
cout<<"\n\n\n\t\t\t\t\t****Wel-come To Come Examination Management System****"<<endl;
char ch;
start:
cout<<"\n\n\t\t\tEnter no of students :-\t";
cin>>nm;
if(nm<0 || nm>1000)
{cout<<"\n\t INVALID !!!";
cout<<"\tEnter any key to go back\t";
cin>>garbage;
goto start;
}
sample s(nm);
for(i=1;i<=nm;i++)
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t****Wel-come To Come Examination Management System****"<<endl;
a:
cout <<"\t\troll no "<< i <<" P/A :\t";
fflush(stdout);
cin>>ch;

if(ch=='P'||ch=='p')
{
s.addmarks(i);
}
else if(ch=='a'||ch=='A')
{
continue;
}
else
{
cout<<"\terror choice"<<endl;
goto a;
}
}
while(1)
{
     system("cls");
 cout<<"\n\n\n\t\t\t\t\t****Wel-come To Come Examination Management System****"<<endl;
cout<<"\n\n\t1] for update\n\t2] for display all data \n\t3] for exit :\t ";
cout<<"\n\tENTER YOUR CHOICE:-\t";
fflush(stdout);
cin>>opt;

if(opt==1)
{
system("cls");    
s.update();

}

if(opt==2)
{
system("cls");   
s.display();

}

if(opt==3)
{

cout<<"thank you very much";
cout<<"enter any key to exit";
cin>>garbage;
return 0;
}
}
return 0;
}