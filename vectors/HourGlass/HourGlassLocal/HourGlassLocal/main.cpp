//
//  main.cpp
//  HourGlassLocal
//
//  Created by Abdullah Juhaif on 8/26/23.
//

#include <iostream>
#include <vector>
using namespace std;
//The below funtion uses itertor to read a vector
void readVectoriterator(vector<vector<int>> &a){
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    for(row=a.begin();row!=a.end();row++){
        // first we are using the vector and accessing rows using the row iterator which is a pointer poinitn to a vector hence we us row here because row is an iterator pointer we use->
        for(col=row->begin();col!=row->end();col++){
            cout<<*col<<" ";
        }
        cout<<endl;
    }
}
//The below funtion uses Indexing to read a vector
void readVectorIndex(vector<vector<int>> &a, int r,int c){
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void writeVectorIterator(vector<vector<int>> &a){
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    int e;
    cout<<"Enter the elements: ";
    for(row=a.begin();row!=a.end();row++){
        // first we are using the vector and accessing rows using the row iterator which is a pointer poinitn to a vector hence we us row here because row is an iterator pointer we use->
        for(col=row->begin();col!=row->end();col++){
            cin>>e;
            *col=e;
        }
    }
}
void writeVectorIndex(vector<vector<int>> &a, int r,int c){
    int e;
    cout<<"Enter the elements: ";
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cin>>e;
            a[i][j]=e;
        }
    }
}
// HourGlass
int hourglassSum(vector<vector<int>> &a, int r,int c){
    int sum=0;
    int maximum=0;
    int temprow,tempcol;
    for (int i = 0; i < r-2; ++i){
        for (int j = 0; j<c-2; ++j){
            sum=0;
            sum=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
            if (sum>=maximum || (i==0 && j==0)){
                maximum=sum;
                temprow=i;
                tempcol=j;
            }
        }
    }
    cout<<temprow<<" "<<tempcol<<endl;
    return maximum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int c;
    int r;
    vector<vector<int>> arr;
    cout<<"Enter the number of coloumn:";
    cin>>c;
    cout<<"Enter the numnber of rows:";
    cin>>r;
    arr.resize(r,vector<int>(c,0));
    //create vector iterators
    
    readVectoriterator(arr);
    writeVectorIterator(arr);
    cout<<endl;
    readVectoriterator(arr);
    //writing to a vector by indecing
    writeVectorIndex(arr,r,c);
    cout<<endl;
    readVectorIndex(arr,r,c);
    int hourMax=hourglassSum(arr, r, c);
    cout<<"hourMax="<<hourMax<<endl;
    return 0;
}
