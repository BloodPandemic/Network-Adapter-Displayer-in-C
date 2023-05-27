#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdlib.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_BOLD    "\033[1m"
#define COLOR_CYAN    "\033[36m"

void printInterfaceInfo(struct ifaddrs *address) {
  int family = address->ifa_addr->sa_family;
  if (family == AF_INET || family == AF_INET6) {
    printf(COLOR_BOLD "%s" COLOR_RESET "\t", address->ifa_name);
    printf(COLOR_CYAN "%s" COLOR_RESET "\t", (family == AF_INET) ? "IPv4" : "IPv6");

    char ap[100];
    const int family_size = (family == AF_INET) ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
    getnameinfo(address->ifa_addr, family_size, ap, sizeof(ap), 0, 0, NI_NUMERICHOST);
    printf(COLOR_RESET "%s\n", ap);
  }
}

int main() {
  struct ifaddrs *addresses;
  if (getifaddrs(&addresses) == -1) {
    printf("getifaddrs call failed\n");
    return -1;
  }

  struct ifaddrs *address = addresses;
  while (address) {
    printInterfaceInfo(address);
    address = address->ifa_next;
  }

  freeifaddrs(addresses);
  return 0;
}
