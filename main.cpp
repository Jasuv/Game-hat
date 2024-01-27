#include"main.h"

const string library = "games.txt";
string line;
ofstream fout;
ifstream fin;

void printIntro() {
    cout << endl;
    cout << "   _____           ________.__         .__         ___________" << endl
         << "  /     \\ _____   /  _____/|__| ____   |  |__ _____\\__    ___/" << endl
         << " /  \\ /  \\\\__  \\ /   \\  ___|  |/ ___\\  |  |  \\\\__  \\ |    |   " << endl
         << "/    Y    \\/ __ \\\\    \\_\\  \\  \\  \\___  |   Y  \\/ __ \\|    |   " << endl
         << "\\____|__  (____  /\\______  /__|\\___  > |___|  (____  /____|   " << endl
         << "        \\/     \\/        \\/        \\/       \\/     \\/         " << endl << endl;
    cout << " - \"add <game>\" to add a new game" << endl
         << " - \"rm <game>\" to remove a game" << endl
         << " - \"games\" to print games in your library" << endl
         << " - \"roll\" to roll for a game" << endl
         << " - \"help\" to print commands" << endl;
}

void addGame(string& game) {
    // check if the game is already in the library
    fin.open(library);
    if (!fin.is_open()) {
        cout << "there was a problem opening the library ):" << endl;
        return;
    } else {
        while(getline(fin, line)) {
            if (line == game) {
                cout << game << " is already in your library!" << endl;
                return;
            }
        }
        fin.close();
    }
    // add the game to the end of the file
    fout.open("games.txt", ofstream::app);
    if (!fout.is_open()) {
        cout << "there was a problem opening the library ):" << endl;
        return;
    } else {
        fout << game << endl;
        fout.close();
        cout << "added " << game << " to the library..." << endl;
    }
    return;
}

void removeGame(string& game) {
    int counter = 0;
    // try to locate the game in the library
    fin.open(library);
    if (!fin.is_open()) {
        cout << "there was a problem opening the library ):" << endl;
        return;
    }
    while(getline(fin, line)) {
        if (line == game) {
            break;
        }
        counter++;
    }
    if (fin.eof()) {
        cout << "can't find " << game << " in your library";
        return;
    }
    fin.close();


    // WORK ON THIS
    fout.open("games.txt", ofstream::app);
    if (!fout.is_open()) {
        cout << "there was a problem opening the library ):" << endl;
        return;
    } else {
        fout << game;
        fout.close();
        cout << "added " << game << " to the library..." << endl;
    }
    return;

}

void viewGames(queue<string>& q) {
    fin.open(library);
    if (!fin.is_open()) {
        cout << "there was a problem opening the library ):" << endl;
        return;
    }
    while(getline(fin, line)) {
        q.push(line);
    }
    fin.close();
    if (q.size() == 0) {
        cout << "there are no games in your library" << endl;
        return;
    }
    while (q.size() > 0) {
        cout << q.front() << endl;
        q.pop();
    }
}

void getGame(queue<string>& q, string& game) {
        fin.open(library);
    if (!fin.is_open()) {
        cout << "there was a problem opening the library ):" << endl;
        return;
    }
    while(getline(fin, line)) {
        q.push(line);
    }
    fin.close();
    if (q.size() == 0) {
        cout << "there are no games in your library" << endl;
        return;
    }
    int n = rand() % q.size();
    for (int i = 0; i < n; i++) { q.pop(); }
    game = q.front();
    cout << "today we are playing";
    for (int i = 0; i < 3; i++) { cout << "."; Sleep(1000); }
    cout << game << "!" << endl;
}

int main() {
    string in;
    string game;
    queue<string> q;
    printIntro();
    while(1) {
        cout << endl;
        getline(cin, in);
             if (in.substr(0, 3) == "add") { addGame(game = in.substr(4)); } 
        else if (in.substr(0, 2) == "rm") { removeGame(game = in.substr(3)); }
        else if (in == "games") { viewGames(q); } 
        else if (in == "roll") { getGame(q, game); } 
        else if (in == "help") { printIntro(); } 
        else { cout << "please enter a valid command..." << endl; }
    }
    return 0;
}