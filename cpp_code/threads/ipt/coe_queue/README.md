$ g++ --std=c++17 -pthread -g3 coe_queue.cc
Как и в предидущем примере, только запускаем много раз пока не поймаем SEGV
$ perf record -e intel_pt/mtc,mtc_period=0/u ./a.out

snarpix@archlinux ~/t/c/t/I/coe_queue> perf record -e intel_pt/mtc,mtc_period=0/u ./a.out
[ perf record: Woken up 1 times to write data ]
[ perf record: Captured and wrote 1.073 MB perf.data ]
fish: “perf record -e intel_pt/mtc,mtc…” terminated by signal SIGSEGV (Address boundary error)

$ perf script -F tid,time,cpu,ip,sym,symoff,srccode,srcline --itrace=c --ns > dump.txt
$ grep 'safe_push\|safe_pop\|safe_empty' dump.txt
// Много проверок на empty до этого
// Первый пуш
11714 [007]  9567.486589889:      5603f4cdc4db safe_push+0x2a
|94           if (safe_empty()) {
11717 [003]  9567.486590014:      5603f4cdc5ed safe_empty+0x26
// Все еще первый пуш
11714 [007]  9567.486590055:      5603f4cdc4e7 safe_push+0x36
11714 [007]  9567.486590055:      5603f4cdc4f6 safe_push+0x45
|94           if (safe_empty()) {
11716 [002]  9567.486590347:      5603f4cdc5ed safe_empty+0x26
// Тоже первый пуш
11714 [007]  9567.486590472:      5603f4cdc502 safe_push+0x51
// Тред 11717 проверил на empty
11717 [003]  9567.486591222:      5603f4cdc5f9 safe_empty+0x32
11717 [003]  9567.486591264:      5603f4cdc608 safe_empty+0x41
// Тред 11716 проверил на empty
11716 [002]  9567.486591930:      5603f4cdc5f9 safe_empty+0x32
11716 [002]  9567.486591930:      5603f4cdc608 safe_empty+0x41
|98           task_t cur = safe_pop();
// Тред 11717 делает pop
11717 [003]  9567.486591930:      5603f4cdc568 safe_pop+0x29
11717 [003]  9567.486592014:      5603f4cdc574 safe_pop+0x35
11717 [003]  9567.486592014:      5603f4cdc57c safe_pop+0x3d
11717 [003]  9567.486592055:      5603f4cdc58e safe_pop+0x4f
11717 [003]  9567.486592347:      5603f4cdc59a safe_pop+0x5b
11717 [003]  9567.486592389:      5603f4cdc5a7 safe_pop+0x68
|98           task_t cur = safe_pop();
// Тред 11716 делает pop пустой очереди
11716 [002]  9567.486592472:      5603f4cdc568 safe_pop+0x29
11716 [002]  9567.486592555:      5603f4cdc574 safe_pop+0x35
11716 [002]  9567.486592639:      5603f4cdc57c safe_pop+0x3d
11716 [002]  9567.486592639:      5603f4cdc58e safe_pop+0x4f
11716 [002]  9567.486592889:      5603f4cdc59a safe_pop+0x5b
11716 [002]  9567.486592972:      5603f4cdc5a7 safe_pop+0x68
