#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int C; //Number of ids

    std::cin >> C;

    unordered_map<int, int> map;

    for (int i = 0; i < C; i++)
    {
        int temp;
        std::cin >> temp;

        //inset into map
        if (map.find(temp) == map.end()){
            map[temp] = 1;
        }else{
            map[temp] = map[temp] + 1;
        }
    }

    //set it to arbitrary value
    int most_common = -9999999;
    int largest_value = -999999999;

    for (auto i = map.begin(); i != map.end(); i++){

        //cout<<"current value is : first-"<<i->first<<" second-"<<i->second<<endl;
        if(i->second >largest_value){
            most_common = i->first;
            largest_value= i->second;
        }
        if(i->second == largest_value) {
            if(i->first < most_common){
                most_common= i->first;
            }

        }

       }
    //edge case
    if(map.size() == 0){
        cout<<""<<endl;
    }

    std::cout<<most_common<<endl;
    }