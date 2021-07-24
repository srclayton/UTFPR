#include <string.h>
#include "pilha.h"

int main () {
   char *sequencia = ")";
   Pilha* abertos = create_stack(10);
   int bem_formada = 1, i = 0;

   while (sequencia[i] != '\0') {
      if(sequencia[i] == '(' || sequencia[i] == '['){
        push(abertos, (int) sequencia[i]);
      }
      else if(sequencia[i] == ')'){
        if(pop(abertos) != (int) '('){
          bem_formada = 0;
          break;
        }
      }
      else if(sequencia[i] == ']'){
        if(pop(abertos) != (int) '['){
          bem_formada = 0;
          break;
        }
      }
      i++;
   }

   if(bem_formada && empty_stack(abertos)) { printf("Bem formada!\n"); }
   else { printf("Mal formada!\n"); }


   return 0;
}
