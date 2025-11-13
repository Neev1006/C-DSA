#include <iostream>
using namespace std;
class Student{
public:
    string Name;
    int id;
    float marks_Maths,marks_DSA,marks_EG,marks_Physics,marks_CO;
    Student* next;
    Student(string a ,int b,float c,float d,float e,float f,float g){
        Name = a;
        id = b;
        marks_Maths = c;
        marks_DSA = d;
        marks_EG = e;
        marks_Physics = f;
        marks_CO = g;
        next = NULL;
    }
};
class List{
    Student*head;
    Student*tail;
    public:
    List(){
        head = tail = NULL;
    }
    void add_new_student(){
    int id;
    string name;
    float m1, m2, m3, m4, m5;

    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Student Name: ";
    cin>>name;
    cout << "Enter marks for Maths: "; cin >> m1;
    cout << "Enter marks for DSA: "; cin >> m2;
    cout << "Enter marks for EG: "; cin >> m3;
    cout << "Enter marks for Physics: "; cin >> m4;
    cout << "Enter marks for CO: "; cin >> m5;
    Student* newStudent = new Student(name, id, m1, m2, m3, m4, m5);
        if(head==NULL){
            head = tail = newStudent;
        }
        else{
            tail->next = newStudent;
            tail=newStudent;
            }
    }
    Student* search(int id) {
    Student* temp = head;
    while (temp) {
        if (temp->id == id){ return temp;}
        temp = temp->next;
    }
    return nullptr;
}
    void edit_student_details(){
        int studentid_to_be_edited;
        cout<<"Enter the id of the student to be edited: ";
        cin>>studentid_to_be_edited;
        Student*temp=search(studentid_to_be_edited);
        if(!temp){
            cout<<"Student not found";
            return;
        }
            int choice = 0;
            while(choice!=8){
            cout<<"Enter the detail you want to change\n1.Name\n2.Id\n3.Maths marks\n4.DSA marks\n5.Physics Marks\n6.EG marks\n7.CO marks\n8.Exit\n";
            cin>>choice;
            if(choice==1){
                string new_name;
                 cout<<"Enter the changes: ";
                cin>>new_name;
                temp->Name = new_name;
            }
            if(choice==2){
                int new_id;
                 cout<<"Enter the changes: ";
                cin>>new_id;
                temp->id = new_id;
            }
            if(choice==3){
                float new_marks;
                cout<<"Enter the changes: ";
                cin>>new_marks;
                temp->marks_Maths = new_marks;
            }
            if(choice==4){
              float new_marks;
                cout<<"Enter the changes: ";
                cin>>new_marks;
                temp->marks_DSA = new_marks;  
            }
            if(choice==5){
                float new_marks;
                cout<<"Enter the changes: ";
                cin>>new_marks;
                temp->marks_EG = new_marks;
            }
            if(choice==6){
                float new_marks;
                cout<<"Enter the changes: ";
                cin>>new_marks;
                temp->marks_Physics = new_marks;
            }
            if(choice==7){
                float new_marks;
                cout<<"Enter the changes: ";
                cin>>new_marks;
                temp->marks_CO = new_marks;
            }
            if(choice==8){
                cout<<endl;
            }
            }

    }
    int delete_student() {
    int id_to_be_deleted;
    cout << "Enter Id of the student to be deleted: ";
    cin >> id_to_be_deleted;
    if (head == NULL) {
        cout << "No students in the list.\n";
        return 0;
    }
    if (head->id == id_to_be_deleted) {
        Student* temp = head;
        head = head->next;
        if (temp == tail) {
            tail = NULL;
        }

        delete temp;
        cout << "Student deleted successfully.\n";
        return 1;
    }
    Student* temp = head;
    while (temp->next != NULL && temp->next->id != id_to_be_deleted) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Student with ID " << id_to_be_deleted << " not found.\n";
        return 0;
    }
    Student* del = temp->next;
    temp->next = temp->next->next;
    if (del == tail) {
        tail = temp;
    }

    delete del;
    return 1;
}
    void display(){
        Student*temp=head;
        while(temp!=NULL){
            cout<<"Name: "<<temp->Name<<endl;
            cout<<"Id: "<<temp->id<<endl;
            cout<<"Maths: "<<temp->marks_Maths<<endl;
            cout<<"DSA: "<<temp->marks_DSA<<endl;
            cout<<"EG: "<<temp->marks_EG<<endl;
            cout<<"Physics: "<<temp->marks_Physics<<endl;
            cout<<"CO: "<<temp->marks_CO<<endl;
            temp = temp->next;
            cout<<endl;
        }
        return;
        }
};
int main(){
    List Studentdata;
    int choice = 0;
    while(choice!=4){
    cout<<"1.Add a student\n2.Edit details\n3.Delete a student\n4.Display Details\n5.Exit\n";
    cin>>choice;
    if(choice==1){
        Studentdata.add_new_student();
    }
    if(choice==2){
        Studentdata.edit_student_details();  
    }
    if(choice==3){
        Studentdata.delete_student();    
    }
    if(choice==4){
        Studentdata.display();
        return 1;

    }
    }
    return 0;
}