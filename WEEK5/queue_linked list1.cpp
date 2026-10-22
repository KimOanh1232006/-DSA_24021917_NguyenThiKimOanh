using namespace std;
#include<iostream>
struct node{
	int data;
	struct node*next;
};
typedef struct node node;
node* makenode(int x){
	node* newnode=new node();
	newnode->data=x;
	newnode->next=NULL;
return newnode;
}
void enqueue(node*&node1,int x){
	node*chen=makenode(x);
if(node1==NULL){
	node1=chen;
	return;
	}
	node*temp=node1;
	while(chen->next!=NULL){
		temp=temp->next;
	}
	temp->next=chen;
}
	int dequeue(node*&queue){
		if(queue==NULL)return -1 ;
		node*xoa=queue;
		int giatri;
		giatri=xoa->data;
queue=queue->next;
		delete xoa;
	return giatri;
}
	bool isTempty(node*newnode){
		return newnode==NULL;
	}
	int size(node*queue){
	node*duyet=queue;
		int counter=0;
		while(duyet!=NULL){
			counter++;
		duyet	=duyet->next;
		}
		return counter;
	}
	int front(node*queue){
		if(queue==NULL){
			return -1;
		}
	return queue->data;
	}

int main(){
	node*newnode=NULL;
	int rc;
while(	cin>>rc){
	if(rc==0){
		int x;
		cin>>x;
		enqueue(newnode,x);
	}
	else if(rc==1){
cout<<	dequeue(newnode);
	}
	else if(rc==2){
		cout<<isTempty(newnode);
	}
	else if(rc==3){
		cout<<size(newnode);
	}
	else if(rc==4){
	cout<< front(newnode);
}
}
}

