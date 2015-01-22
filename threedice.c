#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int roll_dice() {
    return (rand() % 6) + 1;
}

int max_three(int a, int b, int c) {

    int g, max;

    if (a >= b)
        g = a;
    else
        g = b;
    if (g >= c)
        max = g;
    else
        max = c;
    return max;
}

int main() {

    int n_tries = 10000000;
    int less_one, less_two, less_three, less_four, less_five, less_six;
    srand(time(NULL));

    for(int i = 0; i < n_tries; i++) {
        if (max_three(roll_dice(), roll_dice(), roll_dice()) <= 6)
            less_six++;
        if (max_three(roll_dice(), roll_dice(), roll_dice()) <= 5) 
            less_five++;
        if (max_three(roll_dice(), roll_dice(), roll_dice()) <= 4) 
            less_four++;
        if (max_three(roll_dice(), roll_dice(), roll_dice()) <= 3) 
            less_three++;
        if (max_three(roll_dice(), roll_dice(), roll_dice()) <= 2) 
            less_two++;
        if (max_three(roll_dice(), roll_dice(), roll_dice()) <= 1) 
            less_one++;
    }

    printf("%f %% of the tries fall <= 1\n",  ((float)less_one/(float)n_tries));
    printf("%f %% of the tries fall <= 2\n",  ((float)less_two/(float)n_tries));
    printf("%f %% of the tries fall <= 3\n",  ((float)less_three/(float)n_tries));
    printf("%f %% of the tries fall <= 4\n",  ((float)less_four/(float)n_tries));
    printf("%f %% of the tries fall <= 5\n",  ((float)less_five/(float)n_tries));
    printf("%f %% of the tries fall <= 6\n",  ((float)less_six/(float)n_tries));
}

