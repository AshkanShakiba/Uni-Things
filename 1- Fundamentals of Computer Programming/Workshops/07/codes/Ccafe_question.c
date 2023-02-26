#include <stdio.h>
#include <stdbool.h>

#define init_cake_num 40
// Write your code here
#define init_cookie_num 40
#define init_coffee_num 40


/* global variable declaration */
// Write your code here
int choice;


void menu(int cake, int cookie, int coffee) {
    printf("What do you want to order?\n");
    printf("1) cake : %d\n", cake);
    printf("2) cookie : %d\n", cookie);
    printf("3) coffee : %d\n", coffee);
}

void buy() {
    scanf("%d", &choice);

    /* local variable declaration */
    int pic = 0;

    /* static variable declaration */
    // Write your code here
    static int cake=init_cake_num;
	static int cookie=init_cookie_num;
	static int coffee=init_coffee_num; 

    switch (choice) {
        case 1:
        	// Write your code here
        	cake--;
        	menu(cake, cookie, coffee);
        	break;
        case 2:
            // Write your code here
            cookie--;
        	menu(cake, cookie, coffee);
        	break;
        case 3:
            // Write your code here
            coffee--;
        	menu(cake, cookie, coffee);
        	break;
        case 5:
            printf("Do you want a picture?\n1) yes\n0) no\n");
            int a;
            scanf("%d", &a);
            if (a) 
                pic++;
            break;
        default:
            // Write your code here
            printf("Invalid! choose 1 for cake, 2 for cookie, 3 for coffee or 5 to end\n");
    }

    printf("pic num = %d\n", pic);
}

int main() {

    menu(init_cake_num, init_cookie_num, init_coffee_num);

    while(choice != 5)
        buy();

    printf("C U soon\n");

    return 0;
}
