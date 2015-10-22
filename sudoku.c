#include <stdio.h>
#include <stdlib.h>

int  main(){

	int sudoku[3][3][3][3] = {
                                {
                                    {{5,8,2},{7,0,0},{9,0,6}},
                                    {{0,3,0},{0,5,0},{7,4,2}},
                                    {{6,0,4},{0,0,0},{5,0,8}}
                                },{
                                    {{0,1,0},{8,0,4},{0,9,0}},
                                    {{0,8,6},{0,1,0},{4,2,0}},
                                    {{9,4,5},{0,6,2},{7,8,0}}
                                },{
                                    {{3,0,0},{1,0,0},{4,0,5}},
                                    {{5,9,4},{0,0,3},{0,6,1}},
                                    {{0,2,7},{0,5,0},{0,3,0}}
                                }

                            };

	int a, b, c, d;

	int a1, b1, c1, d1;

	int valor, aux;

	int possivel, possibilidades;

	int verificar;

	int ops;

	printf("Preencher automatico - (0) Nao / (1) Sim: ");
	scanf("%d", &ops);

	if(!ops){

		for(a=0; a<3; a++){

			for(c=0; c<3; c++){

				for(b=0; b<3; b++){

					for(d=0; d<3; d++){

						scanf("%d", &sudoku[a][b][c][d]);

					}

				}

			}

		}

	}

    printf("\nSudoku a resolver:\n\n");

    for(a=0; a<3; a++){

        for(c=0; c<3; c++){

            for(b=0; b<3; b++){

                for(d=0; d<3; d++){

                    printf(" %d", sudoku[a][b][c][d]);

                }

                printf(" ");

            }

            printf("\n");

        }

        printf("\n");

    }

	do{

		for(a=0; a<3; a++){

			for(b=0; b<3; b++){

				for(c=0; c<3; c++){

					for(d=0; d<3; d++){

						if( sudoku[a][b][c][d] == 0 ){

							possibilidades = 0;

							for(aux=1; aux<=9; aux++){

								possivel = 1;

								// Linha

								for(b1=0; b1<3; b1++){

									for(d1=0; d1<3; d1++){

										if( sudoku[a][b1][c][d1] == aux ){

											possivel = 0;

										}

									}

								}

								if(!possivel)
									continue;

								// Coluna

								for(a1=0; a1<3; a1++){

									for(c1=0; c1<3; c1++){

										if( sudoku[a1][b][c1][d] == aux ){

											possivel = 0;

										}

									}

								}

								if(!possivel)
									continue;

								// Quadrado

								for(c1=0; c1<3; c1++){

									for(d1=0; d1<3; d1++){

										if( sudoku[a][b][c1][d1] == aux ){

											possivel = 0;

										}

									}

								}

								if(possivel){
									possibilidades++;
									valor = aux;
								}

								if(possibilidades > 1)
									break;

							}

							if(possibilidades == 1)
								sudoku[a][b][c][d] = valor;

						}

					}

				}

			}

		}

		verificar = 0;

		for(a=0; a<3; a++){

            for(b=0; b<3; b++){

                for(c=0; c<3; c++){

					for(d=0; d<3; d++){

						if(sudoku[a][b][c][d] == 0){

							verificar = 1;

						}

					}

				}

			}

		}

	}while(verificar);

	printf("\nSudoku a resolvido:\n\n");

    for(a=0; a<3; a++){

        for(c=0; c<3; c++){

            for(b=0; b<3; b++){

                for(d=0; d<3; d++){

                    printf(" %d", sudoku[a][b][c][d]);

                }

                printf(" ");

            }

            printf("\n");

        }

        printf("\n");

    }

	return 0;

}
