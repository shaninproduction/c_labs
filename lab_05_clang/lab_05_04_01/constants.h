#define MAX_LASTNAME 25
#define MAX_NAME 10
#define MARKS 4
#define INVALID_FLAG 53

struct person
{
    char lastname[MAX_LASTNAME + 1];
    char name[MAX_NAME + 1];
    uint32_t marks[4];
};