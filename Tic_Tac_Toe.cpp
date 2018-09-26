#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cassert>
	
using namespace std; //// cloned

//FUNCTION DECLARATIONS
/**
Prints the rules of the game in Red at the begining of the program
*/
void print_rules();

/**
Prints the diagram of tick tack toe
*/
void print_diagram(int Turn[]);

/**
Checks the board for any winning posibility
@param integer array with the feilds of the diagram
@return char of the winning number if exists or if no one won yet it returns 0
*/
char game_result(int x[]);

/**
Tries playing one imaginary turn, will be used to calculate the best possible move 
@param character with the value indicating who is playing that turn 
@param integer array with feilds of the diagram
@return integer value of the possible winning player
*/
int tester_turn(char turn, int x[]);

/**
Tests to see where would be the best possble position for the computer to play using the tester_run function
@param integer array with the feilds of the diagram
@return charachter value with the best feild for the computer to play
*/
char pick_field(int x[]);

/**
Prints messeges with tge status the game at the endof the game
@param character valueindicating which player won or if no on won
*/
void print_result(char x);

const int adjuster = (-1); // Global constant value

/**
Main function of TicTacToe game.
@return int zero when the function is done without any errors.
*/
int main()
{
    print_rules(); //prints rules of the game once in Red font
    int fields[9]={0};
    print_diagram(fields);//prints an empty tic tac toe diagram
	int number_of_played_turns=0;
	char position=0;
	bool flag =true;
	int spot=0;
	bool input = true;
	bool turn_flag =true; //to check if user input a valid number
	bool board_full =false;
	string turn; //to check if user wants to go first or second 
	
	do{
		cout<<"Would you like to go first?(Y/N)"<<endl;
		cin>>turn; 
		if(turn !="n" && turn!="N" && turn!="no" && turn !="NO" && turn!="No" && turn!="yes" && turn!="y" && turn!="Y" && turn!="Yes" && turn!="YES")
		{
		    cout<<"\nINVALID INPUT!! Please try again\n";
		    flag=false;
		}
		else
		{
		    flag = true;
		}
	}
	while(flag==false);

	while(number_of_played_turns < 8)
	{
	    if (turn_flag== false) //prints error msg and loop if user input number that is not is range
	    {
	        cout<<"INPUT IS NOT IN RANGE! Please try again"<<endl;
	    }

	    if (turn_flag==true && input ==true)
	    {
	
	        if(turn =="n" || turn=="N"|| turn=="no" || turn =="NO" || turn=="No"||flag ==false && turn_flag == true ) 
			{
			     flag = true;                                  //        Computer turn
                 if(game_result(fields)==0 )
                  {
                	int o = 0;
                	int p = 0;
	            	int r = game_result(fields);
                    position= pick_field(fields);
           
                	fields[position]= 1;
           
                     print_diagram(fields);
                     ++number_of_played_turns;
                     if (game_result(fields) != 0)
                     {
				         board_full= false;
					     break;
                      }
		    	 }   
                 else
                 {
                     board_full = false;
            	     break;
                 }
			}
	    }	

        if(turn=="yes"|| turn=="y"|| turn=="Y"||turn=="Yes"||turn=="YES"|| flag == true )                         //Player Turn
    	{ 
	    	cout<<"Please enter the number of the feild where you would like to play your turn(0-8): "<<endl;
	    	cin>>spot;
	    	if(cin.fail())
	    	{
	    	    cout<<"ERROR!! INVALID DATA TYPE! PLEASE RUN PROGRAM AGAIN! =====>> GOODBYE\n"; //ends program if user inputs an invalid data type
	    	    return 0;
	    	}
	    	if (spot>8 || spot <0 ) //checks if input is in range, if not it prints error and loop till input is valid
	    	{
	    	    turn_flag = false;
	    	}
	    	else
	    	{
	    	    turn_flag = true;
	    	}
	    	if (fields[spot]!= 0) //prints error msg if user inputs a value in a field that was already taken and then loop to ask for a diffrent number
	    	{
	    	    cout<<"Field is already taken! Please try a diffrent field!\n";
	    	    input= false;
	    	}
	    	if(fields[ spot]==0 && turn_flag == true )
	    	{
	    	    input = true;
		    	fields[spot]= adjuster;
		    	++number_of_played_turns;
		    	flag = false;
		    	board_full = true;
	    	}
	    }
    }
	
	if(turn_flag== true)
	{
    	if (board_full==true)
    	{
	         if(game_result(fields)==0)
             {
                    position= pick_field(fields);
            	    fields[position]=1;
                    print_diagram(fields);
                    board_full = false;
			        ++number_of_played_turns;
             }
    	}
	}
	
	if (turn_flag ==true)
	{
	char Final_result = game_result(fields);
    print_result(Final_result);
	}
	
	return 0;
}


//                                                                                  ++<<<<<< Helper functions >>>>>>++
/**
Prints the rules of the game in Red at the begining of the program
*/
void print_rules()
{
    cout << "\033[31mRules of the game: \n 1) You will play as 'X' , Computer will play as 'O' \n 2) To win you need to have 'X' in 3 horozontal, vertical or diagonal line\n 3) If all fields are full and no one won then it is a Tie \n 4) You can only pick a feild from 0-8\n 5) You can't pick an already played feild\t\033[0m\n\n";
 
  // The comented code line is to print the same thing in black
  
 // cout<<"Rules of the game: \n 1) You will play as 'X' , Computer will play as 'O' \n 2) To win you need to have 'X' in 3 horozontal, vertical or diagonal line\n 3) If all fields are full and no one won then it is a Tie \n 4) You can only pick a feild from 0-8\n 5) You can't pick an already played feild\n";
}    

/**
Prints the diagram of tick tack toe
*/
void print_diagram(int Turn[])
{
    int R=0;
    int i=0;
    const string space="  ";
    string footer_header ="|-------|-------|-------|\n";
    
    cout<<footer_header;
    while(i<3)
    {
        for(int j=0;j<3;j++)
		{
		    cout<<"|   ";
		    if(Turn[R]==adjuster)
		    {
				cout<<"X\t";
		   	}
			else if(Turn[R] == 0)
			{ 
				cout<<R<<"\t";
			}
			else 
			{
				cout<<"O\t";
			}
			R++;
		}
	cout<<"|\n"<<footer_header;
    ++i;
	}
}

/**
Checks the board for any winning posibility
@param integer array with the feilds of the diagram
@return char of the winning number if exists or if no one won yet it returns 0
*/
char game_result(int x[]) 
{
    bool flag =true;
    char winning_numbers[8][3] ={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int t= 0;
    
    while( 8>t) 
    {
        if(flag== true && x[winning_numbers[t][0]] == x[winning_numbers[t][1]] &&  x[winning_numbers[t][1]] == x[winning_numbers[t][2]]&& x[winning_numbers[t][0]] != 0 )
        {
           flag= false;
           return x[winning_numbers[t][2]];
        }
        else if(flag ==true)
        {
         ++t;
        }
    }
    return 0;
}

/**
Tries playing one imaginary turn, will be used to calculate the best possible move 
@param character with the value indicating who is playing that turn 
@param integer array with feilds of the diagram
@return integer value of the possible winning player
*/
int tester_turn(char turn, int x[]) // using minmax algorithm
{
    int w = 0;
    int loop = 0;
    char result;
    int r = (adjuster*2);
    int s = adjuster;
    result = game_result(x);
 
    if (result==0) 
    {
        while (loop<9)
        {
          if(x[loop] == 0) 
          {
            x[loop] = turn;
            int current = tester_turn( adjuster*turn, x)*adjuster; //reccursion
            if(current > r) 
            {
                s = loop;
                r = current;
            }
            x[loop] = 0;
          } 
          ++loop;
        }
    }
    else if(result !=0)
    {
    return (turn*result);
    }
    
    if(adjuster == s)
    {
        return w;
    }
    else if (adjuster != s)
    {
      return r;
    }
}

/**
Tests to see where would be the best possble position for the computer to play using the tester_run function
@param integer array with the feilds of the diagram
@return charachter value with the best feild for the computer to play
*/
char pick_field(int x[]) 
{    
    char clone;
    char loop =0;
    char w = (adjuster*2); 
    char s = adjuster;
    
    while(loop<9)
    {
        if(x[loop] == 0)
        {
            x[loop] = 1;
            clone = tester_turn(adjuster, x)*adjuster;
            x[loop] = 0;
            if(w < clone) 
            {
                s = loop;
                w = clone;
            }
        }
        loop++;
    }
    return s;
}

/**
Prints messeges with tge status the game at the endof the game
@param character valueindicating which player won or if no on won
*/
void print_result(char x)
{
    if(x==1)
    {
        cout<<"\n        ++<<<<<Computer wins!>>>>>++"<<endl;
    }
    else if(adjuster == x)
    {
        cout<<"\n        ++<<<<<You win!>>>>>++"<<endl; 
    }
    else if(x==0)
    {
        cout<<"\n      ++<<<<<Tie, no one wins!>>>>>++"<<endl;
    }
    cout<<"          Thank you for playing =)\n";
}









