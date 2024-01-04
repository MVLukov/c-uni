#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <chrono>

typedef struct Order
{
    char user[20];
    char city[20];
    char address[20];
    char itemName[20];
    float price;
} Order;

typedef struct Orders
{
    Order list[10];
    int size;
} Orders;

void addOrder(Orders *orders)
{
    if (orders->size + 1 == 10)
        return;

    char user[20];
    char city[20];
    char itemName[20];
    char address[20];
    float price = 0.0;

    printf("Enter user: ");
    scanf("%s", user);
    getchar();

    printf("Enter city: ");
    scanf("%s", city);
    getchar();

    printf("Enter address: ");
    scanf("%s", address);
    getchar();

    printf("Enter item name: ");
    scanf("%s", itemName);
    getchar();

    printf("Enter price: ");
    scanf("%f", &price);
    getchar();

    Order order;
    strcpy(order.address, address);
    strcpy(order.city, city);
    strcpy(order.user, user);
    strcpy(order.itemName, itemName);
    order.price = price;

    orders->list[orders->size] = order;
    orders->size += 1;

    printf("Order added!\n");
}

void ordersByCity(Orders *orders)
{
    if (orders->size == 0)
        return;

    char city[20];

    printf("Enter city to search: ");
    scanf("%s", city);
    getchar();

    for (int i = 0; i < orders->size; i++)
    {
        Order order = orders->list[i];

        if (strcmp(order.city, city) == 0)
        {
            printf("Order[%d] - City: %s, User: %s, Address: %s, Item: %s, Price: %.2f\n", (i + 1), order.city, order.user, order.address, order.itemName, order.price);
        }
    }
}

void totalOrdersPrice(Orders *orders)
{
    if (orders->size == 0)
        return;

    float totalPrice = 0;

    for (int i = 0; i < orders->size; i++)
    {
        Order order = orders->list[i];
        totalPrice += order.price;
    }

    printf("Total price: %.2f\n", totalPrice);
}

int main()
{
    Orders orders;
    orders.size = 0;

    addOrder(&orders);
    addOrder(&orders);
    addOrder(&orders);
    addOrder(&orders);

    ordersByCity(&orders);
    totalOrdersPrice(&orders);

    return 0;
}