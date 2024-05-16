#include<stdio.h>
int mutex = 0;
void producer()
{
    while(mutex<10)
    {
        printf("Produced item %d\n",mutex);
        mutex++;
        if(mutex>=10)
        {
            printf("Producer is full\n");
        }
    }
}

void consumer()
{
    while(mutex>0)
    {
        printf("Consumed item %d\n",mutex);
        mutex--;
        if(mutex<=0)
        {
            printf("Consumer is full\n");
        }
    }
}
int main()
{
    producer();
    consumer();
    return 0;
}