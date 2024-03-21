void cunstom_mouser(){
    if ((inportb(0x64) & 0x01) == 1) {
    // Ler o códimgo da tecla do teclado
    char key = inportb(0x60);
    // Adiciona o código da tecla à buffer de entrada
    inputBuffer[index] = key;
    index++;
    inputBuffer[index] = '\0';  // Adiciona terminador de string
    if(key == 0x48) { // Seta para cnima
        my -= 1;
    } else if(key == 0x50) { // Seta para baixo
        my += 1;
    } else if(key == 0x4B) { // Seta para esquerda
        mx -= 1;
    } else if(key == 0x4D) { // Seta para direita
        mx += 1;
    }
    printf(mx, my, "*");
}
}
void pprogram_main(){
    cunstom_mouser();
    if ((inportb(0x64) & 0x01) == 1) {
    char key = inportb(0x60);
    if (key == 0x01 or key == 0x5B){
        runpaint = false;
        return;
    }else if (key == 0x13) {
        clearScreenWithColor(color);
    }

    }
}
