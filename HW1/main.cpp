#include<iostream>
#include <unordered_set>


int main()
{
  int num; // Number of inputs
  
  std::cin >> num;
  
  for (int i = 0; i < num; i++)
  {
    int distance_1; 
    int distance_2; 
    int number_of_presses;
    std::unordered_set <int> distance_set;
    
    std::cin >> distance_1 >> distance_2 >> number_of_presses;

      //more formatting code
      if(distance_1>distance_2){
          int temp = distance_2;
          distance_2 = distance_1;
          distance_1 = temp;
      }

      //formating code
      bool first_distance = true;

    int distance = -12222;  //set it to something random so it is easy to tell;
    for(int i = 0; i<number_of_presses; i++){
        distance = (distance_2*i) + (distance_1*(number_of_presses - i));

        if(distance_set.find(distance) == distance_set.end()){
            distance_set.insert(distance);
            if(first_distance){
                std::cout<<distance;
                first_distance = false;
            }else{
                std::cout<<" "<<distance;
            }
            /*if (i != number_of_presses-1){
                std::cout<<" ";
            }*/
        }
        //distance_set.insert(distance);
        //std::cout<<distance<<" ";
    }
    //doing this for formatting of autograder
    distance = (distance_2*number_of_presses);
    if(distance_set.find(distance) == distance_set.end()) {
        std::cout<<" "<<distance<<std::endl;
      }else{
        std::cout<<std::endl;
    }
    //std::cout<<distance<<std::endl;
  }
}