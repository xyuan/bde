/* stddef.h                                                          -*-C-*- */
#ifndef INCLUDED_NATIVE_C_STDDEF
#define INCLUDED_NATIVE_C_STDDEF

#include <bsls_ident.h>
BSLS_IDENT("$Id: $")

/*
//@PURPOSE: Provide functionality of the corresponding C++ Standard header.
//
//@SEE_ALSO: package bos+stdhdrs
//
//@DESCRIPTION: Provide functionality of the corresponding C++ standard header.
// This file includes the compiler provided native standard header.  In
// addition, in 'bde-stl' mode (used by Bloomberg managed code, see
// 'bos+stdhdrs.txt' for more information) include the corresponding header in
// 'bsl+bslhdrs' as well as 'bos_stdhdrs_prologue.h' and
// 'bos_stdhdrs_epilogue.h'.  This includes the respective 'bsl' types and
// places them in the 'std' namespace.
*/

/*
// Note that 'stddef.h' is meant for multiple inclusion on Linux, so only the
// ident is protected by the include guard.
*/

#endif  /* INCLUDED_NATIVE_C_STDDEF */

#include <bsls_compilerfeatures.h>

#if !defined(BSL_OVERRIDES_STD) || !defined(__cplusplus)
#   include <bos_stdhdrs_incpaths.h>

#   if defined(BSLS_COMPILERFEATURES_SUPPORT_INCLUDE_NEXT)
#     include_next <stddef.h>
#   else
#     include BSL_NATIVE_OS_STDDEF_HEADER(stddef.h)
#   endif

#else  /* defined(BSL_OVERRIDES_STD) */

#   ifndef BOS_STDHDRS_PROLOGUE_IN_EFFECT
#   include <bos_stdhdrs_prologue.h>
#   endif

#   ifndef BOS_STDHDRS_RUN_EPILOGUE
#   define BOS_STDHDRS_RUN_EPILOGUE
#   define BOS_STDHDRS_EPILOGUE_RUN_BY_c_stddef
#   endif
#   include <bos_stdhdrs_incpaths.h>

#   if defined(BSLS_COMPILERFEATURES_SUPPORT_INCLUDE_NEXT)
#     include_next <stddef.h>
#   else
#     include BSL_NATIVE_OS_STDDEF_HEADER(stddef.h)
#   endif

// On SUN, 'stddef.h' (a C header) defines 'size_t'.  This odd implementation
// forces the following 'using' directive.
#   ifdef BSLS_PLATFORM_CMP_SUN

// This C header file might be included within an 'extern "C"' block.  To avoid
// defining C++ symbols in an 'extern "C"' block, wrap the C++ code with an
// 'extern "C++"' block.
extern "C++" {

    namespace bsl {
        // Import selected symbols into bsl namespace
        using native_std::size_t;
    }

}  // extern "C++"

#   endif  // BSLS_PLATFORM_CMP_SUN

#   ifdef BOS_STDHDRS_EPILOGUE_RUN_BY_c_stddef
#   undef BOS_STDHDRS_EPILOGUE_RUN_BY_c_stddef
#   include <bos_stdhdrs_epilogue.h>
#   endif

#endif  /* BSL_OVERRIDES_STD */

/*
// ----------------------------------------------------------------------------
// Copyright 2013 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------
*/
