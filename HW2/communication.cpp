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
            map.insert(make_pair(temp, 1));
        }else{
            map[temp] = map[temp] + 1;
        }
    }

    //set it to arbitrary value
    int most_common = -9999999;
    int largest_value = -999999999;

    for (auto i = map.begin(); i != map.end(); i++){

        if(i->second >largest_value){
            most_common = i->first;
        }
        if(i->second == largest_value) {
            if(i->first < largest_value){
                most_common= i->first;
            }

        }

       }


    std::cout<<most_common<<endl;
    }