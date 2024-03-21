#include "types.h"
bool click_input = false;
int my = 0;
int mx = 0;
char inputBuffer[256];
int index = 0;
int color = 0x00;
//programas:
bool runnotepad = false;
bool runcall = false;
bool runpaint = false;
bool runfliper = false;
bool runpang = false;
bool runcolor = false;
typedef void (*constructor)();
extern "C" constructor* start_ctors;
extern "C" constructor* end_ctors;
unsigned char inportb(unsigned short port);
extern "C" void callConstructors()
{
    for (constructor* i = start_ctors; i != end_ctors; i++) {
        (*i)();
    }
}
int strcmp(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0;  // As strings são diferentes
        }
        str1++;
        str2++;
    }

    // Verifica se ambas as strings terminaram
    return (*str1 == '\0' && *str2 == '\0');
}
unsigned char inportb(unsigned short port);

unsigned char inportb(unsigned short port) {
    unsigned char result;
    asm volatile("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}
void printf(int x, int y, const char* str) {
    // Inicia o ponteiro para a memória de vídeo na posição especificada
    unsigned short* VideoMemory = (unsigned short*)(0xb8000 + (y * 80 + x) * 2);

    // Escreve cada caractere da string na memória de vídeo
    for (int i = 0; str[i] != '\0'; ++i) {
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i]; // Caractere ASCII na parte baixa do byte
    }
}
int int_to_string(int num, char* buffer) {
    int index = 0;
    // Lidar com o caso especial de zero
    if (num == 0) {
        buffer[index++] = '0';
        buffer[index] = '\0';
        return 1; // Retorna o comprimento da string (1 caractere)
    }
    // Lidar com números negativos
    if (num < 0) {
        buffer[index++] = '-';
        num = -num;
    }
    // Converter cada dígito do número em um caractere
    int length = 0;
    while (num != 0) {
        int digit = num % 10;
        buffer[index++] = '0' + digit; // Converter o dígito em um caractere
        num /= 10;
        length++;
    }
    // Inverter a string
    for (int i = 0; i < index / 2; ++i) {
        char temp = buffer[i];
        buffer[i] = buffer[index - i - 1];
        buffer[index - i - 1] = temp;
    }
    buffer[index] = '\0'; // Adicionar terminador de string
    return length;
}


void printn(int x, int y, int num) {
    // Convertendo o número inteiro para uma string usando sprintf
    char buffer[32];
    int length = int_to_string(num, buffer);

    // Inicia o ponteiro para a memória de vídeo na posição especificada
    unsigned short* VideoMemory = (unsigned short*)(0xb8000 + (y * 80 + x) * 2);

    // Escrevendo a string na tela
    for (int i = 0; i < length; ++i) {
        // Calcula o índice da posição na memória de vídeo
        int index = (y * 80 + x) + i;

        // Escreve o caractere da string na memória de vídeo
        VideoMemory[index] = (VideoMemory[index] & 0xFF00) | buffer[i]; // Caractere ASCII na parte baixa do byte
    }
}

// Função para verificar se um caractere é um dígito
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int str_to_int(char *str) {
    int num = 0;
    int i = 0;

    // Encontra o início do número na string
    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9')) {
        i++;
    }

    // Converte os caracteres numéricos para um número inteiro
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    return num;
}
int charToInt(const char* str) {
    int result = 0;
    int sign = 1;

    // Verifica se o número é negativo
    if (*str == '-') {
        sign = -1;
        ++str;
    }

    // Converte cada dígito do caractere para um número inteiro
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
        } else {
            // Se não for um dígito válido, retorna 0 ou algum valor de erro
            return 0; // Ou outra indicação de erro
        }
        ++str;
    }

    return result * sign;
}

// Função de delay simples
void delay(int milliseconds) {
    for (volatile int i = 0; i < milliseconds * 1000000; i++) {
        // Apenas aguarda
    }
}

void clearScreenWithColor(unsigned char color) {
    // Obtém um ponteiro para a memória de vídeo
    volatile unsigned short* VideoMemory = (volatile unsigned short*)0xb8000;

    // Calcula o valor do atributo de vídeo com base na cor fornecida
    unsigned short attribute = (color << 12) | 0x0700; // Background color no nibble mais alto

    // Preenche a tela com espaços em branco com a cor especificada
    for (int i = 0; i < 80 * 25; i++) {
        VideoMemory[i] = attribute | ' '; // Espaço em branco com a cor especificada
    }
}

#include "credits.h"
// Função para calcular o comprimento de uma string
int strlen(const char* str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

// Função para concatenar duas strings (dest = dest + src)
void strcat(char* dest, const char* src)
{
    int dest_len = strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0'; // Adiciona o terminador de string
}
void mouser(){
    char key = inportb(0x60);
    if(key == 0x48) { // Seta para cnima
        my -= 1;
    } else if(key == 0x50) { // Seta para baixo
        my += 1;
    } else if(key == 0x4B) { // Seta para esquerda
        mx -= 1;
    } else if(key == 0x4D) { // Seta para direita
        mx += 1;
    }else if(key == 0x1C) { // Seta para direita
        click_input = true;
    }else{click_input = false;}
    printf(mx, my, "<-");
    delay(10);
    clearScreenWithColor(color);
}
#include "notepad.h"
#include "callculeitor_novo.h"
#include "paint.h"
#include "pang.h"
#include "colormode.h"
void desktop(){
            printf(0,1,"NotePad");
            printf(0,2,"Call");
            printf(0,3,"Paint");
            printf(0,4,"Pang");
            printf(0,5,"Color Config");
            if ((inportb(0x64) & 0x01) == 1) {
            // Ler o códimgo da tecla do teclado

            char key = inportb(0x60);
            // Adiciona o código da tecla à buffer de entrada
            inputBuffer[index] = key;
            index++;
            inputBuffer[index] = '\0';  // Adiciona terminador de string

        }
        mouser();
        if(click_input == true && mx <= 7 && my == 1){
            runnotepad = true;
        }
        if(click_input == true && mx <= 3 && my == 2){
            runcall = true;
        }
        if(click_input == true && mx <= 3 && my == 3){
            runpaint = true;
        }
        if(click_input == true && mx <= 3 && my == 4){
            runpang = true;
        }
        if(click_input == true && mx <= 10 && my == 5){
            runcolor = true;
        }
}

extern "C" void kernelMain(void* multiboot_structure, uint32_t magicnumber) {
    credits();
    delay(500);
    while(1) {
        if(runnotepad == true){nprogram_main();}
        if(runcall == true){cprogram_main();}
        if(runpaint == true){pprogram_main();}
        if(runpang == true){pang_main();}
        if(runcolor == true){color_seter();}
        else{desktop();}
    }
}
