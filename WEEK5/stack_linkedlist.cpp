using namespace std;
#include<iostream>
struct node{
int data;
struct node*next;
};
node*makenode(int x){
node*newnode=new node();
newnode->data=x;
newnode->next=NULL;
 return newnode;
}
bool isEmpty(node*stack){
return stack==NULL;
}
void push(node*&stack,int x){
 node*chen=makenode(x);
if (chen!=NULL){
chen->next=stack;
stack=chen;
}
}
int pop(node*&stack){
node*tmp=stack;
int giatri=tmp->data;
stack=stack->next;
delete tmp;
return giatri;
}
int size(node*stack){
node*tmp=stack;
int counter=0;
while(tmp!=NULL){
counter++;
tmp=tmp->next;
}
return counter;
}

int top(node*stack){
return stack->data;
}
int main(){
int rc;
node*stack=NULL;
while(cin>>rc){
if(rc==1){
int x;
cin>>x;
push(stack,x);
}
else if(rc==2){
cout<<pop(stack);
}
else if(rc==3){
cout<<size(stack);
}
else if(rc==4){
cout<<top(stack);
}
}
}

 