//
//  bootstrap.c
//  electra
//  Th0r
//  Created by Jamie Bishop on 11/02/2018.
//  Copyright © 2018 Electra Team. All rights reserved.
//

#include "bootstrap.h"
#include "file_utils.h"
#include "fun_objc.h"
#include "amfi_utils.h"
#include "utils.h"
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <spawn.h>

#define tar "/Th0r/tar"

pid_t pd;

void copy_tar() {
    extractGz("tar", "/Th0r/tar");
    chmod(tar, 0755);
    inject_trusts(1, (const char **)&(const char*[]){tar});
}

void copy_basebinaries() {
    mkdir("/Th0r", 0755);
    
    copy_tar();
    
    // Remove old base binaries
    unlink("/Th0r/inject_amfid");
    unlink("/Th0r/inject_launchd");
    unlink("/Th0r/launchd_payload.dylib");
    unlink("/Th0r/xpcproxy_payload.dylib");
    
    unlink("/Th0r/inject_ctriticald");
    unlink("/Th0r/pspawn_payload.dylib");
    
    unlink("/Th0r/amfid_payload.dylib");
    unlink("/Th0r/launchjailbreak");
    unlink("/Th0r/jailbreakd");
    
    extractGz("rm","/Th0r/rm");
    chmod("/Th0r/rm", 0755);
    
    posix_spawn(&pd, tar, NULL, NULL, (char **)&(const char*[]){ tar, "-xpf", progname("basebinaries.tar"), "-C", "/Th0r", NULL }, NULL);
    waitpid(pd, NULL, 0);
    
    printf("[bootstrapper] copied the required binaries into the right places\n");
    
    inject_trusts(4, (const char **)&(const char*[]){
        "/Th0r/inject_criticald",
        "/Th0r/amfid_payload.dylib",
        "/Th0r/pspawn_payload.dylib",
        "/Th0r/libjailbreak.dylib"
    });
}

void extract_bootstrap() {
    unlink("/bin/launchctl");
    extractGz("launchctl", "/Th0r/launchctl");
    cp("/bin/launchctl", "/Th0r/launchctl");
    chmod("/bin/launchctl", 0755);
    unlink("/Th0r/launchctl");
    //REMOVED check for file bootstrapped if ever jalbroken before IGNORE - Do not close bootstarp extraction
    installingCydia();
    
    
    
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/Applications/Cydia.app", NULL }, NULL);
    waitpid(pd, NULL, 0);
    
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/share/terminfo", NULL }, NULL);
    waitpid(pd, NULL, 0);
    
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/local/bin", NULL }, NULL);
    waitpid(pd, NULL, 0);
    
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/local/lib", NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/bash",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/dd",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/ln",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/sed",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/vdir",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/bunzip2",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/dir",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/ls",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/sh",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/zcat",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/bzcat",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/echo",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/mkdir",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/sleep",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/zcmp",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/bzip2",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/egrep",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/mknod",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/stty",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/zdiff",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/bzip2recover",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/false",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/mktemp",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/su",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/zegrep",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/cat",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/fgrep",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/mv",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/sync",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/zfgrep",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/chgrp",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/grep",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/pwd",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/tar",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/zforce",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/chmod",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/gunzip",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/readlink",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/touch",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/zgrep",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/chown",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/gzexe",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/rm",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/true",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/zless",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/cp",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/gzip",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/rmdir",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/uname",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/zmore",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/date",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/kill",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/run-parts",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/uncompress",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/znew",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/private/var/run/utmp",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/sbin/reboot",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/sbin/halt",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/sbin/dmesg",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/sbin/dynamic_pager",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/sbin/nologin",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/lzmainfo",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/iomfsetgamma",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/chsh",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/gpgv",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/toe",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/cmp",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/locate",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/cfversion",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/gpg-zip",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dselect",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/infotocap",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/ncursesw5-config",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-deb",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/diff3",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/sw_vers",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/gpg",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/df",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/renice",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/captoinfo",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-name",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/bashbug",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-split",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/chfn",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/tset",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/unlzma",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/uicache",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/reset",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/pagesize",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/gpgsplit",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/diff",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/uiopen",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-trigger",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/updatedb",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/ncurses5-config",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/script",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/ldrestart",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/time",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/sbdidlaunch",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/clear",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/tic",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/getconf",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/lzless",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-query",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/infocmp",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/lzcmp",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/arch",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/xargs",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/getty",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/lzcat",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/ldid",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/uiduid",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dirname",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/lzdiff",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/find",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/lzmadec",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/lzgrep",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/sdiff",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/lzmore",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/tput",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/lzfgrep",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/hostinfo",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/tar",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/lzma",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/sbreload",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/login",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/which",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/gssc",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/apt-key",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/lzegrep",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/passwd",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libhistory.5.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libapt-pkg.dylib.4.6",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpam.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpamc.1.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libapt-pkg.dylib.4.6.0",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpanelw.5.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libhistory.5.2.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libreadline.6.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpanel.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libapt-inst.dylib.1.1",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libcurses.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/liblzmadec.0.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libhistory.6.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libformw.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libncursesw.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libapt-inst.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libncurses.5.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libapt-pkg.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libreadline.5.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libhistory.6.0.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libform.5.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpanelw.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libmenuw.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libform.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/terminfo",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpam.1.0.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libmenu.5.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpatcyh.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libreadline.6.0.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/liblzmadec.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libncurses.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libhistory.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpamc.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libformw.5.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libapt-inst.dylib.1.1.0",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpanel.5.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/liblzmadec.0.0.0.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/_ncurses",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpam_misc.1.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libreadline.5.2.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpam_misc.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libreadline.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libmenuw.5.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libpam.1.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libmenu.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/liblzmadec.la",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libncursesw.5.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/libexec/frcode",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/libexec/bigram",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/libexec/code",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/libexec/reload",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/libexec/rmt",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/accton",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/vifs",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/ac",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/update",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/pwd_mkdb",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/sysctl",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/zdump",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/startupfiletool",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/iostat",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/mkfile",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/zic",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/vipw",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/share/dict",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/gtar",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dselect",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/cycc",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-statoverride",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-deb",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-divert",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/cynject",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/update-alternatives",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-split",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/uicache",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-trigger",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-maintscript-helper",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/env",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/gnutar",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/cycript",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg-query",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/apt",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/apt-get",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/bin/dpkg",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/libexec/MSUnrestrictProcess",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/libexec/substrate",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/sbin/start-stop-daemon",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libcycript.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libcycript.jar",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libapt-inst.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libapt-pkg.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libdpkg.a",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libcrypto.1.0.0.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libssl.1.0.0.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libcycript.db",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libcurl.4.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libcycript.0.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libcycript.cy",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libdpkg.la",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/lib/libsubstrate.0.dylib",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/cat",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/pwd",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/sed",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/sleep",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/stty",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/date",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/bzip2_64",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/kill",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/sh",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/dd",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/mkdir",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/hostname",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/rmdir",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/mv",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/ln",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/ls",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/cp",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/chown",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/chmod",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/rm",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/bin/bzip2",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/Library/test_inject_springboard.cy",NULL }, NULL);
    waitpid(pd, NULL, 0);
    posix_spawn(&pd, "/Th0r/rm", NULL, NULL, (char **)&(const char*[]){ "rm", "-rf", "/usr/local/lib/libluajit.a",NULL }, NULL);
    waitpid(pd, NULL, 0);
    
    
    unlink("/bin/zsh");
    unlink("/etc/profile");
    unlink("/etc/zshrc");
    
    unlink("/usr/bin/scp"); //missing from removeMe.sh oddly
//removed check for cydia so it forces an install of the bootstrap all over again
    extractGz("bootstrap.tar", "/Th0r/bootstrap.tar");
//TOOK the -k flag out so files will overwrite if need be
    posix_spawn(&pd, tar, NULL, NULL, (char **)&(const char*[]){ tar, "--preserve-permissions", "-xvf", "/Th0r/bootstrap.tar", "-C", "/", NULL }, NULL);
    waitpid(pd, NULL, 0);

    unlink("/Th0r/bootstrap.tar");
    
    unlink("/usr/libexec/cydia/move.sh");
    
    cp("/usr/libexec/cydia/move.sh", progname("move.sh"));
    
    int rv = open("/.bootstrapped_electra", O_RDWR|O_CREAT);
    close(rv);
    rv = open("/.cydia_no_stash",O_RDWR|O_CREAT);
    close(rv);
    
    printf("[bootstrapper] extracted bootstrap to / \n");
    post_bootstrap(true);
}

void post_bootstrap(const bool runUICache) {
    pid_t pd;
    
    if (runUICache){
        posix_spawn(&pd, "/usr/bin/uicache", NULL, NULL, (char **)&(const char*[]){ "uicache", NULL }, NULL);
        waitpid(pd, NULL, 0);
    }
    
    unlink(tar);
    
    FILE *file;
    file = fopen("/etc/hosts","w"); /* write file (create a file if it does not exist and if it does treat as empty.*/
    fprintf(file,"%s","##\n"); //writes
    fprintf(file,"%s","# Host Database\n"); //writes
    fprintf(file,"%s","# localhost is used to configure the loopback interface\n"); //writes
    fprintf(file,"%s","# when the system is booting.  Do not change this entry.\n"); //writes
    fprintf(file,"%s","##\n"); //writes
    fprintf(file,"%s","127.0.0.1    localhost\n"); //writes
    fprintf(file,"%s","255.255.255.255 broadcasthost\n"); //writes
    fprintf(file,"%s","::1      localhost\n"); //writes
    fclose(file); /*done!*/
    
    file = fopen("/etc/apt/sources.list.d/electra.list","w"); /* write file (create a file if it does not exist and if it does treat as empty.*/
    fprintf(file,"%s","deb https://electrarepo64.coolstar.org/ ./\n"); //writes
    fprintf(file,"%s","\n"); //writes
    fclose(file);
    
    file = fopen("/etc/apt/sources.list.d/electra-shim.list","w"); /* write file (create a file if it does not exist and if it does treat as empty.*/
    fprintf(file,"%s","deb https://electrarepo64.coolstar.org/substrate-shim/ ./\n"); //writes
    fprintf(file,"%s","\n"); //writes
    fclose(file);
    
    unlink("/usr/lib/libjailbreak.dylib");
    cp("/usr/lib/libjailbreak.dylib","/Th0r/libjailbreak.dylib");
    
    inject_trusts(1, (const char **)&(const char*[]){"/bin/launchctl"});
    
    int rv = open("/var/lib/dpkg/available", O_RDWR|O_CREAT);
    close(rv);
    
    posix_spawn(&pd, "/bin/bash", NULL, NULL, (char **)&(const char*[]){ "bash", "/usr/libexec/cydia/firmware.sh", NULL }, NULL);
    waitpid(pd, NULL, 0);
    
    posix_spawn(&pd, "/bin/bash", NULL, NULL, (char **)&(const char*[]){ "bash", "/Library/dpkg/info/openssh.postinst", NULL }, NULL);
    waitpid(pd, NULL, 0);
    
    posix_spawn(&pd, "/bin/launchctl", NULL, NULL, (char **)&(const char*[]){ "launchctl", "load", "/Library/LaunchDaemons/com.openssh.sshd.plist", NULL }, NULL);
    waitpid(pd, NULL, 0);
    
    
    run("rm /var/lib/apt/lists/apt.saurik.com*");
    blockSaurikRepo();
    
    char *myenviron[] = {
        "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/bin/X11:/usr/games",
        "PS1=\\h:\\w \\u\\$ ",
        NULL
    };

    posix_spawn(&pd, "/usr/bin/dpkg", NULL, NULL, (char **)&(const char*[]){ "dpkg", "-i", "--refuse-downgrade", progname("/apt7-lib_0.7.25.3-16-coolstar_iphoneos-arm.deb"), NULL }, (char **)&myenviron);
    waitpid(pd, NULL, 0);
    
    printf("[bootstrapper] device has been bootstrapped!\n");
    
    if (runUICache){
        cydiaDone();
    }
}

