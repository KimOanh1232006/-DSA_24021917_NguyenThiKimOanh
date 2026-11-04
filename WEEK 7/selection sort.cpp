using namespace std;
#include<iostream>
	void selectionsort(int a[],int n){
		for(int i=0;i<n;i++){
			int k=i;
			for(int j=i+1;j<n;j++){
				if(a[k]>a[j]){
					k=j;
				}
			}
			swap(a[i],a[k]);
			}
		}
	
	int main(){
		int a[1000];
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		selectionsort(a,n);
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
	}

