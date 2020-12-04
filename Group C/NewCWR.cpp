#include<iostream>
using namespace std;
#define SIZE 10
struct Dict{
    string Word;
    string Meaning;
    int chain;
};
class Hash{
    Dict Arry[SIZE];
    public:
        Hash(){
            for(int i=0;i<SIZE;i++){
                Arry[i].Word="-1";
                Arry[i].Meaning="0";
                Arry[i].chain=-1;
            }
        }
        void insert(string,string);
        void find(string);
        void Delete(string);
        void Show();
};
void Hash::insert(string TWord,string TMean){
    int sum=0;
    int flag1=0,Index=0,Temp_Index=0,Temp_Chain=-1,flag=0,tsum=0,Temp_Index1=0;
    string Word,Mean,Temp_str;
        for(int j=0;j<3 && TWord.length();j++){
            sum=sum+TWord.at(j);
        }
        Index=sum%SIZE;
        flag1=Index;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
        if(Arry[Index].Word=="-1"){
            cout<<"\nData is Inserted At "<<Index;
            Arry[Index].Word=TWord;
            Arry[Index].Meaning=TMean;
        }
        else{
            flag=Index;
            do{//for next empty Location
                Index=(Index+1)%SIZE;
                if(Arry[Index].Word=="-1"){
                    Arry[Index].Word=TWord;
                    Arry[Index].Meaning=TMean;
                    Arry[flag1].chain=Index;
                    cout<<"Data Inserted At "<<Index;
                    break;
                }
                else{ //for replacement
                        /*if(Index!=int((Arry[Index].Word.at(0))%10)){
                            Temp_Index=(Index+1)%SIZE;
                            if(flag1!=Temp_Index){
                            Word=Arry[Index].Word;
                            Mean=Arry[Index].Meaning;
                            Temp_Chain=Arry[Index].chain;
                            }   
                        }*/
                    TWord=Arry[flag].Word;
                    for(int i=0;i<3 && i<TWord.length();i++){
                        tsum=tsum+TWord.at(i);
                    }
                    Temp_Index1=tsum%SIZE;
                    if(Temp_Index1!=Temp_Index){
                        Temp_str=Arry[Temp_Index].Word;
                        Arry[Temp_Index].Word=Arry[Temp_Index1].Word;
                        Arry[Temp_Index1].Word=Temp_str;
                    }
                }
            }while(flag!=Index);
        }
}
void Hash::find(string TWord){
    int sum=0,index=0,flag=0,tchain=0;
     for(int j=0;j<3 && TWord.length();j++){
        sum=sum+TWord.at(j);
    }
    index=sum%SIZE;
    if(Arry[index].Word==TWord){
        cout<<"\nFound at "<<index<<"\n";
        cout<<Arry[index].Word<<"|";
        cout<<Arry[index].Meaning;
    }
    else{
        flag=index;
        Arry[flag].chain=tchain;
        do{
            index=(index+1)%SIZE;
            if(Arry[tchain].chain!=-1){
                if(Arry[tchain].Word==TWord){
                    cout<<"\nFound At"<<tchain;
                    cout<<"\n"<<Arry[index].Word<<"|";
                    cout<<Arry[index].Meaning;
                    break;
                }
            }
        }while(flag!=index);
        cout<<"\nWord is Not Found";
    }
}
void Hash::Delete(string TWord){
    int sum,index,flag,tchain;
     for(int j=0;j<3 && TWord.length();j++){
        sum=sum+TWord.at(j);
    }
    index=sum%SIZE;
    if(Arry[index].Word==TWord){
        cout<<"\nData Deleted Form "<<index;
        Arry[index].Word="-1";
        Arry[index].Meaning="0";
        Arry[index].chain=-1;
    }
    else{
        flag=index;
        do{
            Arry[index].chain=tchain;
            index=(index+1)%SIZE;
            if(Arry[index].chain!=-1){
                if(Arry[index].Word==TWord){
                    cout<<"\nData Deleted From "<<tchain;
                    Arry[tchain].Word="-1";
                    Arry[tchain].Meaning="0";
                    Arry[tchain].chain=-1;
                    break;
                }
            }
        }while(flag!=index);
         cout<<"\nData Not Found";
    }
}
void Hash::Show()
{
    for(int i=0;i<SIZE;i++){
        cout<<"\n\t"<<Arry[i].Word<<"|"<<Arry[i].Meaning<<"|"<<Arry[i].chain;
    }
}
int main(){
    Hash t1;
    char ans;
    int choice;
    string tword,tmeaning;
    do{
        cout<<"\n========================Dictnory DATABASE=========================";
        cout<<"\n\t1.Insert In Dictnory\n\t2.Display List\n\t3.Search Person\n\t4.Delete A Record\n\tEnter Your Choice";
        cin>>choice;
        cout<<"\n===================================================================";
            switch(choice){
                case 1: cout<<"\nEnter The Word";
                        cin>>tword;
                        cout<<"\nEnter The Meaning Of That Word";
                        cin>>tmeaning;
                        t1.insert(tword,tmeaning);
                        break;
                case 2: t1.Show();
                        break;

                case 3 :cout<<"\nEnter The Word";
                        cin>>tword; 
                        t1.find(tword);
                        break;
                case 4:
                        cout<<"\nEnter the Word";
                        cin>>tword;
                        t1.Delete(tword);

                default:return 0;
            }
            cout<<"\nDo You Wants To Continue?";
            cin>>ans;
    }while(ans=='y'|| ans=='Y');
    return 0;
}