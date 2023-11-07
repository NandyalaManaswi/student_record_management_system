
#include <iostream>
using namespace std;
class node{
    public:
    string name;
    int roll;
    int marks;
    string course;
    node *next;
}*head;


void Insert(string name,int roll,int marks,string course)
{
  node *t;
  t=new node();
  t->name=name;
  t->roll=roll;
  t->marks=marks;
  t->course=course;
  t->next=NULL;
  if(head==NULL)
  {
    cout<<"linked list is empty";
    head=t;
  }
  else if (head->roll>t->roll)
  {
    t->next=head;
    head=t;
  }
  else
  {
    node *p=head;
    while(p->next!=NULL)
    {
      if(p->roll==roll)
      {
        cout<<"nothing is inserted or found roll";
      }
      else if (p->next->roll>t->roll)
      {
        t->next=p->next;
        p->next=t;
      }
      else 
      {
        p=p->next;
      }
    }
    p->next=t;
    t->next=NULL;
  }
}


void display(){
  node *p=head;
  
  while(p)
  {
    cout<<"\nstring: "<<p->name<<"\nroll: "<<p->roll<<"\nmarks: "<<p->marks<<"\ncourse: "<<p->course;
    cout<<"\n---------------------------------------------------\n";
    p=p->next;
  }
  
}
void search(node *p,int roll)
{
  while(p)
  {
    if(p->roll==roll)
    {
        cout<<"name: "<<p->name<<"\n";
        cout<<"we have found the key with roll: "<<p->roll<<"\n";
        cout<<"marks: "<<p->marks<<"\n";
        cout<<"course: "<<p->course<<"\n";
    }
    p=p->next;
  }
  if(p==NULL) cout<<"nothing is found\n";
}

void Delete(node *p, int roll)
{
  node *q=NULL;
  // deletion of head node;
  if(head->roll==roll)
  {
    p=head;
    head=head->next;
    delete p;
  }
  while(p)
  {
    if(p->roll!=roll)
    {
      q=p;
      p=p->next;
    }
    else if(p->roll==roll)
    {
      q->next=p->next;
      delete p;
      break;
    }
  }
  cout<<"no roll number is found";
}




int main() 
{
  node student;
  string name;
  int roll;
  int marks;
  string branch;
  string course;
  while(1)
  {
      int n;
      cout<<"enter number\n";
      cin>>n;
      if(n==1)
      {
          cout<<"enter student name: ";
          cin>>name;
          cout<<"enter student roll: ";
          cin>>roll;
          cout<<"enter student marks: ";
          cin>>marks;
          cout<<"enter student branch: ";
          cin>>course;
          Insert(name,roll,marks,course);
      }
      if(n==2) display();
      if(n==3)
      {
           cout<<"enter student roll: ";
           cin>>roll;
           search(head,roll);
           
      }
      if(n==4)
      {
           cout<<"enter student roll: ";
           cin>>roll;
           Delete(head,roll);
      }
      int stop;
      cout<<"\nEnter 0 to exit & 1 to continue: ";
      cin>>stop;
      if(stop==0) break;
  }
  
  return 0;
  
}