//
//  main.cpp
//  VectorReverse
//
//  Created by Abdullah Juhaif on 8/25/23.
//

#include <iostream>
#include <vector>
using namespace std;
void revVector(vector<int> *a){
    //we do not use this as vectors methods and properties do ot need to be explicitly dereferenced
//    reverse(*a->begin(),*a->end());
    reverse(a->begin(), a->end());
//    vector<int>::iterator itr;
//    for(itr=a.begin();itr!=a.end();itr++){
//        cout<<*itr<<" ";
//    }
}
void printVector(vector<int> &a){
    vector<int>::iterator itr;
    for(itr=a.begin();itr!=a.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
}
int main(int argc, const char * argv[]) {
    vector<int> v;
    int n;
    cout<<"Enter the elements of the vector";
    cin>>n;
    for(int i=0;i<n;i++){
        int e;
        cout<<"Enter the vector Element:";
        cin>>e;
        v.insert(v.begin()+i,e);
        cout<<"Element inserted"<<endl;
    }
    cout<<"Before reverse\n";
    printVector(v);
    revVector(&v);
    cout<<"After reverse\n";
    printVector(v);
}

