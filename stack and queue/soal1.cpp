#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int arr[N];
    
    for(int i=0; i<N;i++){
        cin>>arr[i];
    }
    for(int j=0; j<N; j++){
        if (arr[j]%2==1){
        cout<<arr[j];
        cout<<" ";
    }
    }
    return 0;
}
