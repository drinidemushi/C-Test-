#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std ;

enum takeT{            
test,
score,
exitt
};
//here i have used an enum  for the choices of                the user 

struct Id{
  string firstname="";
  string lastname;
  string username;
  int age ;
  string password;
  int score;
};
// here i have created a sturcture that contains info about the user .
 
struct q{
  string question ;
  string alternatives ;
  string correct;
};
//  here i have created a structure about the questioins.
struct Ad{
  string username;
  string pasword;
};
// here i have created a structure for admins .


int fill_arrayadmin(Ad B[]){
   int i;
   ifstream readd;
  readd.open("adminn.txt");
  while(!readd.eof()){
  readd>>B[i].username
  >>B[i].pasword;

}
readd.close();
return i;
} 

void save_admins(Ad B[], int size){
ofstream savee;
savee.open("adminn.txt");
for(int i=0;i<size;i++){
  savee<<B[i].username<<" "
  <<B[i].pasword<<endl;
}
savee.close();
}
// here a have created 2 functions to fill the array with info about admins and to save it in a file . I use the array related with the structure of admin .
Ad get_admin(){
  Ad admin;
  cout<<"Enter your username :";
  cin>>admin.username;
  cout<<"Enter your pasword : " ;
  cin>>admin.pasword;
  return admin;
}
// here we get the info from the user. 
int fill_array(Id A[]){
int i=0;
ifstream read;
read.open("file.txt");
while(!read.eof()){
  read>>A[i].firstname
  >>A[i].lastname
  >>A[i].username
  >>A[i].age
  >>A[i].password
  >>A[i].score;
  i++;
}
read.close();
return i;
}

void save_users(Id A[],int size){
  ofstream save;
  save.open("file.txt");
  for(int i=0;i<size;i++){
    save<<A[i].firstname<<" "
    <<A[i].lastname<<" "
    <<A[i].username<<" "
    <<A[i].age<<" "
    <<A[i].password<<" "
    <<A[i].score<<endl;
}
}
// the same thing as admins but here we use array realted with the structure of user .

Id get_user(){
   Id user;
   cout<<"Enter first name: ";
   cin>>user.firstname;
   cout<<"Enter last name: ";
   cin>>user.lastname;
   cout<<"Enter username: ";
   cin>>user.username;
   cout<<"Enter age : ";
   cin>>user.age;
   cout<<"Enter password: ";
   cin>>user.password;
   return user;
   }
   // get info from the user .

int taketest(){
  q std ;
string answer;
int score=0,questions=0;
ifstream myfile("questions.txt");
while(!myfile.eof()){
questions++;
getline(myfile,std.question);
cout<<std.question<<endl;
getline(myfile,std.alternatives);
cout<<std.alternatives<<endl;
getline(myfile,std.correct);
cin>>answer;
if(answer==std.correct){
  score++;
}
}
myfile.close();
cout<<"You have done "<<score<<" right out of "<<questions<<endl;
return score;
}
// here i have created a function for the teset . firstly i created a file with questions then i read it by using file properties  and show them to the user then if the answer is correct the score will be incremented by on . 
void choose(Id* myuser){
  int option;
  cout<<"Enter your choise: \n.1Take a test , \n.2 See your score \n.3 Exit    ";
  cin>>option;
  takeT choice1=takeT(option-1);
switch(choice1){
  case test: 
    myuser->score=taketest();
  break;
  case score:
   cout<<"This user has a score of "<<myuser->score<<" points!";
  break;
  case exitt:
    exit(0);
  break;
  

}
}
// Here we take adress of a structure and pass it as a parameter . Then this user can take a test or view his score , we manipulate the values using pointers.

bool compareName(Id a,Id b){
  return a.firstname<b.firstname;
}

bool compareAge(Id a,Id b){
  return a.age<b.age;
}

bool compareScore(Id a,Id b){
  return a.score>b.score;
}
// here we compare  user to sort them .
void show_all(Id A[],int size,int i=0){
  if (i==size){
    return;
  }
    cout<<A[i].firstname<<" "<<A[i].lastname<<" "<<A[i].username<<" "<<A[i].age<<" "<<A[i].password<<""<<A[i].score<<endl;
    return show_all(A,size,i+1);
}
// here i have used recursion to show user info.

void show_age_to_score(Id A[],int size){
  int M[size][2];
  for(int i=0;i<size;i++){
    M[i][0]=A[i].age;
    M[i][1]=A[i].score;
  }
  cout<<"Age  Score\n";
  for(int i=0;i<size;i++){
    cout<<M[i][0]<<" "<<M[i][1]<<endl;
  }
  return;
}
//here i have used matrices to show age and score of user .

void admin_choose(Id A[],int size){
  cout<<"Welcome admin!\n";
  cout<<"Do you want to sort your users based on:\n1.Name\n2.Age\n3.Score\n4.Print age to score of every user";
  int option;
  cin>>option;
  switch(option){
    case 1:
    sort(A,A+size,compareName);
    break;
    case 2:
    sort(A,A+size,compareAge);
    break;
    case 3:
    sort(A,A+size,compareScore);
    break;
    case 4:
    show_age_to_score(A,size);
  }
  show_all(A,size);
}
//here i have used a switch function to sort use by the case .
void check(Id A[], int size ){
int i;
Id newuser;
cout<<"Enter your username :";
cin>>newuser.username;
cout<<"Enter your password :";
cin>>newuser.password;
for( i=0;i<=size ;i++){
if(A[i].username==newuser.username&&A[i].password==newuser.password){
cout<<"You are registered ";
choose(&A[i]);
return;
}
}
cout<<"Sorry you need to be registered";
}
// here i check if a user have been registered before or not .

void check(Ad A[],Id B[] , int size,int sizee ){
int i;
Id newuser;
cout<<"Enter your username :";
cin>>newuser.username;
cout<<"Enter your password :";
cin>>newuser.password;
for( i=0;i<=size ;i++){
if(A[i].username==newuser.username&&A[i].pasword==newuser.password){
cout<<"You are registered ";
admin_choose(B,sizee);
return;
}
}
cout<<"Sorry you need to be registered";
}

int main() {
Id A[50];// using an array from structure of id 
Ad B[50];// using an array fom structure of admin .
int size=fill_array(A);
int sizee=fill_arrayadmin(B);
int option;
cout<<"Welcome! Do you want to: \n1.Login as admin \n2.Login as user\n3.Register\4.Exit\n";
cin>>option;
switch(option){
  case 1:
  check(B,A,sizee,size);
  break;
  case 2:
  check(A,size);
  break;
  case 3:
  cout<<"Do you want to register as an admin(1) or an user(2)\n";
  cin>>option;
  if(option==1){
    B[size++-1]=get_admin();
  }
  else if(option==2){
    A[size++-1]=get_user();
  }
  else{
    cout<<"Invalid option please try again.";
    exit(0);
  }
}

save_users(A,size-1);
save_admins(B, sizee-1);
  return 0;
}