// gcc -Og 2024_PDM.c -o 2024_PDM -no-pie -fno-guess-branch-probability

#include <stdio.h>    // para printf(), fgets(), scanf()
#include <stdlib.h>    // para exit()
#include <string.h>    // para strncmp()
#include <stdbool.h>
#include <sys/time.h>  // para gettimeofday(), struct timeval

#define SIZE 100
#define TLIM 10

char passwd[] = "}";  // contraseña "hoyesmartes\n"
char real_password[] = "nadiesabenada\n";
char real_real_password[] = "usuario\n";
char true_password[] = "¿cómoestánlosmáquinas?\n";
int code = 1122;     // pin 1123
int key = 0x77;

// Función para encriptar la contraseña ()
void encrypt_decrypt(char cad[]) {
    int cad_length = strlen(cad);
    for (int i = 0; i < cad_length; ++i) cad[i] = cad[i] ^ key;
}

// Función para comparar la contraseña ingresada con la original
bool compare(char * guess) {
    encrypt_decrypt(passwd);
    return strncmp(guess, passwd, SIZE) == 0;
}

// Función para modificar el pin
int modify(int num) {
    return (num + 1);
}

// Función para verificar el pin
bool check_pin(int guess) {
    return (guess == modify(code));
}

void boom(void){
	printf(	"\n"
		"***************\n"
		"*** BOOM!!! ***\n"
		"***************\n"
		"\n");
	exit(-1);
}

void defused(void){
	printf(	"\n"
		"·························\n"
		"··· bomba desactivada ···\n"
		"·························\n"
		"\n");
	exit(0);
}

int main(){
char pw[SIZE];
    int pc, n;

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    do {
        printf("\nIntroduce la contraseña: ");
    } while (fgets(pw, SIZE, stdin) == NULL);

    if (!compare(pw)) boom();

    gettimeofday(&tv2, NULL);
    if (tv2.tv_sec - tv1.tv_sec > TLIM) boom();

    do {
        printf("\nIntroduce el pin: ");
        n = scanf("%i", &pc);
        if (n == 0) scanf("%*s");
    } while (n != 1);

    if (!check_pin(pc)) boom();

    gettimeofday(&tv1, NULL);
    if (tv1.tv_sec - tv2.tv_sec > TLIM) boom();

    defused();
}
