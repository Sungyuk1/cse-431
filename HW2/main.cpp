#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <set>
using namespace std;


//By default, C++ creates a max-heap for priority queue.

int main()
{
    int E; //Number of emails

    std::cin >> E;

    vector<int> stack;
    priority_queue<int>pq(stack.begin(),stack.end());
    set<int> removed;

    for (int i = 0; i < E; i++)
    {
        int direction;
        int value;
        std::cin >>direction;

        if(direction == 1) {
            cin >> value;
            stack.push_back(value);
            pq.push(value);

        }else if(direction == 2){
            int to_remove = stack[stack.size()-1];
            stack.pop_back();
            removed.insert(to_remove);

        }else if(direction == 3){
            for(int j = 0; j< pq.size(); j++){
                int current_value = pq.top();
                //cout<<"Current Value right now in 3 is : " << current_value<<endl;
                if(removed.find(current_value) == removed.end()){
                    cout<<current_value<<endl;
                    j = pq.size();
                }else{
                    pq.pop();
                    j--;   // need to make smaller cause popping
                }
            }

        }
    }
    }