#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

void ft_lstadd_front(t_list **lst, t_list *new) {
    if (lst == NULL || new == NULL) {
        return;
    }
    new->next = *lst;
    *lst = new;
}

int ft_lstsize(t_list *lst) {
    int size = 0;
    while (lst != NULL) {
        size++;
        lst = lst->next;
    }
    return size;
}

t_list *ft_lstlast(t_list *lst) {
    if (lst == NULL) {
        return NULL;
    }
    while (lst->next != NULL) {
        lst = lst->next;
    }
    return lst;
}

void ft_lstadd_back(t_list **lst, t_list *new) {
    if (lst == NULL || new == NULL) {
        return;
    }
    t_list *last = ft_lstlast(*lst);
    if (last != NULL) {
        last->next = new;
    } else {
        *lst = new;
    }
}

void ft_lstdelone(t_list *lst, void (*del)(void *)) {
    if (lst == NULL || del == NULL) {
        return;
    }
    del(lst->content);
    free(lst);
}

void ft_lstclear(t_list **lst, void (*del)(void *)) {
    if (lst == NULL || del == NULL) {
        return;
    }
    t_list *current = *lst;
    t_list *next;
    while (current != NULL) {
        next = current->next;
        ft_lstdelone(current, del);
        current = next;
    }
    *lst = NULL;
}

void ft_lstiter(t_list *lst, void (*f)(void *)) {
    if (lst == NULL || f == NULL) {
        return;
    }
    while (lst != NULL) {
        f(lst->content);
        lst = lst->next;
    }
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list;
    t_list *new_obj;
    
    if (!lst || !f || !del)
        return (NULL);
    new_list = NULL;
    while (lst)
    {
        new_obj = ft_lstnew(f(lst->content));
        if (!new_obj)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        ft_lstadd_back(&new_list, new_obj);
        lst = lst->next;
    }
    return (new_list);
}

void *toupper_content(void *content) {
    char *str = (char *)content;
    char *new_str = (char *)malloc(strlen(str) + 1);
    if (new_str == NULL) {
        return NULL;
    }
    strcpy(new_str, str);
    for (int i = 0; new_str[i] != '\0'; i++) {
        new_str[i] = toupper(new_str[i]);
    }
    return new_str;
}

void print_content(void *content) {
    printf("%s\n", (char *)content);
}

int main(void) {
    t_list *list = NULL;
    ft_lstadd_back(&list, ft_lstnew(strdup("Hello")));
    ft_lstadd_back(&list, ft_lstnew(strdup("world")));
    ft_lstadd_back(&list, ft_lstnew(strdup("!!!")));
    ft_lstiter(list, print_content);
    t_list *new_list = ft_lstmap(list, toupper_content, free);
    ft_lstiter(new_list, print_content);
    ft_lstclear(&list, free);
    ft_lstclear(&new_list, free);
    return 0;
}