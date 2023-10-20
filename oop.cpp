#include<iostream>

#include<conio.h>




using namespace std;

struct marks
{
int phy;
int chem;
int math;
int eng;
int asses;
float perc;
int flag=1;
};
struct marks s[25];

class sample
{
public:
int l,upmrk,n,roll,droll;
char up[15];
sample(int nm)
{

n=nm;
}


void addmarks(int l)
{


cout<<"enter physics marks : ";
cin>>s[l].phy;
cout<<"enter chemistery marks : ";
cin>>s[l].chem;
cout<<"enter maths marks : ";
cin>>s[l].math;
cout<<"enter english marks : ";
cin>>s[l].eng;
cout<<"enter assesment marks : ";
cin>>s[l].asses;
s[l].perc=(s[l].phy+s[l].chem+s[l].math+s[l].eng+s[l].asses)/5;

}


void update ()
{
cout<<"enter roll no of student  : "<<endl;
cin>>roll;
cout<<"phy/chem/math/eng/asses"<<endl;
cout<<"entet subject you want to update marks "<<endl;
cin>>up;
cout<<"enter marks : "<<endl;
cin>>upmrk;
if(up=="phy")
{
s[roll].phy=upmrk;
}

if(up=="chem")
{
s[roll].chem=upmrk;
}

if(up=="math")
{
s[roll].math=upmrk;
}

if(up=="eng")
{
s[roll].eng=upmrk;
}

if(up=="asses")
{
s[roll].asses=upmrk;
}

}

void del()
{
    cout<<"enter roll number of student : ";
    cin>>droll;
    s[droll].flag=0;
}


void display()
{
for(int k=1;k<=n;k++)
{
if(s[k].flag==1)
{


cout<<"roll_no:"<<k<<endl;
cout<<"physics:"<<s[k].phy<<endl;
cout<<"chemistry:"<<s[k].chem<<endl;
cout<<"maths:"<<s[k].math<<endl;
cout<<"english:"<<s[k].eng<<endl;
cout<<"assesment:"<<s[k].asses<<endl;
cout<<"percentage:"<<s[k].perc<<"%"<<endl;

if(s[k].perc>=40)
{
cout<<"passed";
}
else
{
cout<<"failed";
}

cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
}
}



}



};


int main ()
{

int i,nm,opt;
cout<<"wel-come "<<endl;
char ch;
cout<<"enter no of students "<<endl;
cin>>nm;
sample s(nm);
for(i=1;i<=nm;i++)
{
cout <<"roll no "<< i <<" P/A "<<endl;
cin>>ch;

if(ch=='P'||ch=='p')
{
s.addmarks(i);
}
}
while(1)
{
cout<<"enter choice "<<endl;
cout<<"1-update "<<endl<<"2-display" <<endl<<"3-delete" <<endl<<"4-exit: ";
cin>>opt;

if(opt==1)
{
s.update();
}

if(opt==2)
{
s.display();
}

if(opt==3)
{
s.del();
}
if(opt==4)
{
cout<<"thank you very much";
break;
}
}
return 0;
}