//jogo baseado no muncher do mikeOS baseado na cobrinha do nokia
int score = 0;
int mx = 10;
int my = 10;


void mucher_player(){
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
    printf(mx, my, "#");
    delay(10);
    clearScreenWithColor(0x01);
}
void muncher_score(){
    printf(0,0,"score:");
    printf(6,0,score)
}
void muncher_main(){
    srand
    muncher_score();
    mucher_player();

}
