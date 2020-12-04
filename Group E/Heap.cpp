#include<iostream>
#define SIZE 10
using namespace std;
class Heap{
    int n;
    int Arry[SIZE];
    public:
        Heap(){
        for(int i=0;i<SIZE;i++){
            Arry[i]=0;
            }
            n=0;
        }
        void insert(int);
        void MakeHeap();
        void HeapSort();
        void Display();
};
void Heap::insert(int Key){
    if(n<SIZE){
        Arry[n]=Key;
        n++;
        cout<<"\nInserted data is "<<Key<<" At "<<n<<" th Position\n";
    }
    else{
        cout<<"\n-------------------Array Is Full---------------------";
    }
}
void Heap::Display(){
    cout<<"\tINDEX\t||\tKey\n";
    for(int i=0;i<SIZE;i++){
        cout<<"\t"<<i<<"\t||"<<"\t"<<Arry[i]<<"\n";
    }
}
void Heap::HeapSort(){
    for(int i=n-1;i>0;i--){
        int temp=Arry[i];
        Arry[i]=Arry[0];
        int k=0,j=0;
        if(i==1){
            j=-1;
        }
        else{
            j=1;
        }
        if(i>2 && Arry[2]>Arry[j]){
            j=2;
        }
        while(j>=0 && temp<Arry[j]){
            Arry[k]=Arry[j];
            k=j;
            j=2*k+1;
            if(j+1<=i-1 && Arry[j]<Arry[j+1]){
                j++;
            }
            if(j>i-1){
                j=-1;
            }
            Arry[k]=temp;
        }
    }
}
void Heap::MakeHeap(){
    for(int i=1;i<n;i++){
        int val=Arry[i];
        int j=i;
        int p=(j-1)/2;
        while(j>0 && Arry[p]<val){
            Arry[j]=Arry[p];
            j=p;
            p=(j-1)/2;
        }
        Arry[j]=val;
    }
}
int main(){
    Heap H1;
    int key,choice=0;
    char ans;
    do{
        cout<<"\nMenu\n\t1.Insert\n\t2.MakeHeap\n\t3.Perform Heapsort\n\t4.Display";
        cin>>choice;
        switch(choice){
            case 1: cout<<"\nEnter the data";
                    cin>>key;
                    H1.insert(key);
                    break;
            case 2: cout<<"\n----------------------------------------------";
                    H1.MakeHeap();
                    break;
            case 3: cout<<"\n----------------------------------------------";
                    H1.HeapSort();
                    break;
            
            case 4:
                    H1.Display();


            default:
                    return 0;
        }
        cout<<"Do You Wants To continue?";
        cin>>ans;
    }while (ans=='y' || ans=='Y');
    {
        /* code */
    }
    
}