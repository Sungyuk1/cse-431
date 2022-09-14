#include<iostream>
#include <vector>

int main()
{
  int C; // Number of Contestants
  
  std::cin >> C;

  std::vector<int> endurances;

  int current_time = 0;

  for (int i = 0; i < C; i++)
  {
    int temp;    
    std::cin >> temp;
    
    endurances.push_back(temp);
  }

  //debug code
  //std::cout<<"size of endurance : " << endurances.size() <<std::endl;

  int num_remaining = C;

  //debug code
  //std::cout<<"num remaining : " << num_remaining <<std::endl;

  //debug code
  //std::cout<<"endurance[0] : " << endurances[0] <<std::endl;

  int last_num = num_remaining;
  std::cout<<num_remaining<<std::endl;
 

  while(num_remaining > 0){

    if(num_remaining != last_num){
      std::cout<<num_remaining<<std::endl;
      last_num = num_remaining;
    }

    //current_time = current_time+2;

    /*for(auto i = endurances.begin(); i != endurances.end(); ++i){
        std::cout<<"endurances[*i] : "<<endurances[*i]<<std::endl;
        endurances[*i] = endurances[*i] - 2;
        std::cout<<"endurances[*i] - 2 : "<<endurances[*i]<<std::endl;
        if(endurances[*i] <= 0){
            num_remaining = num_remaining - 1;
            endurances.erase(i);
            i--;
            
        }
    }*/

    for(int i = 0; i<endurances.size(); i++){
      //number we are using to mark if players are still in
      if(endurances[i] != -975463214){

        endurances[i] = endurances[i] - 1;
        if(endurances[i] <= 0){
            endurances[i] = -975463214;
            num_remaining = num_remaining -1;
        }

      }
    }

  }
}