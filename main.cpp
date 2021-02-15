#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <stdio.h>
#include <MMsystem.h>
using namespace std;
void permuteWord(char items[], int len);
int scramble (string answer, string jumble);
bool CheckGuess(string &g, string answer);


int main(int argc, char *argv[])
{
	int size, len;
	string *w_bank;
	string number, word, answer;
	
	ifstream myfile (argv[1]);
	
	if(!myfile.is_open())
	{
		cout << "The file is not succesfully open" << endl;
		exit(1);
	}
	
	getline (myfile, number);
	size=atoi(number.c_str());
	if(size%1!=0)
		cout << "The first line is a number" << endl;
	w_bank= new string[size];
	
	for (int i=0; i < size; i++)
	{
		myfile >> w_bank[i];
	}
	
	srand(time(NULL));
	int index = rand()%size;
	
	word=w_bank[index];
	
	len=word.length();
	char Words[len+1];
	strcpy(Words, word.c_str());
	permuteWord (Words, len);
	
	answer=Words;
	
	scramble (word, Words);
	
	myfile.close();
	
	delete[] w_bank;
	w_bank=NULL;
	return 0;
}

void permuteWord(char items[], int len)
{	
	for(int i=len-1; i > 0; --i)
	{
		int r = rand() % i;
		int temp = items[i];
		items[i] = items[r];
		items[r] = temp;
	}	
}

int scramble (string answer, string jumble)
{
	/*PlaySound(TEXT("C:\Users\user\Music\music\\song.wav"), NULL, SND_SYNC);*/
	
	string guess;
	
	cout << "\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to guess the word.\n";
	cout <<endl;
	
	cout << "The jumbled word is: " << jumble;
	
	system("COLOR 5f");
	
	while(true)
	{
		cout << "\nYour guess: ";
		cin >> guess;
		
		CheckGuess(guess,answer);
	}
	
	return 0;
}

bool CheckGuess(string &g, string answer)
{	int tries=0;
	tries++;
	
	if (g==answer)
	{
		cout << "Congratulations! You have guessed the word in " << tries << endl;
		cout << "Thank you for playing Word Jumble!";
		exit (1);
	}
	
	else if (tries>10)
	{
		cout << "Too many tries...You Lose!" << endl;
		exit (1);
	}	
	
	else
	{
		cout << "Sorry, that is incorrect guess.";
		return false; 
	}
}
