#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string check_bank(long num);
int check_math(long num, int length);
int get_length(string bank);
string bank;

int main(void)
{
    long num = get_long("Number: ");     // get a number
    bank = check_bank(num);              // check visa, amex or mastercard
    int length = get_length(bank);       // get the length of the number
    int valid = check_math(num, length); // check validity

    // add both lengths for visa
    if ((strcmp(bank, "VISA13") == 0) || (strcmp(bank, "VISA16") == 0))
    {
        bank = "VISA\n";
    }

    // remove invalid card numbers
    if (valid == 0)
    {
        bank = "INVALID\n";
    }
    printf("%s", bank);
}

string check_bank(long num)
{
    int length;
    if (num >= 5100000000000000 && num <= 5599999999999999)
    {
        bank = "MASTERCARD\n";
    }

    else if ((num >= 340000000000000 && num <= 349999999999999) || (num >= 370000000000000 && num <= 379999999999999))
    {
        bank = "AMEX\n";
    }

    else if (num >= 4000000000000 && num <= 4999999999999)
    {
        bank = "VISA13";
    }

    else if (num >= 4000000000000000 && num <= 4999999999999999)
    {
        bank = "VISA16";
    }

    else
    {
        bank = "INVALID\n";
    }

    return bank;
}

int get_length(string b)
{
    int length;
    if (strcmp(b, "AMEX\n") == 0)
    {
        length = 15;
    }
    else if (strcmp(b, "MASTERCARD\n") == 0)
    {
        length = 16;
    }
    else if (strcmp(b, "VISA13") == 0)
    {
        length = 13;
    }
    else if (strcmp(b, "VISA16") == 0)
    {
        length = 16;
    }
    else
    {
        length = 0;
    }
    return length;
}

int check_math(long num, int length)
{
    int sum1 = 0;
    int sum2 = num % 10;
    double i = 1.0;
    double j = 2.0;
    int valid;

    while (i < (double) length)
    {
        int digit = (num % (long) (pow(10.0, (i + 1.0))) - num % (long) (pow(10.0, i))) / (long) pow(10.0, i);
        int double_digit = digit * 2;
        if (double_digit > 9)
        {
            double_digit = double_digit % 10 + (double_digit - (double_digit % 10)) / 10;
        }
        sum1 += double_digit;

        i += 2.0;
    }

    while (j < (double) length)
    {
        int digit = (num % (long) (pow(10.0, (j + 1.0))) - num % (long) (pow(10.0, j))) / (long) pow(10.0, j);
        j += 2.0;
        sum2 += digit;
    }

    if ((int) (sum1 + sum2) % 10 == 0)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }
    return valid;
}
