using namespace std;
#include<iostream>
int  a[10000];
int n=0;
int N=10000;
bool isEmpty(){
return n==0;
}
void push(int x){
a [n]=x;
++n;
}
int pop(){
if(n>=1){
return a[n-1];
n--;
}
}
int top(){
if(n!=0){
return a[n-1];
}
}
int size(){
return n;
}
int main(){
int rc;
while(cin >>rc){
if(rc==1){ 
cout<<isEmpty();
}
if(rc==2){
int x;
cin>>x;
push(x);


}
if(rc==3){
cout<<pop();
}
if(rc==4){
cout<<top();
}
}
}


