/*
Problem : Given an array a[0..N-1] each of whose elements can be classified as either RED or BLUE, 
rearrange a[]'s elements (via swapping, but no other operation) 
so that all occurrences of RED come before all occurrences of BLUE and 
so that the variable k indicates the boundary between the RED and BLUE regions.
*/
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
void swap(char * a, char *b ){
    char ch = *a;
    *a = *b;
    *b = ch;
}
int rearrange(vector<char>& arr){
    int left = 0;
    int right = arr.size();
    while(left<right){
        if(arr[left]== 'R'){
            left++;
        }else{
            if(arr[right]=='R'){
                swap(&arr[left], &arr[right]);
                left++;
            }
            right--;
        }
    }
    return left-1;
}
int main(){
    vector<char> arr;
    int n ; 
    cin>>n;
    for(int i = 0;i<n;i++){
        char ch;
        cin>>ch;
        arr.push_back(ch);
    }
    int k = rearrange(arr);
    cout<<"Boundary between R and B is at index : "<<k<<" ie the last index of R in array "<<endl;
    return 0;
}