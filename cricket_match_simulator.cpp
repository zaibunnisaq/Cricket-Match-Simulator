/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////FINAL PROJECT PROGRAMMING FUNDAMENTALS//////////////////////////
//////////////////////////////////ZAIB UN NISA///////////////////////////////////////////
////////////////////////////////////21I-0383/////////////////////////////////////////////
////////////////////////////////////SECTION-F////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
/*Best bowler function to ffind the bowler who has taken maximun wickets during the match
I took names and induvidual wickets as arguments and compared the two arrays with maximum arrays initialized at -10 for comparison*/

void Best_Bowler (string names_A[12], string names_B[12], int ind_wickets[12], int ind_wickets2[12]){
	int max = -10, index =0;
	for(int i = 0; i<11; i++){
		if(ind_wickets[i] > max){
			index = i;
			max = ind_wickets[i];
		}
	}
	int max2 = -10, index2 =0;
	for(int i = 0; i<11; i++){
		if(ind_wickets2[i] > max2){
			index2 = i;
			max2 = ind_wickets2[i];
		}
	}
	if(max > max2){
		cout << "BOWLER OF THE MATCH IS: " << names_A[index] << " with the wickets taken " << ind_wickets[index] << endl;
	}
	else{
		cout << "BOWLER OF THE MATCH IS: " << names_B[index2] << " with the wickets taken " << ind_wickets2[index2] << endl;
	}
}
/*bowling card function that shows the bowlers and the wickets they have taken along with the avg balling rate*/
void Bowling_Card(string names_A[12], int ind_wickets[12]){
	cout << setw(60) << "======================================================" << endl;
	cout << setw(8) << "||" << setw(15) << "Player name" << setw(15) << "Wickets" << setw(10) << "AVG" << setw(10) << " " << setw(10) << "" << setw(7) << "" << endl;
	for (int a = 10; a >= 5; a--)
	{
		float avg = ind_wickets[a]*1.75;
		cout << setw(60) << "======================================================" << endl;
		cout << setw(8) << "||" << setw(12) << names_A[a] << setw(12) << ind_wickets[a] << setw(15) << avg << setw(6) << "" << endl;
	}
	cout << setw(60) << "======================================================" << endl;
	cout << endl;
}
void Best_Batman (string names_A[12], string names_B[12], int scored[12], int scored2[12]){
	int max = -10, index =0;
	for(int i = 0; i<11; i++){
		if(scored[i] > max){
			index = i;
			max = scored[i];
		}
	}
	int max2 = -10, index2 =0;
	for(int i = 0; i<11; i++){
		if(scored2[i] > max2){
			index2 = i;
			max2 =scored2[i];
		}
	}
	if(max > max2){
		cout << "BATSMAN OF THE MATCH IS: " << names_A[index] << " with the score " << scored[index] << endl;
	}
	else{
		cout << "BATSMAN OF THE MATCH IS: " << names_B[index2] << " with the score " << scored2[index2] << endl;
	}


}
// runrate calculator using formula and conversion to double using static cast of existing integer score and number of overs
double runrate (int output_overs, int total_score){
	double rr = static_cast<double>(total_score)/static_cast<double>(output_overs);
	return rr;
}
/*Best batsman function to find the bowler who has taken maximun wickets during the match
I took names and induvidual wickets as arguments and compared the two arrays with maximum arrays initialized at -10 for comparison*/
void Batting_Card(string names_A[12], int scored[12], int& total_score, int fours[12], int sixes[12]) {
	cout << setw(75) << "=====================================================================" << endl;
	cout << setw(8) << "||" << setw(15) << "Player name" << setw(15) << "Runs scored" << setw(10) << "4s" << setw(10) << "6s " << setw(10) << "Avg" << setw(7) << "||" << endl;
	for (int a = 0; a <= 10; a++)
	{
		cout << setw(75) << "=====================================================================" << endl;
		//cout << setw(8) << "||" << setw(36) << "||" << endl;
		float avg = scored[a]/7.0;
		cout << setw(8) << "||" << setw(12) << names_A[a] << setw(12) << scored[a] << setw(15) << fours[a] << setw(10) << sixes[a] << setw(12) << setprecision(2) << avg << setw(6) << "||" << endl;
		//	cout << setw(8) << "||" << setw(36) << "||" << endl;
		total_score += scored[a];
	}
	cout << setw(75) << "=====================================================================" << endl;
	cout << endl;
	cout << "*************************" << endl;
	cout << "Total runs by team: " << total_score << endl;
	cout << "*************************" << endl;
}
/* current overs to be shown in the live score card*/
void current_over (float balls, int i)
{	
	cout << "Current over: " << balls << "." << i << endl;
}
/* to make my code elegantt i made a function of the table lines to be printed*/
void aesthetic()
{
	cout << "=====================================" << endl; 
}
// to calculate the total score of each inning by incrementing score of each player in the variable of total score
int Total(int total_score, int scored[])
{
	//total_score += scored[a];
	return total_score;
}
/* to make my code elegantt i made a function of the welcome lines to be printed*/
void Welcome()
{
	cout << setw(48) << "***********************************" << endl;
	cout << setw(15) << "**" << setw(33) << "**" << endl;
	cout << setw(15) << "**" << setw(20) << " WELCOME TO CRICKET STIMULATOR " << setw(2) << "**" << endl;
	cout << setw(15) << "**" << setw(33) << "**" << endl;
	cout << setw(48) << "***********************************" << endl;
}
/* I made two functions of batting randomizer
1 that prints numbers from 0 to 6
1 that print 0 - 100
I used the max function in a condition with the ration 10:90 and then 50:50 and calculated the players that got out in that ratio
then I used the randomizer func for the rest to randomly allocate score from 0 to 6 */

int batting_random_max()
{
	return rand() % 100;
}
int batting_randomizer()
{
	int a = rand() % 7 - 0;
	return a;
}
/* read over func is to read the numbers of overs placed in my file */
int read_overs()
{
	ifstream myFile;
	int overs;
	myFile.open("configuration.txt", ios::out); // read mode from my files the overs and team name
	if (!myFile)
	{
		cout << "failed to open";
		return 0;
	}

	else
	{
		while (myFile >> overs)
		{
		}
		myFile.close();
		return overs;
	}
}
/* read over func is to read the string of teams placed in my file
i learned a way to pick two words from the same line from a file */

void read_teams()
{
	ifstream myFile2;
	string TeamA, TeamB;
	myFile2.open("teams.txt", ios::out);

	if (!myFile2)
	{
		cout << "failed to open file";
	}

	else
	{
		while (myFile2 >> TeamA >> TeamB)
		{
			cout << setw(35) << "Today's match is between " << TeamA << " vs " << TeamB << endl;
		}
		myFile2.close();
	}
}
/* toss the coin func which gives one random number either 0 or 1
output 0 decides heads meanwhile 1 decides tails*/
int coinToss()
{
	int Toss;
	Toss = rand() % 2;
	return Toss;
}
/*most of this game is done here, which means i applied all logics and condition here */
void innings(int output_overs, string names_A[12], int scored[12], int& wickets, string names_B[12], int fours[12], int sixes[12], int ind_wickets[12])
{
	int player = 0;	 // initial player
	int player2 = 1; // intitial player 2
	float bat = 0;	 // batting randomizer
	float bat2 = 0;	 // batting randomizer
	int flag = 0;	//for the logic that switches my players
	int bowler = 10;	//for the logic of bowling
	for (int balls = 1; balls <= output_overs; balls++)		//outer loop that runs for the total number of balls
	{
		if (player > 10 || player2 > 10)				//players more than 11 the loop should break as all players are outand next inning is called out
		{ // player 1 and 2 shouldnt be more then 10
			break;
		}
		aesthetic();
		cout << "NEW OVER: " << balls << endl;			//for live score card to show that new over has started
		cout << endl;

		for (int i = 1; i <= 6; i++)					// inner loop that runs for each over as each over has 6 balls
		{

			aesthetic();
			if (bowler < 5) {
				bowler = 10;					//logic: as the last 5 payers of the opponent team are bowlers so to continue with the same bowlers
			}
			cout << "Current bowler:	    " << names_B[bowler] << endl; // hence to show the current bowler dueing the over
			aesthetic();

			//	TO SHOW CURRENT OVERS
			current_over( balls,i);

			aesthetic();
			cout << "Current Player "
			     << "  Run "
				 << "   Total score " << endl;

			bat = batting_randomizer();			// function calling for the randomizer bw 0-6
			bat2 = batting_random_max();		// function calling for the randomizer of probabilty logic

			if (player <= 5 || player2 <= 5)
			{

				if (bat2 >= 0 && bat2 <= 10)		
				{ // 10% PROBABILITY OF THE FIRST 5 PLAYERS LOGIC
					wickets++;

					bat = -1;
					{
						if(player >=5 || player <=11){	//logic: as only players 5-11 can take down wickets so condition fulfills
						ind_wickets[bowler]+=1;
						}
						if (flag == 1)		//initially player changes
						{
							cout << setw(10) << names_A[player] << setw(10) << bat << setw(10) << " is OUT " << setw(5) << scored[player] << endl;
							if (player < player2)
							{
								player = player2;
							}
							flag = 0;		// logic that switches player num
							player++;
						}
						else if (flag == 0)			// logic that switches player num
						{
							cout << setw(10) << names_A[player2] << setw(10) << bat << setw(10) << " is OUT " << setw(5) << scored[player2] << endl;
							if (player2 < player)
							{
								player2 = player;
							}
							flag = 1;				// logic that switches player num
							player2++;
						}
						if (player > 10 || player2 > 10)		//loop to break if layer exceeds 10
						{ // player 1 and 2 shouldnt be more then 10
							break;
						}
					}
				}

				else
				{

					if (bat == 1 || bat == 3 || bat == 5)
					{ // 90% PROBABILTY TO SCORE MORE THAN 0 LOGIC
						// cout << "odd " << endl;
						if (flag == 0)	//switch the player
						{
							scored[player] += bat;
							cout << setw(10) << names_A[player] << setw(10) << bat << setw(10) << scored[player] << endl;
							flag = 1;			// logic that switches player num
						}
						else if (flag == 1)		// logic that switches player num
						{
							scored[player2] += bat;
							cout << setw(10) << names_A[player2] << setw(10) << bat << setw(10) << scored[player2] << endl;
							// cout << "switch" << endl;
							flag = 0;			// logic that switches player num
						}
					}

					else
					{

						// cout << "even\n" << endl;
						if (flag == 0)		// logic that switches player num
						{
							scored[player] += bat;
							cout << setw(10) << names_A[player] << setw(10) << bat << setw(10) << scored[player] << endl;

							if(bat == 4){
							cout << "\nIt's a FOUR!!\n";		// when player score a four
							fours[player]+=1;
							}
							if(bat == 6){
								cout << "\nIt's a SIX!!\n";
							sixes[player]+=1;
							}
						}

						else if (flag == 1)	// logic that switches player num
						{
							scored[player2] += bat;
							cout << setw(10) << names_A[player2] << setw(10) << bat << setw(10) << scored[player2] << endl;
							if(bat == 4){
							cout << "\nIt's a FOUR!!\n";
							fours[player2]+=1;
							}
							if(bat == 6){
								cout << "\nIt's a SIX!!\n";
							sixes[player2]+=1;
							}

						}
					}
				}
			} // end of players ki condition wala loop

			else if (player >= 5 || player <= 10 || player2 <= 10 || player2 >= 5)
			{ // PLAYERS BETWEEN 6 TO 11

				if (bat2 >= 0 && bat2 <= 50)
				{ // 50% PROBABILITY OF THE PLAYERS 6 TO 11 LOGIC
					wickets++;
					
					bat = -1;
					{
						if(player >=5 || player <=11){ //wickets taken by bowlers
						ind_wickets[bowler]+=1;
						}
						if (flag == 1)	// logic that switches player num
						{
							cout << setw(10) << names_A[player] << setw(10) << bat << setw(10) << " is OUT " << setw(10) << scored[player] << endl;
							if (player < player2)
							{
								player = player2;
							}
							flag = 0;		// logic that switches player num
							player++;
						}
						else if (flag == 0)				// logic that switches player num
						{
							cout << setw(10) << names_A[player2] << setw(10) << bat << setw(10) << " is OUT " << setw(10) << scored[player2] << endl;
							if (player2 < player)
							{
								player2 = player;
							}
							flag = 1;			// logic that switches player num
							player2++;
						}
						if (player > 10 || player2 > 10)
						{ // player 1 and 2 shouldnt be more then 10
							break;
						}
					}
				}

				else
				{
					if (bat == 1 || bat == 3 || bat == 5)
					{ // 50% PROBABILTY TO SCORE MORE THAN 0 LOGIC FOR 6 TO 11 PLAYERS
						// cout << "odd " << endl;
						if (flag == 0)			// logic that switches player num
						{
							scored[player] += bat;
							cout << setw(10) << names_A[player] << setw(10) << bat << setw(10) << scored[player] << endl;
							flag = 1;		// logic that switches player num
						}
						else if (flag == 1)				// logic that switches player num
						{
							scored[player2] += bat;
							cout << setw(10) << names_A[player2] << setw(10) << bat << setw(10) << scored[player2] << endl;
							// cout << "switch" << endl;
							flag = 0;			// logic that switches player num
						}
					}

					else
					{

						// cout << "even\n" << endl;
						if (flag == 0)			// logic that switches player num
						{
							scored[player] += bat;
							cout << setw(10) << names_A[player] << setw(10) << bat << setw(10) << scored[player] << endl;

							if(bat == 4){
							cout << "\nIt's a FOUR!!\n";
							fours[player]+=1;
							}
							if(bat == 6){
								cout << "\nIt's a SIX!!\n";
							sixes[player]+=1;
							}
						}

						else if (flag == 1)					// logic that switches player num
						{
							scored[player2] += bat;
							cout << setw(10) << names_A[player2] << setw(10) << bat << setw(10) << scored[player2] << endl;
							if(bat == 4){
							cout << "\nIt's a FOUR!!\n";
							fours[player2] +=1;
							}
							if(bat == 6){
								cout << "\nIt's a SIX!!\n";
							sixes[player2] +=1;
							}

						}
					}
				}
			} 
			
			aesthetic();
			cout << "Press any key to throw a ball" << endl;
			cin.get();
			// TO clear DATA EVERYTIME
			system("clear");
		} // end of balls wala loop

		// change of batsman when the over is finished
		if (flag == 0)
		{
			scored[0] += bat;
			flag = 1;
		}
		else if (flag == 1)
		{
			scored[1] += bat;
			flag = 0;
		}
		bowler--; //bowlers frm 5-11

	}// end of overs wala loop
	// TO clear DATA EVERYTIME
	system("clear");

}

int main()
{
	int const size = 12;
	int* scored = new int[size] {};
	int* scored2 = new int[size] {};
	int total_score = 0,
	total_score2 = 0,
		b_faced[size],
		b_bowled[size],
		runs_given[size],
		wickets1 = 0,
		wickets2 = 0,
		fours[size] = {},
		fours2[size] = {},
		sixes[size] = {},
		sixes2[size] = {},
		ind_wickets[size] = {},
		ind_wickets2[size] = {};

	int runs = 0;

	string names_A[size] = {};
	string names_B[size] = {};

	srand(time(NULL));
	
	// FUNCTION FOR WELCOME
	Welcome();
	int output_overs = read_overs();

	cout << "         	 Total Overs of the match are: " << output_overs << endl;

	// Calling function to toss between the two teams

	int output = coinToss();
	// calling function to read the names of the team from file
	read_teams();
	// TO TAKE INPUT FROM USER FOR TEAM A

	cout<<"Enter the names of TEAM A: \n";
	for(int i = 0; i <11; i++)
	{
		cin>> names_A[i];
	}
	//TO TAKE INPUT FROM USER FOR TEAM B
	cout<<"Enter the names of TEAM B: \n";
	for(int i = 0; i <11; i++)
	{
		cin>> names_B[i];
	}

	getchar();
	// TO clear DATA EVERYTIME
	system("clear");
	aesthetic();

	cout << setw(5) << "Players" << setw(25) << "Players" << endl;
	cout << endl;
	cout << setw(5) << "TEAM A" << setw(23) << "TEAM B" << endl;
	aesthetic();
	for(int i = 0; i <11; i++){
	cout << setw(5) << names_A[i] << setw(22) << names_B[i] << endl;
	aesthetic();
	}


	cout << "\n\nLet's TOSS!!!" << endl;
	aesthetic();
	cout << "Press any key to continue" << endl;

	cin.get();
	// TO clear DATA EVERYTIME
	//system("clear");

	if (output == 0)
	{
		cout << setw(48) << "***********************************" << endl;
		cout << setw(15) << "**" << setw(33) << "**" << endl;
		cout << setw(15) << "**" << setw(20) << " HEADS " << setw(13) << "**" << endl;
		cout << setw(15) << "**" << setw(33) << "**" << endl;
		cout << setw(48) << "***********************************" << endl;
		cout << setw(40) << "Team A won the toss" << endl;
		cout << setw(48) << "Team A will do the batting first." << endl;

		aesthetic();
		cout << "Press any key to continue" << endl;
		cin.get();

		// TO clear DATA EVERYTIME
		system("clear");
		innings(output_overs, names_A, scored, wickets1, names_B, fours2, sixes2, ind_wickets2);
		innings(output_overs, names_B, scored2, wickets2, names_A, fours, sixes, ind_wickets);

	}
	else if (output == 1)
	{
		cout << setw(48) << "***********************************" << endl;
		cout << setw(15) << "**" << setw(33) << "**" << endl;
		cout << setw(15) << "**" << setw(20) << " TAILS " << setw(13) << "**" << endl;
		cout << setw(15) << "**" << setw(33) << "**" << endl;
		cout << setw(48) << "***********************************" << endl;
		cout << setw(40) << "Team B won the toss" << endl;
		cout << setw(48) << "Team B will do the batting first." << endl;

		aesthetic();
		cout << "Press any key to continue" << endl;
		cin.get();

		// TO clear DATA EVERYTIME
		system("clear");
		innings(output_overs, names_B, scored2, wickets2, names_A, fours2, sixes2,ind_wickets2);
		innings(output_overs, names_A, scored, wickets1, names_B, fours, sixes,ind_wickets);
	}
	aesthetic();
	cout << "---INNINGS OF TEAM A INDIA---" << endl;
	aesthetic();
	Batting_Card(names_A, scored, total_score, fours, sixes);
	cout << "Wickets: " << wickets1 << endl;
	cout << "Run rate: " << runrate(output_overs,total_score) << endl;

	//SECOND INNINGS
	aesthetic();
	cout << "---INNINGS OF TEAM B PAKISTAN---" << endl;
	aesthetic();
	Batting_Card(names_B, scored2, total_score2, fours2, sixes2);
	cout << "Wickets: " << wickets2 << endl;
	cout << "Run rate: " << runrate(output_overs,total_score2) << endl;

	cout << "\n\n";

	if (total_score > total_score2) {
        aesthetic();
        cout << "---TEAM 1 INDIA WON THE GAME---" << endl;
        aesthetic();
        cout << "WITH THE SCORE: " << total_score << endl;
        aesthetic();
        cout << "AGAINST THE TARGET: " << total_score2 << endl;

    }
    else {
        aesthetic();
        cout << "---TEAM 2 PAKISTAN WON THE GAME---" << endl;
        aesthetic();
        cout << "WITH THE SCORE: " << total_score2 << endl;
        aesthetic();
        cout << "AGAINST THE TARGET: " << total_score << endl;
    }

    aesthetic();
	cout << "Press any key to PRINT BOWLING INFO " << endl;
	cin.get();
	system("clear");


	aesthetic();
	cout << "---BOWLING INFO---" << endl;
	aesthetic();
	cout << endl;
	aesthetic();
	cout << "---SCORE BOARD OF TEAM A PAKISTAN---" << endl;
	aesthetic();
	Bowling_Card(names_A, ind_wickets);
	aesthetic();
	cout << "---SCORE BOARD OF TEAM B INDIA---" << endl;
	aesthetic();
	Bowling_Card(names_B, ind_wickets2);

	cout << "Press any key to PRINT MATCH SUMMARY" << endl;
	cin.get();
	system("clear");
	aesthetic();
	cout << "MATCH SUMMARY" << endl;

    if (total_score > total_score2) {
        aesthetic();
        cout << "---TEAM 1 INDIA WON THE GAME---" << endl;
        aesthetic();
        cout << "WITH THE SCORE: " << total_score << endl;
        aesthetic();
        cout << "AGAINST THE TARGET: " << total_score2 << endl;


    }
    else {
        aesthetic();
        cout << "---TEAM 2 PAKISTAN WON THE GAME---" << endl;
        aesthetic();
        cout << "WITH THE SCORE: " << total_score2 << endl;
        aesthetic();
        cout << "AGAINST THE TARGET: " << total_score << endl;

    }

    cout << "===================================================" << endl;
    Best_Batman (names_A, names_B,scored, scored2);
    cout << "===================================================" << endl;
    Best_Bowler (names_A, names_B,ind_wickets,ind_wickets2);
    cout << "===================================================" << endl;
    cout << "\nMATCH HAS ENDED :) CHEERS!!\n\n\n\n";


	delete[] scored;
	scored = nullptr;
	delete[] scored2;
	scored2 = nullptr;
	return 0;
}