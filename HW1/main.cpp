#include<iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

int main()
{
  int num; // Number of inputs
  
  std::cin >> num;
  
  for (int i = 0; i < num; i++)
  {
    int min; 
    int max; 
    
    std::cin >> min >> max;

    //number dividable by 12
    //bool found_12_num = false;
    //int current_number = min;
    //int num12;

    /*while( found_12_num == false && current_number <= max) {
        if(current_number%12 == 0){
            num12 = current_number;
            found_12_num = true;
        }else{
            current_number = current_number +1;
        }

    }*/

    int left_over = max%12;
    int last_12 = max - left_over;
    std::unordered_set <int> set12;
    int number_of_12 = 0;
    while(last_12 >= min){
        //add to hashmap
        set12.insert(last_12);
        last_12 = last_12 - 12;
        number_of_12 = number_of_12 + 1;
    }





    //number of perfect squares

    bool found_perfect_square = false;
    int perfect_square;
    std::vector<int> perfect_squares;
    int current_number = min;

    while( found_perfect_square == false && current_number <= max){
        //check if the current number is a perfect square
        if(ceil((double) std::sqrt(current_number)) == floor((double) std::sqrt(current_number))){
            found_perfect_square = true;
            perfect_square = current_number;
            //perfect_squares.push_back(perfect_square);
        }else{
            current_number = current_number +1;
        }
    }
    //now use the formula for finding perfect squares
    while(perfect_square <= max){
        perfect_squares.push_back(perfect_square);
        perfect_square = perfect_square + ((std::sqrt(perfect_square) * 2)+1);
    }

    int number_in_both = 0;
    for(int i = 0; i<perfect_squares.size();i++){
        if(set12.find(perfect_squares[i]) != set12.end()){
            number_in_both = number_in_both + 1;
        }
    }

    std::cout<<number_of_12<<" "<<perfect_squares.size()<<" "<<number_in_both<<std::endl;
  }
}