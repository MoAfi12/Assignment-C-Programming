#include <stdio.h>
#include <string.h>



typedef struct {
    char username[40];
    char password[22];
    int user_type;  // 0 = admin, 1 = doctor, 2 = nurse, 3 = receptionist
} User;

User users[100];
int num_users = 0;

void add_user(char *username, char *password, int user_type) {
    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    users[num_users].user_type = user_type;
    num_users++;
}

int login() {
    char username[40];
    char password[22];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return users[i].user_type;
        }
    }

    return 0;  // login failed
}

int main() {
    add_user("admin", "password", 0);
    add_user("doctor", "password", 1);
    add_user("nurse", "password", 2);
    add_user("receptionist", "password", 3);

    int user_type = login();
    if (user_type == -1) {
        printf("Invalid username or password.\n");
    } else {
        printf("Welcome, %s!\n", (user_type == 0) ? "admin" : (user_type == 1) ? "doctor" : (user_type == 2) ? "nurse" : "receptionist");
    }

    return 0;
}

