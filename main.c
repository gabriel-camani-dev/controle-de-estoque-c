#include <stdio.h>
#include <string.h>

#define PRODUTOS 5
#define TAM_NOME 30

void cadastro(char nomes[PRODUTOS][TAM_NOME], float preco[PRODUTOS],int quantidades[PRODUTOS]);
void listarProdutos(char nomes[PRODUTOS][TAM_NOME], float preco[PRODUTOS],int quantidades[PRODUTOS]);
void findProdutos(char nomes[PRODUTOS][TAM_NOME], float preco[PRODUTOS],int quantidades[PRODUTOS]);
void entradaEstoque(char nomes[PRODUTOS][TAM_NOME],int quantidades[PRODUTOS]);
void saidaEstoque(char nomes[PRODUTOS][TAM_NOME],int quantidades[PRODUTOS]);
void valorTotal(char nomes[PRODUTOS][TAM_NOME], float preco[PRODUTOS],int quantidades[PRODUTOS]);

int main(){

    int opcao = 0;
    int resultado;
    int c;
    int cadastroRealizado = 0;

    char nomes[PRODUTOS][TAM_NOME];
    int quantidades[PRODUTOS];
    float precos[PRODUTOS];

    do {

    printf("\n=====================\n");
    printf("CONTROLE DE ESTOQUE\n");
    printf("=====================\n");
    printf("1. Cadastrar produtos\n");
    printf("2. Listar produtos\n");
    printf("3. Buscar produto pelo nome\n");
    printf("4. Registrar entrada no estoque\n");
    printf("5. Registrar saido do estoque\n");
    printf("6. Mostrar valor total do estoque\n");
    printf("0. Sair\n");

    printf("Selecione uma opcao: ");
    resultado = scanf("%d",&opcao);

    while((c = getchar()) != '\n' && c != EOF);

    if(resultado != 1){
        printf("Opcao Invalida!");
        opcao = -1;
        continue;
    }

        switch(opcao){
            
            default:
            printf("Digite um Numero Valido!!\n");
            break;

            case 1: 
            if(cadastroRealizado == 1){
                printf("Os produtos ja foram cadastrados!\n");
            } else {
                cadastro(nomes,precos,quantidades);
                cadastroRealizado = 1;
            }
            break;

            case 2:
            if(cadastroRealizado == 0){
                printf("Nenhum produto foi cadastrado ainda! Digite 1 para cadastrar.");
            } else{
                listarProdutos(nomes,precos,quantidades);
            }
            break;

            case 3:
            if(cadastroRealizado == 0){
                printf("Nenhum produto foi cadastrado ainda! Digite 1 para cadastrar.");
            } else{
                findProdutos(nomes, precos, quantidades);
            }
            break;

            case 4:
            if(cadastroRealizado == 0){
                printf("Nenhum produto foi cadastrado ainda! Digite 1 para cadastrar.");
            } else{
                entradaEstoque(nomes, quantidades);
            }
            break;

            case 5:
            if(cadastroRealizado == 0){
                printf("Nenhum produto foi cadastrado ainda! Digite 1 para cadastrar.");
            } else{
                saidaEstoque(nomes, quantidades);
            }
            break;

            case 6:
            if(cadastroRealizado == 0){
                printf("Nenhum produto foi cadastrado ainda! Digite 1 para cadastrar.");
            } else{
                valorTotal(nomes, precos, quantidades);
            }
            break;

            case 0:
            printf("Encerrando o Programa...");
            break;
        }
    }while(opcao != 0);


    return 0;
}

void cadastro(char nomes[PRODUTOS][TAM_NOME], float preco[PRODUTOS],int quantidades[PRODUTOS]){

    for(int i = 0; i<PRODUTOS; i++){

        int resultado;
        int c;
        int tamanho;

        printf("Digite o nome do [%d] produto: ",i+1);
        fgets(nomes[i], TAM_NOME, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        tamanho = strlen(nomes[i]);

        while (tamanho > 0 && nomes[i][tamanho - 1] == ' '){
            nomes[i][tamanho - 1] = '\0';
            tamanho --;
        }

    do {
        printf("Digite a quantidade: ");
         resultado = scanf("%d", &quantidades[i]);

         while((c = getchar()) != '\n' && c != EOF);

         if(resultado != 1 ||(resultado == 1 && quantidades[i]< 0)) printf("Digite um Valor Valido!\n");

        } while(resultado != 1 ||(resultado == 1 && quantidades[i]< 0));

    do {
         printf("Digite o valor por unidade: ");
             resultado = scanf("%f", &preco[i]);

          while ((c = getchar()) != '\n' && c != EOF);

         if (resultado != 1 || (resultado == 1 && preco[i] <= 0)) printf("Digite um preco valido!\n");

} while (resultado != 1 || (resultado == 1 && preco[i] <= 0));
    }
}
            


void listarProdutos(char nomes[PRODUTOS][TAM_NOME], float preco[PRODUTOS],int quantidades[PRODUTOS]){

    printf("\n--- TODOS OS PRODUTOS ---\n\n");

    printf("%-20s | %-10s | % -10s\n","Produto","Preco","Quantidade");

    printf("------------------------------------------\n");

    for(int i = 0; i < PRODUTOS; i++){
        printf("%-20s | R$ %-7.2f | %-10d\n",nomes[i],preco[i],quantidades[i]);
    }
}

void findProdutos(char nomes[PRODUTOS][TAM_NOME], float preco[PRODUTOS],int quantidades[PRODUTOS]){

    printf("Digite o nome do produto: ");

    int tamanho;
    int encontrado = 0;
    char teste[TAM_NOME]= "";

    fgets(teste,TAM_NOME,stdin);
    teste[strcspn(teste, "\n")] = '\0';
    
    tamanho = strlen(teste);

    while(tamanho > 0 && teste[tamanho - 1] == ' '){
        teste[tamanho - 1] = '\0';
         tamanho--;
}

    for(int i = 0; i<PRODUTOS; i++){
        if(strcmp(teste, nomes[i]) == 0){

            encontrado = 1;

            printf("%-20s | %-10s | % -10s\n","Produto","Preco","Quantidade");

            printf("%-20s | R$ %-7.2f | %-10d\n",nomes[i],preco[i],quantidades[i]);
        } 
    }
    if(encontrado != 1) printf("Produto nao encontrado.\n");
}

void entradaEstoque(char nomes[PRODUTOS][TAM_NOME],int quantidades[PRODUTOS]){

    printf("Qual Produto deseja atualizar a quantidade? ");

    int c = 0;
    int soma = 0;
    int tamanho;
    int resultado = 0;
    int encontrado = 0;
    char teste[TAM_NOME];

    fgets(teste,TAM_NOME,stdin);
    teste[strcspn(teste, "\n")] = '\0';

    for(int i = 0; i< PRODUTOS; i++){

        tamanho = strlen(nomes[i]);

        while (tamanho > 0 && nomes[i][tamanho - 1] == ' ') {
            nomes[i][tamanho - 1] = '\0';
            tamanho--;
        }
        
        if(strcmp(teste, nomes[i]) == 0){

            encontrado = 1;

            printf("%-20s | % -10s\n","Produto","Quantidade");

            printf("%-20s | %-10d\n",nomes[i],quantidades[i]);


            do {
         printf("Quantas unidades deseja adicionar? ");
            resultado = scanf("%d",&soma);

          while ((c = getchar()) != '\n' && c != EOF);

         if (resultado != 1 || (resultado == 1 && soma <= 0)){

            printf("Digite uma quantidade valida!\n");

         } else {
                quantidades[i] += soma; printf("Produto atualizado!");
         }

} while (resultado != 1 || (resultado == 1 && soma <= 0));

        }
    }

    if(encontrado != 1) printf("Produto nao encontrado");
}


void saidaEstoque(char nomes[PRODUTOS][TAM_NOME],int quantidades[PRODUTOS]){

    printf("Qual Produto deseja atualizar a quantidade? ");

    int c = 0;
    int tamanho;
    int resultado = 0;
    int sub = 0;
    int encontrado = 0;
    char teste[TAM_NOME];

    fgets(teste,TAM_NOME,stdin);
    teste[strcspn(teste, "\n")] = '\0';

    for(int i = 0; i< PRODUTOS; i++){

        int tamanho = strlen(nomes[i]);

    while (tamanho > 0 && nomes[i][tamanho - 1] == ' ') {
        nomes[i][tamanho - 1] = '\0';
        tamanho--;
}
        
        if(strcmp(teste, nomes[i]) == 0){

            encontrado = 1;

            printf("%-20s | % -10s\n","Produto","Quantidade");

            printf("%-20s | %-10d\n",nomes[i],quantidades[i]);

            do {
         printf("Quantas unidades deseja retirar? ");
            resultado = scanf("%d",&sub);

          while ((c = getchar()) != '\n' && c != EOF);

         if (resultado != 1 || (resultado == 1 && sub <= 0)){

            printf("Digite um valor valido!\n");

         } else if (sub > quantidades[i]) {
                printf("Estoque insuficiente\n");
              }

            } while (resultado != 1 || sub <= 0 || sub > quantidades[i]);

            quantidades[i] -= sub;
            printf("Valor Atualizado");

        }
    }

    if(encontrado != 1) printf("Produto NAO encontrado\n");
}

void valorTotal(char nomes[PRODUTOS][TAM_NOME], float preco[PRODUTOS],int quantidades[PRODUTOS]){
    
    float total = 0;
    for(int i =0; i<PRODUTOS;i++){
        total += preco[i] * quantidades[i];
    }
    printf("---Valor Total do Estoque: R$%.2f\n",total);
}


