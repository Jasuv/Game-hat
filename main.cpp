#include"main.h"

void printIntro() {
        cout << "logo smt idk";
        cout << "enter [n] to add a new game" << endl
             << "enter [d] to remove a game" << endl
             << "enter [r] to roll for a game" << endl;
}

string addGame(ifstream& fin, ofstream& fout, string& game) {

}

string removeGame(ofstream& fout, string& line, string& game) {

}

string getGame() {

}

int main() {
    char in;
    string line;
    string game;
    ofstream fout;
    ifstream fin;

    while(1) {
        printIntro();
        cin >> in;
        switch(in) {
            case 'n':
                addGame(fin, fout, game); break;
            case 'd':
                removeGame(fout, line, game); break;
            case 'r':
                cout << getGame() << endl; break;
        }
    }
    return 0;
}