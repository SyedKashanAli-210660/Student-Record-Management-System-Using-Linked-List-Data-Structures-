#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
 

class Node {
public:
    int roll, Marks;
    string Name, Dept, Subject;

    
	
    Node* next;
};
 
Node* head = new Node();
 

bool check(int x)
{
    
    if (head == NULL)
        return false;
 
    Node* t = new Node;
    t = head;
 

    while (t != NULL) {
        if (t->roll == x)
            return true;
        t = t->next;
    }
 
    return false;
}


void Insert_Record(int roll, string Name, string Dept, string Subject, int Marks)
{
    
    if (check(roll)) {
        cout << "Student with this record Already Exists\n";
        return;
    }
 
    
    Node* t = new Node();
    t->roll = roll;
    t->Name = Name;
    t->Dept = Dept;
    t->Subject = Subject;
    t->Marks = Marks;
    
    t->next = NULL;
 
    // Insert at Begin
    if (head == NULL || (head-> Marks < t->Marks)) {
        t->next = head;
        head = t;
    }
 
    // Insert at middle or End
    else {
        Node* c = head;
        while (c->next != NULL && c->next->Marks <= t->Marks) {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }
 
    cout << "Record Inserted Successfully\n";
}
 

void Search_Record(int roll)
{
    
    if (head == NULL) {
        cout << "No such Record Available\n";
        return;
    }
 
    // Otherwise
    else {
        Node* p = head;
        while (p) {
            if (p->roll == roll) {
                cout << "Roll Number\t"
                     << p->roll << endl;
                     
                cout << "Name\t\t"
                     << p->Name << endl;
                     
                cout << "Department\t"
                     << p->Dept << endl;
                
				
					      
                cout << "Subject\t\t"
                     << p->Subject << endl;
                     
                cout << "Marks\t\t"
                     << p->Marks << endl;
                     
                return;
            }
            p = p->next;
        }
 
        if (p == NULL)
            cout << "No such Record Available\n";
    }
}
 

int Delete_Record(int roll)
{
    Node* t = head;
    Node* p = NULL;
 
    
    if (t != NULL && t->roll == roll) {
    	
        head = t->next;
        delete t;
 
        cout << "Record Deleted Successfully\n";
        
        return 0;
    }
 
    
    while (t != NULL && t->roll != roll) {
    	
        p = t;
        t = t->next;
    }
    if (t == NULL) {
        cout << "Record does not Exist\n";
        return -1;
        p->next = t->next;
 
        delete t;
        cout << "Record Deleted Successfully\n";
 
        return 0;
    }
}
 
void updateRecord(int roll, string Name, string Dept, string Subject, int Marks) {
			
		Node *t = head;
        while (t != NULL) {
        
        if(t->roll==roll){
		
        t->roll = roll;
        t->Name = Name;
        t->Dept = Dept;
        t->Subject = Subject;
        t->Marks = Marks;
    }
        

    t=t->next;
}

		}
 
void Show_Record()
{
    Node* t = head;
    if (t == NULL) {
        cout << "No Record Available\n";
    }
    else {
    	cout<<"\n\tStudent Records Are:\n\n\n";
        cout << "Roll No.\t\tName    \t\tCourse  \t\tSubject \t\tMarks   \n";
 
        
        while (t != NULL) {
            cout << t->roll << "\t\t\t";
            cout << t->Name << "\t\t\t";
            cout << t->Dept << "\t\t\t";
            cout <<t->Subject<<"\t\t\t";
            cout << t->Marks << endl;
            
            if(t->Marks<33){
       	
       	  cout<<"\t\t\t\t\t\t\t\t\t\t\t\tFail\n\n";
       	  
       }
       	else{
		   
       	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tPass\n\n";
	   }
	   
	   t = t->next;     
    }
       
 
}
}
void saveToFile(string filename) {
        ofstream outFile;
        outFile.open(filename.c_str());

        Node *p = head;
        
        if (p == NULL) {
        outFile << "No Record Available\n";
    }
    else {
    	outFile<<"\n\tStudent Records Are:\n\n\n";
        outFile << "Roll No.\t\tName    \t\tCourse  \t\tSubject \t\tMarks   \n";
        
        while (p != NULL) {
            outFile << p->roll << "\t\t\t";
            outFile << p->Name << "\t\t\t";
            outFile << p->Dept << "\t\t\t";
            outFile <<p->Subject<<"\t\t\t";
            outFile << p->Marks << endl;
            if(p->Marks<33){
       	
       	  outFile<<"\t\t\t\t\t\t\t\t\t\t\t\tFail\n\n";
       	  
       }
       	else{
		   
       	outFile<<"\t\t\t\t\t\t\t\t\t\t\t\tPass\n\n";
	   }
	   
             p = p->next;
        }

        outFile.close();
    }
    cout<<"\t\tSaved To File Successfully\n\n";
}

    

int main()
{   
    head = NULL;
    string Name, Dep ,Subject;
    int Roll, Marks, choice;
  
    do{
	         cout<<"\n\n\t\t\tWelcome to Student Record Management System\n\n";
	         cout<<"\tEnter:\n";
	         cout<<"\t0 to exit\n";
	         cout<<"\t1 to Insert a new Record\n";
	         cout<<"\t2 to Delete a Student Record\n";
	         cout<<"\t3 to Search a Student Record\n";
	         cout<<"\t4 to Update a Student Record\n";
         	 cout<<"\t5 to Display All Students Records\n";
         	 cout<<"\t6 to save To File\n";
         	 cout<<"\t7 to clear screen\n";
         	 
        cout << "\nEnter your Choice:\n";
        cin>>choice;
	    cout<<endl;
	    
switch(choice){
		
		case 0:
			break;
			
		case 1:
			
            cout << "Enter Roll Number of Student:\n";
            cin >> Roll;
            cout << "Enter Name of Student:\n";
            cin >> Name;
            cout << "Enter Departement : \n";
            cin >> Dep;
            cout << "Enter Name of Subject:\n";
            cin >> Subject;
            cout << "Enter Marks of Subject:\n";		
            cin >> Marks;
        
            Insert_Record(Roll, Name, Dep, Subject, Marks);

		     break;
		     
		case 2:
			
			cout << "Enter Roll Number of Student whose record you want to delete:\n";
            cin >> Roll;
            Delete_Record(Roll);
			
			break;
			
		case 3:
		     	
		    cout << "Enter Roll Number of Student whose record you want to Search:\n";
            cin >> Roll;
            Search_Record(Roll);
		    	
		    break;
		    	
		case 4:
			
			cout << "Enter Roll Number of Student whose record you want to Update:\n";
            cin >> Roll;
            if(check(Roll)==false){
            	
            	cout << "No such Record Available\n";
            	
			}
			
			else{
		
            
            cout << "Enter New Roll Number of Student:\n";
            cin >> Roll;
            cout << "Enter New Name of Student:\n";
            cin >> Name;
            cout << "Enter New Departement : \n";
            cin >> Dep;
            cout << "Enter Name of Subject:\n";
            cin >> Subject;
            cout << "Enter New Marks of Subject:\n";		
            cin >> Marks;
        
            updateRecord(Roll, Name, Dep, Subject, Marks);
        }

		
		    	break;
		    	
	    case 5:
        
               Show_Record();

		
		    	break;
		    	
		case 6:
		     	
		    	saveToFile("Student Record Management");
		    	
		    	break;
		    	
		case 7:
		     	
		    	system("cls");
		    	
		    	break;
		    	
		default:
		    	cout<<"Wrong Input\nPlease Try Again";
	}
}
while(choice!=0);

 	
return 0;

 }
