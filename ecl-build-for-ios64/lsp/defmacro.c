/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;DEFMACRO.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "lsp/defmacro.eclh"
/*	function definition for SEARCH-KEYWORD                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_search_keyword(cl_narg narg, cl_object v1list, cl_object v2key, ...)
{