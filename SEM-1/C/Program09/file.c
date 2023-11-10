#include <stdio.h>
#include <string.h>

typedef struct items
{
    unsigned int serial_number;
    char name[10];
    unsigned int price;
}items;

typedef struct 
{
    items names;
    int qty;
}orders;


char things[][20] = {"chocolate","icecream", "cake"};
int prices[] = {10,40,90};
#define LEN_ITEMS (sizeof(things) / 20)
items groceries[LEN_ITEMS];
orders list[10];

void add_groceries(void);
void display_groceries(void);
int get_order(void);
void order_details(int cnt);


int main(void)
{
    add_groceries();
    display_groceries();
    order_details(get_order());
    return 0;
}



void add_groceries(void)
{
    for (int i = 0; i < LEN_ITEMS;i++)
    {
        items item;
        item.serial_number = i+100;
        strcpy(item.name, things[i]);
        item.price = prices[i];
        groceries[i] = item;
    }
}

void display_groceries(void)
{

    printf("\n\n+----------------------------+\n");
    printf("| No  | Items        | price |\n");
    printf("+----------------------------+\n");

    for (int i = 0;i < LEN_ITEMS ;i++ )
    {
        printf("| %-3i | %-12s | %-5i |\n",
        groceries[i].serial_number,
        groceries[i].name,
        groceries[i].price);
    }

    printf("+----------------------------+\n");

}

int get_order(void)
{
    int y = 0;
    printf("\nType 0 to end the loop \n");
    for(int i =0; i < 10; i++)
    {
        orders item;
        int order_num, qty;
        printf("Enter serial number of product :");
        scanf("%i", &order_num);

        if (order_num == 0)
        {
            break;
        }
        printf("Enter qty :");
        scanf("%i", &qty);

        int z = -1;
        for (int j = 0; j < LEN_ITEMS; j++)
        {
            if (order_num == groceries[j].serial_number)
            {
                z = j;
            }
        }
        if (z != -1 )
        {
                item.names = groceries[z];
                item.qty = qty;
                list[y] = item;
                y++;
        }
        else
        {
            printf("Item Not Found !\n");
        }

    }
    return y;
    
}

void order_details(int cnt)
{
    int total = 0;

    printf("\n\n+-----------BILL-------------+\n");
    printf("| Name         | Qty | Total |\n");
    printf("+----------------------------+\n");
    for (int i = 0; i < cnt; i++)
    {
        printf("| %-12s | %-3i | %-5i |\n",
        list[i].names.name,
        list[i].qty,
        list[i].names.price * list[i].qty);
        total += list[i].names.price * list[i].qty;
    }
    printf("+----------------------------+\n");

    printf("|        Grand Total | %-5i |\n", total);

    printf("+----------------------------+\n\n");
}