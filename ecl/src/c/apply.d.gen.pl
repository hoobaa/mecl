#!/usr/bin/env perl

open(STDOUT, '>', "apply.d");

my $up = 64;

print <<"END";
/* -*- mode: c; c-basic-offset: 8 -*- */
#include <ecl/ecl.h>
END

for (my $i=0; $i<=$up; $i++) {
    printf("typedef cl_object (*t_f%d)(cl_narg", $i);
    for (my $j=0; $j<$i; $j++) {
        print(",cl_object");
    }
    print(");\n");
}
##############################
print <<"END";

#ifndef ECL_ASM_APPLY
cl_object
APPLY(cl_narg n, cl_objectfn fn, cl_object *x)
{
    nlogd(">>FUCK APPLY n:%d", n);

    switch (n) {
END

for (my $i=0; $i<=63; $i++) {
    printf("    case %d: return (*((t_f%d)(fn)))(n", $i, $i);
    for (my $j=0; $j<$i; $j++) {
        printf(",x[%d]", $j);
    }
    print(");\n");
}

print <<"END";
    default: return (*fn)(n, x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
                        x[8],x[9],x[10],x[11],x[12],x[13],x[14],
                        x[15],x[16],x[17],x[18],x[19],x[20],x[21],
                        x[22],x[23],x[24],x[25],x[26],x[27],x[28],
                        x[29],x[30],x[31],x[32],x[33],x[34],x[35],
                        x[36],x[37],x[38],x[39],x[40],x[41],x[42],
                        x[43],x[44],x[45],x[46],x[47],x[48],x[49],
                        x[50],x[51],x[52],x[53],x[54],x[55],x[56],
                        x[57],x[58],x[59],x[60],x[61],x[62],x[63]);
    }
}


END
##############################
printf("typedef cl_object (*t_ff0)();\n");
for (my $i=1; $i<=$up; $i++) {
    printf("typedef cl_object (*t_ff%d)(cl_object", $i);
    for (my $j=1; $j<$i; $j++) {
        print(",cl_object");
    }
    print(");\n");
}
##############################
print <<"END";

cl_object
APPLY_fixed(cl_narg n, cl_object (*fn)(), cl_object *x)
{
    nlogd(">>FUCK APPLY-fixed n:%d", n);
    switch (n) {

END

print("    case 0:  return (*fn)();\n");
for (my $i=1; $i<=64; $i++) {
    printf("    case %d: return (*((t_ff%d)(fn)))(x[0]", $i, $i);
    for (my $j=1; $j<$i; $j++) {
        printf(",x[%d]", $j);
    }
    print(");\n");
}
print <<"END";
    default:
  	  FEprogram_error_noreturn("Too many arguments", 0);
    }
}
#endif

END
##############################
