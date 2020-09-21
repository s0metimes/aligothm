#include <stdio.h>
#define MAX_HZ 146000
#define MIN_HZ 144000
#define A 0
#define B 1

int channel[2];

int ftoi(float hz) { return (int)(hz*100); }
int down(int hz);
int up(int hz);
int moveChannel(int ch);
int main(int argc, char const *argv[])
{
    int testCase;
    
    scanf("%d", &testCase);

    while(testCase--) {
        float fa, fb, fg;
        char nowChannel;
        scanf("%f %f %c %f", &fa, &fb, &nowChannel, &fg);
        int ig = ftoi(fg), now = (nowChannel == 'A') ? channel[A] : channel[B];
        
        channel[A] = ftoi(fa);
        channel[B] = ftoi(fb);

        int minV = 6; // 숫자 다이얼 6번 입력하는 것 
        
        if(ig == now) minV = 0; // 현재와 바꿀 주파수가 동일한 경우
        
        // UP과 다운으로만 이동하는 경우 
        // UP
        if((ig - now) % 20 == 0)) minV = min(minV, (ig-now)/20);

        printf("%d\n", minV);
    }
    return 0;
}

int down(int hz) {
    if(hz < MIN_HZ+20 && hz >= MIN_HZ) return MAX_HZ;
    else return hz - 20;
}

int up(int hz) {
    if(hz <= MAX_HZ && hz > MAX_HZ-20) return MIN_HZ;
    else return hz + 20;
}

int moveChannel(int ch) {
    if(ch == A) return channel[A];
    else if(ch == B) return channel[B];
}


