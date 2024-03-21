void cprogram_main() {
int num1;
int num2;
char* cinput = "0";
char* operação = "";
int numatual = 1;
int li = 5;
while(1){
    char inputBuffer[256];
    int index = 0;
    printf(0,2,"[+][-][*][/][=]");
    bool times = false;
    while (times == false){
        printf(0,0,"[Callculaitor                                                                  ]");
        printf(0,2,"[+][-][*][/][=]");
        // Verificar se h谩 um caractere dispon铆vel para leitura no teclado
        if ((inportb(0x64) & 0x01) == 1) {
            // Ler o c贸digo da tecla do teclado
            char key = inportb(0x60);

            // Adiciona o c贸digo da tecla 脿 buffer de entrada
            inputBuffer[index] = key;
            index++;
            inputBuffer[index] = '\0';  // Adiciona terminador de string
            if (key == 0x29) {
                char b[] = "0";
                // Concatena 'B' 脿 string 'hey'
                strcat(cinput, b);
            }
            else if (key == 0x02) {
                char b[] = "1";
                // Concatena 'B' 脿 string 'hey'
                strcat(cinput, b);
            }
            else if (key == 0x03) {
                char b[] = "2";
                // Concatena 'B' 脿 string 'hey'
                strcat(cinput, b);
            }
            else if (key == 0x04) {
                char b[] = "3";
                // Concatena 'B' 脿 string 'hey'
                strcat(cinput, b);
            }
            else if (key == 0x05) {
                char b[] = "4";
                // Concatena 'B' 脿 string 'hey'
                strcat(cinput, b);
            }
            else if (key == 0x06) {
                char b[] = "5";
                // Concatena 'B' 脿 string 'hey'
                strcat(cinput, b);
            }
            else if (key == 0x07) {
                char b[] = "6";
                // Concatena 'B' 脿 string 'hey'
                strcat(cinput, b);
            }
            else if (key == 0x08) {
                char b[] = "7";
                // Concatena 'B' 脿 string 'hey'
                strcat(cinput, b);
            }
            else if (key == 0x09) {
                char b[] = "8";
                // Concatena 'B' 脿 string 'hey'
                strcat(cinput, b);
            }
            else if (key == 0x0a) {
                char b[] = "9";
                // Concatena 'B' 脿 string 'hey'
                strcat(cinput, b);
            }
            else if (key == 0x31) {
                runcall = false;
                runcall = true;
            }
            else if (key == 0x0e) {
                int len = strlen(cinput);
                if (len > 0) {
                    cinput[len - 1] = '\0';  // Atribui o caractere nulo 脿 posi莽茫o anterior ao 煤ltimo caractere
                }
                clearScreenWithColor(0x01);
            }
            else if (key == 0x01 or key == 0x5B) {
                runcall = false;
                return;
            }

    }
   mouser();
    printf(0, 1, cinput);
    if(numatual == 1){
    num1 = str_to_int(cinput);
}
if(numatual == 2){
    num2 = str_to_int(cinput);
}
    if (click_input == true && mx == 1 && my == 2) {
        operação = "adicao";
        numatual = 2;
        cinput[0] = '\0';
        clearScreenWithColor(0x01);
    }
    if (click_input == true && mx == 4 && my == 2) {
        operação = "subtracao";
        numatual = 2;
        cinput[0] = '\0';
        clearScreenWithColor(0x01);
    }
    if (click_input == true && mx == 7 && my == 2) {
        operação = "multiplicacao";
        numatual = 2;
        cinput[0] = '\0';
        clearScreenWithColor(0x01);
    }
    if (click_input == true && mx == 10 && my == 2) {
        operação = "divisao";
        numatual = 2;
        cinput[0] = '\0';
        clearScreenWithColor(0x01);
    }

    if (click_input == true && mx == 13 && my == 2) {
        if (operação == "adicao") {
            clearScreenWithColor(0x01);
            int resultado = num1 + num2;
            printn(0, 1, resultado);
            numatual = 1;
            delay(150);
        }
        else if(operação == "subtracao"){
            clearScreenWithColor(0x01);
            int resultado = num1 - num2;
            printn(0, 1, resultado);
            numatual = 1;
            delay(150);
        }
        else if(operação == "multiplicacao"){
            clearScreenWithColor(0x01);
            int resultado = num1 * num2;
            printn(0, 1, resultado);
            numatual = 1;
            delay(150);
        }
        else if(operação == "adicao"){
            clearScreenWithColor(0x01);
            int resultado = num1 / num2;
            printn(0, 1, resultado);
            numatual = 1;
            delay(150);
        }
    }
}

}
}
