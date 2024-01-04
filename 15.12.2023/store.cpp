#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <chrono>

typedef struct ProductPrice
{
    float retailPrice;
    float wholesalePrice;
} ProductPrice;

typedef struct Product
{
    ProductPrice price;
    char productName[20];
    std::chrono::system_clock::time_point manufactureDate;
    std::chrono::system_clock::time_point expiryDate;

} Product;

typedef struct Products
{
    Product list[10];
    int size;
} Products;

typedef struct Store
{
    char name[20];
    Products products;
} Store;

Store createShop()
{
    Store store;
    Products products;
    products.size = 0;
    store.products = products;

    char name[20];
    printf("Enter store name: ");
    scanf("%s", name);
    getchar();

    strcpy(store.name, name);

    return store;
}

void addProductToStore(Store *store)
{
    if (store->products.size + 1 == 10)
    {
        return;
    }

    char productName[20];
    float retailPrice = 0;
    float wholesalePrice = 0;

    int mdD = 0;
    int mdM = 0;
    int mdY = 0;

    int exD = 0;
    int exM = 0;
    int exY = 0;

    printf("Enter product name: ");
    scanf("%s", productName);
    getchar();

    printf("Enter retail price: ");
    scanf("%f", &retailPrice);
    getchar();

    printf("Enter wholesale price: ");
    scanf("%f", &wholesalePrice);
    getchar();

    printf("Enter manufacture date (D M YYYY): ");
    scanf("%d %d %d", &mdD, &mdM, &mdY);
    getchar();

    printf("Enter expiry date (D M YYYY): ");
    scanf("%d %d %d", &exD, &exM, &exY);
    getchar();

    struct tm manufacture_time;
    struct tm expiry_time;

    manufacture_time.tm_mday = mdD;
    manufacture_time.tm_mon = mdM - 1;
    manufacture_time.tm_year = mdY - 1900;
    manufacture_time.tm_hour = 0;
    manufacture_time.tm_min = 0;
    manufacture_time.tm_sec = 1;
    manufacture_time.tm_isdst = -1;

    std::chrono::system_clock::time_point manufacture_time_convert = std::chrono::system_clock::from_time_t(std::mktime(&manufacture_time));

    expiry_time.tm_mday = exD;
    expiry_time.tm_mon = exM - 1;
    expiry_time.tm_year = exY - 1900;
    expiry_time.tm_hour = 0;
    expiry_time.tm_min = 0;
    expiry_time.tm_sec = 1;
    expiry_time.tm_isdst = -1;

    std::chrono::system_clock::time_point expiry_time_convert = std::chrono::system_clock::from_time_t(std::mktime(&expiry_time));

    Product product;
    ProductPrice productPrice;

    productPrice.retailPrice = retailPrice;
    productPrice.wholesalePrice = wholesalePrice;

    strcpy(product.productName, productName);
    product.manufactureDate = manufacture_time_convert;
    product.expiryDate = expiry_time_convert;
    product.price = productPrice;

    store->products.list[store->products.size] = product;
    store->products.size += 1;

    printf("Product added!\n");
}

void getExpiredProducts(Store *store)
{
    if (store->products.size == 0)
    {
        return;
    }

    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);

    // Convert current time to tm structure
    std::tm currentTm = *std::localtime(&currentTimeT);

    for (int i = 0; i < store->products.size; i++)
    {
        Product product = store->products.list[i];
        std::chrono::system_clock::time_point productDate = product.expiryDate;
        std::time_t productDateT = std::chrono::system_clock::to_time_t(productDate);

        // Convert current time to tm structure
        std::tm productDateTM = *std::localtime(&productDateT);

        if (currentTm.tm_year > productDateTM.tm_year || currentTm.tm_mon > productDateTM.tm_mon || currentTm.tm_mday > productDateTM.tm_mday)
        {
            printf("Product %s is expired!\n", product.productName);
        }
    }
}

int main()
{
    Store store;
    store = createShop();
    addProductToStore(&store);
    addProductToStore(&store);
    getExpiredProducts(&store);

    return 0;
}