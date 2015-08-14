#!/usr/bin/env perl

my $up = 64;

print <<"END";
  #include <ecl/ecl.h>
END

for (my $i=0; $i<=$up; $i++) {
    printf("typedef cl_object (*t_f%d)(cl_narg", $i);
    for (my $j=0; $j<$i; $j++) {
        print(",cl_object");
    }
    print(");\n");
}

print <<"END";
  #ifndef ECL_ASM_APPLY
  cl_object
  APPLY(cl_narg n, cl_objectfn fn, cl_object *x)
  {
    nlogd(">>FUCK APPLY n:%d", n);
  
    switch (n) {
   
END

for (my $i=0; $i<=$up; $i++) {
    printf("    case %d: return (*((t_f%d)(fn)))(n,", $i);
    for (my $j=0; $j<$i; $j++) {
        print(",x[%d]", $j);
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

