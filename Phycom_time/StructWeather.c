#include <stdio.h>
#include <string.h>
 
struct Weather
{
    char outlook[9]; // outlook{overcast,sunny,rain}
    int temperature;
    int humidity;
    char wind; // wind{T,F}
};
void playing_decision(struct Weather *weather);
 
int main()
{
    int n;
    scanf("%d", &n);
    struct Weather weather[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %c", weather[i].outlook, &weather[i].temperature, &weather[i].humidity, &weather[i].wind);
    }
    for (int i = 0; i < n; i++)
    {
        playing_decision(&weather[i]);
    }
}
 
void playing_decision(struct Weather *weather)
{
    if (strcmp(weather->outlook, "overcast") == 0)
    {
        printf("yes\n");
    }
    else if (strcmp(weather->outlook, "rain") == 0)
    {
        if (weather->wind == 'F')
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    else if (strcmp(weather->outlook, "sunny") == 0)
    {
        if (weather->humidity > 77.5)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
    }
}