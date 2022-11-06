#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
// #include <conio.
#include <stdlib.h>
#include <cstdlib>
using namespace std;
string name;
class student {

private:
string name , roll_no , class_ , contact , add;
int total = 0;
public:

void menu();
void insert();
void display();
void modify();
void search();
void delete_();

};

void student :: menu (){
  menustart:
  int choose;
  char x;
 
  system("clear");


  cout<<"\t\t\t-----------------------------------------------------------------------------"<<endl;
  cout<<"\t\t\t--------------------|| STUDENT MANAGEMENT SYSTEM ||--------------------------"<<endl;
  cout<<"\t\t\t-----------------------------------------------------------------------------"<<endl;
  cout<<endl;
  cout<<endl;

  cout<<"\t\t\t\tEnter 1 for adding "<<endl;
  cout<<"\t\t\t\tEnter 2 for modifying "<<endl;
  cout<<"\t\t\t\tEnter 3 for display "<<endl;
  cout<<"\t\t\t\tEnter 4 for search "<<endl;
  cout<<"\t\t\t\tEnter 5 for deleting "<<endl;
  cout<<"\t\t\t\tEnter 6 for exit "<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"\t\t\t--------------------------------------------------------"<<endl;
  cout<<"\t\t\t-------||CHOOSE AND PRESS OPTION [1/2/3/4/5/6]||--------"<<endl;
  cout<<"\t\t\t--------------------------------------------------------"<<endl;
  cout<<"Enter the choose :- ";
  cin>>choose;

  switch (choose){

    case 1 :
    do{
      insert();
      cout<<"\n\t\t\t  DO YOU WANT TO ADD ANOTHER STUDENT (Y/N) "<<endl;
      cin>>x;
    }while(x=='y' || x=='Y');
    break;

    case 2 :
    modify();
    break;

    case 3 :
    display();
    break;

    case 4 :
    search();
    break;

    case 5 :
    delete_();
    break;

    case 6 :
    exit(0);

    default :
    cout<<"Invalid choose please try again .....";
  }
  // getch();
  goto menustart;
  

}

void student :: insert (){
  system("clear");
  fstream file;
  cout<<"\t\t\t|------------------------------------------------------|"<<endl;
  cout<<"\t\t\t|---------------|| ADD STUDENT DETAIL||----------------|"<<endl;
  cout<<"\t\t\t|------------------------------------------------------|"<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"Enter the name of the student:- ";
  cin>>name;
  cout<<"Enter the ROLL number of the student:- ";
  cin>>roll_no;
  cout<<"Enter the class of the student:- ";
  cin>>class_;
  cout<<"Enter the contact number of student:- ";
  cin>>contact;
  cout<<"Enter the ADDRESS of student :-";
  cin>>add;
  file.open("studentrecord.txt" , ios::app | ios::out);
  file<<" "<<name<<" "<<roll_no<<" "<<class_<<" "<<contact<<" "<<add<<"\n";
  file.close();
  
}

void student :: display (){

  system("clear");
  fstream file;
  cout<<"\t\t\t|------------------------------------------------------|"<<endl;
  cout<<"\t\t\t|-------------||SHOWING STUDENT DETAIL||---------------|"<<endl;
  cout<<"\t\t\t|------------------------------------------------------|"<<endl;
  cout<<endl;
  cout<<endl;

  file.open("studentrecord.txt", ios::in);

  if(!file){
    cout<<"\n\t\t\t NO DATA IS PRESENT .......";
    file.close();
  }

  else{
   file >> name >> roll_no >> class_ >> contact >> add;
    while(!file.eof()){

      cout<<"\t\t********************************************"<<endl;
      cout<<"\t\t\tstudent No :- "<<total++<<endl;
      cout<<"\t\t\tstudent name :- "<<name<<endl;
      cout<<"\t\t\tstudent roll no :- "<<roll_no<<endl;
      cout<<"\t\t\tstudent class :- "<<class_<<endl;
      cout<<"\t\t\tstudent contact :- "<<contact<<endl;
      cout<<"\t\t\tstudent address :- "<<add<<endl;
      cout<<"\t\t********************************************"<<endl;
      cout<<endl;
      cout<<endl;
     file >> name >> roll_no >> class_ >> contact >> add;

    }

    if(total == 0){
      cout<<"\n\t\t\t NO DATA IS PRESENT .......";
    }
  }
  file.close();

  int a;
  cout<<"Enter 0 for menu page "<<endl;
  cin>>a;
  if(a==0){
     menu();
  }
}

void student :: modify (){
  system("clear");
  fstream file , file1;
  string rollon;
  int found =0;
  cout<<"\t\t\t|------------------------------------------------------|"<<endl;
  cout<<"\t\t\t|-------------||MODIFYING STUDENT DETAIL||-------------|"<<endl;
  cout<<"\t\t\t|------------------------------------------------------|"<<endl;
  file.open("studentrecord.txt" , ios::in);

  if(!file){
    cout<<"\t\t\t DATA IS NOT PRESENT .......";
    file.close();
  }

  else{
    cout<<"\n Enter the roll no of student of which student to modify \n";
    cin>>rollon;
    file1.open("record.txt" , ios::app | ios::out);
    file >> name >> roll_no >> class_ >> contact >> add;

    while(!file.eof()){

      if(rollon!=roll_no){
      file1<<" "<<name<<" "<<roll_no<<" "<<class_<<" "<<contact<<" "<<add<<"\n";
      }

      else{

        cout<<"Enter the name of the student:- ";
        cin>>name;
        cout<<"Enter the ROLL number of the student:- ";
        cin>>roll_no;
        cout<<"Enter the class of the student:- ";
        cin>>class_;
        cout<<"Enter the contact number of student:- ";
        cin>>contact;
        cout<<"Enter the ADDRESS of student :-";
        cin>>add;
        file1<<" "<<name<<" "<<roll_no<<" "<<class_<<" "<<contact<<" "<<add<<"\n";
        found++;
      }

      file >> name >> roll_no >> class_ >> contact >> add;
      if(found == 0){

        cout<<"\t\t\t STUDENT ROLL NO NOT FOUND .....";
      }

    }
    file1.close();
    file.close();
    remove("studentrecord.txt");
    total =0;
    rename("record.txt" , "studentrecord.txt");
  }

}

void student :: search(){
  system("clear");
  fstream file;
  cout<<"\t\t\t|------------------------------------------------------|"<<endl;
  cout<<"\t\t\t|-------------||SHOWING STUDENT DETAIL||---------------|"<<endl;
  cout<<"\t\t\t|------------------------------------------------------|"<<endl;

  file.open("studentrecord.txt", ios::in);
  int found =0;

  if(!file){
    cout<<"\n\t\t\t NO DATA IS PRESENT .......";
    file.close();
  }

  else{
     
    string rollno;
    cout<<"Enter the roll no of student to serch ";
    cin>>rollno;
    file >> name >> roll_no >> class_ >> contact >> add;

    while(!file.eof()){

      if(rollno ==roll_no){
      cout<<"\t\t\tstudent No :- "<<total++<<endl;
      cout<<"\t\t\tstudent name :- "<<name<<endl;
      cout<<"\t\t\tstudent roll no :- "<<roll_no<<endl;
      cout<<"\t\t\tstudent class :- "<<class_<<endl;
      cout<<"\t\t\tstudent contact :- "<<contact<<endl;
      cout<<"\t\t\tstudent address :- "<<add<<endl;
      found++;
      }
     file >> name >> roll_no >> class_ >> contact >> add;
    }

    if(found == 0){
      cout<<"\n\t\t\tstudent roll no not found ";
    }

    file.close();

  }

}

void student :: delete_(){

  system("clear");
  fstream file , file1;
  string rollno;
  int found =0;
  cout<<"\t\t\t|------------------------------------------------------|"<<endl;
  cout<<"\t\t\t|-------------||DELETE STUDENT DETAIL||----------------|"<<endl;
  cout<<"\t\t\t|------------------------------------------------------|"<<endl;
  cout<<endl;
  cout<<endl;

  file.open("studentrecord.txt", ios::in);

  if(!file){
    cout<<"\n\t\t\t NO DATA IS PRESENT .......";
    file.close();
  }


  else{
    cout<<"Enter the roll no student which you want to delete "<<endl;
    cin>>rollno;
    file1.open("record.txt" , ios::app | ios::out);
    file >> name >> roll_no >> class_ >> contact >> add;
    while(!file.eof()){

      if(rollno != roll_no){
        file1<<" "<<name<<" "<<roll_no<<" "<<class_<<" "<<contact<<" "<<add<<"\n";
      }
      else
      {
        found++;
      }
     file >> name >> roll_no >> class_ >> contact >> add;

    }

    if(found ==0){
      cout<<"ROLL NO  IS NOT PRESENT "<<endl;
    }

    file1.close();
    file.close();
    remove("studentrecord.txt");
    total =0;
    rename("record.txt" , "studentrecord.txt");
  }

}

int main (){

  student s;
  s.menu();
  
}