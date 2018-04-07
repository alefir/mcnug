# mcnug

McDonalds Chicken McNugget Purchase Optimizing Tool

## Usage

```
mcnug [-d <amount>]

Options:
-d <amount>	Calculate the amount of nuggets that can be purchased
-n <amount>	Calculate the most efficient way to purchase the amount of nuggets
```

## Output

`mcnug` outputs the amount of four-, ten-, twenty- and forty-packs to purchase given the amount of money provided.

Consideration is made for sales tax.

## Example

```
$ ./mcnug -d 23

Four-Packs to buy: 1
Ten-Packs to buy: 0
Twenty-Packs to buy: 0
Forty-Packs to buy: 2
Remaining Money: $1.43
Total Nuggets: 84

$ ./mcnug -n 30

Four-Packs to buy: 0
Ten-Packs to buy: 1
Twenty-Packs to buy: 1
Forty-Packs to buy: 0
Money Spent: $10.25
Total Nuggets: 30
Nugget Excess: 0
```

## Configuration

Prices and sales tax can be configured by editing the values in `prices.h`
