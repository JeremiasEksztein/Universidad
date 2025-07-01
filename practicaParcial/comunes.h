#ifndef COMUNES_H_INCLUDED
#define COMUNES_H_INCLUDED

//Tal vez me sea util esta macro

#define TRY(expr)   do{ \
    if(expr){           \
        return expr;    \
    }                   \
    }while(0);


#define ERR_MEMORIA 1
#define ERR_ARCHIVO 2
#define FIN_DE_SECUENCIA 3



#endif // COMUNES_H_INCLUDED
