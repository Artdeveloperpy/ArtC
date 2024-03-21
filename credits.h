void credits() {
    clearScreenWithColor(0x02);
    asm volatile (
        "movb $0b10111110, %al\n" // Configura o registrador de controle de áudio
        "out %al, $0x61\n" // Escreve o valor no registrador de controle de áudio
        "movw $10000, %cx\n" // Configura um contador para aguardar um tempo
        "1:\n" // Rótulo para iniciar o loop
        "loop 1b\n" // Executa o loop
    );

printf(20,1,"         _,--,            _");
printf(20,2,"   __,-'____| ___      /' |");
printf(20,3," /'   `\,--,/'   `\  /'   |");
printf(20,4,"(       )  (       )'      ");
printf(20,5," \_   _/'  `\_   _/        ");
printf(20,6,"   """        """          ");
printf(20,8,"    _         _    ____ ");
printf(20,9,"   / \   _ __| |_ / ___|");
printf(20,10,"  / _ \ | '__| __| |    ");
printf(20,11," / ___ \| |  | |_| |___ ");
printf(20,12,"/_/   \_\_|   \_| \____|");
}

