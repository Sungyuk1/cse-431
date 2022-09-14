#include<iostream>

//done
//OpisClimb



int cell_reuse(int cells, int c){

  if(c>cells){
    return 0;
  }
  int combinations = cells/ c;
  if(cells%c != 0){
    int new_combo = cells%c + combinations;
    combinations = combinations + cell_reuse(new_combo, c);
  }else{
    combinations = combinations + cell_reuse(combinations, c);
  }
  return combinations;
}

int main()
{
  int num; // Number of inputs
  
  std::cin >> num;
  
  for (int i = 0; i < num; i++)
  {
    int gallons; 
    int gal_per_cell; 
    int c; //number of used cells that can be combined to create a new cell
    
    std::cin >> gallons >> gal_per_cell >> c;
    
    // Your code
    int full_cell_num = gallons/gal_per_cell;
    int combinations = cell_reuse(full_cell_num, c);

    int total_miles = full_cell_num + combinations;
    std::cout<<total_miles<<std::endl;
  }
}