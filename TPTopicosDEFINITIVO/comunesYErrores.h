#ifndef COMUNESYERRORES_H_INCLUDED
#define COMUNESYERRORES_H_INCLUDED


#define ERROR_CHECK(error) \
        if((error)){ \
            printf("Error: %d, At: %s, Line: %d\n", (error), __FILE__, __LINE__);\
            return (error); \
        }

#define TRY(expr)           \
    do{                     \
        ERROR_CHECK((expr))  \
    }while(0);

#define NOM_ARCH_INDICES_GENERAL 1
#define NOM_ARCH_INDICES_ITEMS 2
#define NOM_ARCH_INDICES_UNIF 3

#define BUFFER_TAM 256

#define EXITO 0
#define ERR_MEMORIA 1
#define ERR_ARCHIVO 2
#define ERR_MAL_INGRESO 3
#define ERR_REGISTRO 4

#endif // COMUNESYERRORES_H_INCLUDED
