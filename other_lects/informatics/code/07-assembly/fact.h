#pragma once

#ifndef MYABI
#define MYABI __attribute__((sysv_abi))
#endif

MYABI int fact(int x);

