#include <iostream>
using namespace std;
class stack{
        int data[10];
        int top=-1;
        public: 
    int isFull(){
        if(top==9){
            return true;
        }
        else{
            return false;
        }
    }
    int isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int num){
        if(isFull()){
            cout<<"Stack is full."<<endl;
        }
        else{
            top++;
            data[top]=num;
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty."<<endl;
        }
        else{
            top--;
        }
    }
    void peek(){
        if(isEmpty()){
            cout<<"Stack is empty."<<endl;
        }
        else{
            cout<<"The topmost element is : "<<data[top]<<"."<<endl;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty.";
        }
        for(int i=top;i>=0;i--){
            cout<<data[i]<<endl;
        }
    }
    void size(){
        cout<<"The number of elements in  the stack is : "<<top + 1<<".";
    }
    void search(int number_to_be_searched) {  
    if (isEmpty()) {  
        cout << "Stack is empty." << endl;  
        return;
    }  

    int position = -1;          
    for (int i = top; i >= 0; i--) {  
        if (data[i] == number_to_be_searched) {  
            position = i;
            break;
        }  
    }  
    
    if (position != -1) {  
        cout << "Number found at position " << position + 1 << "." << endl;  
    } else {  
        cout << "Number not found." << endl;  
    }  
}        
    };
int main(){
    stack s;
    int choice;
        do{
        cout<<"Stack operations\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Size\n6.Search\n7. Exit"<<endl;
        cin>>choice;
        if(choice==1){
            int num;
            cout<<"Enter number to be pushed: ";
            cin>>num;
            s.push(num);
        }
        if(choice==2){
            s.pop();
        }
        if(choice==3){
            s.peek();
            return 0;
        }
        if(choice==4){
           s.display();
           return 0; 
        }
        if(choice==5){
            s.size();
            return 0;
        }
        if(choice==6){
            if (s.isEmpty()) {  
                cout << "Stack is empty." << endl;
            }
            else{
            int num;
            cout<<"Enter number to be searched: ";
            cin>>num;
            s.search(num);
            }
        }
    }while(choice!=7);
           
return 0;
}