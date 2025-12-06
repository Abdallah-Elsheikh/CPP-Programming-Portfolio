#include <iostream>
using namespace std;

struct Decision {
    string decision_type;
    string person_name;
    string decision_time;
};

class Node {
public:
    Decision data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(string decision_type, string person_name, string decision_time) {
        Node* newNode = new Node();
        newNode->data.decision_type = decision_type;
        newNode->data.person_name = person_name;
        newNode->data.decision_time = decision_time;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Removed last decision:\n[ " << temp->data.decision_type
             << " ] by " << temp->data.person_name
             << " at " << temp->data.decision_time << endl;

        top = top->next;
        delete temp;
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "No decisions to show." << endl;
            return;
        }

        cout << "Last decision:\n[ " << top->data.decision_type
             << " ] by " << top->data.person_name
             << " at " << top->data.decision_time << endl;
        cout << endl;
    }

    void display() {
        Node* temp = top;
        if (isEmpty()) {
            cout << "No decisions yet." << endl;
            return;
        }

        cout << "Decision history:\n";
        while (temp != NULL) {
            cout << "[ " << temp->data.decision_type
                 << " ] by " << temp->data.person_name
                 << " at " << temp->data.decision_time << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack decisionHistory;
    int n;
    cout << "Enter number of decisions to add : ";
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string type, name, time;
        cout << "\nDecision #" << (i + 1) << endl;
        cout << "Enter decision type (Approve/Reject) : ";
        getline(cin, type);

        cout << "Enter person name : ";
        getline(cin, name);

        cout << "Enter decision time ( e.g., 10:30 AM ) : ";
        getline(cin, time);

        decisionHistory.push(type, name, time);
    }

    cout << endl;
    decisionHistory.display();

    decisionHistory.peek();

    decisionHistory.pop();

    decisionHistory.display();

    return 0;
}
