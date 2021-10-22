#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

int choice,i,n,m;
char ch,schedule[100];

int welcome()
{
	   clrscr();

	   cout<<"********************************************************************************\n"
	       <<"                             WELCOME TO EMBRACE\n\n"
	       <<"********************************************************************************\n"
	       <<"Please tell if the user is :\n"
	       <<"1.ADMIN\n"
	       <<"2.TEACHER\n"
	       <<"3.STUDENT\n"
	       <<"4.HOME\n"
	       <<"\nENTER CHOICE ";

	   cin>>choice;

      return choice;
}

class teacher
{
  protected:
  float percent,mathsmarks,physmarks,chemmarks,biomarks,rank;
  char name[10];

  public:

   void getstudent()
     {
		cout<<"\nEnter name of student: ";
		      gets(name);
		cout<<"\nEnter marks obtained in maths: ";
		      cin>>mathsmarks;
		cout<<"\nEnter marks obtained in physics: ";
		      cin>>physmarks;
		cout<<"\nEnter marks obtained in chemistry: ";
		      cin>>chemmarks;
		cout<<"\nEnter marks obtained in biology: ";
		      cin>>biomarks;
		cout<<"\nEnter rank of the student is: ";
		      cin>>rank;
     }

   void percentage()
     {
       percent=((mathsmarks+physmarks+chemmarks+biomarks)/4);
       cout<<"\nName is: "<<name;
       cout<<"\nPercentage is: "<<percent;
       cout<<"\nRank is : "<<rank<<endl;
     }

   float returnpercent()
     {
	return percent;
     }

   ~teacher() {}

}t1;

class student:protected teacher
{
   public:

  student()
      {
		mathsmarks=0;
		physmarks=0;
		chemmarks=0;
		biomarks=0;
		strcpy(name,"no name");
      }

  ~student() {}

}s1;

void insert()
{
 clrscr();
  cout<<"**INSERT DATA**\n";

  cout<<"\nEnter no. of students\n";
  cin>>n;

  ofstream fout("rank.txt",ios::out|ios::app);
  for(i=0;i<n;i++)
  {
     t1.getstudent();
     fout.write((char*)&t1,sizeof(teacher));
  }
  fout.close();

    cout<<"\nCONTENT IN FILE";
	  ifstream fin("rank.txt",ios::in);
	    while(1)
	     {
		  fin.read((char*)&t1,sizeof(teacher));
		  if(fin.eof())break;
		  t1.percentage();
	     }
	  fin.close();
}

void see()
{
   clrscr();

    cout<<"\nCONTENT IN FILE";
	  ifstream fin("rank.txt",ios::in);
	    while(1)
	     {
		  fin.read((char*)&t1,sizeof(teacher));
		  if(fin.eof())break;
		  t1.percentage();
	     }
	  fin.close();
}

void areyou();

void changetea()
{
  do{
      clrscr();

      cout<<"What do you want to see?\n"
	  <<"1.READ CLASSES,TESTS AND RESULTS\n"
	  <<"2.UPDATE RESULTS\n"
	  <<"3.UPDATE PERCENTAGE/RANK\n"
	  <<"4.LOG OUT\n"
	  <<"PS: If screen appears empty ,it means admin has not updated yet.\n"
	  <<"\n ENTER CHOICE ";

	  cin>>choice;
		switch(choice)
		 {
		  case 1: cout<<"\n\nWhat do you want to read?\n"
			      <<"1.Classes\n"
			      <<"2.Results/Tests\n"
			      <<"\nENTER CHOICE ";
			  cin>>choice;
			      if(choice==1)
				   {
				      cout<<"\nCONTENT IN FILE\n";
				      ifstream fin1("teacher.txt",ios::in|ios::nocreate);
				      while(!fin1.eof())
					{
					  fin1.getline(schedule,100);
					  puts(schedule);
					}
				      fin1.close();
				   }
			      else if(choice==2)
				   {
				     cout<<"\nCONTENT IN FILE\n";
				     ifstream fin2("student.txt",ios::in|ios::nocreate);
				     while(!fin2.eof())
				       {
					 fin2.getline(schedule,100);
					 puts(schedule);
				       }
				     fin2.close();
				  }
			    break;

		  case 2:   cout<<"\nEnter Results\n";
			    ofstream fout2("student.txt",ios::out|ios::app);
			    gets(schedule);
			    fout2<<" "<<schedule;
			    fout2.close();
			    break;

		  case 3:   cout<<"Would you like to\n"
				<<"1.INSERT RECORD\n"
				<<"2.SEE RECORDS\n";
			   cin>>choice;

					switch(choice)
					{
						 case 1:insert();break;

						 case 2:see(); break;
					}
			    break;

		  case 4:  areyou();
			   break;

		 }
      cout<<"\n\nDo you want to continue?(y/n) ";
      cin>>ch;
       }while(ch=='y');
}

void changestu()
{
  do{
      clrscr();

      cout<<"What do you want to see?\n"
	  <<"1.SEE UPCOMING CLASSES\n"
	  <<"2.SEE RESULTS\n"
	  <<"3.SEE PERCENTAGE/RANK\n"
	  <<"4.LOG OUT\n"
	  <<"PS: If screen appears empty ,it means admin has not updated yet.\n"
	  <<"\n ENTER CHOICE ";

	  cin>>choice;
		switch(choice)
		 {
		   case 1 :     cout<<"\nCONTENT IN FILE\n";
				ifstream fin1("teacher.txt",ios::in|ios::nocreate);
				while(!fin1.eof())
				  {
				    fin1.getline(schedule,100);
				    puts(schedule);
				  }
				fin1.close();
				break;

		   case 2 :     cout<<"\nCONTENT IN FILE\n";
				ifstream fin2("student.txt",ios::in|ios::nocreate);
				while(!fin2.eof())
				  {
				    fin2.getline(schedule,100);
				    puts(schedule);
				  }
				fin2.close();
				break;

		   case 3 :  cout<<"\nCONTENT IN FILE";
			     ifstream fin("rank.txt",ios::in);
				while(1)
				  {
				    fin.read((char*)&t1,sizeof(teacher));
				    if(fin.eof())break;
				    t1.percentage();
				  }
			     fin.close();
			     break;

		   case 4 :     areyou();
				break;

		 }
     cout<<"\n\nDo you want to continue?(y/n) ";
     cin>>ch;
       }while(ch=='y');

}

void changeadm()
 {
   do{
    clrscr();

    cout<<"\nWhat do you want to edit? :\n"
	<<"1.TEACHER'S SECTION\n"//file name-teacher
	<<"2.STUDENTS' SECTION\n"//file name-student
	<<"3.READ CLASSES,TESTS AND RESULTS\n"
	<<"4.LOG OUT\n"
	<<"\n ENTER CHOICE ";
	   cin>>choice;
		switch(choice)
		 {
		   case 1 : cout<<"\n\nEnter classes for teachers\n";
			    ofstream fout1("teacher.txt",ios::out|ios::app);
			    cout<<"Write schedule\n";
			    gets(schedule);
			    fout1<<" "<<schedule;
			    fout1.close();
			    break;

		   case 2 : cout<<"\n\nEnter Results and upcoming tests for students\n";
			    ofstream fout2("student.txt",ios::out|ios::app);
			    gets(schedule);
			    fout2<<" "<<schedule;
			    fout2.close();
			    break;

		   case 3 :
			  cout<<"\n\nWhat do you want to read?\n"
			      <<"1.Classes\n"
			      <<"2.Results/Tests\n"
			      <<"\nENTER CHOICE ";
			  cin>>choice;
			      if(choice==1)
				   {
				      cout<<"\nCONTENT IN FILE\n";
				      ifstream fin1("teacher.txt",ios::in|ios::nocreate);
				      while(!fin1.eof())
					{
					  fin1.getline(schedule,100);
					  puts(schedule);
					}
				      fin1.close();
				   }
			      else if(choice==2)
				   {
				     cout<<"\nCONTENT IN FILE\n";
				     ifstream fin2("student.txt",ios::in|ios::nocreate);
				     while(!fin2.eof())
				       {
					 fin2.getline(schedule,100);
					 puts(schedule);
				       }
				     fin2.close();
				  }
			    break;

		   case 4 : areyou();
			    break;
		 }
   cout<<"\nDo you want to continue?(y/n) ";
   cin>>ch;
     }while(ch=='y');

}

class admin
  {
     char username[90],password[90];

     public:

      void invalid()
      {
	cout<<"\nSorry,invalid.";
	getch();
	welcome();
	enter();
      }

      void check()
	{
		if(choice==1)
			 {
				if(strcmp(username,"admin1")==0)
					{
					 if(strcmp(password,"qwerty1")==0)
						{
							cout<<"   \n **ACCEPTED**  \n";
							getch();
							changeadm();
						}
					 else invalid();
					 }

				else if(strcmp(username,"admin2")==0)
					{
					 if(strcmp(password,"qwerty2")==0)
						{
							cout<<"   \n **ACCEPTED**  \n";
							getch();
							changeadm();
						}
					 else invalid();
					}

				else invalid();

			 }//SECURITTY ADMIN
		else if(choice==2)
			 {
				if(strcmp(username,"teacher1")==0)
					{
					 if(strcmp(password,"qwerty1")==0)
						{
							cout<<"   \n **ACCEPTED**  \n";
							getch();
							changetea();
						}
					 else invalid();
					}

				else if(strcmp(username,"teacher2")==0)
					{
					 if(strcmp(password,"qwerty2")==0)
						{
							cout<<"   \n **ACCEPTED**  \n";
							getch();
							changetea();
						}
					 else invalid();
					}
				else invalid();

			 }//SECURITTY TEACHER

		else if(choice==3)
			 {
				if(strcmp(username,"student1")==0)
					{
					 if(strcmp(password,"qwerty1")==0)
						{
							cout<<"   \n **ACCEPTED**  \n";
							getch();
							changestu();
						}
					 else invalid();
					}

				else if(strcmp(username,"student2")==0)
					{
					 if(strcmp(password,"qwerty2")==0)
						{
							cout<<"   \n **ACCEPTED**  \n";
							getch();
							changestu();
						}
					 else invalid();
					}
				else invalid();
			 }//SECURITTY STUDENT
	}//check


	void enter()
	   {
		clrscr();

		if(choice==1)
			    {
				cout<<"\n    Enter Admin Username ";
				gets(username);
				cout<<"\n    Enter Password ";
				gets(password);

			       check();
			     }

		else if(choice==2)
			    {
			      cout<<"\n    Enter Teacher Username ";
			      gets(username);
			      cout<<"\n    Enter Password ";
			      gets(password);

			     check();
			    }

		else if(choice==3)
			    {
			     cout<<"\n    Enter Student Username ";
			     gets(username);
			     cout<<"\n    Enter Password ";
			     gets(password);

			     check();
			    }

		else if(choice==4)
			    areyou();

	   }

     void admission()
	   {
	     char name[30],course[30],institute[30];
	     cout<<"ENTER NAME : ";
	     gets(name);
	     cout<<"ENTER COURSE : ";
	     gets(course);
	     cout<<"ENTER INSTITUTE : ";
	     gets(institute);
	   }

 ~admin() {}

}a1;

void not()
{
  do{
	 clrscr();

	 cout<<"********************************************************************************\n"
	     <<"                             WELCOME TO EMBRACE\n\n"
	     <<"********************************************************************************\n"
	     <<"Please tell if the user wants to see:\n"
	     <<"1.INSTITUTES NEARBY\n"
	     <<"2.CONTACT INFO\n"
	     <<"3.COURSES OFFERED\n"
	     <<"4.REGISTER\n"
	     <<"5.HOME\n"
	     <<"\n ENTER CHOICE ";

	   cin>>choice;

		   switch(choice)
		      {
			 case 1: cout<<"\n1.Delhi : a)Pitampura\n          b)Punjabhi Bagh\n"
				     <<"2.Maharashtra : a)Napean Road\n                b)Worli\n"
				     <<"3.Rajashthan : a)Jaipur\n               b)Kota\n"
				     <<"4.Uttar Pradesh : a)Noida\n ";
				     break;

			 case 2: cout<<"\nContact no. : 9876543210\n"
				     <<"\nEmail ID : embrace@gmail.com\n";
				     break;

			 case 3: cout<<"\n1.Three-Year Program"
				     <<"\n2.Two-Year Program"
				     <<"\n3.One-Year Program"
				     <<"\n4.One-year Correspondance"
				     <<"\n5.Three-Month Crash Course\n";
				     break;

			 case 4: cout<<"\nWe are glad tat you applied to us!\n"
				     <<"\nPlease fill the following form to apply for admission test\n";

				      ofstream fout("admissionform.txt",ios::app|ios::out);
					   a1.admission();
					   fout.write((char*)&a1,sizeof(admin));
					   fout.close();
				 cout<<"Congrats,your form has been submitted.\n";
				  break;

			 case 5: areyou();
			}

		 cout<<"\nDo you want to continue?(y/n) ";
		 cin>>ch;

	    }while(ch=='y');

}

void openscreen()
{
   int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	 cout<<"\n\n\n\n\n\n\n\n\n\n"
	   <<"                                  WELCOME\n"
	   <<"                                    TO\n"
	   <<"                                  EMBRACE";

	for(i=60;i<130;i++)
	{
		delay(10);
		setcolor(i/10);
		arc(300,250,0,180,i+100);
	}
	 getch();

	 cleardevice();
	 closegraph();
}

void main()
{
   openscreen();

   areyou();
}

void areyou()
{
 clrscr();

  cout<<"\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
      <<"   ARE YOU:\n"
      <<"    1.AN EXISTING ADMIN/TEACHER/STUDENT?\n"
      <<"    2.A PERSON WHO WANTS TO ENQUIRE?\n"
      <<"    3.EXIT \n"
      <<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
      <<"   ENTER OPTION ";

    cin>>choice;
      switch(choice)
	   {
	      case 1:    welcome();
			 a1.enter();
			 break;

	      case 2:    not();
			 break;

	      case 3:    exit(0);
			 break;
	   }

  getch();
}
