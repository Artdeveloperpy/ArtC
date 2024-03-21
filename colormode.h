void color_seter(){
    //printa os nomes
    printf(0,0,"Colors:");
    printf(0,1,"[Black]");
    printf(0,2,"[Blue]");
    printf(0,3,"[Green]");
    printf(0,4,"[Cyan]");
    printf(0,5,"[Red]");
    printf(0,6,"[Purple]");
    printf(0,7,"[Yellow]");
    if ((inportb(0x64) & 0x01) == 1) {
        // Ler o código da tecla do teclado
        char key = inportb(0x60);
        // Adiciona o código da tecla à buffer de entrada
        inputBuffer[index] = key;
        index++;
        inputBuffer[index] = '\0';  // Adiciona terminador de string
    mouser();
    if(click_input == true && mx <= 4 && my == 1){
        color = 0x00;
    }
    if(click_input == true && mx <= 4 && my == 2){
        color = 0x01;
    }
    if(click_input == true && mx <= 4 && my == 3){
        color = 0x02;
    }
    if(click_input == true && mx <= 4 && my == 4){
        color = 0x03;
    }
    if(click_input == true && mx <= 4 && my == 5){
        color = 0x04;
    }
    if(click_input == true && mx <= 4 && my == 6){
        color = 0x05;
    }
    if(click_input == true && mx <= 4 && my == 7){
        color = 0x06;
    }
    if (key == 0x01 or key == 0x5B) {
        runcolor = false;
        return;
    }
    }
}
