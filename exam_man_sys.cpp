#include<iostream>
#include<string.h>
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
};
struct marks s[100];

class sample
{
public:
int l,upmrk,n,roll,sub_code;
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
ll:
cout<<"phy-1/chem-2/math-3/eng-4/asses-5"<<endl;
cout<<"entet subject code you want to update marks "<<endl;
cin>>sub_code;
cout<<"\tenter marks :\t "<<endl;
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
    cout<<"wrong subject code";
    goto ll;
}

}




void display()
{
for(int k=1;k<=n;k++)
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
cout<<"passed"<<endl;
}
else
{
cout<<"failed"<<endl;
}

cout<<"-------------------------------------------------------------------------------"<<endl;


}



}



};


int main ()
{

int i,nm,opt;
cout<<"wel-come "<<endl;
char ch;
cout<<"enter no of students :";
cin>>nm;
sample s(nm);
for(i=1;i<=nm;i++)
{
cout <<"roll no "<< i <<" P/A :";
cin>>ch;

if(ch=='P'||ch=='p')
{
s.addmarks(i);
}
}
while(1)
{
cout<<"enter choice "<<endl;
cout<<"1 for update 2 for display all data 3 for exit : ";
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
cout<<"thank you very much";
break;
}
}
return 0;
}
