#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

  int main() {

    char tris[3][3] = {
      ' ',
      ' ',
      ' ',
      ' ',
      ' ',
      ' ',
      ' ',
      ' ',
      ' '
    };
    int i = 0, j = 0, newY = 0, newX = 0, player = 1, moves = 0, k = 0, g = 0, x = 0, xs = 0, o = 0, tx = 0, to = 0;
    bool won1 = false, won2 = false;

    do {

      system("CLS");
      moves++;
      for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

          printf("[ %c ]", tris[i][j]);

        }
        printf("\n");

      }
      for (g = 0; g < 3 && (won1 == false || won2 == false); g++) {

        //controllo orizzontale	
        for (k = 0; k < 3; k++) {

          if (tris[g][k] == 'x') {

            xs++;

          }

          if (tris[g][k] == 'o') {

            o++;

          }

          if (xs == 3) {

            won1 = true;
            moves = 10;
            printf("Il Giocatore 1 vince!");
            system("PAUSE");

          }
          if (o == 3) {

            won2 = true;
            moves = 10;
            printf("Il Giocatore 2 vince!");
            system("PAUSE");

          }

        }
        xs = 0;
        o = 0;
        ////Fine controllo orizzontale

        //controllo verticale	
        for (k = 0; k < 3; k++) {

          if (tris[k][g] == 'x') {

            xs++;

          }

          if (tris[k][g] == 'o') {

            o++;

          }

          if (xs == 3) {

            won1 = true;
            moves = 10;
            printf("Il Giocatore 1 vince!\n");
            system("PAUSE");

          }
          if (o == 3) {

            won2 = true;
            moves = 10;
            printf("Il Giocatore 2 vince!\n");
            system("PAUSE");

          }

        }
        xs = 0;
        o = 0;
        ////Fine controllo verticale

      }

      //Controllo diagonale
      if (tris[0][0] == 'x' && tris[1][1] == 'x' && tris[2][2] == 'x') {

        won1 = true;
        moves = 10;
        printf("Il Giocatore 1 vince!\n");
        system("PAUSE");

      }

      if (tris[0][0] == 'o' && tris[1][1] == 'o' && tris[2][2] == 'o') {

        won2 = true;
        moves = 10;
        printf("Il Giocatore 2 vince!\n");
        system("PAUSE");

      }
      //Fine controllo diagonale

      if (!won1 && !won2) {

        printf("Giocatore %d, inserisci le coordinate (y, x): ", player);
        scanf("%d", & newX);
        scanf("%d", & newY);
        if (tris[newX][newY] == 'x' || tris[newX][newY] == 'o') {

          printf("Posto gia' occupato da un altro segno, reinserisci");
          moves--;
          system("PAUSE");

        } else {

          if (newX > 2 || newY > 2) {

            printf("Numero troppo alto");
            moves--;
            system("PAUSE");

          } else {

            if (player == 1) {

              tris[newX][newY] = 'x';
              player++;

            } else {

              tris[newX][newY] = 'o';
              player--;

            }

          }

        }

      }

    } while (moves < 10);

    return 0;
  }
