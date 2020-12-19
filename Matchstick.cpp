/* MarienBad game 

Sample Pattern:

|||||||||||
|||
|||||||
||||||||||

*/

#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
//function prototypes
void firstPlayer(string,string,vector<vector<string>>&); //first player game prototype
void secondPlayer(string,string,vector<vector<string>>&); // Second player Game prototype
void displayPattern(vector<vector<string>>&); //prototype for display the pattern

//This functions checks whether all matchsticks have been removed or not
bool isRemovedAll(vector<vector<string>>&patternCheck){
/*We are considering initially that there is no matchstick left
that's why "check" is true. So a nested loop is introduce to checkd 
whether there is any stick left or not. If a single non-space value 
is found, which simply means still some sticks are left so it will 
return false to the caller, which say that all sticks are not removed. */
	bool check = true;
	
	for(int i = 0; i<patternCheck.size(); i++){

		for(int j = 0; j<patternCheck[i].size(); j++){
	
			if(patternCheck[i][j] != " ") check = false;
		}

	}
		
	return check;
}
//this function displays the updated pattern each time it is called
void displayPattern(vector<vector<string>>&patternMatch){
	
    cout<<"\nHero You Go Your Game Pattern !!\n"<<endl;
	for(int i = 0; i<patternMatch.size(); i++){
         cout<<"\nRow"<<i+1<<">> ";
		for(int j=0; j<patternMatch[i].size(); j++){
	
			cout<<patternMatch[i][j];
		}		
		cout<<endl;
	}
}
// function for two player game
void TwoPlayerGame(vector<vector<string>>&pattern){
	
	string player1, player2;
	cout<<"\nEnter Player1 Name: ";
	cin>>player1;
	cout<<"Enter Player2 Name: ";
	cin>>player2;
	cout<<"\nWait !! Randomly Generating First Move for the first time...";
	//srand(time(NULL));
	int move = rand()%2 + 1 ;  // generate between 1 and 2
	if(move == 1) {
		cout<<"\nIt's "<<player1<<"'s turn!!";
		firstPlayer(player1,player2,pattern);
	}
	else if(move == 2){
		cout<<"\nIt's "<<player2<<"'s turn!!";
		secondPlayer(player2,player1,pattern);
	} 		
}
void firstPlayer(string player1,string player2,vector<vector<string>>&pattern) {
	
	bool isFinished = isRemovedAll(pattern); 
//if all sticks were removed then isFinished set to true
//if it is true then game is finished and will exit with successful status code 0/
	if(isFinished) {
		cout<<"\nGame has Finished !!\n";
		cout<<player1<<"\n Won the Game !!";
		exit(0);  
	}
		
	int r, sr; 
// r holds selected row number and sr holds sticks count that will be removed.
	cout<<"\n\nHey "<<""<<player1<<"!! Choose RowNumber to remove MatchSticks: ";
	cin>>r;
	start:
	cout<<"\nHow many sticks want to remove randomly from this row?? ";
	cin>>sr;
// No of removed sticks should be 1/2/3/7 as given in the question	
	if(sr == 1 || sr == 3 || sr == 5 || sr == 7){
/*if sticks removed count is greater than the available sticks for that row 
then will generate an error message.
checking r-1 because array index starts from 0 so if user selects row1 that 
is row0 for array.
Goto statements also used to change the flow.
*/	
		if(sr > pattern[r-1].size()) {
			cout<<"\nOut of Available Sticks, Choose Correct Count !!";
			goto start;
		}			
		else
		{
					//srand(time(NULL));
			for(int i = 0; i<sr; i++){
				
				int removedStick;
				stick:
				cout<<"\nEnter StickNumber"<<i+1<<" to remove: ";
				cin>>removedStick;
			
				if(removedStick > pattern[r-1].size()){
					cout<<"\nNot Available, Choose Correct Stick Number!!";
					goto stick;
				}
				else{
				if(pattern[r-1][removedStick-1] == " "){
					cout<<"\nAlready Removed !!";
				}
				else {
						pattern[r-1][removedStick-1] =" ";
						cout<<"\nRemoved Sticks are "<<removedStick<<" ";
			    	}	
				}						
		 	}
		 	
		    displayPattern(pattern); //once all sticks removed, pattern will be displayed 
		}
		
	} 
	else
	{
		cout<<"\nYou are allowed to remove only 1 or 3 or 5 or 7 Sticks !!";
		goto start;
	}
//first player turn is over that's why it will move to second player	
	secondPlayer(player2,player1,pattern); 	
}
void secondPlayer(string player2,string player1,vector<vector<string>>&pattern) {
     firstPlayer(player2,player1,pattern);
}
	
void HumanComputerGame(){
//Now if you implement this one also. just for this you need to use random generation
//Srand(time(0)) will change the seed value so that rand() function generate different value everytime
//rand() function generates a value from 0 to rand_max so if you want to generate random
//numbers between 1 to 6, then use rand()%6 + 1	
	cout<<"\nYou Can Implement This Like for TWoPlayers!!";
}

int main(){
// data structures for storing game configuration	
	int rows, cols, res;
			
	cout<<"Enter Row Count for the Pattern: ";
	cin>>rows;
    vector<vector<string>>matchPattern(rows);
	for(int i = 0; i<rows; i++){
		cout<<"\nEnter No. of MatchSticks for Row"<<i+1<<": ";
		cin>>cols;
		matchPattern[i] = vector<string>(cols);	
	}
		
	for(int i = 0; i<rows; i++){
		
		for(int j=0; j<matchPattern[i].size(); j++){
			matchPattern[i][j] = "|";
			//cout<<"Pushed sucessfully!!"<<endl;
		}
	}

//displaying your enter match pattern

displayPattern(matchPattern);

cout<<"\nChoose Game Option !!"<<endl;
cout<<"1) Two Player Game"<<endl;
cout<<"2) Human-Computer Game"<<endl;

cout<<"\nEnter Response(1/2): ";
cin>>res;

if(res == 1) TwoPlayerGame(matchPattern);
else if(res == 2)HumanComputerGame();
else cout<<"Invalid Choice!!";

return 0;
}

