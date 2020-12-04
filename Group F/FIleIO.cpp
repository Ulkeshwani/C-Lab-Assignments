#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class  Student{
    int Size=0;
    int RollNo;
    char Name[20];
    char div;
    float Percentage;
    public:
        void Getdata();
        void Putdata();
        void DeleteData(int,Student[]);
};
void Student::Getdata(){
    cout<<"\nEnter The Details Of Students";
        cout<<"\nEnter the Roll No.";
        cin>>RollNo;
        cout<<"\nEnter the Percentage";
        cin>>Percentage;
        cout<<"\nEnter the Division";
        cin>>div;
        cout<<"\nEnter the Name";
        cin>>Name;
        
}
void Student::Putdata(){
    cout << "\nRoll No. :: " << RollNo << endl;
    cout << "\nName :: " << Name<< endl;
    cout << "\nMarks :: " << Percentage << endl;
    cout << "\nDivision  :: " << div << endl;
}
void Student::DeleteData(int index,Student s[10]){
    cout<<"\n Deletion... ";
    fstream file;
    file.open("Database.txt",ios::out);
    file.seekg(0,ios::beg);
    int offset=index*sizeof(s[index]);
    file.seekp(offset);
    strcpy(s[index].Name,"--");
    s[index].RollNo=-1;
    s[index].div='-';
    s[index].Percentage=0.00;
    file.write((char *)&s[index],sizeof(s[index]))<<flush;
    file.seekg(0);
    file.close();
    cout<<"\nRecord Has Been Deleted !!!";
}
int main(){
    fstream file;
    int index=0;
    int n;
    int cases;
    char ch;

    cout<<"\nHow Many Students Are In Your Classroom";
    cin>>n;
    Student s[n];
    do
    {
        cout<<"\n1.Insert\n2.Show\n3.Delete";
        cin>>cases;
        switch(cases){
            case 1: file.open("Database.txt", ios :: out);
                    for(int i=0;i<n;i++){
                        s[i].Getdata();
                        file.write((char *)&s[i], sizeof(s[i]));
                    }
                    file.close();
                    break;

            case 2: file.open("Database.txt", ios :: in); // open file for reading
                    cout << "\nReading Student information to the file :- " << endl;
                    for (int i = 0; i < n; i++){
                    // read an object from a file
                        file.read((char *)&s[i], sizeof(s[i]));
                        s[i].Putdata();
                    }
                    file.close(); // close the file
                    break;
            
            case 3: cout<<"\nDelete Operation ";
                    cout<<"\nEnter The Position Of Data Yo Wants To Delete";
                    cin>>index;
                    if(index>n){
                        cout<<"\nInvalid Position ";
                    }else{
                    s[index].DeleteData(index,s);
                    }
                    file.close();
                    break;
        }
        cout<<"\ncontinue?";
        cin>>ch;
    } while (ch=='y' || ch=='Y');
   return 0;
}