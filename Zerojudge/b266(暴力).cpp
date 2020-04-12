#include <iostream>
#define num 100
using namespace std;

int s[num][num], MM[num];
int R, C, M;
void action_1(){
    int s_cpy[num][num], i, j;
    for(i = 0; i < R; i++)
        for(j = 0; j < C; j++)
            s_cpy[C - 1 - j][i] = s[i][j] ;
    int temp = R; R = C; C = temp;
    for(i = 0; i < R; i++)
        for(j = 0; j < C; j++)
            s[i][j] = s_cpy[i][j];
}
void action_2(){
    int s_cpy[num][num], i, j; 

    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++)
            s_cpy[R - 1 - i][j] = s[i][j];
    }
    for(i = 0; i < R; i++)
        for(j = 0; j < C; j++)
            s[i][j] = s_cpy[i][j];
}
int main(){
    int i, j;
    while (cin >> R >> C >> M){
        for(int i = 0; i < R; i++)
            for(j = 0; j < C; j++)
                cin >> s[i][j];
        for(i = 0; i < M; i++)
            cin >> MM[i];
        for(i = M - 1; i >= 0; i--){
            if(MM[ i ] == 0)
                action_1();
            else
                action_2();
        }
        cout << R << " " << C << endl;
        for(i = 0; i < R; i++){
            for(j = 0; j < C - 1; j ++)
                cout << s[i][j] << " ";
            cout << s[i][C - 1] << endl;
        }
    }
    return 0 ;
}
