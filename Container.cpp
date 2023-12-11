#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;

int main()
{
    typedef map<string,float>mapType;
    mapType populationMap;
    populationMap.insert(make_pair("Maharashtra",125));
    populationMap.insert(make_pair("Goa",12));
    populationMap.insert(make_pair("Bihar",15));
    populationMap.insert(make_pair("Rajasthan",35));
    populationMap.insert(make_pair("Kerala",78));
    populationMap.insert(make_pair("Gujarat",23));
    populationMap.insert(make_pair("Karnataka",67));
    populationMap.insert(make_pair("Punjab",57));
    populationMap.insert(make_pair("Haryana",47));
    populationMap.insert(make_pair("Uttarakhand",56));
    populationMap.insert(make_pair("Assam",45));
    populationMap.insert(make_pair("Sikkim",34));
    populationMap.insert(make_pair("Mizoram",23));
    populationMap.insert(make_pair("Manipur",26));
    populationMap.insert(make_pair("Meghalaya",30));

    mapType::iterator iter = --populationMap.end();
    populationMap.erase(iter);
    cout<<"Total state of India with population : "<<populationMap.size()<<"\n";
    for(iter = populationMap.begin();iter != populationMap.end();iter++)
    {
        cout<<iter->first<<":"<<iter->second<<"million\n";
    }
    char c;
    do
    {
        string state;
        cout<<"Enter the state you want to know the population of : \n";
        cin>>state;
        iter = populationMap.find(state);
        if(iter != populationMap.end())
        {
            cout<<state<<"'s population is "<<iter->second<<" million"<<endl;
        }
        else
        {
            cout<<"State is not in populationMap\n";
        }
        cout<<"\nDo you wish to continue?(y/n) : ";
        cin>>c;
    } while (c == 'y' || c == 'Y');
    populationMap.clear();
    
    return 0;
}