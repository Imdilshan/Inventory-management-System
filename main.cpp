#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node {
    string name;
    float price;
    Node* left;
    Node* right;

    Node(string n, float p) {
        name = n;
        price = p;
        left = right = nullptr;
    }
};

class InventoryBST {
private:
    Node* root;
    Node* insert(Node* node, string name, float price) {
        if (node == nullptr) {
            cout << "Item " << name << " added successfully.\n";
            return new Node(name, price);
        }
        if (name < node->name)
            node->left = insert(node->left, name, price);
        else if (name > node->name)
            node->right = insert(node->right, name, price);
        else
            cout << "Item " << name << " already exists. Use update to change price.\n";
        return node;
    }
    
    Node* search(Node* node, string name) {
        if (node == nullptr || node->name == name)
            return node;
        if (name < node->name)
            return search(node->left, name);
        else
            return search(node->right, name);
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << setw(15) << left << node->name << " ₹" << node->price << endl;
            inorder(node->right);
        }
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
    
    Node* deleteNode(Node* root, string name) {
        if (root == nullptr) {
            cout << "Item " << name << " not found.\n";
            return root;
        }
        if (name < root->name)
            root->left = deleteNode(root->left, name);
        else if (name > root->name)
            root->right = deleteNode(root->right, name);
        else {
            if (root->left == nullptr) {
                cout << "Item " << name << " deleted.\n";
                Node* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == nullptr) {
                cout << "🗑️ Item '" << name << "' deleted.\n";
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->name = temp->name;
            root->price = temp->price;
            root->right = deleteNode(root->right, temp->name);
        }
        return root;
    }

public:
    InventoryBST() {
        root = nullptr;
    }

    void insert(string name, float price) {
        root = insert(root, name, price);
    }

    void search(string name) {
        Node* result = search(root, name);
        if (result != nullptr)
            cout << "Found: " << result->name << " - ₹" << result->price << endl;
        else
            cout << "Item " << name << " not found.\n";
    }

    void update(string name, float newPrice) {
        Node* result = search(root, name);
        if (result != nullptr) {
            result->price = newPrice;
            cout << "Updated " << name << " price to ₹" << newPrice << ".\n";
        } else {
            cout << "Item " << name << " not found.\n";
        }
    }

    void deleteItem(string name) {
        root = deleteNode(root, name);
    }

    void display() {
        if (root == nullptr) {
            cout << " Inventory is empty.\n";
            return;
        }
        cout << "\n Current Inventory:\n";
        cout << "-------------------------------\n";
        inorder(root);
        cout << "-------------------------------\n";
    }
};

int main() {
    InventoryBST inventory;
    int choice;
    string name;
    float price;

    do {
        cout << "\n====== INVENTORY MANAGEMENT SYSTEM (BST) ======\n";
        cout << "1. Insert Item\n";
        cout << "2. Display Inventory\n";
        cout << "3. Search Item\n";
        cout << "4. Update Item Price\n";
        cout << "5. Delete Item\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                getline(cin, name);
                cout << "Enter price: ₹";
                cin >> price;
                inventory.insert(name, price);
                break;
            case 2:
                inventory.display();
                break;
            case 3:
                cout << "Enter item name to search: ";
                getline(cin, name);
                inventory.search(name);
                break;
            case 4:
                cout << "Enter item name to update: ";
                getline(cin, name);
                cout << "Enter new price: ₹";
                cin >> price;
                inventory.update(name, price);
                break;
            case 5:
                cout << "Enter item name to delete: ";
                getline(cin, name);
                inventory.deleteItem(name);
                break;
            case 6:
                cout << "Exiting program... \n";
                break;
            default:
                cout << "Invalid choice. Try again!\n";
        }
    } while (choice != 6);

    return 0;
}
