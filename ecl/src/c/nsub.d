#include <stdarg.h>
void nsuml(long *sum , long argc , ... ) {
    va_list list;
    long i;
    
    *sum = 0;
    va_start( list ,  argc );
    for( i=0 ; i<argc ; i++ ) {
        *sum += *(va_arg( list , long* ));
    }
    va_end( list );
}
