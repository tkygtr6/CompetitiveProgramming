#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct dot{
    int x;
    int y;
}Dot;

bool is_used_r[100];

void init(int N){
    for(int i = 0; i < 100; i++){
        if(i < N){
            is_used_r[i] = false;
        }
    }
}


bool y_sort(Dot a, Dot b){
    if(a.y > b.y){
        return true;
    }else{
        return false;
    }
}

bool x_sort(Dot a, Dot b){
    if(a.x > b.x){
        return true;
    }else{
        return false;
    }
}

int calc_n_pairs(vector<dot> rdots, vector<dot> bdots, int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (is_used_r[j] == true){
                continue;
            }
            if(rdots[j].x < bdots[i].x){
                if(rdots[j].y < bdots[i].y){
                    is_used_r[j] = true;
                    cnt++;
                    break;
                }
            }
        }
    }
    return cnt;
}

int calc_n_pairs_(vector<dot> rdots, vector<dot> bdots, int n){
    init(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (is_used_r[j] == true){
                continue;
            }
            if(rdots[j].y < bdots[i].y){
                if(rdots[j].x < bdots[i].x){
                    is_used_r[j] = true;
                    cnt++;
                    break;
                }
            }
        }
    }
    return cnt;
}

int main(void){
    int N;
    scanf("%d", &N);
    init(N);

    vector<Dot> rdots;
    for(int i = 0; i < N; i++){
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        Dot d = {x, y};
        rdots.push_back(d);
    }
    sort(rdots.begin(), rdots.end(), y_sort);
    sort(rdots.begin(), rdots.end(), x_sort);

    vector<Dot> bdots;
    for(int i = 0; i < N; i++){
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        Dot d = {x, y};
        bdots.push_back(d);
    }
    sort(bdots.begin(), bdots.end(), y_sort);
    sort(bdots.begin(), bdots.end(), x_sort);

    int cnt = calc_n_pairs(rdots, bdots, N);

    sort(rdots.begin(), rdots.end(), x_sort);
    sort(rdots.begin(), rdots.end(), y_sort);
    sort(bdots.begin(), bdots.end(), x_sort);
    sort(bdots.begin(), bdots.end(), y_sort);
    
    int cnt_ = calc_n_pairs_(rdots, bdots, N);

    printf("%d\n", max(cnt, cnt_));

    return 0;
}
