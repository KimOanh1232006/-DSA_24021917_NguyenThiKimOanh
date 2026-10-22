using namespace std;
#include<iostream>
int a[10000];
int N=10000;
int n=0;
bool isEmpty(){
	return n==0;
}
void enquene(int item){//chèn
	if(n==N) return ;
item =a[N];
n++;
}
int  dequeue(){//xóa đầu
	if(n==0)return -1 ;
	int val=a[0];
	for(int i=0;i<n;i++){
		a[i]=a[i+1];
	}
	n--;
}

int front(){
	return a[0];
}
int size(){
	return n;
}
int main(){
	int rc;
	while(cin>>rc){
		if(rc==1){
	cout<<isEmpty();		
		}
		else if(rc==2){
		int x;
		cin>>x;
		enquene(x);
}
else if(rc==3){
	cout<<dequeue();
}	
if(rc==4){
	cout<<size();
}
	}
		}
