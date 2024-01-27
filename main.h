#include<stdlib.h>
#include<iostream>
#include<windows.h> // for sleep function
#include<string>
#include<queue>
#include<fstream>
#include<vector>

using namespace std;

// prints the intro
void printIntro();

// adds a game to the hat
void addGame(string& game);
/* 
 * return "this game is already in hat" if checkGame
 * open library to write
 * add game to library
 * return "added {game} to hat"
 */

// removes a gmae from the hat
void removeGame(string& game);
/*
 * get input for game
 * return "this game is already in hat" if checkGame
 * read until EOF:
 *      if line == game:
 *          replace line with \b
 *          return "{game} was removed from the hat"
 * return "couldn't find {game} in hat"
 */

// prints the library
void viewGames();

// prints a random game from the hat
void getGame(string& game);
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
