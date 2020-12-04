#include<iostream>
#include<stdlib.h>
using namespace std;
#define SIZE 3
struct GraphNode
{
    int Vertex;
    GraphNode *next; 
};
class Graph
{
    int n=SIZE;
    public: 
        GraphNode *Head[SIZE]={NULL};
        int Arry[SIZE][SIZE];
        void Create();
        void Listindegree(int);
        void ListOutdegree(int);
        void List_in(int);
        void MatrixInsert();
        void MatrixIndegree(int);
        void MatrixOutdegree(int);
        void Show();
        void MatrixShow();
};
void Graph::List_in(int vertex)
{
    int i=0;
    int deg=0;
    GraphNode *temp;
    temp=Head[vertex];
    for(i=0;i<SIZE;i++){
        while (temp->next!=NULL){
            ++deg;
            temp=temp->next;
        }
    }
    cout<<deg;
}
void Graph::MatrixInsert()
{
    int n=0;
    cout<<"\nHow many Vertices";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<"\nEnter The Value For "<<i<<" "<<j;
            cin>>Arry[i][j];
        }
    }
}
void Graph::MatrixIndegree(int vertex)
{
    int Count_indegree=0;
    for(int i=0;i<SIZE;i++){
        if(Arry[i][vertex]==1){
            Count_indegree+=1;
        }
    }
    cout<<"\n"<<Count_indegree;
}
void Graph::MatrixOutdegree(int vertex)
{
    int Count_outdegree=0;
    for(int i=0;i<SIZE;i++){
        if(vertex==Arry[vertex][i]){
            Count_outdegree+=1;
        }
    }
    cout<<"\n"<<Count_outdegree;

}
void Graph::ListOutdegree(int Vertex)
{ 
    GraphNode *temp;
    int Count_of_out=0;
    temp=Head[Vertex];
    do{
        temp=temp->next;
        Count_of_out++;
    }while(temp->next!=NULL);
    cout<<"\n"<<Count_of_out;
}
void Graph::Show()
{
    int i=1;
   GraphNode *temp;
   temp=Head[i];
   for(i=1;i<=SIZE;i++){
       cout<<Head[i]->Vertex<<"->";
       temp=Head[i]->next;
       do{
           if(temp==NULL){
               cout<<"NULL";
           }
           else{
               cout<<""<<temp->Vertex<<"->";
               temp=temp->next;
           }
       }while(temp);
       cout<<"\n";
   }
}
void Graph::Create()
{
    int i=1;
    int Data;
    char choice;
    GraphNode *temp,*p;
    cout<<"\nHow Many Nodes";
    cin>>n;
    while (n){
        Head[i]=new GraphNode;
        cout<<"\nEnter the Vertex name";
        cin>>Head[i]->Vertex;
        Head[i]->next=NULL;
        temp=Head[i];
        do{
            cout<<"\nEnter the Vertex Data";
            cin>>Data;
            if(Data==-1){
                break;
            }
            else{
                p = new GraphNode;
                p->Vertex=Data;
                p->next=NULL;
                temp->next=p;
                temp=p;
            }
            cout<<"\nIs There Any Adj.Vertex to "<<Head[i]->Vertex<<" (y/n)";
            cin>>choice;
        }while((choice=='y') || (choice=='Y'));
        n--;
        i++;
    }
    
}
void Graph::MatrixShow()
{
    for(int i=1;i<=SIZE;i++){
        cout<<"\n"<<i<<"|";
        for(int j=1;j<=SIZE;j++){
            cout<<"\t"<<Arry[i][j];
        }
    }
}
int main()
{
    Graph Graph_obj;
    int choice;
    int Vertex_Data;
    do{
        cout<<"\n\t1.Create Graph\n\t2.Find Indegre\n\t3.Find Outdegree\n\t4.Show\n\t5.Matrix Creation\n\t6.Matrix SHow\n\t7.Matrix Indegree\n\t8.Maxtrix outDegree";
        cin>>choice;
        switch(choice)
        {
            case 1: Graph_obj.Create();
                    break;
        
            case 2: cout<<"\nEnter the Vertex Name";
                    cin>>Vertex_Data;
                    Graph_obj.List_in(Vertex_Data);
                    break;
        
            case 3: cout<<"\nEnter the Vertex Name";
                    cin>>Vertex_Data;
                    Graph_obj.ListOutdegree(Vertex_Data);
                    break;
        
            case 4: Graph_obj.Show();
                    break;

            case 5: Graph_obj.MatrixInsert();
                    break;
            
            case 6: Graph_obj.MatrixShow();
                    break;

            case 7: cin>>Vertex_Data;
                    Graph_obj.MatrixIndegree(Vertex_Data);
                    break;

            case 8: cin>>Vertex_Data;
                    Graph_obj.MatrixOutdegree(Vertex_Data);
                    break;
        }
    }while(choice<=8);
    return 0;
}