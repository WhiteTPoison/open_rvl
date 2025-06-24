#pragma once

extern "C" {
int socket(int domain, int type, int protocal);
int bind(int socket, const struct sockaddr* address, int address_len);
int connect(int socket, const struct sockaddr* address, int address_len);
int closesocket(int socket);
u32 recvfrom(int socket, void* buffer, u32 length, int flags, struct sockaddr* address, u32* address_len);
u32 sendto(int socket, const void* message, u32 length, int flags, const struct sockaddr* dest_addr, u32 dest_len);
bool CanReceiveOnSocket(int socket);
bool CanSendOnSocket(int socket);

u32 recv(int sockfd, void* buf, size_t len, int flags);
u32 send(int sockfd, const void* buf, size_t len, int flags);
int accept(int sockfd, struct sockaddr* addr, u32* addrlen);
int listen(int sockfd, int backlog);
int getsockname(int sockfd, struct sockaddr* addr, u32* addrlen);
}