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

    /*int left_over = max%12;
    int last_12 = max - left_over;
    std::unordered_set <int> set12;
    int number_of_12 = 0;
    while(last_12 >= min){
        //add to hashmap
        set12.insert(last_12);
        last_12 = last_12 - 12;
        number_of_12 = number_of_12 + 1;
    }*/


    //get the number of 12 in a range in constant time
    //citation : https://stackoverflow.com/questions/16381828/how-to-find-the-number-of-values-in-a-given-range-divisible-by-a-given-value
    int number_of_12 = 0;

    int min12 = min;
    int remainder = min % 12;
    if(remainder != 0){
        min12 = min + (12 - remainder);
    }

    int max12 = max;
    if(max%12 != 0){
        max12 = max - (max%12);
    }

    if(min12 <= max12)
        number_of_12 = ((max12 - min12)/12) + 1;



    //number of perfect squares

    bool found_perfect_square = false;
    int perfect_square;
    //std::vector<int> perfect_squares;
    int current_number = min;
    int perfect_squares_num = 0;
    int number_in_both = 0;

    while( found_perfect_square == false && current_number <= max){
        //check if the current number is a perfect square
        if(ceil((double) std::sqrt(current_number)) == floor((double) std::sqrt(current_number))){
            found_perfect_square = true;
            perfect_square = current_number;
        }else{
            current_number = current_number +1;
        }
    }
    //now use the formula for finding perfect squares
    while(perfect_square <= max && found_perfect_square == true){
        //perfect_squares.push_back(perfect_square);
        perfect_squares_num = perfect_squares_num + 1;
        if(perfect_square%12 ==0){
            number_in_both = number_in_both + 1;
        }
        perfect_square = perfect_square + ((std::sqrt(perfect_square) * 2)+1);
    }

    /*int number_in_both = 0;
    for(int i = 0; i<perfect_squares.size();i++){
        if(set12.find(perfect_squares[i]) != set12.end()){
            number_in_both = number_in_both + 1;
        }
    }*/

    std::cout<<number_of_12<<" "<<perfect_squares_num<<" "<<number_in_both<<std::endl;
  }
}