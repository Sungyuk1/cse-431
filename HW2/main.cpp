#include <iostream>
#include <unordered_map>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

//This code is from geeksforgeeks : https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-1-sort-by-first-and-second/
// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int,int> &a,
        const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int C; //Number inputs

    std::cin >> C;

    vector< pair <int,int> > time_sorted_vector;
    vector< pair <int,int> > value_sorted_vector;

    for (int i = 0; i<C; i++) {
        int arrival_time;
        int time_required;
        std::cin >> arrival_time >> time_required;

        cout<<"before make pair"<<endl;
        time_sorted_vector.push_back(make_pair(arrival_time,time_required));
        value_sorted_vector.push_back(make_pair(arrival_time,time_required));
        cout<<"after make pair"<<endl;

    }

    sort(time_sorted_vector.begin(), time_sorted_vector.end());
    cout<<"Time sorted test : "<<time_sorted_vector[0].first<<" "<<time_sorted_vector[1].first<<endl;
    // Using sort() function to sort by 2nd element
    // of pair
    sort(value_sorted_vector.begin(), value_sorted_vector.end(), sortbysec);
    cout<<"Value Sorted Test : "<<value_sorted_vector[0].second<<" "<<value_sorted_vector[1].second<<endl;


}