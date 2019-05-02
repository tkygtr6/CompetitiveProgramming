#include <stdio.h>
#define NUM 100010
#define INF 1000000010

int main(void){
    int N;
    long long sum = 0;
    long long count = 0;
    long long min_ = INF;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        long long a;
        scanf("%lld", &a);

        if(a < 0){
            a = -a;
            count++;
        }
        min_ = min_ < a ? min_:a;

        sum += a;
    }

    if(count % 2 == 0){
        printf("%lld\n", sum);
    }else{
        printf("%lld\n", sum - min_ * 2);
    }

    return 0;
}
