#ifndef _IPTABLES_COMMON_H
#define _IPTABLES_COMMON_H

#ifdef __ANDROID__

/* Deal with collisions between iproute local include files and those
 * provided by the Android NDK toolchain.
 */
typedef unsigned short sa_family_t;

struct sockaddr {
 sa_family_t sa_family;
 char sa_data[14];
};

struct ucred {
 unsigned int pid;
 unsigned int uid;
 unsigned int gid;
};

struct winsize {
 unsigned short ws_row;
 unsigned short ws_col;
 unsigned short ws_xpixel;
 unsigned short ws_ypixel;
};


#define AF_UNSPEC 0
#define AF_UNIX 1
#define AF_INET 2
#define AF_IPX 4
#define AF_BRIDGE 7
#define AF_INET6 10
#define AF_NETLINK 16
#define AF_PACKET 17

#define PF_UNSPEC AF_UNSPEC
#define PF_INET AF_INET
#define PF_PACKET AF_PACKET
#define PF_INET6 AF_INET6
#define PF_BRIDGE AF_BRIDGE

#define SOCK_CLOEXEC 02000000
#define SOL_SOCKET 1
#define SO_SNDBUF 7
#define SO_RCVBUF 8
#define SO_PEERCRED 17

#define MSG_PEEK 2
#define MSG_TRUNC 0x20
#define MSG_DONTWAIT 0x40

#define SIOCDEVPRIVATE 0x89F0

typedef unsigned int __kernel_size_t;
struct msghdr {
 void * msg_name;
 int msg_namelen;
 struct iovec * msg_iov;
 __kernel_size_t msg_iovlen;
 void * msg_control;
 __kernel_size_t msg_controllen;
 unsigned msg_flags;
};

#define ND_OPT_PREFIX_INFORMATION	3

#endif


/* Shared definitions between ipv4 and ipv6. */

enum exittype {
	OTHER_PROBLEM = 1,
	PARAMETER_PROBLEM,
	VERSION_PROBLEM,
	RESOURCE_PROBLEM
};

/* this is a special 64bit data type that is 8-byte aligned */
#define aligned_u64 unsigned long long __attribute__((aligned(8)))

extern void exit_printhelp(void) __attribute__((noreturn));
extern void exit_tryhelp(int) __attribute__((noreturn));
int check_inverse(const char option[], int *invert, int *optind, int argc);
extern int string_to_number(const char *, 
			    unsigned int, 
			    unsigned int,
			    unsigned int *);
extern int string_to_number_l(const char *, 
			    unsigned long int, 
			    unsigned long int,
			    unsigned long *);
extern int string_to_number_ll(const char *, 
			    unsigned long long int, 
			    unsigned long long int,
			    unsigned long long *);
extern int iptables_insmod(const char *modname, const char *modprobe);
extern int load_iptables_ko(const char *modprobe);
void exit_error(enum exittype, char *, ...)__attribute__((noreturn,
							  format(printf,2,3)));
extern const char *program_name, *program_version;
extern char *lib_dir;

#define _init __attribute__((constructor)) my_init
#ifdef NO_SHARED_LIBS
# ifdef _INIT
#  undef _init
#  define _init _INIT
# endif
  extern void init_extensions(void);
#endif

#define __be32	u_int32_t
#define __le32	u_int32_t
#define __be16	u_int16_t
#define __le16	u_int16_t

#endif /*_IPTABLES_COMMON_H*/
