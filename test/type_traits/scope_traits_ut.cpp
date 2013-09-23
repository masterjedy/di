//
// Copyright (c) 2012-2013 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "boost/di/type_traits/scope_traits.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/type_traits/is_same.hpp>

#include "boost/di/named.hpp"

#if defined(__GNUC__) && (__GNUC__ >= 4)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations" // std::auto_ptr
#endif

#if defined(__INTEL_COMPILER)
    #pragma warning push
    #pragma warning(disable:1478) //class "std::auto_ptr<...>" was declared deprecated
#endif

namespace boost {
namespace di {
namespace type_traits {

struct c { };

BOOST_AUTO_TEST_CASE(basic) {
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<int>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<named<int>>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<c>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<named<c>>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<const int&>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<named<const int&>>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<int*>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<named<int*>>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<const int*>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<named<const int*>>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<std::auto_ptr<int>>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<named<std::auto_ptr<int>>>::type>::value));
    BOOST_CHECK((is_same<scopes::singleton<>, scope_traits<shared_ptr<int>>::type>::value));
    BOOST_CHECK((is_same<scopes::singleton<>, scope_traits<named<shared_ptr<int>>>::type>::value));
    BOOST_CHECK((is_same<scopes::external<>, scope_traits<int&>::type>::value));
    BOOST_CHECK((is_same<scopes::external<>, scope_traits<named<int&>>::type>::value));

#if !defined(BOOST_NO_CXX11_SMART_PTR)
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<std::unique_ptr<int>>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<named<std::unique_ptr<int>>>::type>::value));
    BOOST_CHECK((is_same<scopes::singleton<>, scope_traits<std::shared_ptr<int>>::type>::value));
    BOOST_CHECK((is_same<scopes::singleton<>, scope_traits<named<std::shared_ptr<int>>>::type>::value));
#endif

#if !defined(BOOST_NO_RVALUE_REFERENCES)
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<int&&>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<named<int&&>>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<const int&&>::type>::value));
    BOOST_CHECK((is_same<scopes::per_request<>, scope_traits<named<const int&&>>::type>::value));
#endif
}

} // namespace type_traits
} // namespace di
} // namespace boost

#if defined(__GNUC__) && (__GNUC__ >= 4)
    #pragma GCC diagnostic pop
#endif

#if defined(__INTEL_COMPILER)
    #pragma warning pop
#endif

