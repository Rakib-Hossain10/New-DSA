#include<iostream>
using namespace std;
bool ispossiblesoln(int arr[],int size,int mid,int sn){
    int studentn=1;
    int pagesum=0;
    for(int i=0; i<=size-1; i++){
        if(pagesum + arr[i] <= mid){
            pagesum+=arr[i];// ai page gula 1st student ke dea hoice
        }
        else{
            studentn++;   
            if(studentn > sn  || arr[i] > mid){
                return false;
            } 
            pagesum=0;//ekhane 0 near karon hocce (porer student gulake notun kore dea hocce)
            pagesum+=arr[i];//ai page gula porer student k dea hocce
        }
    }
    return true;
}

int main () {
    int arr[]={20,30,40,50};
    int size = sizeof(arr)/sizeof(int);
    int ans=-1;
    int student=2;
    int start=0;
    int sum=0;
    for(int i=0; i<=size-1; i++){
        sum+=arr[i];
    }
    int end=sum;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(ispossiblesoln(arr,size,mid,student)){
            ans=mid;
            end=mid-1;
        }
        else {
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    cout<<"The solution is : "<<ans;

}
