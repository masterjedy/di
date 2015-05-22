//
// Copyright (c) 2012-2015 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef BOOST_DI_FWD_HPP
#define BOOST_DI_FWD_HPP

namespace boost {

template<class> class shared_ptr;

namespace di { inline namespace v1 {

struct no_name {
    const char* operator()() const noexcept { return nullptr; }
};

class config;

template<class...>
class injector;

namespace aux {
    struct none_type;
};

namespace core {

template<class> struct any_type_fwd;
template<class> struct any_type_ref_fwd;

template<
    class TScope
  , class TExpected
  , class TGiven = TExpected
  , class TName = no_name
  , class TPriority = aux::none_type
> struct dependency;
} // core

namespace providers { class heap; class stack_over_heap; } // providers

}}} // boost::di::v1

#endif

