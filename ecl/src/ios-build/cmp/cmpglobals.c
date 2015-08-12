/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPGLOBALS.LSP                                */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpglobals.eclh"

#include "cmp/cmpglobals.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclXM15AMbFTaMi9_TpwTOE21(cl_object flag)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object *VVtemp;
 if (flag != OBJNULL){
 Cblock = flag;
 #ifndef ECL_DYNAMIC_VV
 flag->cblock.data = VV;
 #endif
 flag->cblock.data_size = VM;
 flag->cblock.temp_data_size = VMtemp;
 flag->cblock.data_text = compiler_data_text;
 flag->cblock.data_text_size = compiler_data_text_size;
 flag->cblock.cfuns_size = compiler_cfuns_size;
 flag->cblock.cfuns = compiler_cfuns;
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPGLOBALS.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclXM15AMbFTaMi9_TpwTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_special(VV[0]);
 if (ecl_boundp(cl_env_copy,VV[0])) { goto L3; }
 cl_set(VV[0],ecl_function_dispatch(cl_env_copy,VV[88])(0) /*  MAKE-INFO */);
L3:;
 si_Xmake_special(VV[1]);
 if (ecl_boundp(cl_env_copy,VV[1])) { goto L10; }
 cl_set(VV[1],ecl_make_fixnum(0));
L10:;
 si_Xmake_special(VV[2]);
 if (ecl_boundp(cl_env_copy,VV[2])) { goto L17; }
 cl_set(VV[2],ecl_make_fixnum(0));
L17:;
 si_Xmake_special(VV[3]);
 if (ecl_boundp(cl_env_copy,VV[3])) { goto L24; }
 cl_set(VV[3],ecl_make_fixnum(3));
L24:;
 si_Xmake_special(VV[4]);
 if (ecl_boundp(cl_env_copy,VV[4])) { goto L31; }
 cl_set(VV[4],VV[5]);
L31:;
 si_Xmake_special(VV[6]);
 if (ecl_boundp(cl_env_copy,VV[6])) { goto L38; }
 cl_set(VV[6],VV[5]);
L38:;
 si_Xmake_special(VV[7]);
 if (ecl_boundp(cl_env_copy,VV[7])) { goto L45; }
 cl_set(VV[7],ecl_make_fixnum(-1));
L45:;
 si_Xmake_special(VV[8]);
 if (ecl_boundp(cl_env_copy,VV[8])) { goto L52; }
 cl_set(VV[8],ECL_T);
L52:;
 si_Xmake_special(VV[9]);
 if (ecl_boundp(cl_env_copy,VV[9])) { goto L59; }
 cl_set(VV[9],ECL_NIL);
L59:;
 si_Xmake_special(VV[10]);
 if (ecl_boundp(cl_env_copy,VV[10])) { goto L66; }
 cl_set(VV[10],ECL_NIL);
L66:;
 si_Xmake_special(VV[11]);
 if (ecl_boundp(cl_env_copy,VV[11])) { goto L73; }
 cl_set(VV[11],ECL_NIL);
L73:;
 si_Xmake_special(ECL_SYM("*COMPILE-PRINT*",28));
 if (ecl_boundp(cl_env_copy,ECL_SYM("*COMPILE-PRINT*",28))) { goto L80; }
 cl_set(ECL_SYM("*COMPILE-PRINT*",28),ECL_NIL);
L80:;
 si_Xmake_special(ECL_SYM("*COMPILE-VERBOSE*",29));
 if (ecl_boundp(cl_env_copy,ECL_SYM("*COMPILE-VERBOSE*",29))) { goto L87; }
 cl_set(ECL_SYM("*COMPILE-VERBOSE*",29),ECL_NIL);
L87:;
 si_Xmake_special(VV[12]);
 if (ecl_boundp(cl_env_copy,VV[12])) { goto L94; }
 cl_set(VV[12],VVtemp[0]);
L94:;
 si_Xmake_special(VV[13]);
 if (ecl_boundp(cl_env_copy,VV[13])) { goto L101; }
 cl_set(VV[13],VV[14]);
L101:;
 si_Xmake_special(VV[15]);
 if (ecl_boundp(cl_env_copy,VV[15])) { goto L108; }
 cl_set(VV[15],ECL_NIL);
L108:;
 si_Xmake_special(VV[16]);
 if (ecl_boundp(cl_env_copy,VV[16])) { goto L115; }
 cl_set(VV[16],ECL_NIL);
L115:;
 si_Xmake_special(VV[17]);
 if (ecl_boundp(cl_env_copy,VV[17])) { goto L122; }
 cl_set(VV[17],ECL_NIL);
L122:;
 si_Xmake_special(VV[18]);
 if (ecl_boundp(cl_env_copy,VV[18])) { goto L129; }
 cl_set(VV[18],ECL_NIL);
L129:;
 si_Xmake_special(VV[19]);
 si_Xmake_special(VV[20]);
 si_Xmake_special(VV[21]);
 si_Xmake_special(VV[22]);
 if (ecl_boundp(cl_env_copy,VV[22])) { goto L148; }
 cl_set(VV[22],ECL_NIL);
L148:;
 si_Xmake_special(VV[23]);
 if (ecl_boundp(cl_env_copy,VV[23])) { goto L155; }
 cl_set(VV[23],ECL_T);
L155:;
 si_Xmake_special(VV[24]);
 si_Xmake_special(VV[25]);
 if (ecl_boundp(cl_env_copy,VV[25])) { goto L166; }
 cl_set(VV[25],ecl_make_fixnum(2));
L166:;
 si_Xmake_special(VV[26]);
 if (ecl_boundp(cl_env_copy,VV[26])) { goto L173; }
 cl_set(VV[26],ecl_make_fixnum(3));
L173:;
 si_Xmake_special(VV[27]);
 if (ecl_boundp(cl_env_copy,VV[27])) { goto L180; }
 cl_set(VV[27],ecl_make_fixnum(0));
L180:;
 si_Xmake_special(VV[28]);
 if (ecl_boundp(cl_env_copy,VV[28])) { goto L187; }
 cl_set(VV[28],ecl_make_fixnum(0));
L187:;
 si_Xmake_special(VV[29]);
 if (ecl_boundp(cl_env_copy,VV[29])) { goto L194; }
 cl_set(VV[29],ECL_T);
L194:;
 si_Xmake_special(VV[30]);
 if (ecl_boundp(cl_env_copy,VV[30])) { goto L201; }
 cl_set(VV[30],ecl_make_fixnum(0));
L201:;
 si_Xmake_special(VV[31]);
 if (ecl_boundp(cl_env_copy,VV[31])) { goto L208; }
 cl_set(VV[31],ecl_make_fixnum(0));
L208:;
 si_Xmake_special(VV[32]);
 if (ecl_boundp(cl_env_copy,VV[32])) { goto L215; }
 cl_set(VV[32],ecl_make_fixnum(0));
L215:;
 si_Xmake_special(VV[33]);
 if (ecl_boundp(cl_env_copy,VV[33])) { goto L222; }
 cl_set(VV[33],ecl_make_fixnum(0));
L222:;
 si_Xmake_special(VV[34]);
 if (ecl_boundp(cl_env_copy,VV[34])) { goto L229; }
 cl_set(VV[34],ecl_make_fixnum(0));
L229:;
 si_Xmake_special(VV[35]);
 if (ecl_boundp(cl_env_copy,VV[35])) { goto L236; }
 cl_set(VV[35],ecl_make_fixnum(0));
L236:;
 si_Xmake_special(VV[36]);
 if (ecl_boundp(cl_env_copy,VV[36])) { goto L243; }
 cl_set(VV[36],ecl_make_fixnum(0));
L243:;
 si_Xmake_special(VV[37]);
 if (ecl_boundp(cl_env_copy,VV[37])) { goto L250; }
 cl_set(VV[37],ecl_make_fixnum(0));
L250:;
 si_Xmake_special(VV[38]);
 if (ecl_boundp(cl_env_copy,VV[38])) { goto L257; }
 cl_set(VV[38],ecl_make_fixnum(0));
L257:;
 si_Xmake_special(VV[39]);
 if (ecl_boundp(cl_env_copy,VV[39])) { goto L264; }
 cl_set(VV[39],ECL_NIL);
L264:;
 si_Xmake_special(VV[40]);
 if (ecl_boundp(cl_env_copy,VV[40])) { goto L271; }
 cl_set(VV[40],ECL_NIL);
L271:;
 si_Xmake_special(VV[41]);
 if (ecl_boundp(cl_env_copy,VV[41])) { goto L278; }
 cl_set(VV[41],ecl_make_fixnum(0));
L278:;
 si_Xmake_special(VV[42]);
 if (ecl_boundp(cl_env_copy,VV[42])) { goto L285; }
 cl_set(VV[42],ecl_make_fixnum(0));
L285:;
 si_Xmake_special(VV[43]);
 if (ecl_boundp(cl_env_copy,VV[43])) { goto L292; }
 cl_set(VV[43],ECL_NIL);
L292:;
 si_Xmake_special(VV[44]);
 if (ecl_boundp(cl_env_copy,VV[44])) { goto L299; }
 cl_set(VV[44],ECL_T);
L299:;
 si_Xmake_special(VV[45]);
 if (ecl_boundp(cl_env_copy,VV[45])) { goto L306; }
 cl_set(VV[45],ecl_make_fixnum(0));
L306:;
 si_Xmake_special(VV[46]);
 si_Xmake_special(VV[47]);
 si_Xmake_special(VV[48]);
 if (ecl_boundp(cl_env_copy,VV[48])) { goto L321; }
 cl_set(VV[48],ECL_NIL);
L321:;
 si_Xmake_special(VV[49]);
 if (ecl_boundp(cl_env_copy,VV[49])) { goto L328; }
 cl_set(VV[49],ECL_NIL);
L328:;
 {
  cl_object T0, T1, T2;
 si_Xmake_special(VV[50]);
 if (ecl_boundp(cl_env_copy,VV[50])) { goto L335; }
 T0 = cl_constantly(ECL_NIL);
 T1 = cl_list(3, VV[51], ECL_SYM("MACRO",1101), T0);
 T2 = ecl_list1(T1);
 cl_set(VV[50],CONS(ECL_NIL,T2));
L335:;
 }
 si_Xmake_special(VV[52]);
 si_Xmake_special(VV[53]);
 if (ecl_boundp(cl_env_copy,VV[53])) { goto L346; }
 cl_set(VV[53],ECL_NIL);
L346:;
 si_Xmake_special(VV[54]);
 if (ecl_boundp(cl_env_copy,VV[54])) { goto L353; }
 cl_set(VV[54],ECL_T);
L353:;
 si_Xmake_special(VV[55]);
 if (ecl_boundp(cl_env_copy,VV[55])) { goto L360; }
 cl_set(VV[55],ECL_NIL);
L360:;
 si_Xmake_special(VV[56]);
 if (ecl_boundp(cl_env_copy,VV[56])) { goto L367; }
 cl_set(VV[56],ECL_NIL);
L367:;
 si_Xmake_special(VV[57]);
 if (ecl_boundp(cl_env_copy,VV[57])) { goto L374; }
 cl_set(VV[57],ECL_NIL);
L374:;
 si_Xmake_special(VV[58]);
 if (ecl_boundp(cl_env_copy,VV[58])) { goto L381; }
 cl_set(VV[58],ECL_T);
L381:;
 si_Xmake_special(VV[59]);
 if (ecl_boundp(cl_env_copy,VV[59])) { goto L388; }
 cl_set(VV[59],ECL_NIL);
L388:;
 si_Xmake_special(VV[60]);
 si_Xmake_special(VV[61]);
 if (ecl_boundp(cl_env_copy,VV[61])) { goto L399; }
 cl_set(VV[61],ecl_make_fixnum(0));
L399:;
 si_Xmake_special(VV[62]);
 if (ecl_boundp(cl_env_copy,VV[62])) { goto L406; }
 cl_set(VV[62],ECL_T);
L406:;
 si_Xmake_special(VV[63]);
 if (ecl_boundp(cl_env_copy,VV[63])) { goto L413; }
 cl_set(VV[63],ECL_NIL);
L413:;
 si_Xmake_special(VV[64]);
 if (ecl_boundp(cl_env_copy,VV[64])) { goto L420; }
 cl_set(VV[64],ECL_NIL);
L420:;
 si_Xmake_special(VV[65]);
 if (ecl_boundp(cl_env_copy,VV[65])) { goto L427; }
 cl_set(VV[65],ECL_NIL);
L427:;
 si_Xmake_special(VV[66]);
 if (ecl_boundp(cl_env_copy,VV[66])) { goto L434; }
 cl_set(VV[66],ECL_NIL);
L434:;
 si_Xmake_special(VV[67]);
 if (ecl_boundp(cl_env_copy,VV[67])) { goto L441; }
 cl_set(VV[67],ECL_NIL);
L441:;
 si_Xmake_special(VV[68]);
 if (ecl_boundp(cl_env_copy,VV[68])) { goto L448; }
 cl_set(VV[68],ECL_NIL);
L448:;
 si_Xmake_special(VV[69]);
 if (ecl_boundp(cl_env_copy,VV[69])) { goto L455; }
 cl_set(VV[69],ECL_NIL);
L455:;
 si_Xmake_special(VV[70]);
 if (ecl_boundp(cl_env_copy,VV[70])) { goto L462; }
 cl_set(VV[70],ECL_NIL);
L462:;
 si_Xmake_special(VV[71]);
 if (ecl_boundp(cl_env_copy,VV[71])) { goto L469; }
 cl_set(VV[71],ECL_NIL);
L469:;
 si_Xmake_special(VV[72]);
 if (ecl_boundp(cl_env_copy,VV[72])) { goto L476; }
 cl_set(VV[72],ECL_NIL);
L476:;
 si_Xmake_special(VV[73]);
 if (ecl_boundp(cl_env_copy,VV[73])) { goto L483; }
 cl_set(VV[73],ECL_NIL);
L483:;
 si_Xmake_special(ECL_SYM("*COMPILER-CONSTANTS*",1017));
 if (ecl_boundp(cl_env_copy,ECL_SYM("*COMPILER-CONSTANTS*",1017))) { goto L490; }
 cl_set(ECL_SYM("*COMPILER-CONSTANTS*",1017),ECL_NIL);
L490:;
 si_Xmake_special(VV[74]);
 if (ecl_boundp(cl_env_copy,VV[74])) { goto L497; }
 cl_set(VV[74],ECL_T);
L497:;
 si_Xmake_special(VV[75]);
 if (ecl_boundp(cl_env_copy,VV[75])) { goto L504; }
 cl_set(VV[75],ECL_NIL);
L504:;
 si_Xmake_special(VV[76]);
 if (ecl_boundp(cl_env_copy,VV[76])) { goto L511; }
 cl_set(VV[76],ECL_NIL);
L511:;
 si_Xmake_special(VV[77]);
 if (ecl_boundp(cl_env_copy,VV[77])) { goto L518; }
 cl_set(VV[77],ECL_NIL);
L518:;
 si_Xmake_special(VV[78]);
 if (ecl_boundp(cl_env_copy,VV[78])) { goto L525; }
 cl_set(VV[78],ECL_NIL);
L525:;
 si_Xmake_special(VV[79]);
 if (ecl_boundp(cl_env_copy,VV[79])) { goto L532; }
 cl_set(VV[79],ECL_NIL);
L532:;
 si_Xmake_special(VV[80]);
 if (ecl_boundp(cl_env_copy,VV[80])) { goto L539; }
 cl_set(VV[80],ECL_NIL);
L539:;
 si_Xmake_special(VV[81]);
 if (ecl_boundp(cl_env_copy,VV[81])) { goto L546; }
 cl_set(VV[81],ECL_NIL);
L546:;
 si_Xmake_special(VV[82]);
 if (ecl_boundp(cl_env_copy,VV[82])) { goto L553; }
 cl_set(VV[82],ECL_NIL);
L553:;
 si_Xmake_special(VV[83]);
 if (ecl_boundp(cl_env_copy,VV[83])) { goto L560; }
 cl_set(VV[83],ECL_NIL);
L560:;
 si_Xmake_special(VV[84]);
 if (ecl_boundp(cl_env_copy,VV[84])) { goto L567; }
 cl_set(VV[84],ECL_NIL);
L567:;
 si_Xmake_special(VV[85]);
 if (ecl_boundp(cl_env_copy,VV[85])) { goto L574; }
 cl_set(VV[85],ECL_NIL);
L574:;
 si_Xmake_special(VV[86]);
 if (ecl_boundp(cl_env_copy,VV[86])) { goto L581; }
 cl_set(VV[86],ECL_NIL);
L581:;
 si_Xmake_constant(VV[87], VVtemp[1]);
}
