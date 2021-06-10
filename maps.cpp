#include <iostream>
#include <map>
#include<string>
 
using namespace std;

//Map is an assosciative array
 
void print_map(map<int,int,greater <int>> &map1)
{
    map<int,int,greater <int>>::iterator iter;
    for(iter=map1.begin();iter!=map1.end();iter++)
    cout<<(*iter).first<<" "<<(*iter).second<<endl;
}

int main()
{
    map<int,int,greater <int>> marksMap;
    marksMap[1]=2;
    marksMap[2]=98;
    marksMap[3]=45;
    marksMap.insert(make_pair(4,56));
    marksMap.insert({5,66});

    map<string,int>::iterator iter;

    print_map(marksMap);

    



}