#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>


int main() {
    float A = 0, B = 0;
    float i, j;
    int c;
    float z[1760];
    char b[1760];
    printf("\x1b[2J");
    for(;;) {
        memset(b,32,1760);
	//memset(b,64,1760);
	//memset(z,32,7040); In case you wanted @ in the background 
        memset(z,0,7040);
        for(j=0; j <6.28; j += 0.07) {
	    for (i=0;i<6.28; i+=0.02){
		float cosj = cos(j)+2;
		float tmp = 1/((sin(i)*cosj*sin(A)+sin(j)*cos(A)+5));
		float perm = sin(i)*cosj*cos(A)-sin(j)*sin(A);
		int x = 40+30 * tmp *(cos(i)*cosj*cos(B)-perm * sin(B));
		int y = 12+15*tmp*(cos(i)*cosj*sin(B)+perm*cos(B));
		int o =x + 80 * y;
		int k = 8 * (( sin(j)*sin(A) - sin(i)*cos(j)*cos(A)) * cos(B)-sin(i)*cos(j)*sin(A)-sin(j)*cos(A)-cos(i)*cos(j)*sin(B));

                if(22 > y && y > 0 && x > 0 && 80 > x && tmp > z[o]) {
                    z[o] = tmp;
                    b[o] = ".,-~:;=!*#$@"[k > 0 ? k : 0];
		    
                }
            }
        }
        printf("\x1b[H");
        for(c = 0; c < 1761; c++) {
            putchar(c % 80 ? b[c] : 10);
	    A += 0.00003;
            B += 0.00001;
        }
       usleep(10000);
    }
    return 0;
}
