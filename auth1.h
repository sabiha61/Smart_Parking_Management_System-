#ifndef AUTH1_H
#define AUTH1_H

int registerUser(const char *username, const char *password, const char *role);
int loginUser(const char *username, const char *password, char *roleOut);

#endif
