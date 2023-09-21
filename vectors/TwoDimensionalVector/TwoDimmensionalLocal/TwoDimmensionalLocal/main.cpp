//
//  main.cpp
//  TwoDimmensionalLocal
//
//  Created by Abdullah Juhaif on 8/29/23.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<int> lastNumber;
    int lastAnswer=0;
    vector<vector<int>> arr;
    int idx;
    arr.resize(n,vector<int>(1,0));
    vector<vector<int>>::iterator row;
    //As we can declare a vector only with values , In our case here we need to modify the the first time we write to a row and then we are going to do push backs we need to set flags, if we use a for loop it will become time consuming hence we can have vector with the same size as the vector that needs to be modifed  and have a boolean for it
    vector<bool> modified(n, false);
    for(row=queries.begin();row!=queries.end();row++){
        if((*row)[0] == 1){
            idx=(((*row)[1]^lastAnswer)%n);
            if(!modified[idx]){
                (arr)[idx][0]=((*row)[2]);
                modified[idx] = true;
            }
            else{
                (arr)[idx].push_back((*row)[2]);
            }
        }
        else{
            idx=(((*row)[1]^lastAnswer)%n);
            lastAnswer=arr[idx][(*row)[2]%((arr)[idx].size())];
            lastNumber.push_back(lastAnswer);
        }
    }
    return lastNumber;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> queries;
    vector<int> lastNumber;
    // instead of creating queries by inserting one element after the other, we are query to a vector of integer and adding it to queries
    vector<int> tempArray;
    int n,q;
    int num;
    string query;
    cout<<"Enter the sizeof the array:";
    cin>>n;
    cout<<"Enter the number of queries:";
    cin>>q;
    cin.ignore();
    queries.resize(q,vector<int>(3,0));
    vector<vector<int>>::iterator row;
    for(row=queries.begin();row!=queries.end();row++){
        cout<<"Enter the query";
        getline(cin,query);
        istringstream iss(query);
        while (iss >> num) {
            tempArray.push_back(num);
            }
        *row=tempArray;
        tempArray.clear();
    }
    
    lastNumber=dynamicArray(n,queries);
    vector<int>::iterator itr;
    for(itr=lastNumber.begin();itr!=lastNumber.end(); itr++){
        cout<<*itr<<endl;
    }
}
