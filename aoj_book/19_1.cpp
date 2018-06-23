#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

#define SEC_NUM 8
#define NIL -1

bool fullX[SEC_NUM];
bool fullY[SEC_NUM];
bool fullDiagPos[SEC_NUM * 2 - 1];
bool fullDiagNeg[SEC_NUM * 2 - 1];

stack<pair<int, int>> S;

void init(){
    for(int i = 0; i < SEC_NUM; i++){
        fullX[i] = false;
        fullY[i] = false;
        fullDiagPos[i] = false;
        fullDiagNeg[i] = false;
    }
}

void setQueen(int x, int y){
   fullX[x] = true;
   fullY[y] = true;
   fullDiagPos[x + y] = true;
   fullDiagNeg[x - y + SEC_NUM] = true;
}

void removeQueen(int x, int y){
   fullX[x] = false;
   fullY[y] = false;
   fullDiagPos[x + y] = false;
   fullDiagNeg[x - y + SEC_NUM] = false;
}

bool canPutQueen(int x, int y){
    if(!fullX[x] && !fullY[y] && !fullDiagPos[x + y] && !fullDiagNeg[x - y + SEC_NUM])
        return true;
    return false;
}

int getNextX(int x){
    x++;
    while(x < SEC_NUM){
        if(!fullX[x]){
            return x;
        }
        x++;
    }
    return NIL;
}

int getNextY(int x, int y){
    y++;
    while(y < SEC_NUM){
        if(canPutQueen(x, y)){
            return y;
        }
        y++;
    }
    return NIL;
}

void output(stack<pair<int,int>> S){
    char Queen[SEC_NUM][SEC_NUM];
    for(int i = 0; i < SEC_NUM; i++){
        for(int j = 0; j < SEC_NUM; j++){
            Queen[i][j] = '.';
        }
    }
    
    while(!S.empty()){
        pair<int, int> p = S.top(); S.pop();
        Queen[p.first][p.second] = 'Q';
    }

    for(int i = 0; i < SEC_NUM; i++){
        for(int j = 0; j < SEC_NUM; j++){
            printf("%c", Queen[i][j]);
        }
        printf("\n");
    }
 
}

int main(void){
    init();

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        setQueen(x, y);
        S.push(make_pair(x, y));
    }

    int x = -1;
    int y = -1;
    while((x = getNextX(x)) != -1){
        y = -1;
        while(true){
            y = getNextY(x, y);
            if(y != -1){
                S.push(make_pair(x, y));
                setQueen(x, y);
                break;
            }else{
                pair<int,int> before_pair = S.top(); S.pop();
                x = before_pair.first;
                y = before_pair.second;
                removeQueen(x, y);
                continue;
            }
        }
    }

    output(S);
}

