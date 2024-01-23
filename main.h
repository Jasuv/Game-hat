#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// prints the intro
void printIntro();

// adds a game to the hat
string addGame(ifstream& fin, ofstream& fout, string& game);
/* 
 * ask input for game
 * open games.txt to read
 * read until EOF:
 *      if line == game:
 *      return "this game is already in hat"
 * open games.txt to write
 * add game to file
 * return "added {game} to hat"
 */

// removes a gmae from the hat
string removeGame(ofstream& fout, string& line, string& game);
/*
 * ask input for game
 * open games.txt to read
 * read until EOF:
 *      if line == game:
 *          replace line with \b
 *          return "{game} was removed from the hat"
 * return "couldn't find {game} in hat"
 */

// prints a random game from the hat
string getGame();
/*
 * establish random generator
 * open games.txt to read
 * read until EOF:
 *      x <- number of lines
 * y <- pick a numebr between 0 and x-1
 * read until EOF:
 *      if pos = y return "let's play {game}!"
 * return "whoops something didn't work"
 */
