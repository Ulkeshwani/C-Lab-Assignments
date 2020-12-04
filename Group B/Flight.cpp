#include<iostream>
using namespace std;
struct enode{
    string dest;
    int time;
    enode *link;
};
struct hnode{
    string city;
    hnode *down;
    enode *next;
};
class Flight{
  int n;
  hnode *start;
  public:   
        Flight(){
            start=NULL;
            n=0;
        }
        void create();
        void show();
};
void Flight::show(){
    hnode *temp;
    enode *tp;
    temp=start;
        while(temp!=NULL){
            cout<<temp->city;
            tp=temp->next;
            while(tp!=NULL){
                cout<<"->"<<tp->dest<<"|"<<tp->time<<"|";
                tp=tp->link;
            }
            cout<<"\n";
            temp=temp->down;
        }

}
void Flight::create(){
    enode *temp2;
    int i;
    hnode *h1,*temp1;
    enode *s;
    char ch;
    string data;
    cout<<"\nHow many Cities?";
    cin>>n;
    while(n){
        h1=new hnode;
        cout<<"\nEnter The City Name";
        cin>>h1->city;
        h1->next=NULL;
        if(start==NULL){
            start=h1;
            temp1=h1;
        }
        else{
            temp1->down=h1;
            temp1=h1;
        }
        do{
            cout<<"\nEnter The Destination";
            cin>>data;
            if(data=="no"){
                break;
            }
            else{
                s= new enode;
                cout<<"\nEnter The time for go to"<<data;
                cin>>s->time;
                s->dest=data;
                s->link=NULL;
                if(temp1->next==NULL){
                    temp1->next=s;
                    temp2=s;
                }
                else{
                    temp2->link=s;
                    temp2=s;
                }
            }
            cout<<"\nIs There Any Another Destination";
            cin>>ch;
        }while(ch=='y' || ch=='Y');
        n--;
    }

}
int main(){
    Flight f;
    string sc,des;
    char ans;
    int ch,in;
    do{
        cout<<"\n\t1.Create\n\t2.Display\n";
        cin>>ch;
        switch (ch)
        {
        case 1: f.create();
                break;

        case 2: f.show();
                break;
        default:
                break;
        }
        cout<<"\nDo You want TO continue?";
        cin>>ans;
    }while(ans=='y' ||ans=='Y');
    return 0;
}