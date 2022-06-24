#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
int temp_c=1;
void newContact();
void deleteContact();
void viewAll();
void exportAsFile();
void viewForDel();
struct node{
    char name[50];
    char number[15];
    char email[130];
    struct node *next;
}*head=NULL,*newnode,*temp,*p,*d,*d2;
void newContact(){
    newnode=(struct node*)malloc(sizeof(struct node));
    cout<<"Name : ";
    cin>>newnode->name;
    cout<<"Number : ";
    cin>>newnode->number;
    cout<<"E-Mail Address : ";
    cin>>newnode->email;
    newnode->next=NULL;

    if(head==NULL){
        temp=newnode;
        head=temp;
    }else{
        temp->next=newnode;
        temp=newnode;
    }
    cout<<"New Contact Created!"<<endl<<"Press any key to continue!";
    getch();
}

void viewAll(){
    p=head;
    temp_c=1;
    cout<<"================================================"<<endl;
    cout<<"Name\t\tPhone Number\tE-Mail Address"<<endl;
    cout<<"================================================"<<endl;
    if(head==NULL){
        cout<<"No Contacts Found!"<<endl;
    }else{
        while(p!=NULL){
            cout<<p->name<<"\t\t"<<p->number<<"\t"<<p->email<<endl;
            temp_c++;
            p=p->next;
        }
    }
    cout<<"================================================"<<endl;
    cout<<endl<<"Press any key to continue!";
    getch();
}

void viewForDel(){
    d=head;
    temp_c=1;
    while(d!=NULL){
        if((temp_c%5)!=0){
            cout<<"("<<temp_c<<") "<<d->name<<"\t";
        }else{
            cout<<"("<<temp_c<<") "<<d->name<<endl;
        }
        temp_c++;
        d=d->next;
    }
    int pos;
    cout<<endl<<"Select a Contact to delete : ";
    cin>>pos;

    d=head;
    if(pos==1){
        // delete from beginning
        d=head;
        head=d->next;
        free(d);
    }else{
        // delete from a given position
        for(int i=1;i<pos-1;i++){
            d=d->next;
        }
        d2=d->next;
        d->next=d2->next;
        free(d2);
    }

    cout<<endl<<"Contact Deleted!"<<endl<<"Press any key to continue!";
    getch();
}

void deleteContact(){
    if(head==NULL){
        cout<<endl<<"No Contacts found!"<<endl<<"Press any key to continue...";
        getch();
    }else{
        viewForDel();
    }
}

void exportAsFile(){
    ofstream out;
    out.open("contacts.csv");
    out<<"Name"<<","<<"Phone Number"<<","<<"E-Mail Address"<<endl;
    temp=head;
    while(temp!=NULL){
        out<<temp->name<<","<<temp->number<<","<<temp->email<<endl;
        temp_c++;
        temp=temp->next;
    }
    out.close();

    cout<<endl<<"Export Successful!"<<endl<<"Press any key to continue!";
    getch();
}

int main(){
    int n=0;
    do{
        system("cls");
        cout<<"========================================="<<endl;
        cout<<"             PHONEBOOK                   "<<endl;
        cout<<"========================================="<<endl;
        cout<<"(1) Create New Contact"<<endl<<"(2) View all Contacts"<<endl<<"(3) Delete a Contact"<<endl<<"(4) Export as CSV"<<endl<<"(5) Close"<<endl;
        cout<<"\nEnter your Choice (1/2/3/4/5): ";
        cin>>n;
        switch(n){
            case 1:
                // create an contact
                newContact();
                break;
            case 2:
                // display all contacts
                viewAll();
                //viewForDel();
                break;
            case 3:
                // delete a contact
                deleteContact();
                break;
            case 4:
                // export into file
                exportAsFile();
                break;
            case 5:
                // exit
                return 0;
            default:
                cout<<"\nInvalid Input! Try Again\n";
                getch();
        }
    }while(n!=5);
}

