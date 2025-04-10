#include <iostream>
#include <vector>

using namespace std;

class User {
private:
    string name, user_name, password;
    static int m;
public:
    User() {}
    User(string n, string u, string p) : name(n), user_name(u), password(p) {
        m++;
    }
    void setUser_name(string u) {
        user_name = u;
    }
    
    bool login(User u[], string username, string pass) {
        for (int i = 0; i < m; i++) {
            if (username == u[i].user_name && pass == u[i].password) {
                cout << "Login successful" << endl;
                return true;
            }
        }
        cout << "Username or password is wrong" << endl;
        return false;
    }
};

class comment {
    string body;
    User user;
public:
    comment(string c, User u) : body(c), user(u) {}
    
    string get_body() {
        return body;
    }
};

class Tag {
private:
    string body;
public:
    Tag(string s) : body(s) {}
    
    void print() {
        cout << "Tag = " << body << endl;
    }
    
    string get_body() {
        return body;
    }
};

class news {
private:
    string title, body;
    vector<Tag> tags;
    vector<comment> comments;
    User user;
public:
    news(string t, string b, vector<Tag> tagList, vector<comment> commentList, User u)
        : title(t), body(b), tags(tagList), comments(commentList), user(u) {}

    string get_title() {
        return title;
    }

    string get_body() {
        return body;
    }

    vector<Tag> get_tags() {
        return tags;
    }

    vector<comment> get_comments() {
        return comments;
    }
};

int User::m = 0;

void print_all(news);

int main() {
    User user1("Julian", "arcane", "gsfd12345");
    User user2("Esabella", "esabel", "easy1918");
    User user3("Sam", "sam123", "o87654p");
    User users[] = { user1, user2, user3 };

    comment c1("Wow", user1);
    comment c2("Great", user2);
    comment c3("Amazing", user3);
    vector<comment> comments = { c1, c2, c3 };

    Tag t1("Computer");
    Tag t2("Science");
    vector<Tag> tags = { t1, t2 };

    user1.login(users, "ktrdkiuiu", "lkjnl");  // Incorrect login
    user1.login(users, "arcane", "gsfd12345"); // Correct login
    user2.login(users, "esabel", "easy1918");  // Correct login

    news n1("COMPUTER SCIENCE", "Computer science is a great field for studying", tags, comments, user1);
    print_all(n1);
}

void print_all(news n) {
    cout << "The news is:" << endl;
    cout << n.get_title() << ": " << n.get_body() << endl;
    
    cout << "Tags: ";
    for (Tag t : n.get_tags()) {
        cout << t.get_body() << " ";
    }
    cout << endl;

    cout << "Comment section: ";
    for (comment c : n.get_comments()) {
        cout << c.get_body() << " ";
    }
    cout << endl;
}
