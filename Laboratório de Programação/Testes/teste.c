#include<stdio.h>
#include<string.h>

main(){
    
    char textoOriginal[40],textoInvertido[40];
    int tamanhoPalavra = 0;
    printf("Informe uma palavra: ");
    gets(textoOriginal);

    tamanhoPalavra = strlen(textoOriginal)-1;

    for(int i = 0; textoOriginal[i] != '\0'; i++, tamanhoPalavra--){
        textoInvertido[i] = textoOriginal[tamanhoPalavra];
    }

    printf("%s\n", textoInvertido);
}