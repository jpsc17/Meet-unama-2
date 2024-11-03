#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void initialize(struct Node** head_ref) {
    *head_ref = NULL;
}

struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insertInOrder(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);

    if (*head_ref == NULL || (*head_ref)->data >= new_data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* current = *head_ref;
    while (current->next != NULL && current->next->data < new_data) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void removeNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    // Se o nó a ser removido é o primeiro
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Muda a cabeça
        free(temp); // Libera a memória
        return;
    }

    // Procura o nó a ser removido
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Se o nó não foi encontrado
    if (temp == NULL) {
        printf("Valor %d não encontrado na lista.\n", key);
        return;
    }

    // Desvincula o nó da lista
    prev->next = temp->next;
    free(temp); // Libera a memória
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head;
    initialize(&head);

    int n, value;
    printf("Quantos valores deseja inserir? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite o valor #%d: ", i + 1);
        scanf("%d", &value);
        insertInOrder(&head, value);
    }

    printf("Lista encadeada ordenada: ");
    printList(head);

    printf("Digite o valor a ser removido: ");
    scanf("%d", &value);
    removeNode(&head, value);

    printf("Lista encadeada após remoção: ");
    printList(head);

    return 0;
}