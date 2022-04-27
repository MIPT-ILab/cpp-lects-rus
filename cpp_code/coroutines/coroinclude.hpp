//------------------------------------------------------------------------------
//
// Header for coroutines include
//
// clang/MSVC still keeps coroutine support in experimental header
// and namespace as std::experimental
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#pragma once

#if defined(__clang__) || defined(_WIN32)
#include <experimental/coroutine>
namespace coro = std::experimental;
#else
#include <coroutine>
namespace coro = std;
#endif