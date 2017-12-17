#include <iostream>
using namespace std;

void ClearBoard();
void PrintBoard();
void Info();
void TempatBidak(int col, int row);
void GetInput();
void CheckWin();
//kalkulasi
int IBoard[3][3] = {0};
//characters
char Board[3][3];
int turn = 1;
int BidakValue = 0;
bool Play = true;

int main(int argc, const char * argv[])
{
    Info();
    ClearBoard();
    PrintBoard();
    int Command = 0;
    cin >> Command;
    if (Command == 2)
        Play = false;
    int BoardFull = 0;
    while (Play) {
        GetInput();
        CheckWin();
        BoardFull++;
        //Check Game draw
        if (BoardFull == 9) {
            cout << "Draw" << endl;
            Play = false;
        }
    }

    return 0;
}

void ClearBoard() {
    for (int i = 0; i < 3; i++)
		for (int j=0; j < 3; j++)
			Board[i][j] = '-';
}

void PrintBoard () {
    cout << "\t1 \t2 \t3 " << endl;
    cout << "1\t" << Board[0][0] << "  \t" << Board[1][0] << "  \t" << Board[2][0] << endl;
    cout << "2\t" << Board[0][1] << "  \t" << Board[1][1] << "  \t" << Board[2][1] << endl;
    cout << "3\t" << Board[0][2] << "  \t" << Board[1][2] << "  \t" << Board[2][2] << endl;
    
    /* for (int i=0; i < 3; i ++)
	{
		for (int j=0; j < 3; j++)
		{
			cout << Board[j][i] << "\t";
			if (j < 2)
				cout << "|\t";
		}
		if (i < 2)
			cout << "\n------------------\n";
	} */
    cout << endl << endl;
}

void Info() {
    cout << "Commands: \n1.Mulai game\n2.Keluar" << endl;
}

void TempatBidak(int row, int col) {
    //pergantian lambang tiap putaran
    char piece;
    if (turn % 2 == 0) {
        piece = 'O';
    }
    else {
        piece = 'X';
    }
    Board[row][col] = piece;
    
    
    if (piece == 'O') {
        BidakValue = -1;
    }
    else if (piece == 'X') {
        BidakValue = 1;
    }
    IBoard[row][col]  = BidakValue;
    
    turn++;
    
    PrintBoard();
}

void GetInput() {
    //Check Turn
    if (turn % 2 == 0)
        cout << "Player 2 turn." << endl;
    else
        cout << "Player 1 turn." << endl;
    
    cout << "masukkan lokasi ('baris(spasi)kolom / baris(enter)kolom'): " << endl;
    int row = 0, col = 0;
    cin >> row >> col;
    //Check input valid
    if (row > 3 || row < 1 || col > 3 || col < 1) {
        cout << "Invalid, try again." << endl;
        cin >> row >> col;
    }
    if (IBoard[col - 1][row - 1] != 0) {
        cout << "Tempat sudah terambil, try again." << endl;
        cin >> row >> col;
    }
    TempatBidak(col - 1, row - 1); 
}

void CheckWin() {
    bool WinX = false;
    bool WinO = false;
    //Check Horizontal
    for (int i = 0; i < 3; i++) {
        int TotalValue = 0;
        for (int j = 0; j < 3; j++) {
            TotalValue += IBoard[i][j];
        }
        if (TotalValue == 3) {
            WinX = true;
        }
        else if (TotalValue == -3) {
            WinO = true;
        }
    }
    //Check Vertical
    for (int j = 0; j < 3; j++) {
        int TotalValue = 0;
        for (int i = 0; i < 3; i++) {
            TotalValue += IBoard[i][j];
        }
        if (TotalValue == 3) {
            WinX = true;
        }
        else if (TotalValue == -3) {
            WinO = true;
        }
    }
    //Check Diagonal
    int TotalValue = 0;
    TotalValue = IBoard[0][0] + IBoard[1][1] + IBoard[2][2];
    if (TotalValue == 3) {
        WinX = true;
    }
    else if (TotalValue == -3) {
        WinO = true;
    }
    TotalValue = IBoard[0][2] + IBoard[1][1] + IBoard[2][0];
    if (TotalValue == 3) {
        WinX = true;
    }
    else if (TotalValue == -3) {
        WinO = true;
    }
    //Jika menang
    if (WinX) {
        cout << "Player 1 Wins";
        Play = false;
    }
    if (WinO)  {
        cout << "Player 2 Wins";
        Play = false;
    }
}
