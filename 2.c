/*Name: Bhavya Joshi
Reg no.:MT2024032
2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
*/

#include<stdio.h>

int main(){
while(1){
}
return 0;
}


/*Output:
bhavya@Bhavya:/proc$ cd 3767
bhavya@Bhavya:/proc/3767$ ls
arch_status  clear_refs          cpuset   fdinfo             limits     mountinfo   numa_maps      patch_state  schedstat     stack    task            wchan
attr         cmdline             cwd      gid_map            loginuid   mounts      oom_adj        personality  sessionid     stat     timens_offsets
autogroup    comm                environ  io                 map_files  mountstats  oom_score      projid_map   setgroups     statm    timers
auxv         coredump_filter     exe      ksm_merging_pages  maps       net         oom_score_adj  root         smaps         status   timerslack_ns
cgroup       cpu_resctrl_groups  fd       ksm_stat           mem        ns          pagemap        sched        smaps_rollup  syscall  uid_map
bhavya@Bhavya:/proc/3767$ cat status
Name:	a.out
Umask:	0002
State:	R (running)
Tgid:	3767
Ngid:	0
Pid:	3767
PPid:	3747
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 118 1000 
NStgid:	3767
NSpid:	3767
NSpgid:	3767
NSsid:	3747
VmPeak:	    2544 kB
VmSize:	    2484 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	     896 kB
VmRSS:	     896 kB
RssAnon:	       0 kB
RssFile:	     896 kB
RssShmem:	       0 kB
VmData:	      92 kB
VmStk:	     132 kB
VmExe:	       4 kB
VmLib:	    1672 kB
VmPTE:	      36 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
Threads:	1
SigQ:	0/30109
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	ffff
Cpus_allowed_list:	0-15
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	0
nonvoluntary_ctxt_switches:	614

*/
