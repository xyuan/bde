// bdlqq_threadargument.h                                              -*-C++-*-
#ifndef INCLUDED_BDLQQ_THREADARGUMENT
#define INCLUDED_BDLQQ_THREADARGUMENT

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$: $")

//@PURPOSE: Provide a type encapsulating an object with an allocator.
//
//@CLASSES:
//  ThreadArgument: A template for managing an object along with an allocator.
//
//@AUTHOR: David Schumann (dschumann1)
//
//@DESCRIPTION: This component defines a type, 'ThreadArgument', that contains
// a single instance of a templated type along with an allocator to manage it.
// It simplifies the need to dynamically allocate a copy of an object and store
// the allocator used alongside the object. The allocator is passed through
// to the copy constructor of the contained object if its type has traits
// indicating it uses 'bslma::Allocator'.

#ifndef INCLUDED_BSLSCM_VERSION
#include <bslscm_version.h>
#endif

#ifndef INCLUDED_BSLALG_CONSTRUCTORPROXY
#include <bslalg_constructorproxy.h>
#endif

namespace BloombergLP {

namespace bdlqq {

template <typename TYPE>
class ThreadArgument {
    // Hold a copy of an instance of parameterized type, along with the
    // allocator used to manage the copy.  'TYPE' shall have a copy constructor,
    // and declare the 'bslma::UsesBslmaAllocator' trait if it uses
    // 'bslma::Allocator' as an argument to its copy constructor.

    // DATA
    bslalg::ConstructorProxy<TYPE>  d_object;
    bslma::Allocator               *d_allocator_p;
    
 public:
    // CREATORS
    ThreadArgument(const TYPE& other, bslma::Allocator *allocator);
      // Create a new managed object holding a new instance of the specified
      // 'other' value and using the specified 'allocator' to manage memory.

    // ~ThreadArgument() = default;
        // Destroy this object and the underlying managed object.  Note that
        // this destructor is generated by the compiler.
    
    // ACCESSORS
    TYPE* object() const;
      // Return the address of the managed object.

    bslma::Allocator* allocator() const;
      // Return the allocator supplied at construction.
};

// ============================================================================
//                      INLINE FUNCTION DEFINITIONS
// ============================================================================

                        // -------------------
                        // class ThreadArgument
                        // -------------------

// CREATORS    
template <typename TYPE>
inline
ThreadArgument<TYPE>::ThreadArgument(const TYPE&       other,
                                   bslma::Allocator *allocator)
: d_object(other, allocator)
, d_allocator_p(allocator)
{}

// ACCESSORS
template <typename TYPE>
inline
TYPE* ThreadArgument<TYPE>::object() const {
    return const_cast<TYPE*>(&d_object.object());
}

template <typename TYPE>
inline
bslma::Allocator* ThreadArgument<TYPE>::allocator() const {
    return d_allocator_p;
}
    
}  // close package namespace
}  // close enterprise namespace

#endif

// ---------------------------------------------------------------------------
// Copyright 2015 Bloomberg Finance L.P.
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
// ----------------------------- END-OF-FILE ---------------------------------

    
