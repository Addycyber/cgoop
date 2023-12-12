// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    
    //Creating an empty map associative container
    map<string, long> statePop;
    
    //Inserting keys (state names) and values (populations)
    
    statePop["Maharashtra"] = 971882678;
    statePop["Gujrat"] = 6523342678;
    statePop["Delhi"] = 671882678;
    statePop["Up"] = 31282678;
    
    //accepting int
    
    cout<<"$ $ $ Population of states in India $ $ $";
    
    cout<<"\nSize Of Map : "<<statePop.size();
    
    
    cout<<"\nEnter the state name keep first letter 'A' capital: ";
    string in;
    getline(cin, in);
    
    if(statePop.find(in) != statePop.end()){
        
        cout<<"State name: "<<in<<"\nState Population: "<<statePop[in]<<endl;
        
    }
    else{
        
        cout<<"No State Exist!!!";
    }
    
    
    return 0;
}