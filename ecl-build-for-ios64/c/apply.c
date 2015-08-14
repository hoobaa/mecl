#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/apply.d"
  #include <ecl/ecl.h>
typedef cl_object (*t_f0)(cl_narg);
typedef cl_object (*t_f1)(cl_narg,cl_object);
typedef cl_object (*t_f2)(cl_narg,cl_object,cl_object);
typedef cl_object (*t_f3)(cl_narg,cl_object,cl_object,cl_object);
typedef cl_object (*t_f4)(cl_narg,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f5)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f6)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f7)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f8)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f9)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f10)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f11)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f12)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f13)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f14)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f15)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f16)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f17)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f18)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f19)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f20)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f21)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f22)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f23)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f24)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f25)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f26)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f27)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f28)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f29)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f30)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f31)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f32)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f33)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f34)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f35)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f36)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f37)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f38)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f39)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f40)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f41)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f42)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f43)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f44)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f45)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f46)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f47)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f48)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f49)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f50)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f51)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f52)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f53)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f54)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f55)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f56)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f57)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f58)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f59)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f60)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f61)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f62)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f63)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
typedef cl_object (*t_f64)(cl_narg,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object,cl_object);
  #ifndef ECL_ASM_APPLY
  cl_object
  APPLY(cl_narg n, cl_objectfn fn, cl_object *x)
  {
    nlogd(">>FUCK APPLY n:%d", n);
  
    switch (n) {
   
    case 0: return (*((t_f0)(fn)))(n);
    case 1: return (*((t_f1)(fn)))(n,x[0]);
    case 2: return (*((t_f2)(fn)))(n,x[0],x[1]);
    case 3: return (*((t_f3)(fn)))(n,x[0],x[1],x[2]);
    case 4: return (*((t_f4)(fn)))(n,x[0],x[1],x[2],x[3]);
    case 5: return (*((t_f5)(fn)))(n,x[0],x[1],x[2],x[3],x[4]);
    case 6: return (*((t_f6)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5]);
    case 7: return (*((t_f7)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6]);
    case 8: return (*((t_f8)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7]);
    case 9: return (*((t_f9)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8]);
    case 10: return (*((t_f10)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9]);
    case 11: return (*((t_f11)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10]);
    case 12: return (*((t_f12)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11]);
    case 13: return (*((t_f13)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12]);
    case 14: return (*((t_f14)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13]);
    case 15: return (*((t_f15)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14]);
    case 16: return (*((t_f16)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15]);
    case 17: return (*((t_f17)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16]);
    case 18: return (*((t_f18)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17]);
    case 19: return (*((t_f19)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18]);
    case 20: return (*((t_f20)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19]);
    case 21: return (*((t_f21)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20]);
    case 22: return (*((t_f22)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21]);
    case 23: return (*((t_f23)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22]);
    case 24: return (*((t_f24)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23]);
    case 25: return (*((t_f25)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24]);
    case 26: return (*((t_f26)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25]);
    case 27: return (*((t_f27)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26]);
    case 28: return (*((t_f28)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27]);
    case 29: return (*((t_f29)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28]);
    case 30: return (*((t_f30)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29]);
    case 31: return (*((t_f31)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30]);
    case 32: return (*((t_f32)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31]);
    case 33: return (*((t_f33)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32]);
    case 34: return (*((t_f34)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33]);
    case 35: return (*((t_f35)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34]);
    case 36: return (*((t_f36)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35]);
    case 37: return (*((t_f37)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36]);
    case 38: return (*((t_f38)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37]);
    case 39: return (*((t_f39)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38]);
    case 40: return (*((t_f40)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39]);
    case 41: return (*((t_f41)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40]);
    case 42: return (*((t_f42)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41]);
    case 43: return (*((t_f43)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42]);
    case 44: return (*((t_f44)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43]);
    case 45: return (*((t_f45)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44]);
    case 46: return (*((t_f46)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45]);
    case 47: return (*((t_f47)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46]);
    case 48: return (*((t_f48)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47]);
    case 49: return (*((t_f49)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48]);
    case 50: return (*((t_f50)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49]);
    case 51: return (*((t_f51)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50]);
    case 52: return (*((t_f52)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51]);
    case 53: return (*((t_f53)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51],x[52]);
    case 54: return (*((t_f54)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51],x[52],x[53]);
    case 55: return (*((t_f55)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51],x[52],x[53],x[54]);
    case 56: return (*((t_f56)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51],x[52],x[53],x[54],x[55]);
    case 57: return (*((t_f57)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51],x[52],x[53],x[54],x[55],x[56]);
    case 58: return (*((t_f58)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51],x[52],x[53],x[54],x[55],x[56],x[57]);
    case 59: return (*((t_f59)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51],x[52],x[53],x[54],x[55],x[56],x[57],x[58]);
    case 60: return (*((t_f60)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51],x[52],x[53],x[54],x[55],x[56],x[57],x[58],x[59]);
    case 61: return (*((t_f61)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51],x[52],x[53],x[54],x[55],x[56],x[57],x[58],x[59],x[60]);
    case 62: return (*((t_f62)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51],x[52],x[53],x[54],x[55],x[56],x[57],x[58],x[59],x[60],x[61]);
    case 63: return (*((t_f63)(fn)))(n,x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11],x[12],x[13],x[14],x[15],x[16],x[17],x[18],x[19],x[20],x[21],x[22],x[23],x[24],x[25],x[26],x[27],x[28],x[29],x[30],x[31],x[32],x[33],x[34],x[35],x[36],x[37],x[38],x[39],x[40],x[41],x[42],x[43],x[44],x[45],x[46],x[47],x[48],x[49],x[50],x[51],x[52],x[53],x[54],x[55],x[56],x[57],x[58],x[59],x[60],x[61],x[62]);
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
  cl_object
  APPLY_fixed(cl_narg n, cl_object (*fn)(), cl_object *x)
  {
    switch (n) {
    case 0:  return (*fn)();
    case 1:  return (*fn)(x[0]);
    case 2:  return (*fn)(x[0],x[1]);
    case 3:  return (*fn)(x[0],x[1],x[2]);
    case 4:  return (*fn)(x[0],x[1],x[2],x[3]);
    case 5:  return (*fn)(x[0],x[1],x[2],x[3],x[4]);
    case 6:  return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5]);
    case 7:  return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6]);
    case 8:  return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7]);
    case 9:  return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		     x[8]);
    case 10: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9]);
    case 11: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10]);
    case 12: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11]);
    case 13: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12]);
    case 14: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13]);
    case 15: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14]);
    case 16: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15]);
    case 17: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16]);
    case 18: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17]);
    case 19: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18]);
    case 20: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19]);
    case 21: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20]);
    case 22: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21]);
    case 23: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22]);
    case 24: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23]);
    case 25: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24]);
    case 26: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25]);
    case 27: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26]);
    case 28: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27]);
    case 29: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28]);
    case 30: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29]);
    case 31: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30]);
    case 32: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31]);
    case 33: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32]);
    case 34: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33]);
    case 35: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34]);
    case 36: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35]);
    case 37: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36]);
    case 38: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37]);
    case 39: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38]);
    case 40: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39]);
    case 41: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40]);
    case 42: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41]);
    case 43: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42]);
    case 44: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43]);
    case 45: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44]);
    case 46: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45]);
    case 47: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46]);
    case 48: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47]);
    case 49: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48]);
    case 50: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49]);
    case 51: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50]);
    case 52: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51]);
    case 53: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52]);
    case 54: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52],x[53]);
    case 55: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52],x[53],x[54]);
    case 56: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52],x[53],x[54],x[55]);
    case 57: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52],x[53],x[54],x[55],x[56]);
    case 58: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52],x[53],x[54],x[55],x[56],
  		      x[57]);
    case 59: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52],x[53],x[54],x[55],x[56],
  		      x[57],x[58]);
    case 60: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52],x[53],x[54],x[55],x[56],
  		      x[57],x[58],x[59]);
    case 61: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52],x[53],x[54],x[55],x[56],
  		      x[57],x[58],x[59],x[60]);
    case 62: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52],x[53],x[54],x[55],x[56],
  		      x[57],x[58],x[59],x[60],x[61]);
    case 63: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52],x[53],x[54],x[55],x[56],
  		      x[57],x[58],x[59],x[60],x[61],x[62]);
    case 64: return (*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
  		      x[8],x[9],x[10],x[11],x[12],x[13],x[14],
  		      x[15],x[16],x[17],x[18],x[19],x[20],x[21],
  		      x[22],x[23],x[24],x[25],x[26],x[27],x[28],
  		      x[29],x[30],x[31],x[32],x[33],x[34],x[35],
  		      x[36],x[37],x[38],x[39],x[40],x[41],x[42],
  		      x[43],x[44],x[45],x[46],x[47],x[48],x[49],
  		      x[50],x[51],x[52],x[53],x[54],x[55],x[56],
  		      x[57],x[58],x[59],x[60],x[61],x[62],x[63]);
    default:
  	  FEprogram_error_noreturn("Too many arguments", 0);
    }
  }
  #endif
