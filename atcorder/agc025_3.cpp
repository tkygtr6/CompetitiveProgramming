#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;

int N;

bool first_compare_asc(pair<int, int> a, pair<int, int> b){
    if(a.first > b.first){
        return true;
    }else{
        return false;
    }
}

bool first_compare_desc(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first){
        return true;
    }else{
        return false;
    }
}

bool second_compare_asc(pair<int, int> a, pair<int, int> b){
    if(a.second > b.second){
        return true;
    }else{
        return false;
    }
}

bool second_compare_desc(pair<int, int> a, pair<int, int> b){
    if(a.second < b.second){
        return true;
    }else{
        return false;
    }
}

int main(void){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int L, R;
        scanf("%d %d", &L, &R);
        v1.push_back(make_pair(L, R));
        v2.push_back(make_pair(R, L));
    }

    sort(v1.begin(), v1.end(), second_compare_desc);
    sort(v1.begin(), v1.end(), first_compare_desc);
    sort(v2.begin(), v2.end(), first_compare_asc);
    sort(v2.begin(), v2.end(), second_compare_asc);

    printf("\n");
    for(int i = 0; i < v1.size(); i++){
        printf("%d %d\n", v1[i].first, v1[i].second);
    }
    printf("\n");
    for(int i = 0; i < v2.size(); i++){
        printf("%d %d\n", v2[i].first, v2[i].second);
    }

    int x = 0;
    int sum = 0;
    
    for(int i = 0; i < N; i++){
        int max_r = v1[0].first;
        int min_l = v2[0].second;
        pair<int, int> target;
        sum += max(x - max_r, min_l - x);
        printf("%d\n", sum);
        if(x - max_r > min_l - x){
            x = max_r;
            target = v1[0];
            v2.erase(lower_bound(v2.begin(), v2.end(), make_pair(v1[0].second, v1[0].first)));
            v1.erase(v1.begin());
        }else{
            x = min_l;
            target = v2[0];
            v1.erase(lower_bound(v1.begin(), v1.end(), make_pair(v2[0].second, v2[0].first)));
            v2.erase(v2.begin());
        }
    }

    sum += max(x, -x);

    printf("%d", sum);


}
