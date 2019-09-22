//
int main(void)
{
    /* this is a 'block' */
    int i = 5;

    {
        /* this is also a 'block', nested inside the outer block */
        int i = 6;
    }

    return 0;
}
