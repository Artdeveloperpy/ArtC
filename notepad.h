char* innput;

void input(){
    char inputBuffer[256];
    int index = 0;

    bool times = false;
    while (times == false){

        printf(0,0,"[New                                                                           ]");
        // Verificar se há um caractere disponível para leitura no teclado
        if ((inportb(0x64) & 0x01) == 1) {
            // Ler o código da tecla do teclado
            char key = inportb(0x60);

            // Adiciona o código da tecla à buffer de entrada
            inputBuffer[index] = key;
            index++;
            inputBuffer[index] = '\0';  // Adiciona terminador de string

            // Verifica se é a tecla 'A' (A corresponde ao valor 0x1E no layout PT-BR)
            if (key == 0x1E) {
                char a[] = "A";
                // Concatena 'A' à string 'hey'
                strcat(innput, a);
            }
            // Verifica se é a tecla 'B' (B corresponde ao valor 0x30 no layout PT-BR)
            else if (key == 0x30) {
                char b[] = "B";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x2E) {
                char b[] = "C";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x20) {
                char b[] = "D";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x12) {
                char b[] = "E";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x21) {
                char b[] = "F";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x22) {
                char b[] = "G";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x23) {
                char b[] = "H";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x17) {
                char b[] = "I";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x24) {
                char b[] = "J";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x25) {
                char b[] = "K";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x26) {
                char b[] = "L";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x32) {
                char b[] = "M";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x31) {
                char b[] = "N";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x18) {
                char b[] = "O";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x19) {
                char b[] = "P";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x10) {
                char b[] = "Q";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x13) {
                char b[] = "R";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x1f) {
                char b[] = "S";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x14) {
                char b[] = "T";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x16) {
                char b[] = "U";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x2f) {
                char b[] = "V";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x11) {
                char b[] = "W";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x2d) {
                char b[] = "X";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x15) {
                char b[] = "Y";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x2c) {
                char b[] = "Z";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x29) {
                char b[] = "0";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x02) {
                char b[] = "1";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x03) {
                char b[] = "2";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x04) {
                char b[] = "3";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x05) {
                char b[] = "4";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x06) {
                char b[] = "5";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x07) {
                char b[] = "6";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x08) {
                char b[] = "7";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x09) {
                char b[] = "8";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x0a) {
                char b[] = "9";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x39) {
                char b[] = " ";
                // Concatena 'B' à string 'hey'
                strcat(innput, b);
            }
            else if (key == 0x0e) {
                int len = strlen(innput);
                if (len > 0) {
                    innput[len - 1] = '\0';  // Atribui o caractere nulo à posição anterior ao último caractere
                }
                clearScreenWithColor(color);
            }
            else if (key == 0x01 or key == 0x5B) {
                times = true;
                runnotepad = false;
                return;
            }

    }
    mouser();
    printf(0,1,innput);
}
}

void nprogram_main(){

    input();
}
