#include <stdio.h>

int main()
{
    int n, m, i, j;
    int box[101];
    int cnt[101]={0};
    int cnt_max=-1;

    scanf("%d %d", &n, &m);         // 가로 n, 세로 m인 방
    for(i=0; i<n; i++)             // 가로 x, 세로 y
        scanf("%d", &box[i]);

    for(i=0; i<n; i++)             // 입력받은 상자들 높이 비교해서 오른쪽에 낮은 상자 개수 세기
    {                              // 오른쪽의 낮은 상자의 개수 = 낙하거리
        for(j=i+1; j<n; j++)       
            if(box[j]<box[i])   cnt[i]++;
        if(cnt_max<cnt[i])  cnt_max=cnt[i];      // 낙하거리(cnt_max) 중 최댓값 찾기
    }

    printf("가장 큰 낙하거리 : %d", cnt_max);
    
    return 0;
}
