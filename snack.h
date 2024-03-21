// Declaração das funções necessárias
extern "C" int printf(const char* format, ...);
extern "C" int rand();

// Definindo o tamanho do campo de jogo
#define FIELD_WIDTH 80
#define FIELD_HEIGHT 25

// Definindo a estrutura do jogo Snake
struct SnakeGame {
    int snakeX[FIELD_WIDTH * FIELD_HEIGHT]; // Posições X do corpo da cobra
    int snakeY[FIELD_WIDTH * FIELD_HEIGHT]; // Posições Y do corpo da cobra
    int snakeLength; // Comprimento da cobra
    int foodX; // Posição X da comida
    int foodY; // Posição Y da comida
    int directionX; // Direção X da cobra (-1, 0 ou 1)
    int directionY; // Direção Y da cobra (-1, 0 ou 1)
    int score; // Pontuação do jogador
    bool gameOver; // Flag para indicar o fim do jogo
};

// Função para inicializar o jogo Snake
void initializeSnakeGame(SnakeGame& game) {
    // Inicializando a posição inicial da cobra e da comida
    game.snakeX[0] = FIELD_WIDTH / 2;
    game.snakeY[0] = FIELD_HEIGHT / 2;
    game.snakeLength = 1;
    game.foodX = rand() % FIELD_WIDTH;
    game.foodY = rand() % FIELD_HEIGHT;
    game.score = 0;
    game.gameOver = false;

    // Definindo uma direção inicial para a cobra
    game.directionX = 1;
    game.directionY = 0;
}

// Função para desenhar o campo de jogo
void drawField(const SnakeGame& game) {
    // Desenha as bordas do campo de jogo
    for (int i = 0; i < FIELD_WIDTH + 2; ++i) {
        printf("#");
    }
    printf("\n");

    for (int i = 0; i < FIELD_HEIGHT; ++i) {
        printf("#");
        for (int j = 0; j < FIELD_WIDTH; ++j) {
            if (j == game.foodX && i == game.foodY) {
                printf("O");
            } else {
                bool printSnake = false;
                for (int k = 0; k < game.snakeLength; ++k) {
                    if (j == game.snakeX[k] && i == game.snakeY[k]) {
                        printf("S");
                        printSnake = true;
                        break;
                    }
                }
                if (!printSnake) {
                    printf(" ");
                }
            }
        }
        printf("#\n");
    }

    for (int i = 0; i < FIELD_WIDTH + 2; ++i) {
        printf("#");
    }
    printf("\n");

    // Exibe a pontuação do jogador
    printf("Score: %d\n", game.score);
}

// Função para mover a cobra
void moveSnake(SnakeGame& game) {
    // Move o corpo da cobra
    for (int i = game.snakeLength - 1; i > 0; --i) {
        game.snakeX[i] = game.snakeX[i - 1];
        game.snakeY[i] = game.snakeY[i - 1];
    }

    // Move a cabeça da cobra
    game.snakeX[0] += game.directionX;
    game.snakeY[0] += game.directionY;

    // Verifica se a cobra comeu a comida
    if (game.snakeX[0] == game.foodX && game.snakeY[0] == game.foodY) {
        // Aumenta o comprimento da cobra
        game.snakeLength++;
        // Gera uma nova posição para a comida
        game.foodX = rand() % FIELD_WIDTH;
        game.foodY = rand() % FIELD_HEIGHT;
        // Aumenta a pontuação do jogador
        game.score++;
    }

    // Verifica se a cobra colidiu com a parede ou consigo mesma
    if (game.snakeX[0] == 0 || game.snakeX[0] == FIELD_WIDTH - 1 || game.snakeY[0] == 0 || game.snakeY[0] == FIELD_HEIGHT - 1) {
        game.gameOver = true; // Fim do jogo
    }
    for (int i = 1; i < game.snakeLength; ++i) {
        if (game.snakeX[i] == game.snakeX[0] && game.snakeY[i] == game.snakeY[0]) {
            game.gameOver = true; // Fim do jogo
        }
    }
}

// Função principal do jogo Snake
void playSnakeGame() {
    SnakeGame game;
    initializeSnakeGame(game);

    while (!game.gameOver) {
        clearScreenWithColor(0x01); // Limpa a tela
        drawField(game); // Desenha o campo de jogo
        moveSnake(game); // Move a cobra
        delay(100); // Adiciona um pequeno delay para controlar a velocidade do jogo
    }

    // Exibe a mensagem de fim de jogo
    printf(FIELD_WIDTH / 2 - 5, FIELD_HEIGHT / 2, "Game Over!");
}

// Função principal do kernel
void snake_main(){
    delay(500); // Aguarda 500 milissegundos
    playSnakeGame(); // Inicia o jogo Snake
}
