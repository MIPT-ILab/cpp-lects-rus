$ g++ --std=c++17 -pthread -g3 -DFOCUS 09-condvars.cc
$ perf record -e intel_pt/mtc,mtc_period=0/u ./a.out
mtc,mtc_period=0 - генерировать дополнительные пакеты трассы, чтобы повысить частоту timestampов
$ perf script -F comm,tid,time,cpu,ip,sym,symoff,srccode,srcline --itrace=c --ns > dump.txt
$ grep 'lock\|unlock\|wait\|notify\|std::cout' -B2 dump.txt

Результат(ручная выборка):
           a.out  9348 [006]  6627.437190773:      557def495294 processing+0x25
  09-condvars.cc:18
|18         std::cout << "w";
--
           a.out  9349 [001]  6627.437200315:      557def495294 processing+0x25
  09-condvars.cc:18
|18         std::cout << "w";
--
           a.out  9350 [007]  6627.437219065:      557def495323 preparation+0x25
  09-condvars.cc:31
|31           std::lock_guard<std::mutex> lk{gmut};
--
           a.out  9350 [007]  6627.437219898:      557def49533e preparation+0x40
  09-condvars.cc:34
|34           data_cond.notify_one();
--
           a.out  9350 [007]  6627.437220481:      557def4956dc std::lock_guard<std::mutex>::~lock_guard+0x16
  std_mutex.h:165
|165            { _M_device.unlock(); }
--
           a.out  9350 [007]  6627.437220981:      557def49535d preparation+0x5f
  09-condvars.cc:36
|36         std::cout << "+";
--
           a.out  9348 [006]  6627.437221606:      557def4952a7 processing+0x38
  09-condvars.cc:21
|21           std::unique_lock<std::mutex> lk{gmut};
--
           a.out  9348 [006]  6627.437221856:      557def4952ba processing+0x4b
  09-condvars.cc:22
|22           data_cond.wait(lk, []{ return counter > 0;});
--
           a.out  9348 [006]  6627.437221856:      557def495745 std::unique_lock<std::mutex>::~unique_lock+0x1f
  unique_lock.h:106
|106      	  unlock();
--
           a.out  9348 [006]  6627.437221940:      557def4952e2 processing+0x73
  09-condvars.cc:26
|26         std::cout << "-";
--
           a.out  9349 [001]  6627.437244356:      557def4956fb std::unique_lock<std::mutex>::unique_lock+0x17
  unique_lock.h:69
--
           a.out  9349 [001]  6627.437244565:      557def4952ba processing+0x4b
  09-condvars.cc:22
|22           data_cond.wait(lk, []{ return counter > 0;});
--
           a.out  9349 [001]  6627.437244606:      557def495745 std::unique_lock<std::mutex>::~unique_lock+0x1f
  unique_lock.h:106
|106      	  unlock();
--
           a.out  9349 [001]  6627.437244690:      557def4952e2 processing+0x73
  09-condvars.cc:26
|26         std::cout << "-";
--
           a.out  9346 [005]  6627.437287148:      557def4953fc main+0x83
  09-condvars.cc:47
|47         std::cout << "\n";

Есть еще способ посмотреть исполнение по инструкциям, но вывода столько что найти интересные моменты очень сложно:
perf script -F tid,time,cpu,ip,sym,symoff,insn,srccode,srcline --itrace=i1i --xed --ns > dump_insn.txt
Но там видно что потоки очень много тупят на загрузке динамических библиотек.
