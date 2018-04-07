# mcnug

McDonalds Chicken McNugget Purchasing Optimizing Tool

## Usage

```
mcnug [-d <amount>]

Options:
-d <amount>	Calculate the amount of nuggets that can be purchased
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
```
