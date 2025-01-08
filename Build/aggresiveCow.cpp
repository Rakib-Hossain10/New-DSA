#include <iostream>
using namespace std;
bool ispossiblesoln(int arr[],int size,int cow,int mid){
  int cowCount=1;
  int lastpos=arr[0];//1st cow ke 1st possition a rakha holo
  for(int i=0; i<=size-1; i++){
    
    if(arr[i] - lastpos >= mid){
      cowCount++;
      if(cowCount == cow ){ //2ta ba 3ta cow boshano hoe gelai kaj shesh
      return true;
    }
    lastpos=arr[i];
    }
  }
  return false;
}
int main () {
  int arr[]={1,2,3,4,6};//Agressive cow
int cow; cout<<"The Amount of cow is : "<<endl;
cin>>cow;
int size = sizeof(arr)/sizeof(int);
int start=0;
int end=arr[size-1];//karon 2 ta cow er highest distance
int mid=start+(end-start)/2;
int ans=-1;

while(start<=end){
 if(ispossiblesoln(arr,size,cow,mid)){
  ans=mid;
  start=mid+1;//karon highest distance is the answer
 } 
else{
  end=mid-1;
}
mid=start+(end-start)/2;
}
cout<<"The highest distance of cow's is : "<<ans;
}