#include <stdio.h>
#include <libprg/libprg.h>

int main()
{
    result_t resultado = compute(1,2,SUM);

    if(!resultado.error){
        printf("Resultado: %8.2f\n",resultado.value);
    }

    printf("%s\n",ola_mundo());

    return 0;
}
