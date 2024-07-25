#include<iostream>
#include<fstream>
using namespace std;
class Student
{
	int roll;
	char name[20];
	char fname[20];
	char clg[20];
	
	public:
		void input()
		{
			cout<<"\n Enter Roll : ";
			cin>>roll;
			cout<<"\n Enter Name : ";
			fflush(stdin);
			gets(name);
			cout<<"\n Enter Father's Name : ";
			gets(fname);
			cout<<"\n Enter College : ";
			gets(clg);
			fflush(stdin);
		}
			
		void disp()
		{
			cout<<"\n Roll : "<<roll<<endl;
			cout<<"\n Name : "<<name<<endl;
			cout<<"\n Father's Name : "<<fname<<endl;
			cout<<"\n College : "<<clg<<endl;
		}
		
	/*	void save()
		{
			ofstream f1;
			f1.open("D:\\MyData\\records.txt",ios::app);
			if(!f1)
			{
				cout<<"\n File Opening Error...";
				return;
			}
			
			f1<<roll<<" "<<name<<" "<<fname<<" "<<clg<<" "<<endl;
			f1.close();
			
		}
		
		void showData()
		{
			ifstream fin("D:\\MyData\\records.txt",ios::in);
			if(!fin)
			{
				cout<<"\n File opening Error";
				return;
			}
			fin>>roll>>name>>fname>>clg;
			cout<<clg<<endl;
			fin.close();
		}*/
	
};


void save()
{
	Student s;
	ofstream fout("D:\\MyData\\records.txt",ios::app);
	if(!fout.is_open())
	{
		cout<<"\n File oppening Error";
		return;
		
	}
	
	s.input();
	cout<<"\n Do you want to save the Records (y/n) : ";
	char ch;
	fflush(stdin);
	cin>>ch;
	if(ch=='y' || ch == 'Y')
	{
		fout.write((char*) &s,sizeof(s));
		cout<<"\n Congratulation Your Registration Success ! ";
	}
	else{
			cout<<"\n Sorry ! Try Again";
	}
	
	fout.close();
	
}

void showData()
{
	ifstream fin("D:\\MyData\\records.txt",ios::in);
	if(!fin.is_open())
	{
		cout<<"\n File opening error .";
		return;
	}
	Student s;
	while(fin.read((char*) &s, sizeof(s)))
	{
		s.disp();
	}
	
	s.disp();
}

int main()
{
	while(1)
	{
		cout<<"\n 1. Registration ";
		cout<<"\n 2. Show Data ";
		cout<<"\n 3. Exit ";
		cout<<"\n Enter your choice : ";
		fflush(stdin);
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:
				save();
				break;
			case 2:
				showData();
				break;
			case 3:
				exit(0);
			default:
				cout<<"\n Invalid Choice...";
		}
	}
	
	
	return 0;
}










