#include<iostream>
using namespace std;
#define size 10
struct Hash{
    string Name;
    long long Mob;
};
class Table{
    Hash DB[size];
    public:
        Table(){
            for(int i=0;i<size;i++){
                DB[i].Name="-1";
                DB[i].Mob=0;
            }
        }
        void insert();
        void show();
        void search();
};
int main(){
    Table t1;
    char ans;
    int choice;
    do{
        cout<<"\n========================TELEPHONE DATABASE=========================";
        cout<<"\n\t1.Insert In Telephone Book\n\t2.Display List\n\t3.Search Person\n\tEnter Your Choice";
        cin>>choice;
        cout<<"\n===================================================================";
            switch(choice){
                case 1: t1.insert();
                    break;
                case 2: t1.show();
                    break;
                case 3 : t1.search();
                    break;
            }
            cout<<"\nDo You Wants To Continue?";
            cin>>ans;
    }while(ans=='y'|| ans=='Y');
    return 0;
}
void Table::insert(){
    long long tmob;
    int sum=0,index=0;
    string tname;
    char ch;
    int j=0;
    int flag;
    do{
        //cout<<"\nEnter the First Name";
        //cin>>tname;
        cout<<"\nEnter the Mobile Number ";
        cin>>tmob;
        for(int i=0;i<3 && tname.length();i++){
            sum=sum+tname.at(i);
        }
        index=sum%10;
        if(DB[index].Name=="-1"){
            DB[index].Name=tname;
            DB[index].Mob=tmob;
        }
        else{
             flag=index;
             do{
                index=(int(index+(j*j))%10);
                    if(DB[index].Name=="-1"){
                        DB[index].Mob=tmob;
                        DB[index].Name=tname;
                        break;
                    }
                    else{
                        if(flag==index){
                            cout<<"\ntable Is full";
                        }
                    }
                    j++;
                }while(flag!=index);
        }
        cout<<"\nDO You want To Store Any Person Name? ";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
}
void Table::show(){
    for(int i=0;i<size;i++){
        cout<<"\n"<<DB[i].Name<<"|"<<DB[i].Mob<<"\n";
    }
}
void Table::search(){
    string tname;
    int flag;
    int j=0;
    int index=0,sum=0;
    cout<<"\nEnter The Person name To Search ";
    cin>>tname;
    for(int i=0;i<3 &&tname.length();i++){
        sum=sum+tname.at(i);
    }
    index=sum%10;
    if(DB[index].Name==tname){
        cout<<"\nPerson Is Present In Your PhoneBook At "<<index;
        cout<<"\n\tPerson Details\n\t"<<DB[index].Name<<"|"<<DB[index].Mob;
    }
    else{
        flag=index;
        do{
            index=(index+(j*j))%10;
            if(DB[index].Name==tname){
                cout<<"\nPerson Is Present In Your PhoneBook At "<<index;
                cout<<"\n\tPerson Details\n\t"<<DB[index].Name<<"|"<<DB[index].Mob;
                break;
            }
            else{
                if(flag==index){
                    cout<<"\nPerson Is Not Found";
                    break;
                }
            }
            j++;
        }while(flag!=index);
    }

}