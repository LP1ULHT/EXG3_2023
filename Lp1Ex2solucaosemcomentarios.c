/*
 ============================================================================
 Name        : Lp1JsonEx2G.c
 Author      : Daniel Silveira e Thiago Gustavo
 Version     :
 Copyright   : Universidade Lusofona
 Description : Solucao do exericicio de grupo 2
			   Parser de JSON simplificado
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MENU "\n 1 - Analise sintatica\n 2 - Sair\n"
#define SAIR 2

/* Tipos de elements no json */
enum Elemento_json_e 
{
  elemento_json_ERRO = 0,
  elemento_json_STRING,
  elemento_json_NUMBER,
  elemento_json_OBJECT,
  elemento_json_OBJECT_END,
  elemento_json_ARRAY,
  elemento_json_ARRAY_END
};
typedef enum Elemento_json_e Elemento_json;

typedef struct t_contadorElementos{
  int num_STRING;
  int num_NUMBER;
  int num_OBJECT;
  int num_ARRAY;
} contadorElementos;


/** 
 *Funcoes auxiliares 
 */
int json_is_string(char ch) 
{ 
  return ch == '"'; 
}

int json_is_number(char ch) 
{
  return (ch >= '0' && ch <= '9') || ch == '+' || ch == '-' || ch == '.' || ch == 'e' || ch == 'E';
}

int json_is_object(char ch) 
{ 
  return ch == '{'; 
}

int json_is_object_end(char ch) 
{ 
return ch == '}'; 
}

int json_is_array(char ch) 
{ 
  return ch == '['; 
}

int json_is_array_end(char ch) 
{ 
  return ch == ']'; 
}
/** 
 * Fim Funcoes auxiliares 
 */


void printElement(Elemento_json x)
{
    switch (x) 
    {
      case elemento_json_STRING:
        printf("\"");
        break;
      
      case elemento_json_ARRAY:
        printf("[");
        break;
      case elemento_json_ARRAY_END:
        printf("]");
        break;
             
      case elemento_json_NUMBER:
        printf("NUMBER");
        break;

      case elemento_json_OBJECT:
        printf("{");
        break;
      case elemento_json_OBJECT_END:
        printf("}");
        break;
        
      case elemento_json_ERRO:
      default:
        printf("{");
    }
}  

/* Funcao pop */
int pop(int pilha, Elemento_json tipo)
{
  printf ("\npop  ");
  printElement(tipo);

  pilha--;  
  if(pilha < 0)
  {
    printf ("\nerro 02: stack underflow!\n");
    pilha = -1;
  }
  return pilha;
}

/* Funcao push */
int push(int pilha, int max_stack, Elemento_json tipo)
{
  printf ("\npush ");
  printElement(tipo);

  pilha++;
  if(pilha > max_stack)
  {
    printf ("\nerro 01: stack overflow!\n");
    pilha = -1;
  }

  return pilha;
}

/* Deteta qual o tipo de elemento json na string */
Elemento_json ler_Elemento_json(char ch) 
{
  Elemento_json tipo;

  if (json_is_string(ch))
    tipo = elemento_json_STRING;
  else if (json_is_object(ch))
    tipo = elemento_json_OBJECT;
  else if (json_is_object_end(ch))
    tipo = elemento_json_OBJECT_END;
  else if (json_is_array(ch))
    tipo = elemento_json_ARRAY;
  else if (json_is_array_end(ch))
    tipo = elemento_json_ARRAY_END;
  else if (json_is_number(ch))
    tipo = elemento_json_NUMBER;
  else
    tipo = elemento_json_ERRO;

  return tipo;
}

contadorElementos parse(char str, contadorElementos cont, int max_stack)
{
  enum Elemento_json_e tipo = ler_Elemento_json(str);
  switch (tipo)
  {
    case elemento_json_STRING:
        if(cont.num_STRING == 1)
          cont.num_STRING = pop(cont.num_STRING, tipo);
        else
          cont.num_STRING = push(cont.num_STRING, max_stack, tipo);
      break;
    
    case elemento_json_ARRAY:
      cont.num_ARRAY = push(cont.num_ARRAY, max_stack, tipo);
      break;
      
    case elemento_json_ARRAY_END:
      cont.num_ARRAY = pop(cont.num_ARRAY, tipo);
      break;
      
    case elemento_json_NUMBER:
      cont.num_NUMBER++;
      break;

    case elemento_json_OBJECT:
      cont.num_OBJECT = push(cont.num_OBJECT, max_stack, tipo);
      break;

    case elemento_json_OBJECT_END:
      cont.num_OBJECT = pop(cont.num_OBJECT, tipo);
      break;
      
    case elemento_json_ERRO:  
    default:
      printf (" ");
  }
  return cont;
}


void detetaErros (contadorElementos resultado)
{
  if(
    (resultado.num_ARRAY == 0) &&
    (resultado.num_OBJECT == 0) && 
    (resultado.num_STRING == 0))
    printf ("\nFBF - Ficheiro bem formado!\n");
  else
    printf ("\nFMF - Ficheiro mal formado!\n");
}

/* Deteta stack overflow */
int detetaStackOverflow (contadorElementos resultado)
{
  if(
    (resultado.num_ARRAY == -1) ||
    (resultado.num_OBJECT == -1) || 
    (resultado.num_STRING == -1))
    return 1;
  else
    return 0;
}

/*
void imprimeStats(contadorElementos resultado)
{
  printf ("\nTotal de Strings: %d\n", resultado.num_STRING);
  printf ("\nTotal de Objectos: %d\n", resultado.num_OBJECT);
  printf ("\nTotal de Objectos End: %d\n", resultado.num_OBJECT_END);
  printf ("\nTotal de Arrays: %d\n", resultado.num_ARRAY);
  printf ("\nTotal de Arrays End: %d\n", resultado.num_ARRAY_END);
}
*/

int menu ()
{
    int opcao = 2;
    printf (MENU);
    scanf (" %d", &opcao);
    return opcao;

}

void analise_sintatica()
{
  int stacksize = 0;    
  contadorElementos resultado = {0};
  FILE* ptr;
  char ch;
  char filename[50];

  printf ("\nInforme o tamanho da stack: ");
  scanf (" %d", &stacksize);

  printf ("\nInforme o nome do ficheiro a analisar:");
  scanf (" %s", filename);

  // Opening file in reading mode
  ptr = fopen(filename, "r");

  if (NULL == ptr) {
    printf("FNE - Ficheiro nao existe!\n");
    return;
  }

  do {
    ch = fgetc(ptr);
    resultado = parse(ch, resultado, stacksize);
    if(detetaStackOverflow(resultado))
        ch = EOF;

    // Checking if character is not EOF.
    // If it is EOF stop reading.
  } while (ch != EOF);

  // Closing the file
  fclose(ptr);
  detetaErros(resultado);
  //imprimeStats(resultado);

}


int main(void) {
  int opcao = 1;

  while (opcao == 1)
  {
    opcao = menu();
    switch (opcao)
    {
      case 1:
        analise_sintatica();
        break;
      default:
        return 1;
    }      
  } 

  return 0;   
}
