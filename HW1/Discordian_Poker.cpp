#include<iostream>

//function for checking under and over flows according to the problem
int flow_check(int _bet){
    if(_bet < 0){
        while(_bet < 0){
            _bet = _bet + 1000000;
        }
    }

    if(_bet > 1000000){
        while(_bet >1000000){
            _bet = _bet - 1000000;
        }
    }

    return _bet;
}

int Discordian_Poker(int _startingBet, int _numberOfRounds){

    int output = _startingBet;

    for(int i = 0; i<_numberOfRounds; i++){
        //odd case
        if(output % 2 == 1){
            output = output - 15;
            output = flow_check(output);
            output = output *2;
            output = flow_check(output);
        }else{
            //even case
            output = output - 99;
            output = flow_check(output);
            output = output *3;
            output = flow_check(output);
        }
    }
    return output;
}

int main()
{
  int T; // Number of test cases
  
  std::cin >> T;
  
  for (int i = 0; i < T; i++)
  {
    int S; // Starting bet
    int k; // Number of rounds
    
    std::cin >> S >> k;
    
    // Your code
    std::cout<<Discordian_Poker(S,k)<<std::endl;
  }
}


