/*!
  * Não obrigatoriamente, a função pode chamar outras funções que por sua
  * vez podem chamar a função inicial, por exemplo.
  * O importante para a função ser recursiva é que contenha em si uma chamada
  * de função a qual contenha em si outra chamada de função que também tenha
  * em si outra chamada de função e assim por diante.
  */

  /* Exemplo básico de função recursiva que não chama a si mesma */
  int foo(int);
  int bar(int);

  int foo(int x) {
      if(x>0) return 0;
      return bar(x-10);
  }

  int bar(int x) {
      if(x<0) return 1;
      return foo(x+15);
  }
/* foo() e bar() são funções recursivas e não chamam a si mesmas */
