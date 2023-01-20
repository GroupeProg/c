#include <stdio.h>
#include <stdlib.h>

#include "mylib.h"


int main()
{
    srand(time(NULL));
    //    int i1, i2, i3;
    //    scanf("%d %d %d", &i1, &i2, &i3);
    //    q3(&i1, &i2, &i3);
    //    printf("%d %d %d", i1, i2, i3);

    //    for(int i = 2000; i < 2100; i++){
    //        printf("%d bissextile : %d\n", i, q5(i));
    //    }

    //    for(int i = 1; i < 13; i++){
    //        q6(i);
    //        printf("\n");
    //    }

//        int i1, i2;
//        scanf("%d %d", &i1, &i2);
//        printf("%d", q7(i1, i2));
//        return 0;

//        int i1;
//        scanf("%d", &i1);
//        q8(i1);

//        for(int i = 0; i < 100; i++){
//            printf("%d is %s\n", i, (is_perfect(i) ? "perfect" : "not perfect"));
//        }
    print_tab(tab100());
}
