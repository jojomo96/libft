#include "ft_dlist.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void print_list(t_dlist *lst) {
    t_dlist_node *current = lst->head;
    printf("List size: %zu\n", ft_dlist_size(lst));
    while (current != NULL) {
        printf("%s -> ", (char*)current->content);
        current = current->next;
    }
    printf("NULL\n");
}

void test_dlist_new_and_destroy() {
    printf("Testing ft_dlist_new and ft_dlist_destroy...\n");
    t_dlist *lst = ft_dlist_new();
    assert(lst != NULL && lst->head == NULL && lst->size == 0);
    ft_dlist_destroy(&lst, free);
    assert(lst == NULL);
    printf("PASS\n");
}

void test_dlist_prepend_and_pop_front() {
    printf("Testing ft_dlist_prepend and ft_dlist_pop_front...\n");
    t_dlist *lst = ft_dlist_new();
    char *data1 = strdup("First");
    char *data2 = strdup("Second");

    ft_dlist_prepend(lst, ft_dlist_new_node(data2));
    ft_dlist_prepend(lst, ft_dlist_new_node(data1));

    print_list(lst);

    t_dlist_node *popped = ft_dlist_pop_front(lst);
    assert(strcmp(popped->content, data1) == 0);
    free(popped->content);
    free(popped);

    print_list(lst);

    ft_dlist_destroy(&lst, free);
    printf("PASS\n");
}

void test_dlist_append_and_pop_back() {
    printf("Testing ft_dlist_append and ft_dlist_pop_back...\n");
    t_dlist *lst = ft_dlist_new();
    char *data1 = strdup("First");
    char *data2 = strdup("Second");

    ft_dlist_append(lst, ft_dlist_new_node(data1));
    ft_dlist_append(lst, ft_dlist_new_node(data2));

    print_list(lst);

    t_dlist_node *popped = ft_dlist_pop_back(lst);
    assert(strcmp(popped->content, data2) == 0);
    free(popped->content);
    free(popped);

    print_list(lst);

    ft_dlist_destroy(&lst, free);
    printf("PASS\n");
}

void test_dlist_rotate() {
    printf("Testing ft_dlist_rotate...\n");
    t_dlist *lst = ft_dlist_new();
    char *data1 = strdup("First");
    char *data2 = strdup("Second");
    char *data3 = strdup("Third");

    ft_dlist_append(lst, ft_dlist_new_node(data1));
    ft_dlist_append(lst, ft_dlist_new_node(data2));
    ft_dlist_append(lst, ft_dlist_new_node(data3));

    printf("Original list:\n");
    print_list(lst);

    ft_dlist_rotate(lst);
    printf("After rotate:\n");
    print_list(lst);

    // Check if the first element is now "Second"
    assert(strcmp(lst->head->content, data2) == 0);
    // Check if the last element is now "First"
    assert(strcmp(lst->tail->content, data1) == 0);

    ft_dlist_destroy(&lst, free);
    printf("PASS\n");
}

void test_dlist_reverse_rotate() {
    printf("Testing ft_dlist_reverse_rotate...\n");
    t_dlist *lst = ft_dlist_new();
    char *data1 = strdup("First");
    char *data2 = strdup("Second");
    char *data3 = strdup("Third");

    ft_dlist_append(lst, ft_dlist_new_node(data1));
    ft_dlist_append(lst, ft_dlist_new_node(data2));
    ft_dlist_append(lst, ft_dlist_new_node(data3));

    printf("Original list:\n");
    print_list(lst);

    ft_dlist_reverse_rotate(lst);
    printf("After reverse rotate:\n");
    print_list(lst);

    // Check if the first element is now "Third"
    assert(strcmp(lst->head->content, data3) == 0);
    // Check if the second element is now "First"
    assert(strcmp(lst->head->next->content, data1) == 0);

    ft_dlist_destroy(&lst, free);
    printf("PASS\n");
}

int main() {
    test_dlist_new_and_destroy();
    test_dlist_prepend_and_pop_front();
    test_dlist_append_and_pop_back();
    test_dlist_rotate();
    test_dlist_reverse_rotate();
    // Add more tests for each function as needed
    return 0;
}
