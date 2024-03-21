// Definir a estrutura da bola
struct Ball {
    int x;
    int y;
    int dx; // Direção horizontal da bola (-1 ou 1)
    int dy; // Direção vertical da bola (-1 ou 1)
};

// Definir a estrutura das paletas dos jogadores
struct Paddle {
    int x;
    int y;
};

// Variáveis globais para o jogo
Ball ball = {40, 12, -1, 1}; // Posição inicial e direção da bola
Paddle player1 = {1, 10};    // Posição inicial da paleta do jogador 1
Paddle player2 = {78, 10};   // Posição inicial da paleta do jogador 2

// Função para desenhar a bola na tela
void drawBall() {
    printf(ball.x, ball.y, "*");
}

// Função para desenhar as paletas dos jogadores na tela
void drawPaddles() {
    // Desenha a paleta do jogador 1
    for (int i = player1.y - 1; i <= player1.y + 1; ++i) {
        printf(player1.x, i, "|");
    }

    // Desenha a paleta do jogador 2
    for (int i = player2.y - 1; i <= player2.y + 1; ++i) {
        printf(player2.x, i, "|");
    }
}

// Função para mover a bola
void moveBall() {
    // Move a bola na direção atual
    ball.x += ball.dx;
    ball.y += ball.dy;

    // Verifica colisões com as paredes superior e inferior
    if (ball.y <= 0 || ball.y >= 24) {
        ball.dy = -ball.dy;
    }

    // Verifica colisões com as paletas dos jogadores
    if (ball.x == player1.x + 1 && ball.y >= player1.y - 1 && ball.y <= player1.y + 1) {
        ball.dx = -ball.dx;
    }
    if (ball.x == player2.x - 1 && ball.y >= player2.y - 1 && ball.y <= player2.y + 1) {
        ball.dx = -ball.dx;
    }

    // Verifica se a bola saiu do campo
    if (ball.x < 0 || ball.x > 79) {
        // Reseta a posição da bola
        ball.x = 40;
        ball.y = 12;
        // Reseta a direção da bola
        ball.dx = -ball.dx;
        ball.dy = 1;
    }
}

// Função para mover as paletas dos jogadores
void movePaddles() {
    // Movimenta a paleta do jogador 1 (usando as setas W e S)
    if ((inportb(0x64) & 0x01) == 1) {
        char key = inportb(0x60);
        if (key == 0x11) { // W
            if (player1.y > 1) {
                player1.y--;
            }
        } else if (key == 0x1F) { // S
            if (player1.y < 22) {
                player1.y++;
            }
        }
    }

    // Movimenta a paleta do jogador 2 (usando as setas UP e DOWN)
    char key = inportb(0x60);
    if (key == 0x48) { // UP
        if (player2.y > 1) {
            player2.y--;
        }
    } else if (key == 0x50) { // DOWN
        if (player2.y < 22) {
            player2.y++;
        }
    }
}

// Função principal do jogo Pong
void playPong() {
    while (1) {
        clearScreenWithColor(color); // Limpa a tela

        drawBall();     // Desenha a bola
        drawPaddles();  // Desenha as paletas dos jogadores

        moveBall();     // Move a bola
        movePaddles();  // Move as paletas dos jogadores

        delay(50);      // Adiciona um pequeno delay para controlar a velocidade do jogo
    }
}

// Função principal do kernel
void pang_main(){
    delay(100); // Aguarda 500 milissegundos
    playPong(); // Inicia o jogo Pong
        // Ler o código da tecla do teclado
        char key = inportb(0x60);
        // Adiciona o código da tecla à buffer de entrada
        inputBuffer[index] = key;
        index++;
        inputBuffer[index] = '\0';  // Adiciona terminador de string

    if (key == 0x01 or key == 0x5B) {
        runpang = false;
        return;
    }
}
