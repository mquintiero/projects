#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

char player1 = 'X';
char player2 = 'O';

void draw_board(){
    cout << " " << board[0][0] << " | " << " " << board[0][1] << " | " << " " << board[0][2] << endl;
    cout << "-------------" << endl;
    cout << " " << board[1][0] << " | " << " " << board[1][1] << " | " << " " << board[1][2] <<  endl;
    cout << "-------------" << endl;
    cout << " " << board[2][0] << " | " << " " << board[2][1] << " | " << " " << board[2][2] <<  endl;
}

pair<int, int> table[9] =  {make_pair(0,0), make_pair(0,1), make_pair(0,2),
                            make_pair(1,0), make_pair(1,1), make_pair(1,2),
                            make_pair(2,0), make_pair(2,1), make_pair(2,2)};

bool valid_play(int box){
    bool res = true;
    int row = get<0>(table[box]);
    int col = get<1>(table[box]);
    if(board[row][col] != ' '){
        res = false;
    }
    return res;
}

void setBox(int box, char player){
    int row = get<0>(table[box]);
    int col = get<1>(table[box]);
    board[row][col] = player;
}

char nextTurn(char player){
    if (player == player1){
        return player2;
    } else {
        return player1;
    }
}

bool check_end(){
    // Veo si alguien gano con alguna de las posible combinaciones
    for (int i = 0; i < 3; ++i) {
        // Veo si alguien tiene 3 iguales en alguna fila
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return true;
        }
        // Veo si alguien tiene 3 iguales en alguna columna
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return true;
        }
    }
    // Veo si alguien tiene 3 iguales en diagonal
    if (board[0][0] == board[1][1] && board[1][1] != ' ' && board[1][1] == board[2][2]){
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] != ' ' && board[1][1] == board[2][0]){
        return true;
    }
    return false;
}

bool free_boxes(){
    bool res = false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' '){
                res = true;
                break;
            }
        }
    }
    return res;
}

int main() {
    char current_player = player2;
    bool ongoing = free_boxes();
    bool winner = false;
    while (ongoing && !winner){ // Mientras nadie haya ganado, se sigue jugando (ver empate)
        draw_board();
        current_player = nextTurn(current_player);
        cout << "Player " << current_player << ", it´s your turn. Select your box: ";
        int box;
        cin >> box;
        while (!valid_play(box - 1)){
            cout << "Invalid play. Select another box: ";
            cin >> box;
        }
        // Si salgo de este while, la jugada es valida y pongo la casilla
        setBox(box - 1, current_player);
        // Chequeo si con esa jugada gano o empato.
        winner = check_end();
        ongoing = free_boxes();
        // Termina el turno
    }
    // Si salgo del while es porque alguien gano o empató, chequeo empate para ver que mensaje tirar
    draw_board();
    if (winner == true){
        cout << "Player " << current_player << " won" << endl;
    } else {
        cout << "It´s a draw" << endl;
    }
    return 0;
}
