#ifndef Rice__detail__define_method_and_auto_wrap__ipp_
#define Rice__detail__define_method_and_auto_wrap__ipp_

#include "wrap_function.hpp"
#include "method_data.hpp"
#include "Exception_Handler_defn.hpp"

template<typename Fun_T>
void Rice::detail::
define_method_and_auto_wrap(
    VALUE klass,
    char const * name,
    Fun_T function,
    Data_Object<Exception_Handler> handler)
{
  Wrapped_Function * f(wrap_function(function, handler));
  define_method_with_data(klass, name, f->func(), f->arity(), f);
}

#endif // Rice__detail__define_method_and_auto_wrap__ipp_
