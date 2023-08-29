//
//  main.cpp
//  VectorRotateLocal
//
//  Created by Abdullah Juhaif on 8/28/23.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> vectorRotate(vector<int> &a,int d){
    int rotate,n,dif;
    vector<int> temp;
    n=a.size();
    rotate=d%n;
    dif=n-rotate;
    temp.resize(n,0);
    for(int i=0;i<n;i++){
        if((i-d)<0){
            temp[dif+i]=a[i];
        }
        else{
            temp[i-d]=a[i];
        }
    }
    return temp;
}
vector<int> vectorStdRotate(vector<int> arr, int d){
    rotate(arr.begin(), arr.begin()+d, arr.end());
    //to rotate towards right we need to give - instead of +
    return arr;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,d,e;
    cout<<"HI";
    cin>>n;
    cin>>d;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cout<<"Enter the Number: ";
        cin>>e;
        arr.push_back(e);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Vector after rotaing"<<endl;
    arr=vectorRotate(arr,d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //Lets use the STD Rotate algorithm
    arr=vectorStdRotate(arr,d);
    cout<<"\nAfter Rotating the vector again by "<<d<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
